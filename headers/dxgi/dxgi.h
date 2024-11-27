#pragma once

#include "dxgicommon.h"
#include "dxgiformat.h"

typedef enum DXGI_MODE_ROTATION { 
  DXGI_MODE_ROTATION_UNSPECIFIED  = 0,
  DXGI_MODE_ROTATION_IDENTITY     = 1,
  DXGI_MODE_ROTATION_ROTATE90     = 2,
  DXGI_MODE_ROTATION_ROTATE180    = 3,
  DXGI_MODE_ROTATION_ROTATE270    = 4
} DXGI_MODE_ROTATION;

typedef enum DXGI_MODE_SCALING { 
  DXGI_MODE_SCALING_UNSPECIFIED  = 0,
  DXGI_MODE_SCALING_CENTERED     = 1,
  DXGI_MODE_SCALING_STRETCHED    = 2
} DXGI_MODE_SCALING;

typedef enum DXGI_MODE_SCANLINE_ORDER { 
  DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED        = 0,
  DXGI_MODE_SCANLINE_ORDER_PROGRESSIVE        = 1,
  DXGI_MODE_SCANLINE_ORDER_UPPER_FIELD_FIRST  = 2,
  DXGI_MODE_SCANLINE_ORDER_LOWER_FIELD_FIRST  = 3
} DXGI_MODE_SCANLINE_ORDER;

typedef struct DXGI_ADAPTER_DESC {
  WCHAR  Description[128];
  UINT   VendorId;
  UINT   DeviceId;
  UINT   SubSysId;
  UINT   Revision;
  SIZE_T DedicatedVideoMemory;
  SIZE_T DedicatedSystemMemory;
  SIZE_T SharedSystemMemory;
  LUID   AdapterLuid;
} DXGI_ADAPTER_DESC;

typedef struct DXGI_FRAME_STATISTICS {
  UINT          PresentCount;
  UINT          PresentRefreshCount;
  UINT          SyncRefreshCount;
  LARGE_INTEGER SyncQPCTime;
  LARGE_INTEGER SyncGPUTime;
} DXGI_FRAME_STATISTICS;

typedef struct DXGI_GAMMA_CONTROL_CAPABILITIES {
  BOOL  ScaleAndOffsetSupported;
  float MaxConvertedValue;
  float MinConvertedValue;
  UINT  NumGammaControlPoints;
  float ControlPointPositions[1025];
} DXGI_GAMMA_CONTROL_CAPABILITIES;

typedef struct DXGI_MAPPED_RECT {
  INT  Pitch;
  BYTE *pBits;
} DXGI_MAPPED_RECT;

typedef struct DXGI_MODE_DESC {
  UINT                     Width;
  UINT                     Height;
  DXGI_RATIONAL            RefreshRate;
  DXGI_FORMAT              Format;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
} DXGI_MODE_DESC;

typedef struct DXGI_OUTPUT_DESC {
  WCHAR              DeviceName[32];
  RECT               DesktopCoordinates;
  BOOL               AttachedToDesktop;
  DXGI_MODE_ROTATION Rotation;
  HMONITOR           Monitor;
} DXGI_OUTPUT_DESC;

typedef struct DXGI_RGB {
  float Red;
  float Green;
  float Blue;
} DXGI_RGB;

typedef struct DXGI_GAMMA_CONTROL {
  DXGI_RGB Scale;
  DXGI_RGB Offset;
  DXGI_RGB GammaCurve[1025];
} DXGI_GAMMA_CONTROL;

typedef struct DXGI_SURFACE_DESC {
  UINT             Width;
  UINT             Height;
  DXGI_FORMAT      Format;
  DXGI_SAMPLE_DESC SampleDesc;
} DXGI_SURFACE_DESC;


typedef struct IDXGIObject IDXGIObject;

typedef struct IDXGIObjectVtbl
{
	HRESULT (*QueryInterface)(IDXGIObject *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(IDXGIObject *This);
    ULONG (*Release)(IDXGIObject *This);
	HRESULT (*SetPrivateData)(IDXGIObject *This, GUID *Name, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(IDXGIObject *This, GUID *Name, IUnknown *pUnknown);
	HRESULT (*GetPrivateData)(IDXGIObject *This, GUID *Name, UINT *pDataSize, void *pData);
	HRESULT (*GetParent)(IDXGIObject *This, IID *riid, void **ppParent);
} IDXGIObjectVtbl;

struct IDXGIObject
{
	IDXGIObjectVtbl *lpVtbl;
};


typedef struct IDXGIDeviceSubObject IDXGIDeviceSubObject;

typedef struct IDXGIDeviceSubObjectVtbl
{
	HRESULT (*QueryInterface)(IDXGIDeviceSubObject *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(IDXGIDeviceSubObject *This);
    ULONG (*Release)(IDXGIDeviceSubObject *This);
	HRESULT (*SetPrivateData)(IDXGIDeviceSubObject *This, GUID *Name, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(IDXGIDeviceSubObject *This, GUID *Name, IUnknown *pUnknown);
	HRESULT (*GetPrivateData)(IDXGIDeviceSubObject *This, GUID *Name, UINT *pDataSize, void *pData);
	HRESULT (*GetParent)(IDXGIDeviceSubObject *This, IID *riid, void **ppParent);
	HRESULT (*GetDevice)(IDXGIDeviceSubObject *This, IID *riid, void **ppDevice);
} IDXGIDeviceSubObject;

struct IDXGIDeviceSubObject
{
	IDXGIDeviceSubObjectVtbl *lpVtbl;
};


typedef struct IDXGISurface IDXGISurface;

typedef struct IDXGISurfaceVtbl
{
	HRESULT (*QueryInterface)(IDXGISurface *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(IDXGISurface *This);
    ULONG (*Release)(IDXGISurface *This);
	HRESULT (*SetPrivateData)(IDXGISurface *This, GUID *Name, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(IDXGISurface *This, GUID *Name, IUnknown *pUnknown);
	HRESULT (*GetPrivateData)(IDXGISurface *This, GUID *Name, UINT *pDataSize, void *pData);
	HRESULT (*GetParent)(IDXGISurface *This, IID *riid, void **ppParent);
	HRESULT (*GetDevice)(IDXGISurface *This, IID *riid, void **ppDevice);
	HRESULT (*GetDesc)(IDXGISurface *This, DXGI_SURFACE_DESC *pDesc);
	HRESULT (*Map)(IDXGISurface *This, DXGI_MAPPED_RECT *pLockedRect, UINT MapFlags);
	HRESULT (*Unmap)(IDXGISurface *This);
} IDXGISurfaceVtbl;

struct IDXGISurface
{
	IDXGISurfaceVtbl *lpVtbl;
};


typedef struct IDXGIOutput IDXGIOutput;

typedef struct IDXGIOutputVtbl
{
	HRESULT (*QueryInterface)(IDXGIOutput *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(IDXGIOutput *This);
    ULONG (*Release)(IDXGIOutput *This);
	HRESULT (*SetPrivateData)(IDXGIOutput *This, GUID *Name, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(IDXGIOutput *This, GUID *Name, IUnknown *pUnknown);
	HRESULT (*GetPrivateData)(IDXGIOutput *This, GUID *Name, UINT *pDataSize, void *pData);
	HRESULT (*GetParent)(IDXGIOutput *This, IID *riid, void **ppParent);
	HRESULT (*GetDesc)(IDXGIOutput *This, DXGI_OUTPUT_DESC *pDesc);
	HRESULT (*GetDisplayModeList)(IDXGIOutput *This, DXGI_FORMAT EnumFormat, UINT Flags, UINT *pNumModes, DXGI_MODE_DESC *pDesc);
	HRESULT (*FindClosestMatchingMode)(IDXGIOutput *This, const DXGI_MODE_DESC *pModeToMatch, DXGI_MODE_DESC *pClosestMatch, IUnknown *pConcernedDevice);
	HRESULT (*WaitForVBlank)(IDXGIOutput *This);
	HRESULT (*TakeOwnership)(IDXGIOutput *This, IUnknown *pDevice, BOOL Exclusive);
	HRESULT (*ReleaseOwnership)(IDXGIOutput *This);
	HRESULT (*GetGammaControlCapabilities)(IDXGIOutput *This, DXGI_GAMMA_CONTROL_CAPABILITIES *pGammaCaps);
	HRESULT (*SetGammaControl)(IDXGIOutput *This, const DXGI_GAMMA_CONTROL *pArray);
	HRESULT (*GetGammaControl)(IDXGIOutput *This, DXGI_GAMMA_CONTROL *pArray);
	HRESULT (*SetDisplaySurface)(IDXGIOutput *This, IDXGISurface *pScanoutSurface);
	HRESULT (*GetDisplaySurfaceData)(IDXGIOutput *This, IDXGISurface *pDestination);
	HRESULT (*GetFrameStatistics)(IDXGIOutput *This, DXGI_FRAME_STATISTICS *pStats);
} IDXGIOutputVtbl;

struct IDXGIOutput
{
	IDXGIOutputVtbl *lpVtbl;
};


typedef struct IDXGIAdapter IDXGIAdapter;

typedef struct IDXGIAdapterVtbl
{
	HRESULT (*QueryInterface)(IDXGIAdapter *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(IDXGIAdapter *This);
    ULONG (*Release)(IDXGIAdapter *This);
	HRESULT (*SetPrivateData)(IDXGIAdapter *This, GUID *Name, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(IDXGIAdapter *This, GUID *Name, IUnknown *pUnknown);
	HRESULT (*GetPrivateData)(IDXGIAdapter *This, GUID *Name, UINT *pDataSize, void *pData);
	HRESULT (*GetParent)(IDXGIAdapter *This, IID *riid, void **ppParent);
	HRESULT (*EnumOutputs)(IDXGIAdapter *This, UINT Output, IDXGIOutput **ppOutput);
	HRESULT (*GetDesc)(IDXGIAdapter *This, DXGI_ADAPTER_DESC *pDesc);
	HRESULT (*CheckInterfaceSupport)(IDXGIAdapter *This, GUID *InterfaceName, LARGE_INTEGER *pUMDVersion);
} IDXGIAdapterVtbl;

struct IDXGIAdapter
{
	IDXGIAdapterVtbl *lpVtbl;
};
