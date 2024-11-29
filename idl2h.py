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
	def __init__(self, name, rettype, interface):
		self.name = name
		self.rettype = rettype
		self.intf = interface
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


class IDLParser:
	_intf_pat = re.compile(r"interface\s+(\w+)")
	_intf_fwd_pat = re.compile(r"interface\s+(\w+);")
	_root_pat = re.compile(r"\s*:?\s*(\w+)")
	_cpp_pat = re.compile(r'cpp_quote\s*\(\s*"(.*)"\s*\)')
	_imp_pat = re.compile(r'import\s+"(\w+)\.(h|idl)"')
	_field_pat = re.compile(r"\s*(\w+)\s*(\*+)?\s+(\w+)\s*\[?\s*([0-9]+)?\s*\]?")
	_struct_pat = re.compile(r"typedef\s+struct\s+(\w+)")
	_end_pat = re.compile(r"\}\s*(\w+)?,?\s*\*?(\w+)?\s*;")
	_td_pat = re.compile(r"typedef\s+(.*);")
	_enum_pat = re.compile(r"typedef\s+enum\s+(\w+)")
	_enum_const_pat = re.compile(r"\s*(\w+)\s*=\s*([\w\s\-\+\<\>]+),?")
	_func_pat = re.compile(r"\s*(\w+)\s+(\w+)\s*\(")
	_param_pat = re.compile(r"\s*\[.*\]\s*(const)?(\w+)\s*(\*+)?(const)?\s+(\w+)\s*,?\s*(\);)?")
	_const_pat = re.compile(r"const\s+\w+\s+(\w+)\s*=\s*([\w\s\-\+\<\>]+);")
	_cplusplus_pat = re.compile(r"#ifdef\s+__cplusplus|(?<!!)\s*defined\s*\(\s*__cplusplus")

	def __init__(self, input):
		# IUnknown
		unknown = Interface("IUnknown")
		query_interface = Method("QueryInterface", "HRESULT", unknown)
		query_interface.add_param("riid", "IID *")
		query_interface.add_param("ppvObject", "void **")
		unknown.add_method(query_interface)
		unknown.add_method(Method("AddRef", "ULONG", unknown))
		unknown.add_method(Method("Release", "ULONG", unknown))

		self._intfs = [unknown]
		self._fwds = []
		self._items = []
		self._imps = []
		self._input = input.splitlines()
		self._line = 0
	
	def _parse_import(self, match):
		self._items.append(f"#include \"{match.group(1)}.h\"")
		self._line += 1

		# might have to parse these as well
		if match.group(2) == "idl":
			self._imps.append(match.group(1))
	
	def _parse_cpp_quote(self, match):
		if not match.group(1).startswith("//"):
			cplusplus_match = IDLParser._cplusplus_pat.match(match.group(1))
			if cplusplus_match or "#if 0" in match.group(1):
				if_depth = 0
				self._line += 1
				while True:
					cpp_match = IDLParser._cpp_pat.match(self._input[self._line])
					if cpp_match:
						if "#if" in cpp_match.group(1):
							if_depth += 1
							self._line += 1
							continue
						if "#endif" in cpp_match.group(1):
							if if_depth == 0:
								self._line += 1
								break
							if_depth -= 1
					self._line += 1
			else:
				self._items.append(match.group(1))
				self._line += 1
	
	def _parse_enum(self, match):
		enum = Enumeration(match.group(1))

		while True:
			self._line += 1
			val_match = IDLParser._enum_const_pat.match(self._input[self._line])
			if not val_match:
				break
			else:
				enum.add_const(val_match.group(1), val_match.group(2))
		
		end_match = IDLParser._end_pat.match(self._input[self._line])
		if end_match:
			if end_match.group(1):
				enum.public_name = end_match.group(1)
			if end_match.group(2):
				enum.ptr_name = end_match.group(2)
			self._items.append(enum)
	
	def _parse_struct(self, match):
		struct = Structure(match.group(1))

		while True:
			self._line += 1
			field_match = IDLParser._field_pat.match(self._input[self._line])
			if not field_match:
				break
			field = Field(field_match.group(3), field_match.group(1));
			if field_match.group(2):
				field.type += field_match.group(2)
			if field_match.group(4):
				field.array_depth = int(field_match.group(4))
			struct.add_field(field)
		
		end_match = IDLParser._end_pat.match(self._input[self._line])
		if end_match:
			if end_match.group(1):
				struct.public_name = end_match.group(1)
			if end_match.group(2):
				struct.ptr_name = end_match.group(2)
			self._items.append(struct)
		self._line += 1
	
	def _parse_method(self, match, interface):
		func = Method(match.group(2), match.group(1), interface)

		while True:
			param_match = IDLParser._param_pat.match(self._input[self._line])
			if param_match:
				mytype = ""
				if param_match.group(1):
					mytype = "const "
				mytype += param_match.group(2)
				if param_match.group(3):
					mytype += param_match.group(3)
				if param_match.group(4):
					mytype += " const"
				func.add_param(param_match.group(5), mytype)

				if param_match.group(6):
					interface.add_method(func)
					self._line += 1
	
	def _parse_interface(self, match):
		intf = Interface(match.group(1))
		self._line += 1

		root_match = IDLParser._root_pat.match(self._input[self._line])
		if root_match:
			for i in self._intfs:
				if i.name == root_match.group(1):
					intf.set_root(i)
			self._line += 1
		
		while self._input[self._line] != "};":
			func_match = IDLParser._func_pat.match(self._input[self._line])
			if func_match:
				self._parse_method(func_match, intf)
			pdb.set_trace()
			self._line += 1
	
	def parse(self):
		self._line = 0

		while self._line < len(self._input):
			self._input[self._line] = self._input[self._line].strip()

			# 'None' safeguard
			if not self._input[self._line]:
				self._line += 1
				continue
			
			# import
			imp_match = IDLParser._imp_pat.match(self._input[self._line])
			if imp_match:
				self._parse_import(imp_match)
				continue

			# const
			const_match = IDLParser._const_pat.match(self._input[self._line])
			if const_match:
				self._items.append(f"#define {const_match.group(1)} {const_match.group(2)}")
				self._line += 1
				continue

			# cpp_quote
			cpp_match = IDLParser._cpp_pat.match(self._input[self._line])
			if cpp_match:
				self._parse_cpp_quote(cpp_match)
				continue

			# enum
			enum_match = IDLParser._enum_pat.match(self._input[self._line])
			if enum_match:
				self._parse_enum(enum_match)
				continue

			# struct
			struct_match = IDLParser._struct_pat.match(self._input[self._line])
			if struct_match:
				self._parse_struct(struct_match)
				continue

			# interface
			intf_match = IDLParser._intf_pat.match(self._input[self._line])
			if intf_match:
				self._parse_interface(intf_match)
				continue

			# typedefs must be last to avoid enum/struct clashing
			td_match = IDLParser._td_pat.match(self._input[self._line])
			if td_match:
				self._items.append(f"typedef {td_match.group(1)};")
				self._line += 1
				continue

			# everything else, skip it
			self._line += 1
			continue

# def parse_idl(context):

# 	for line in context.splitlines():
# 		in_scope = bool(curr_intf or curr_enum or curr_struct or curr_func)

# 		if not in_scope:
# 			if not skip:
# 				line = line.strip()
# 				if not line or line.startswith("//"):
# 					continue

# 				imp_match = imp_pat.match(line)
# 				if imp_match:
# 					elems.append(f"#include \"{imp_match.group(1)}.h\"")
# 					continue
				
# 				const_match = const_pat.match(line)
# 				if const_match:
# 					elems.append(f"#define {const_match.group(1)} {const_match.group(2)}")
# 					continue
				
# 				cpp_match = cpp_pat.match(line)
# 				if cpp_match:
# 					if not cpp_match.group(1).startswith("//"):
# 						cplusplus_match = cplusplus_pat.match(line)
# 						if cplusplus_match or "#if 0" in cpp_match.group(1):
# 							skip = True
# 						else:
# 							elems.append(cpp_match.group(1))
# 					continue

# 				enum_match = enum_pat.match(line)
# 				if enum_match:
# 					curr_enum = Enumeration(enum_match.group(1))
# 					continue

# 				struct_match = struct_pat.match(line)
# 				if struct_match:
# 					curr_struct = Structure(struct_match.group(1))
# 					continue

# 				# must be checked before interface parse
# 				intf_fwd_match = intf_fwd_pat.match(line)
# 				if intf_fwd_match:
# 					fwds.append(intf_fwd_match.group(1))
# 					continue

# 				intf_match = intf_pat.match(line)
# 				if intf_match:
# 					curr_intf = Interface(intf_match.group(1))
# 					continue

# 				# typedefs must be last to avoid enum/struct clashing
# 				td_match = td_pat.match(line)
# 				if td_match:
# 					elems.append(f"typedef {td_match.group(1)};")
# 					continue
# 			else:
# 				cpp_match = cpp_pat.match(line)
# 				if cpp_match:
# 					if "#if" in cpp_match.group(1):
# 						if_depth += 1
# 						continue
# 					if "#endif" in cpp_match.group(1):
# 						if if_depth == 0:
# 							skip = False
# 							continue
# 						if_depth -= 1
# 				continue
# 		else:
# 			if curr_intf:
# 				if curr_func:
# 					param_match = param_pat.match(line)
# 					if param_match:
# 						pdb.set_trace()
# 						mytype = ""
# 						if param_match.group(1):
# 							mytype = "const "
# 						mytype += param_match.group(2)
# 						if param_match.group(3):
# 							mytype += param_match.group(3)
# 						if param_match.group(4):
# 							mytype += " const"
# 						curr_func.add_param(param_match.group(5), mytype)

# 						if param_match.group(6):
# 							curr_intf.add_method(curr_func)
# 							curr_func = None
# 							continue
						
# 				root_match = root_pat.match(line)
# 				if root_match:
# 					for i in intfs:
# 						if i.name == root_match.group(1):
# 							curr_intf.set_root(i)
# 					continue

# 				func_match = func_pat.match(line)
# 				if func_match:
# 					curr_func = Method(func_match.group(2), func_match.group(1), curr_intf)
# 					continue

# 				if line == "};":
# 					intfs.append(curr_intf)
# 					elems.append(curr_intf)
# 					curr_intf = None
# 					continue
# 			if curr_enum:
# 				enum_const_match = enum_const_pat.match(line)
# 				if enum_const_match:
# 					curr_enum.add_const(enum_const_match.group(1), enum_const_match.group(2))
# 					continue

# 				end_match = end_pat.match(line)
# 				if end_match:
# 					if end_match.group(1):
# 						curr_enum.public_name = end_match.group(1)
# 					if end_match.group(2):
# 						curr_enum.ptr_name = end_match.group(2)
# 					elems.append(curr_enum)
# 					curr_enum = None
# 					continue
# 			if curr_struct:
# 				field_match = field_pat.match(line)
# 				if field_match:
# 					field = Field(field_match.group(3), field_match.group(1));
# 					if field_match.group(2):
# 						field.type += field_match.group(2)
# 					if field_match.group(4):
# 						field.array_depth = int(field_match.group(4))
# 					curr_struct.add_field(field)
# 					continue

# 				end_match = end_pat.match(line)
# 				if end_match:
# 					if end_match.group(1):
# 						curr_struct.public_name = end_match.group(1)
# 					if end_match.group(2):
# 						curr_struct.ptr_name = end_match.group(2)
# 					elems.append(curr_struct)
# 					curr_struct = None
# 					continue

idlp = None
try:
	with open(sys.argv[1], "r") as f:
		idl = f.read()	
	
	idlp = IDLParser(idl)
	idlp.parse()
except FileNotFoundError as e:
	print(f"Error: {e}")

if idlp:
	for i in idlp._items:
		try:
			print(str(i))
		except:
			print("oops!")
