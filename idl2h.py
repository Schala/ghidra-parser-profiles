import re
import sys

import pdb

class Parameter:
	def __init__(self, name, type=None):
		self.name = name
		self.type = type
	
	def __str__(self):
		return f"{self.type} {self.name}"


class Method:
	def __init__(self, name, rettype, intf):
		self.name = name
		self.rettype = rettype
		self.intf = intf
		self.params = []
	
	def add_param(self, name, type):
		self.params.append(Parameter(name, type))
	
	def __str__(self):
		output = f"\t{self.rettype} (*{self.name})({self.intf.name} *This"

		for p in self.params:
			output += f", {str(p)}"
		output += ");\n"
		return output


class Interface:
	def __init__(self, name):
		self.name = name
		self.root = None
		self.methods = []
	
	def add_method(self, method):
		self.methods.append(method)
	
	def set_root(self, root):
		self.root = root
		for m in root.methods:
			self.methods.append(m)
	
	def __str__(self):
		output = f"typedef struct {self.name} {self.name};\n\ntypedef struct {self.name}Vtbl {{\n"
		for m in self.methods:
			output += str(m)
		output += f"}};\n\nstruct {self.name} {{\n\t{self.name}Vtbl *lpVtbl;\n}};\n\n"
		return output


class Field:
	def __init__(self, name, type, array_depth=-1):
		self.name = name
		self.type = type
		self.array_depth = array_depth
	
	def __str__(self):
		output = f"{self.type} {self.name}"
		if self.array_depth >= 0:
			output += f"[{self.array_depth}]"
		output += ";\n"
		return output


class Structure:
	def __init__(self, name):
		self.private_name = name
		self.public_name = None
		self.ptr_name = None
		self.fields = []
	
	def add_field(self, field):
		self.fields.append(field)
	
	def __str__(self):
		output = "typedef struct "
		if self.private_name:
			output += f"{self.private_name} "
		output += "{\n"
		for f in self.fields:
			output += f"\t{str(f)}"
		output += f"}} {self.public_name};\n\n"
		return output


class EnumConstant:
	def __init__(self, name, value):
		self.name = name
		self.value = value

	def __str__(self):
		return f"{self.name} = {self.value}"


class Enumeration:
	def __init__(self, name):
		self.private_name = name
		self.public_name = None
		self.ptr_name = None
		self.vals = []
	
	def add_const(self, name, value):
		self.vals.append(EnumConstant(name, value))
	
	def __str__(self):
		output = "typedef enum "
		if self.private_name:
			output += f"{self.private_name} "
		output += "{\n"
		total_vals = len(self.vals) - 1
		for i, v in enumerate(self.vals):
			output += f"\t{str(v)}"
			if i != total_vals:
				output += ","
			output += "\n"
		output += f"}} {self.public_name};\n\n"
		return output


# IUnknown
unknown = Interface("IUnknown")
query_interface = Method("QueryInterface", "HRESULT", unknown)
query_interface.add_param("riid", "IID *")
query_interface.add_param("ppvObject", "void **")
unknown.add_method(query_interface)
unknown.add_method(Method("AddRef", "ULONG", unknown))
unknown.add_method(Method("Release", "ULONG", unknown))


fwds = []
intfs = [unknown]
elems = []

def parse_idl(context):
	intf_pat = re.compile(r"interface\s+(\w+)")
	intf_fwd_pat = re.compile(r"interface\s+(\w+);")
	root_pat = re.compile(r"\s*:\s*(\w+)")
	cpp_pat = re.compile(r'cpp_quote\s*\(\s*"(.*)"\s*\)')
	imp_pat = re.compile(r'import\s+"(\w+)\.idl"')
	field_pat = re.compile(r"\s*(\w+)\s*(\*+)?\s+(\w+)\s*\[?\s*([0-9]+)?\s*\]?")
	struct_pat = re.compile(r"typedef\s+struct\s+(\w+)")
	end_pat = re.compile(r"\}\s*(\w+)?,?\s*\*?(\w+)?\s*;")
	td_pat = re.compile(r"typedef\s+(.*);")
	enum_pat = re.compile(r"typedef\s+enum\s+(\w+)")
	enum_const_pat = re.compile(r"\s*(\w+)\s*=\s*([\w\s\-\+\<\>]+),?")
	func_pat = re.compile(r"\s*(\w+)\s+(\w+)\s*\(")
	param_pat = re.compile(r"\s*\[.*\]\s*(const)?(\w+)\s*(\*+)?(const)?\s+(\w+)\s*,?\s*(\);)?")
	const_pat = re.compile(r"const\s+\w+\s+(\w+)\s*=\s*([\w\s\-\+\<\>]+);")
	cplusplus_pat = re.compile(r"#ifdef\s+__cplusplus|(?<!!)\s*defined\s*\(\s*__cplusplus")
	
	curr_intf = None
	curr_struct = None
	curr_enum = None
	curr_func = None
	skip = False
	if_depth = 0

	for line in context.splitlines():
		in_scope = bool(curr_intf or curr_enum or curr_struct or curr_func)

		if not in_scope:
			if not skip:
				line = line.strip()
				if not line or line.startswith("//"):
					continue

				imp_match = imp_pat.match(line)
				if imp_match:
					elems.append(f"#include \"{imp_match.group(1)}.h\"")
					continue
				
				const_match = const_pat.match(line)
				if const_match:
					elems.append(f"#define {const_match.group(1)} {const_match.group(2)}")
					continue
				
				cpp_match = cpp_pat.match(line)
				if cpp_match:
					if not cpp_match.group(1).startswith("//"):
						cplusplus_match = cplusplus_pat.match(line)
						if cplusplus_match or "#if 0" in cpp_match.group(1):
							skip = True
						else:
							elems.append(cpp_match.group(1))
					continue

				enum_match = enum_pat.match(line)
				if enum_match:
					curr_enum = Enumeration(enum_match.group(1))
					continue

				struct_match = struct_pat.match(line)
				if struct_match:
					curr_struct = Structure(struct_match.group(1))
					continue

				# must be checked before interface parse
				intf_fwd_match = intf_fwd_pat.match(line)
				if intf_fwd_match:
					fwds.append(intf_fwd_match.group(1))
					continue

				intf_match = intf_pat.match(line)
				if intf_match:
					curr_intf = Interface(intf_match.group(1))
					continue

				# typedefs must be last to avoid enum/struct clashing
				td_match = td_pat.match(line)
				if td_match:
					elems.append(f"typedef {td_match.group(1)};")
					continue
			else:
				cpp_match = cpp_pat.match(line)
				if cpp_match:
					if "#if" in cpp_match.group(1):
						if_depth += 1
						continue
					if "#endif" in cpp_match.group(1):
						if if_depth == 0:
							skip = False
							continue
						if_depth -= 1
				continue
		else:
			if curr_intf:
				if curr_func:
					param_match = param_pat.match(line)
					if param_match:
						pdb.set_trace()
						mytype = ""
						if param_match.group(1):
							mytype = "const "
						mytype += param_match.group(2)
						if param_match.group(3):
							mytype += param_match.group(3)
						if param_match.group(4):
							mytype += " const"
						curr_func.add_param(param_match.group(5), mytype)

						if param_match.group(6):
							curr_intf.add_method(curr_func)
							curr_func = None
							continue
						
				root_match = root_pat.match(line)
				if root_match:
					for i in intfs:
						if i.name == root_match.group(1):
							curr_intf.set_root(i)
					continue

				func_match = func_pat.match(line)
				if func_match:
					curr_func = Method(func_match.group(2), func_match.group(1), curr_intf)
					continue

				if line == "};":
					intfs.append(curr_intf)
					elems.append(curr_intf)
					curr_intf = None
					continue
			if curr_enum:
				enum_const_match = enum_const_pat.match(line)
				if enum_const_match:
					curr_enum.add_const(enum_const_match.group(1), enum_const_match.group(2))
					continue

				end_match = end_pat.match(line)
				if end_match:
					if end_match.group(1):
						curr_enum.public_name = end_match.group(1)
					if end_match.group(2):
						curr_enum.ptr_name = end_match.group(2)
					elems.append(curr_enum)
					curr_enum = None
					continue
			if curr_struct:
				field_match = field_pat.match(line)
				if field_match:
					field = Field(field_match.group(3), field_match.group(1));
					if field_match.group(2):
						field.type += field_match.group(2)
					if field_match.group(4):
						field.array_depth = int(field_match.group(4))
					curr_struct.add_field(field)
					continue

				end_match = end_pat.match(line)
				if end_match:
					if end_match.group(1):
						curr_struct.public_name = end_match.group(1)
					if end_match.group(2):
						curr_struct.ptr_name = end_match.group(2)
					elems.append(curr_struct)
					curr_struct = None
					continue

idl = None
try:
	with open(sys.argv[1], "r") as f:
		idl = f.read()	
	parse_idl(idl)
except FileNotFoundError as e:
	print(f"Error: {e}")

for e in elems:
	try:
		print(str(e))
	except:
		print("oops!")
