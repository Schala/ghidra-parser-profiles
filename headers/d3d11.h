#pragma once

typedef enum D3D11_USAGE {
  D3D11_USAGE_DEFAULT = 0,
  D3D11_USAGE_IMMUTABLE = 1,
  D3D11_USAGE_DYNAMIC = 2,
  D3D11_USAGE_STAGING = 3
};

typedef struct D3D11_BUFFER_DESC {
  UINT        ByteWidth;
  D3D11_USAGE Usage;
  UINT        BindFlags;
  UINT        CPUAccessFlags;
  UINT        MiscFlags;
  UINT        StructureByteStride;
} D3D11_BUFFER_DESC;

typedef struct D3D11_BUFFER_RTV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
} D3D11_BUFFER_RTV;

typedef struct D3D11_BUFFER_SRV {
  union {
    UINT FirstElement;
    UINT ElementOffset;
  };
  union {
    UINT NumElements;
    UINT ElementWidth;
  };
} D3D11_BUFFER_SRV;

typedef struct D3D11_BUFFER_UAV {
  UINT FirstElement;
  UINT NumElements;
  UINT Flags;
} D3D11_BUFFER_UAV;

typedef struct D3D11_BUFFEREX_SRV {
  UINT FirstElement;
  UINT NumElements;
  UINT Flags;
} D3D11_BUFFEREX_SRV;

typedef struct D3D11_CLASS_INSTANCE_DESC {
  UINT InstanceId;
  UINT InstanceIndex;
  UINT TypeId;
  UINT ConstantBuffer;
  UINT BaseConstantBufferOffset;
  UINT BaseTexture;
  UINT BaseSampler;
  BOOL Created;
} D3D11_CLASS_INSTANCE_DESC;

typedef enum D3D11_DSV_DIMENSION {
  D3D11_DSV_DIMENSION_UNKNOWN = 0,
  D3D11_DSV_DIMENSION_TEXTURE1D = 1,
  D3D11_DSV_DIMENSION_TEXTURE1DARRAY = 2,
  D3D11_DSV_DIMENSION_TEXTURE2D = 3,
  D3D11_DSV_DIMENSION_TEXTURE2DARRAY = 4,
  D3D11_DSV_DIMENSION_TEXTURE2DMS = 5,
  D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY = 6
};

typedef enum D3D11_INPUT_CLASSIFICATION {
  D3D11_INPUT_PER_VERTEX_DATA = 0,
  D3D11_INPUT_PER_INSTANCE_DATA = 1
};

typedef struct D3D11_INPUT_ELEMENT_DESC {
  LPCSTR                     SemanticName;
  UINT                       SemanticIndex;
  DXGI_FORMAT                Format;
  UINT                       InputSlot;
  UINT                       AlignedByteOffset;
  D3D11_INPUT_CLASSIFICATION InputSlotClass;
  UINT                       InstanceDataStepRate;
} D3D11_INPUT_ELEMENT_DESC;

typedef enum D3D11_RESOURCE_DIMENSION {
  D3D11_RESOURCE_DIMENSION_UNKNOWN = 0,
  D3D11_RESOURCE_DIMENSION_BUFFER = 1,
  D3D11_RESOURCE_DIMENSION_TEXTURE1D = 2,
  D3D11_RESOURCE_DIMENSION_TEXTURE2D = 3,
  D3D11_RESOURCE_DIMENSION_TEXTURE3D = 4
};

typedef enum D3D11_RTV_DIMENSION {
  D3D11_RTV_DIMENSION_UNKNOWN = 0,
  D3D11_RTV_DIMENSION_BUFFER = 1,
  D3D11_RTV_DIMENSION_TEXTURE1D = 2,
  D3D11_RTV_DIMENSION_TEXTURE1DARRAY = 3,
  D3D11_RTV_DIMENSION_TEXTURE2D = 4,
  D3D11_RTV_DIMENSION_TEXTURE2DARRAY = 5,
  D3D11_RTV_DIMENSION_TEXTURE2DMS = 6,
  D3D11_RTV_DIMENSION_TEXTURE2DMSARRAY = 7,
  D3D11_RTV_DIMENSION_TEXTURE3D = 8
};

typedef struct D3D11_SO_DECLARATION_ENTRY {
  UINT   Stream;
  LPCSTR SemanticName;
  UINT   SemanticIndex;
  BYTE   StartComponent;
  BYTE   ComponentCount;
  BYTE   OutputSlot;
} D3D11_SO_DECLARATION_ENTRY;

typedef enum D3D11_SRV_DIMENSION { 
  D3D11_SRV_DIMENSION_UNKNOWN           = 0,
  D3D11_SRV_DIMENSION_BUFFER            = 1,
  D3D11_SRV_DIMENSION_TEXTURE1D         = 2,
  D3D11_SRV_DIMENSION_TEXTURE1DARRAY    = 3,
  D3D11_SRV_DIMENSION_TEXTURE2D         = 4,
  D3D11_SRV_DIMENSION_TEXTURE2DARRAY    = 5,
  D3D11_SRV_DIMENSION_TEXTURE2DMS       = 6,
  D3D11_SRV_DIMENSION_TEXTURE2DMSARRAY  = 7,
  D3D11_SRV_DIMENSION_TEXTURE3D         = 8,
  D3D11_SRV_DIMENSION_TEXTURECUBE       = 9,
  D3D11_SRV_DIMENSION_TEXTURECUBEARRAY  = 10,
  D3D11_SRV_DIMENSION_BUFFEREX          = 11
} D3D11_SRV_DIMENSION;

typedef struct D3D11_SUBRESOURCE_DATA {
  const void *pSysMem;
  UINT       SysMemPitch;
  UINT       SysMemSlicePitch;
} D3D11_SUBRESOURCE_DATA;

typedef struct D3D11_TEX1D_ARRAY_DSV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX1D_ARRAY_DSV;

typedef struct D3D11_TEX1D_ARRAY_RTV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX1D_ARRAY_RTV;

typedef struct D3D11_TEX1D_ARRAY_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX1D_ARRAY_SRV;

typedef struct D3D11_TEX1D_ARRAY_UAV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX1D_ARRAY_UAV;

typedef struct D3D11_TEX1D_DSV {
  UINT MipSlice;
} D3D11_TEX1D_DSV;

typedef struct D3D11_TEX1D_RTV {
  UINT MipSlice;
} D3D11_TEX1D_RTV;

typedef struct D3D11_TEX1D_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
} D3D11_TEX1D_SRV;

typedef struct D3D11_TEX1D_UAV {
  UINT MipSlice;
} D3D11_TEX1D_UAV;

typedef struct D3D11_TEX2D_ARRAY_DSV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2D_ARRAY_DSV;

typedef struct D3D11_TEX2D_ARRAY_RTV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2D_ARRAY_RTV;

typedef struct D3D11_TEX2D_ARRAY_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2D_ARRAY_SRV;

typedef struct D3D11_TEX2D_ARRAY_UAV {
  UINT MipSlice;
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2D_ARRAY_UAV;

typedef struct D3D11_TEX2D_DSV {
  UINT MipSlice;
} D3D11_TEX2D_DSV;

typedef struct D3D11_TEX2D_RTV {
  UINT MipSlice;
} D3D11_TEX2D_RTV;

typedef struct D3D11_TEX2D_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
} D3D11_TEX2D_SRV;

typedef struct D3D11_TEX2D_UAV {
  UINT MipSlice;
} D3D11_TEX2D_UAV;

typedef struct D3D11_TEX2DMS_ARRAY_DSV {
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2DMS_ARRAY_DSV;

typedef struct D3D11_TEX2DMS_ARRAY_RTV {
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2DMS_ARRAY_RTV;

typedef struct D3D11_TEX2DMS_ARRAY_SRV {
  UINT FirstArraySlice;
  UINT ArraySize;
} D3D11_TEX2DMS_ARRAY_SRV;

typedef struct D3D11_TEX2DMS_DSV {
  UINT UnusedField_NothingToDefine;
} D3D11_TEX2DMS_DSV;

typedef struct D3D11_TEX2DMS_RTV {
  UINT UnusedField_NothingToDefine;
} D3D11_TEX2DMS_RTV;

typedef struct D3D11_TEX2DMS_SRV {
  UINT UnusedField_NothingToDefine;
} D3D11_TEX2DMS_SRV;

typedef struct D3D11_TEX3D_RTV {
  UINT MipSlice;
  UINT FirstWSlice;
  UINT WSize;
} D3D11_TEX3D_RTV;

typedef struct D3D11_TEX3D_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
} D3D11_TEX3D_SRV;

typedef struct D3D11_TEX3D_UAV {
  UINT MipSlice;
  UINT FirstWSlice;
  UINT WSize;
} D3D11_TEX3D_UAV;

typedef struct D3D11_TEXCUBE_ARRAY_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
  UINT First2DArrayFace;
  UINT NumCubes;
} D3D11_TEXCUBE_ARRAY_SRV;

typedef struct D3D11_TEXCUBE_SRV {
  UINT MostDetailedMip;
  UINT MipLevels;
} D3D11_TEXCUBE_SRV;

typedef struct D3D11_DEPTH_STENCIL_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D11_DSV_DIMENSION ViewDimension;
  UINT                Flags;
  union {
    D3D11_TEX1D_DSV         Texture1D;
    D3D11_TEX1D_ARRAY_DSV   Texture1DArray;
    D3D11_TEX2D_DSV         Texture2D;
    D3D11_TEX2D_ARRAY_DSV   Texture2DArray;
    D3D11_TEX2DMS_DSV       Texture2DMS;
    D3D11_TEX2DMS_ARRAY_DSV Texture2DMSArray;
  };
} D3D11_DEPTH_STENCIL_VIEW_DESC;

typedef struct D3D11_RENDER_TARGET_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D11_RTV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_RTV        Buffer;
    D3D11_TEX1D_RTV         Texture1D;
    D3D11_TEX1D_ARRAY_RTV   Texture1DArray;
    D3D11_TEX2D_RTV         Texture2D;
    D3D11_TEX2D_ARRAY_RTV   Texture2DArray;
    D3D11_TEX2DMS_RTV       Texture2DMS;
    D3D11_TEX2DMS_ARRAY_RTV Texture2DMSArray;
    D3D11_TEX3D_RTV         Texture3D;
  };
} D3D11_RENDER_TARGET_VIEW_DESC;

typedef struct D3D11_SHADER_RESOURCE_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D11_SRV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_SRV        Buffer;
    D3D11_TEX1D_SRV         Texture1D;
    D3D11_TEX1D_ARRAY_SRV   Texture1DArray;
    D3D11_TEX2D_SRV         Texture2D;
    D3D11_TEX2D_ARRAY_SRV   Texture2DArray;
    D3D11_TEX2DMS_SRV       Texture2DMS;
    D3D11_TEX2DMS_ARRAY_SRV Texture2DMSArray;
    D3D11_TEX3D_SRV         Texture3D;
    D3D11_TEXCUBE_SRV       TextureCube;
    D3D11_TEXCUBE_ARRAY_SRV TextureCubeArray;
    D3D11_BUFFEREX_SRV      BufferEx;
  };
} D3D11_SHADER_RESOURCE_VIEW_DESC;

typedef struct D3D11_TEXTURE1D_DESC {
  UINT        Width;
  UINT        MipLevels;
  UINT        ArraySize;
  DXGI_FORMAT Format;
  D3D11_USAGE Usage;
  UINT        BindFlags;
  UINT        CPUAccessFlags;
  UINT        MiscFlags;
} D3D11_TEXTURE1D_DESC;

typedef struct D3D11_TEXTURE2D_DESC {
  UINT             Width;
  UINT             Height;
  UINT             MipLevels;
  UINT             ArraySize;
  DXGI_FORMAT      Format;
  DXGI_SAMPLE_DESC SampleDesc;
  D3D11_USAGE      Usage;
  UINT             BindFlags;
  UINT             CPUAccessFlags;
  UINT             MiscFlags;
} D3D11_TEXTURE2D_DESC;

typedef struct D3D11_TEXTURE3D_DESC {
  UINT        Width;
  UINT        Height;
  UINT        Depth;
  UINT        MipLevels;
  DXGI_FORMAT Format;
  D3D11_USAGE Usage;
  UINT        BindFlags;
  UINT        CPUAccessFlags;
  UINT        MiscFlags;
} D3D11_TEXTURE3D_DESC;

typedef enum D3D11_UAV_DIMENSION {
  D3D11_UAV_DIMENSION_UNKNOWN = 0,
  D3D11_UAV_DIMENSION_BUFFER = 1,
  D3D11_UAV_DIMENSION_TEXTURE1D = 2,
  D3D11_UAV_DIMENSION_TEXTURE1DARRAY = 3,
  D3D11_UAV_DIMENSION_TEXTURE2D = 4,
  D3D11_UAV_DIMENSION_TEXTURE2DARRAY = 5,
  D3D11_UAV_DIMENSION_TEXTURE3D = 8
};

typedef struct D3D11_UNORDERED_ACCESS_VIEW_DESC {
  DXGI_FORMAT         Format;
  D3D11_UAV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_UAV      Buffer;
    D3D11_TEX1D_UAV       Texture1D;
    D3D11_TEX1D_ARRAY_UAV Texture1DArray;
    D3D11_TEX2D_UAV       Texture2D;
    D3D11_TEX2D_ARRAY_UAV Texture2DArray;
    D3D11_TEX3D_UAV       Texture3D;
  };
} D3D11_UNORDERED_ACCESS_VIEW_DESC;


typedef struct ID3D11Device ID3D11Device;


typedef struct ID3D11DeviceChild ID3D11DeviceChild;

typedef struct ID3D11DeviceChildVtbl
{
	HRESULT (*QueryInterface)(ID3D11DeviceChild *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11DeviceChild *This);
    ULONG (*Release)(ID3D11DeviceChild *This);
	void (*GetDevice)(ID3D11DeviceChild *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11DeviceChild *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11DeviceChild *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11DeviceChild *This, GUID *guid, const IUnknown *pData);
} ID3D11DeviceChildVtbl;

struct ID3D11DeviceChild
{
	ID3D11DeviceChildVtbl *lpVtbl;
};

typedef struct ID3D11ClassInstance ID3D11ClassInstance;
typedef struct ID3D11ClassLinkage ID3D11ClassLinkage;

typedef struct ID3D11ClassLinkageVtbl
{
	HRESULT (*QueryInterface)(ID3D11ClassLinkage *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11ClassLinkage *This);
    ULONG (*Release)(ID3D11ClassLinkage *This);
	void (*GetDevice)(ID3D11ClassLinkage *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11ClassLinkage *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11ClassLinkage *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11ClassLinkage *This, GUID *guid, const IUnknown *pData);
	HRESULT (*GetClassInstance)(ID3D11ClassLinkage *This, LPCSTR pClassInstanceName, UINT InstanceIndex, ID3D11ClassInstance **ppInstance);
	HRESULT (*CreateClassInstance)(ID3D11ClassLinkage *This, LPCSTR pClassTypeName, UINT ConstantBufferOffset, UINT ConstantVectorOffset, UINT TextureOffset, UINT SamplerOffset, ID3D11ClassInstance **ppInstance);
} ID3D11ClassLinkageVtbl;

struct ID3D11ClassLinkage
{
	ID3D11ClassLinkageVtbl *lpVtbl;
};


typedef struct ID3D11ClassInstanceVtbl
{
	HRESULT (*QueryInterface)(ID3D11ClassInstance *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11ClassInstance *This);
    ULONG (*Release)(ID3D11ClassInstance *This);
	void (*GetDevice)(ID3D11ClassInstance *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11ClassInstance *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11ClassInstance *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11ClassInstance *This, GUID *guid, const IUnknown *pData);
	void (*GetClassLinkage)(ID3D11ClassInstance *This, ID3D11ClassLinkage **ppLinkage);
	void (*GetDesc)(ID3D11ClassInstance *This, D3D11_CLASS_INSTANCE_DESC *pDesc);
	void (*GetInstanceName)(ID3D11ClassInstance *This, LPSTR pInstanceName, SIZE_T *pBufferLength);
	void (*GetTypeName)(ID3D11ClassInstance *This, LPSTR pTypeName, SIZE_T *pBufferLength);
} ID3D11ClassInstanceVtbl;

struct ID3D11ClassInstance
{
	ID3D11ClassInstanceVtbl *lpVtbl;
};


typedef struct ID3D11GeometryShader ID3D11GeometryShader;

typedef struct ID3D11GeometryShaderVtbl
{
	HRESULT (*QueryInterface)(ID3D11GeometryShader *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11GeometryShader *This);
    ULONG (*Release)(ID3D11GeometryShader *This);
	void (*GetDevice)(ID3D11GeometryShader *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11GeometryShader *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11GeometryShader *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11GeometryShader *This, GUID *guid, const IUnknown *pData);
} ID3D11GeometryShaderVtbl;

struct ID3D11GeometryShader
{
	ID3D11GeometryShaderVtbl *lpVtbl;
};


typedef struct ID3D11InputLayout ID3D11InputLayout;

typedef struct ID3D11InputLayoutVtbl
{
	HRESULT (*QueryInterface)(ID3D11InputLayout *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11InputLayout *This);
    ULONG (*Release)(ID3D11InputLayout *This);
	void (*GetDevice)(ID3D11InputLayout *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11InputLayout *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11InputLayout *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11InputLayout *This, GUID *guid, const IUnknown *pData);
} ID3D11InputLayoutVtbl;

struct ID3D11InputLayout
{
	ID3D11InputLayoutVtbl *lpVtbl;
};


typedef struct ID3D11Resource ID3D11Resource;

typedef struct ID3D11ResourceVtbl
{
	HRESULT (*QueryInterface)(ID3D11Resource *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Resource *This);
    ULONG (*Release)(ID3D11Resource *This);
	void (*GetDevice)(ID3D11Resource *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Resource *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Resource *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Resource *This, GUID *guid, const IUnknown *pData);
	void (*GetType)(ID3D11Resource *This, D3D11_RESOURCE_DIMENSION *pResourceDimension);
	void (*SetEvictionPriority)(ID3D11Resource *This, UINT EvictionPriority);
	UINT (*GetEvictionPriority)(ID3D11Resource *This);
} ID3D11ResourceVtbl;

struct ID3D11Resource
{
	ID3D11ResourceVtbl *lpVtbl;
};


typedef struct ID3D11Buffer ID3D11Buffer;

typedef struct ID3D11BufferVtbl
{
	HRESULT (*QueryInterface)(ID3D11Buffer *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Buffer *This);
    ULONG (*Release)(ID3D11Buffer *This);
	void (*GetDevice)(ID3D11Buffer *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Buffer *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Buffer *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Buffer *This, GUID *guid, const IUnknown *pData);
	void (*GetType)(ID3D11Buffer *This, D3D11_RESOURCE_DIMENSION *pResourceDimension);
	void (*SetEvictionPriority)(ID3D11Buffer *This, UINT EvictionPriority);
	UINT (*GetEvictionPriority)(ID3D11Buffer *This);
	void (*GetDesc)(ID3D11Buffer *This, D3D11_BUFFER_DESC *pDesc);
} ID3D11BufferVtbl;

struct ID3D11Buffer
{
	ID3D11BufferVtbl *lpVtbl;
};


typedef struct ID3D11Texture1D ID3D11Texture1D;

typedef struct ID3D11Texture1DVtbl
{
	HRESULT (*QueryInterface)(ID3D11Texture1D *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Texture1D *This);
    ULONG (*Release)(ID3D11Texture1D *This);
	void (*GetDevice)(ID3D11Texture1D *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Texture1D *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Texture1D *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Texture1D *This, GUID *guid, const IUnknown *pData);
	void (*GetType)(ID3D11Texture1D *This, D3D11_RESOURCE_DIMENSION *pResourceDimension);
	void (*SetEvictionPriority)(ID3D11Texture1D *This, UINT EvictionPriority);
	UINT (*GetEvictionPriority)(ID3D11Texture1D *This);
	void (*GetDesc)(ID3D11Texture1D *This, D3D11_TEXTURE1D_DESC *pDesc);
} ID3D11Texture1DVtbl;

struct ID3D11Texture1D
{
	ID3D11Texture1DVtbl *lpVtbl;
};


typedef struct ID3D11Texture2D ID3D11Texture2D;

typedef struct ID3D11Texture2DVtbl
{
	HRESULT (*QueryInterface)(ID3D11Texture2D *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Texture2D *This);
    ULONG (*Release)(ID3D11Texture2D *This);
	void (*GetDevice)(ID3D11Texture2D *This, ID3D12Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Texture2D *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Texture2D *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Texture2D *This, GUID *guid, const IUnknown *pData);
	void (*GetType)(ID3D11Texture2D *This, D3D11_RESOURCE_DIMENSION *pResourceDimension);
	void (*SetEvictionPriority)(ID3D11Texture2D *This, UINT EvictionPriority);
	UINT (*GetEvictionPriority)(ID3D11Texture2D *This);
	void (*GetDesc)(ID3D11Texture2D *This, D3D11_TEXTURE2D_DESC *pDesc);
} ID3D11Texture2DVtbl;

struct ID3D11Texture2D
{
	ID3D11Texture2DVtbl *lpVtbl;
};


typedef struct ID3D11Texture3D ID3D11Texture3D;

typedef struct ID3D11Texture3DVtbl
{
	HRESULT (*QueryInterface)(ID3D11Texture3D *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Texture3D *This);
    ULONG (*Release)(ID3D11Texture3D *This);
	void (*GetDevice)(ID3D11Texture3D *This, ID3D13Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Texture3D *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Texture3D *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Texture3D *This, GUID *guid, const IUnknown *pData);
	void (*GetType)(ID3D11Texture3D *This, D3D11_RESOURCE_DIMENSION *pResourceDimension);
	void (*SetEvictionPriority)(ID3D11Texture3D *This, UINT EvictionPriority);
	UINT (*GetEvictionPriority)(ID3D11Texture3D *This);
	void (*GetDesc)(ID3D11Texture3D *This, D3D11_TEXTURE3D_DESC *pDesc);
} ID3D11Texture3DVtbl;

struct ID3D11Texture3D
{
	ID3D11Texture3DVtbl *lpVtbl;
};


typedef struct ID3D11VertexShader ID3D11VertexShader;

typedef struct ID3D11VertexShaderVtbl
{
	HRESULT (*QueryInterface)(ID3D11VertexShader *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11VertexShader *This);
    ULONG (*Release)(ID3D11VertexShader *This);
	void (*GetDevice)(ID3D11VertexShader *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11VertexShader *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11VertexShader *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11VertexShader *This, GUID *guid, const IUnknown *pData);
} ID3D11VertexShaderVtbl;

struct ID3D11VertexShader
{
	ID3D11VertexShaderVtbl *lpVtbl;
};


typedef struct ID3D11View ID3D11View;

typedef struct ID3D11ViewVtbl
{
	HRESULT (*QueryInterface)(ID3D11View *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11View *This);
    ULONG (*Release)(ID3D11View *This);
	void (*GetDevice)(ID3D11View *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11View *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11View *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11View *This, GUID *guid, const IUnknown *pData);
	void (*GetResource)(ID3D11View *This, ID3D11Resource **ppResource);
} ID3D11ViewVtbl;

struct ID3D11View
{
	ID3D11ViewVtbl *lpVtbl;
};


typedef struct ID3D11DepthStencilView ID3D11DepthStencilView;

typedef struct ID3D11DepthStencilViewVtbl
{
	HRESULT (*QueryInterface)(ID3D11DepthStencilView *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11DepthStencilView *This);
    ULONG (*Release)(ID3D11DepthStencilView *This);
	void (*GetDevice)(ID3D11DepthStencilView *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11DepthStencilView *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11DepthStencilView *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11DepthStencilView *This, GUID *guid, const IUnknown *pData);
	void (*GetResource)(ID3D11DepthStencilView *This, ID3D11Resource **ppResource);
	void (*GetDesc)(ID3D11DepthStencilView *This, D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc);
} ID3D11DepthStencilViewVtbl;

struct ID3D11DepthStencilView
{
	ID3D11DepthStencilViewVtbl *lpVtbl;
};


typedef struct ID3D11RenderTargetView ID3D11RenderTargetView;

typedef struct ID3D11RenderTargetViewVtbl
{
	HRESULT (*QueryInterface)(ID3D11RenderTargetView *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11RenderTargetView *This);
    ULONG (*Release)(ID3D11RenderTargetView *This);
	void (*GetDevice)(ID3D11RenderTargetView *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11RenderTargetView *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11RenderTargetView *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11RenderTargetView *This, GUID *guid, const IUnknown *pData);
	void (*GetResource)(ID3D11RenderTargetView *This, ID3D11Resource **ppResource);
	void (*GetDesc)(ID3D11RenderTargetView *This, D3D11_RENDER_TARGET_VIEW_DESC *pDesc);
} ID3D11RenderTargetViewVtbl;

struct ID3D11RenderTargetView
{
	ID3D11RenderTargetViewVtbl *lpVtbl;
};


typedef struct ID3D11ShaderResourceView ID3D11ShaderResourceView;

typedef struct ID3D11ShaderResourceViewVtbl
{
	HRESULT (*QueryInterface)(ID3D11ShaderResourceView *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11ShaderResourceView *This);
    ULONG (*Release)(ID3D11ShaderResourceView *This);
	void (*GetDevice)(ID3D11ShaderResourceView *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11ShaderResourceView *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11ShaderResourceView *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11ShaderResourceView *This, GUID *guid, const IUnknown *pData);
	void (*GetResource)(ID3D11ShaderResourceView *This, ID3D11Resource **ppResource);
	void (*GetDesc)(ID3D11ShaderResourceView *This, D3D11_SHADER_RESOURCE_VIEW_DESC *pDesc);
} ID3D11ShaderResourceViewVtbl;

struct ID3D11ShaderResourceView
{
	ID3D11ShaderResourceViewVtbl *lpVtbl;
};


typedef struct ID3D11UnorderedAccessView ID3D11UnorderedAccessView;

typedef struct ID3D11UnorderedAccessViewVtbl
{
	HRESULT (*QueryInterface)(ID3D11UnorderedAccessView *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11UnorderedAccessView *This);
    ULONG (*Release)(ID3D11UnorderedAccessView *This);
	void (*GetDevice)(ID3D11UnorderedAccessView *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11UnorderedAccessView *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11UnorderedAccessView *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11UnorderedAccessView *This, GUID *guid, const IUnknown *pData);
	void (*GetResource)(ID3D11UnorderedAccessView *This, ID3D11Resource **ppResource);
	void (*GetDesc)(ID3D11UnorderedAccessView *This, D3D11_UNORDERED_ACCESS_VIEW_DESC *pDesc);
} ID3D11UnorderedAccessViewVtbl;

struct ID3D11UnorderedAccessView
{
	ID3D11UnorderedAccessViewVtbl *lpVtbl;
};


typedef struct ID3D11DeviceVtbl
{
	HRESULT (*QueryInterface)(ID3D11Device *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Device *This);
    ULONG (*Release)(ID3D11Device *This);
	HRESULT (*CreateBuffer)(ID3D11Device *This, const D3D11_BUFFER_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Buffer **ppBuffer);
	HRESULT (*CreateTexture1D)(ID3D11Device *This, const D3D11_TEXTURE1D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture1D **ppTexture1D);
	HRESULT (*CreateTexture2D)(ID3D11Device *This, const D3D11_TEXTURE2D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture2D **ppTexture2D);
	HRESULT (*CreateTexture3D)(ID3D11Device *This, const D3D11_TEXTURE3D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture3D **ppTexture3D);
	HRESULT (*CreateShaderResourceView)(ID3D11Device *This, ID3D11Resource *pResource, const D3D11_SHADER_RESOURCE_VIEW_DESC *pDesc, ID3D11ShaderResourceView **ppSRView);
	HRESULT (*CreateUnorderedAccessView)(ID3D11Device *This, ID3D11Resource *pResource, const D3D11_UNORDERED_ACCESS_VIEW_DESC *pDesc, ID3D11UnorderedAccessView **ppUAView);
	HRESULT (*CreateRenderTargetView)(ID3D11Device *This, ID3D11Resource *pResource, const D3D11_RENDER_TARGET_VIEW_DESC *pDesc, ID3D11RenderTargetView **ppRTView);
	HRESULT (*CreateDepthStencilView)(ID3D11Device *This, ID3D11Resource *pResource, const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc, ID3D11DepthStencilView **ppDepthStencilView);
	HRESULT (*CreateInputLayout)(ID3D11Device *This, const D3D11_INPUT_ELEMENT_DESC *pInputElementDescs, UINT NumElements, const void *pShaderBytecodeWithInputSignature, SIZE_T BytecodeLength, ID3D11InputLayout **ppInputLayout);
	HRESULT (*CreateVertexShader)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11VertexShader **ppVertexShader);
	HRESULT (*CreateGeometryShader)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11GeometryShader **ppGeometryShader);
	HRESULT (*CreateGeometryShaderWithStreamOutput)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, const D3D11_SO_DECLARATION_ENTRY *pSODeclaration, UINT NumEntries, const UINT *pBufferStrides, UINT NumStrides, UINT RasterizedStream, ID3D11ClassLinkage *pClassLinkage, ID3D11GeometryShader **ppGeometryShader);
} ID3D11DeviceVtbl;

struct ID3D11Device
{
	ID3D11DeviceVtbl *lpVtbl;
};