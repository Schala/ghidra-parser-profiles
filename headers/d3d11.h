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

typedef enum D3D11_RESOURCE_DIMENSION {
  D3D11_RESOURCE_DIMENSION_UNKNOWN = 0,
  D3D11_RESOURCE_DIMENSION_BUFFER = 1,
  D3D11_RESOURCE_DIMENSION_TEXTURE1D = 2,
  D3D11_RESOURCE_DIMENSION_TEXTURE2D = 3,
  D3D11_RESOURCE_DIMENSION_TEXTURE3D = 4
};

typedef struct D3D11_SUBRESOURCE_DATA {
  const void *pSysMem;
  UINT       SysMemPitch;
  UINT       SysMemSlicePitch;
} D3D11_SUBRESOURCE_DATA;

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


typedef struct ID3D11DeviceVtbl
{
	HRESULT (*QueryInterface)(ID3D11Device *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Device *This);
    ULONG (*Release)(ID3D11Device *This);
	HRESULT (*CreateBuffer)(ID3D11Device *This, const D3D11_BUFFER_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Buffer **ppBuffer);
	HRESULT (*CreateTexture1D)(ID3D11Device *This, const D3D11_TEXTURE1D_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, ID3D11Texture1D **ppTexture1D);
} ID3D11DeviceVtbl;

struct ID3D11Device
{
	ID3D11DeviceVtbl *lpVtbl;
};