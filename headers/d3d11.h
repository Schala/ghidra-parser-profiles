#pragma once

typedef enum D3D11_BLEND {
  D3D11_BLEND_ZERO = 1,
  D3D11_BLEND_ONE = 2,
  D3D11_BLEND_SRC_COLOR = 3,
  D3D11_BLEND_INV_SRC_COLOR = 4,
  D3D11_BLEND_SRC_ALPHA = 5,
  D3D11_BLEND_INV_SRC_ALPHA = 6,
  D3D11_BLEND_DEST_ALPHA = 7,
  D3D11_BLEND_INV_DEST_ALPHA = 8,
  D3D11_BLEND_DEST_COLOR = 9,
  D3D11_BLEND_INV_DEST_COLOR = 10,
  D3D11_BLEND_SRC_ALPHA_SAT = 11,
  D3D11_BLEND_BLEND_FACTOR = 14,
  D3D11_BLEND_INV_BLEND_FACTOR = 15,
  D3D11_BLEND_SRC1_COLOR = 16,
  D3D11_BLEND_INV_SRC1_COLOR = 17,
  D3D11_BLEND_SRC1_ALPHA = 18,
  D3D11_BLEND_INV_SRC1_ALPHA = 19
};

typedef enum D3D11_BLEND_OP {
  D3D11_BLEND_OP_ADD = 1,
  D3D11_BLEND_OP_SUBTRACT = 2,
  D3D11_BLEND_OP_REV_SUBTRACT = 3,
  D3D11_BLEND_OP_MIN = 4,
  D3D11_BLEND_OP_MAX = 5
};

typedef enum D3D11_COMPARISON_FUNC {
  D3D11_COMPARISON_NEVER = 1,
  D3D11_COMPARISON_LESS = 2,
  D3D11_COMPARISON_EQUAL = 3,
  D3D11_COMPARISON_LESS_EQUAL = 4,
  D3D11_COMPARISON_GREATER = 5,
  D3D11_COMPARISON_NOT_EQUAL = 6,
  D3D11_COMPARISON_GREATER_EQUAL = 7,
  D3D11_COMPARISON_ALWAYS = 8
};

typedef enum D3D11_COUNTER {
  D3D11_COUNTER_DEVICE_DEPENDENT_0 = 0x40000000
};

typedef enum D3D11_CULL_MODE {
  D3D11_CULL_NONE = 1,
  D3D11_CULL_FRONT = 2,
  D3D11_CULL_BACK = 3
};

typedef enum D3D11_DEPTH_WRITE_MASK {
  D3D11_DEPTH_WRITE_MASK_ZERO = 0,
  D3D11_DEPTH_WRITE_MASK_ALL = 1
};

typedef enum D3D11_DSV_DIMENSION {
  D3D11_DSV_DIMENSION_UNKNOWN = 0,
  D3D11_DSV_DIMENSION_TEXTURE1D = 1,
  D3D11_DSV_DIMENSION_TEXTURE1DARRAY = 2,
  D3D11_DSV_DIMENSION_TEXTURE2D = 3,
  D3D11_DSV_DIMENSION_TEXTURE2DARRAY = 4,
  D3D11_DSV_DIMENSION_TEXTURE2DMS = 5,
  D3D11_DSV_DIMENSION_TEXTURE2DMSARRAY = 6
};

typedef enum D3D11_FILL_MODE {
  D3D11_FILL_WIREFRAME = 2,
  D3D11_FILL_SOLID = 3
};

typedef enum D3D11_FILTER {
  D3D11_FILTER_MIN_MAG_MIP_POINT = 0,
  D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR = 0x1,
  D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x4,
  D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR = 0x5,
  D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT = 0x10,
  D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x11,
  D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT = 0x14,
  D3D11_FILTER_MIN_MAG_MIP_LINEAR = 0x15,
  D3D11_FILTER_ANISOTROPIC = 0x55,
  D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT = 0x80,
  D3D11_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = 0x81,
  D3D11_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x84,
  D3D11_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = 0x85,
  D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = 0x90,
  D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x91,
  D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = 0x94,
  D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = 0x95,
  D3D11_FILTER_COMPARISON_ANISOTROPIC = 0xd5,
  D3D11_FILTER_MINIMUM_MIN_MAG_MIP_POINT = 0x100,
  D3D11_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x101,
  D3D11_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x104,
  D3D11_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x105,
  D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x110,
  D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x111,
  D3D11_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x114,
  D3D11_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR = 0x115,
  D3D11_FILTER_MINIMUM_ANISOTROPIC = 0x155,
  D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_POINT = 0x180,
  D3D11_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR = 0x181,
  D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = 0x184,
  D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR = 0x185,
  D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT = 0x190,
  D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = 0x191,
  D3D11_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT = 0x194,
  D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR = 0x195,
  D3D11_FILTER_MAXIMUM_ANISOTROPIC = 0x1d5
};

typedef enum D3D11_INPUT_CLASSIFICATION {
  D3D11_INPUT_PER_VERTEX_DATA = 0,
  D3D11_INPUT_PER_INSTANCE_DATA = 1
};

typedef enum D3D11_MAP {
  D3D11_MAP_READ = 1,
  D3D11_MAP_WRITE = 2,
  D3D11_MAP_READ_WRITE = 3,
  D3D11_MAP_WRITE_DISCARD = 4,
  D3D11_MAP_WRITE_NO_OVERWRITE = 5
};

typedef enum D3D11_QUERY {
  D3D11_QUERY_EVENT = 0,
  D3D11_QUERY_OCCLUSION,
  D3D11_QUERY_TIMESTAMP,
  D3D11_QUERY_TIMESTAMP_DISJOINT,
  D3D11_QUERY_PIPELINE_STATISTICS,
  D3D11_QUERY_OCCLUSION_PREDICATE,
  D3D11_QUERY_SO_STATISTICS,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE,
  D3D11_QUERY_SO_STATISTICS_STREAM0,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM0,
  D3D11_QUERY_SO_STATISTICS_STREAM1,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM1,
  D3D11_QUERY_SO_STATISTICS_STREAM2,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM2,
  D3D11_QUERY_SO_STATISTICS_STREAM3,
  D3D11_QUERY_SO_OVERFLOW_PREDICATE_STREAM3
};

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

typedef enum D3D11_STENCIL_OP {
  D3D11_STENCIL_OP_KEEP = 1,
  D3D11_STENCIL_OP_ZERO = 2,
  D3D11_STENCIL_OP_REPLACE = 3,
  D3D11_STENCIL_OP_INCR_SAT = 4,
  D3D11_STENCIL_OP_DECR_SAT = 5,
  D3D11_STENCIL_OP_INVERT = 6,
  D3D11_STENCIL_OP_INCR = 7,
  D3D11_STENCIL_OP_DECR = 8
};

typedef enum D3D11_TEXTURE_ADDRESS_MODE {
  D3D11_TEXTURE_ADDRESS_WRAP = 1,
  D3D11_TEXTURE_ADDRESS_MIRROR = 2,
  D3D11_TEXTURE_ADDRESS_CLAMP = 3,
  D3D11_TEXTURE_ADDRESS_BORDER = 4,
  D3D11_TEXTURE_ADDRESS_MIRROR_ONCE = 5
};

typedef enum D3D11_UAV_DIMENSION {
  D3D11_UAV_DIMENSION_UNKNOWN = 0,
  D3D11_UAV_DIMENSION_BUFFER = 1,
  D3D11_UAV_DIMENSION_TEXTURE1D = 2,
  D3D11_UAV_DIMENSION_TEXTURE1DARRAY = 3,
  D3D11_UAV_DIMENSION_TEXTURE2D = 4,
  D3D11_UAV_DIMENSION_TEXTURE2DARRAY = 5,
  D3D11_UAV_DIMENSION_TEXTURE3D = 8
};

typedef enum D3D11_USAGE {
  D3D11_USAGE_DEFAULT = 0,
  D3D11_USAGE_IMMUTABLE = 1,
  D3D11_USAGE_DYNAMIC = 2,
  D3D11_USAGE_STAGING = 3
};

typedef struct D3D11_RENDER_TARGET_BLEND_DESC {
  BOOL           BlendEnable;
  D3D11_BLEND    SrcBlend;
  D3D11_BLEND    DestBlend;
  D3D11_BLEND_OP BlendOp;
  D3D11_BLEND    SrcBlendAlpha;
  D3D11_BLEND    DestBlendAlpha;
  D3D11_BLEND_OP BlendOpAlpha;
  UINT8          RenderTargetWriteMask;
} D3D11_RENDER_TARGET_BLEND_DESC;

typedef struct D3D11_BLEND_DESC {
  BOOL                           AlphaToCoverageEnable;
  BOOL                           IndependentBlendEnable;
  D3D11_RENDER_TARGET_BLEND_DESC RenderTarget[8];
} D3D11_BLEND_DESC;

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

typedef struct D3D11_COUNTER_DESC {
  D3D11_COUNTER Counter;
  UINT          MiscFlags;
} D3D11_COUNTER_DESC;

typedef struct D3D11_DEPTH_STENCILOP_DESC {
  D3D11_STENCIL_OP      StencilFailOp;
  D3D11_STENCIL_OP      StencilDepthFailOp;
  D3D11_STENCIL_OP      StencilPassOp;
  D3D11_COMPARISON_FUNC StencilFunc;
} D3D11_DEPTH_STENCILOP_DESC;

typedef struct D3D11_DEPTH_STENCIL_DESC {
  BOOL                       DepthEnable;
  D3D11_DEPTH_WRITE_MASK     DepthWriteMask;
  D3D11_COMPARISON_FUNC      DepthFunc;
  BOOL                       StencilEnable;
  UINT8                      StencilReadMask;
  UINT8                      StencilWriteMask;
  D3D11_DEPTH_STENCILOP_DESC FrontFace;
  D3D11_DEPTH_STENCILOP_DESC BackFace;
} D3D11_DEPTH_STENCIL_DESC;

typedef struct D3D11_INPUT_ELEMENT_DESC {
  LPCSTR                     SemanticName;
  UINT                       SemanticIndex;
  DXGI_FORMAT                Format;
  UINT                       InputSlot;
  UINT                       AlignedByteOffset;
  D3D11_INPUT_CLASSIFICATION InputSlotClass;
  UINT                       InstanceDataStepRate;
} D3D11_INPUT_ELEMENT_DESC;

typedef struct D3D11_MAPPED_SUBRESOURCE {
  void *pData;
  UINT RowPitch;
  UINT DepthPitch;
} D3D11_MAPPED_SUBRESOURCE;

typedef struct D3D11_QUERY_DESC {
  D3D11_QUERY Query;
  UINT        MiscFlags;
} D3D11_QUERY_DESC;

typedef struct D3D11_RASTERIZER_DESC {
  D3D11_FILL_MODE FillMode;
  D3D11_CULL_MODE CullMode;
  BOOL            FrontCounterClockwise;
  INT             DepthBias;
  FLOAT           DepthBiasClamp;
  FLOAT           SlopeScaledDepthBias;
  BOOL            DepthClipEnable;
  BOOL            ScissorEnable;
  BOOL            MultisampleEnable;
  BOOL            AntialiasedLineEnable;
} D3D11_RASTERIZER_DESC;

typedef struct D3D11_SAMPLER_DESC {
  D3D11_FILTER               Filter;
  D3D11_TEXTURE_ADDRESS_MODE AddressU;
  D3D11_TEXTURE_ADDRESS_MODE AddressV;
  D3D11_TEXTURE_ADDRESS_MODE AddressW;
  FLOAT                      MipLODBias;
  UINT                       MaxAnisotropy;
  D3D11_COMPARISON_FUNC      ComparisonFunc;
  FLOAT                      BorderColor[4];
  FLOAT                      MinLOD;
  FLOAT                      MaxLOD;
} D3D11_SAMPLER_DESC;

typedef struct D3D11_SO_DECLARATION_ENTRY {
  UINT   Stream;
  LPCSTR SemanticName;
  UINT   SemanticIndex;
  BYTE   StartComponent;
  BYTE   ComponentCount;
  BYTE   OutputSlot;
} D3D11_SO_DECLARATION_ENTRY;

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


typedef struct ID3D11Asynchronous ID3D11Asynchronous;

typedef struct ID3D11AsynchronousVtbl
{
	HRESULT (*QueryInterface)(ID3D11Asynchronous *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Asynchronous *This);
    ULONG (*Release)(ID3D11Asynchronous *This);
	void (*GetDevice)(ID3D11Asynchronous *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Asynchronous *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Asynchronous *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Asynchronous *This, GUID *guid, const IUnknown *pData);
	UINT (*GetDataSize)(ID3D11Asynchronous *This);
} ID3D11AsynchronousVtbl;

struct ID3D11Asynchronous
{
	ID3D11AsynchronousVtbl *lpVtbl;
};


typedef struct ID3D11BlendState ID3D11BlendState;

typedef struct ID3D11BlendStateVtbl
{
	HRESULT (*QueryInterface)(ID3D11BlendState *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11BlendState *This);
    ULONG (*Release)(ID3D11BlendState *This);
	void (*GetDevice)(ID3D11BlendState *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11BlendState *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11BlendState *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11BlendState *This, GUID *guid, const IUnknown *pData);
	void (*GetDesc)(ID3D11BlendState *This, D3D11_BLEND_DESC *pDesc);
} ID3D11BlendStateVtbl;

struct ID3D11BlendState
{
	ID3D11BlendStateVtbl *lpVtbl;
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


typedef struct ID3D11ComputeShader ID3D11ComputeShader;

typedef struct ID3D11ComputeShaderVtbl
{
	HRESULT (*QueryInterface)(ID3D11ComputeShader *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11ComputeShader *This);
    ULONG (*Release)(ID3D11ComputeShader *This);
	void (*GetDevice)(ID3D11ComputeShader *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11ComputeShader *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11ComputeShader *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11ComputeShader *This, GUID *guid, const IUnknown *pData);
} ID3D11ComputeShaderVtbl;

struct ID3D11ComputeShader
{
	ID3D11ComputeShaderVtbl *lpVtbl;
};


typedef struct ID3D11Counter ID3D11Counter;

typedef struct ID3D11CounterVtbl
{
	HRESULT (*CounterInterface)(ID3D11Counter *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Counter *This);
    ULONG (*Release)(ID3D11Counter *This);
	void (*GetDevice)(ID3D11Counter *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Counter *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Counter *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Counter *This, GUID *guid, const IUnknown *pData);
	UINT (*GetDataSize)(ID3D11Counter *This);
	void (*GetDesc)(ID3D11Counter *This, D3D11_COUNTER_DESC *pDesc);
} ID3D11CounterVtbl;

struct ID3D11Counter
{
	ID3D11CounterVtbl *lpVtbl;
};


typedef struct ID3D11DepthStencilState ID3D11DepthStencilState;

typedef struct ID3D11DepthStencilStateVtbl
{
	HRESULT (*QueryInterface)(ID3D11DepthStencilState *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11DepthStencilState *This);
    ULONG (*Release)(ID3D11DepthStencilState *This);
	void (*GetDevice)(ID3D11DepthStencilState *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11DepthStencilState *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11DepthStencilState *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11DepthStencilState *This, GUID *guid, const IUnknown *pData);
	void (*GetDesc)(ID3D11DepthStencilState *This, D3D11_DEPTH_STENCIL_DESC *pDesc);
} ID3D11DepthStencilStateVtbl;

struct ID3D11DepthStencilState
{
	ID3D11DepthStencilStateVtbl *lpVtbl;
};


typedef struct ID3D11DomainShader ID3D11DomainShader;

typedef struct ID3D11DomainShaderVtbl
{
	HRESULT (*QueryInterface)(ID3D11DomainShader *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11DomainShader *This);
    ULONG (*Release)(ID3D11DomainShader *This);
	void (*GetDevice)(ID3D11DomainShader *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11DomainShader *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11DomainShader *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11DomainShader *This, GUID *guid, const IUnknown *pData);
} ID3D11DomainShaderVtbl;

struct ID3D11DomainShader
{
	ID3D11DomainShaderVtbl *lpVtbl;
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


typedef struct ID3D11HullShader ID3D11HullShader;

typedef struct ID3D11HullShaderVtbl
{
	HRESULT (*QueryInterface)(ID3D11HullShader *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11HullShader *This);
    ULONG (*Release)(ID3D11HullShader *This);
	void (*GetDevice)(ID3D11HullShader *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11HullShader *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11HullShader *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11HullShader *This, GUID *guid, const IUnknown *pData);
} ID3D11HullShaderVtbl;

struct ID3D11HullShader
{
	ID3D11HullShaderVtbl *lpVtbl;
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


typedef struct ID3D11PixelShader ID3D11PixelShader;

typedef struct ID3D11PixelShaderVtbl
{
	HRESULT (*QueryInterface)(ID3D11PixelShader *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11PixelShader *This);
    ULONG (*Release)(ID3D11PixelShader *This);
	void (*GetDevice)(ID3D11PixelShader *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11PixelShader *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11PixelShader *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11PixelShader *This, GUID *guid, const IUnknown *pData);
} ID3D11PixelShaderVtbl;

struct ID3D11PixelShader
{
	ID3D11PixelShaderVtbl *lpVtbl;
};

typedef struct ID3D11Predicate ID3D11Predicate;

typedef struct ID3D11PredicateVtbl
{
	HRESULT (*PredicateInterface)(ID3D11Predicate *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Predicate *This);
    ULONG (*Release)(ID3D11Predicate *This);
	void (*GetDevice)(ID3D11Predicate *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Predicate *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Predicate *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Predicate *This, GUID *guid, const IUnknown *pData);
	UINT (*GetDataSize)(ID3D11Predicate *This);
	void (*GetDesc)(ID3D11Predicate *This, D3D11_Predicate_DESC *pDesc);
} ID3D11PredicateVtbl;

struct ID3D11Predicate
{
	ID3D11PredicateVtbl *lpVtbl;
};


typedef struct ID3D11Query ID3D11Query;

typedef struct ID3D11QueryVtbl
{
	HRESULT (*QueryInterface)(ID3D11Query *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11Query *This);
    ULONG (*Release)(ID3D11Query *This);
	void (*GetDevice)(ID3D11Query *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11Query *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11Query *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11Query *This, GUID *guid, const IUnknown *pData);
	UINT (*GetDataSize)(ID3D11Query *This);
	void (*GetDesc)(ID3D11Query *This, D3D11_QUERY_DESC *pDesc);
} ID3D11QueryVtbl;

struct ID3D11Query
{
	ID3D11QueryVtbl *lpVtbl;
};


typedef struct ID3D11RasterizerState ID3D11RasterizerState;

typedef struct ID3D11RasterizerStateVtbl
{
	HRESULT (*QueryInterface)(ID3D11RasterizerState *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11RasterizerState *This);
    ULONG (*Release)(ID3D11RasterizerState *This);
	void (*GetDevice)(ID3D11RasterizerState *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11RasterizerState *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11RasterizerState *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11RasterizerState *This, GUID *guid, const IUnknown *pData);
	void (*GetDesc)(ID3D11RasterizerState *This, D3D11_DEPTH_STENCIL_DESC *pDesc);
} ID3D11RasterizerStateVtbl;

struct ID3D11RasterizerState
{
	ID3D11RasterizerStateVtbl *lpVtbl;
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


typedef struct ID3D11SamplerState ID3D11SamplerState;

typedef struct ID3D11SamplerStateVtbl
{
	HRESULT (*QueryInterface)(ID3D11SamplerState *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11SamplerState *This);
    ULONG (*Release)(ID3D11SamplerState *This);
	void (*GetDevice)(ID3D11SamplerState *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11SamplerState *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11SamplerState *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11SamplerState *This, GUID *guid, const IUnknown *pData);
	void (*GetDesc)(ID3D11SamplerState *This, D3D11_SAMPLER_DESC *pDesc);
} ID3D11SamplerStateVtbl;

struct ID3D11SamplerState
{
	ID3D11SamplerStateVtbl *lpVtbl;
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


typedef struct ID3D11DeviceContext ID3D11DeviceContext;

typedef struct ID3D11DeviceContextVtbl
{
	HRESULT (*QueryInterface)(ID3D11DeviceContext *This, IID *riid, void **ppvObject);
    ULONG (*AddRef)(ID3D11DeviceContext *This);
    ULONG (*Release)(ID3D11DeviceContext *This);
	void (*GetDevice)(ID3D11DeviceContext *This, ID3D11Device **ppDevice);
	HRESULT (*GetPrivateData)(ID3D11DeviceContext *This, GUID *guid, UINT *pDataSize, void *pData);
	HRESULT (*SetPrivateData)(ID3D11DeviceContext *This, GUID *guid, UINT DataSize, const void *pData);
	HRESULT (*SetPrivateDataInterface)(ID3D11DeviceContext *This, GUID *guid, const IUnknown *pData);
	void (*VSSetConstantBuffers)(ID3D11DeviceContext *This, UINT StartSlot, UINT NumBuffers, ID3D11Buffer * const *ppConstantBuffers);
	void (*PSSetShaderResources)(ID3D11DeviceContext *This, UINT StartSlot, UINT NumViews, ID3D11ShaderResourceView * const *ppShaderResourceViews);
	void (*PSSetShader)(ID3D11DeviceContext *This, ID3D11PixelShader *pPixelShader, ID3D11ClassInstance * const *ppClassInstances, UINT NumClassInstances);
	void (*PSSetSamplers)(ID3D11DeviceContext *This, UINT StartSlot, UINT NumSamplers, ID3D11SamplerState * const *ppSamplers);
	void (*VSSetShader)(ID3D11DeviceContext *This, ID3D11VertexShader *pVertexShader, ID3D11ClassInstance * const *ppClassInstances, UINT NumClassInstances);
	void (*DrawIndexed)(ID3D11DeviceContext *This, UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
	void (*Draw)(ID3D11DeviceContext *This, UINT VertexCount, UINT StartVertexLocation);
	HRESULT (*Map)(ID3D11DeviceContext *This, ID3D11Resource *pResource, UINT Subresource, D3D11_MAP MapType, UINT MapFlags, D3D11_MAPPED_SUBRESOURCE *pMappedResource);
	void (*Unmap)(ID3D11DeviceContext *This, ID3D11Resource *pResource, UINT Subresource);
	void (*PSSetConstantBuffers)(ID3D11DeviceContext *This, UINT StartSlot, UINT NumBuffers, ID3D11Buffer * const *ppConstantBuffers);
	void (*IASetInputLayout)(ID3D11DeviceContext *This, ID3D11InputLayout *pInputLayout);
	void (*IASetVertexBuffers)(ID3D11DeviceContext *This, UINT StartSlot, UINT NumBuffers, ID3D11Buffer * const *ppVertexBuffers, const UINT *pStrides, const UINT *pOffsets);
	void (*IASetIndexBuffer)(ID3D11DeviceContext *This, ID3D11Buffer *pIndexBuffer, DXGI_FORMAT Format, UINT Offset); 
} ID3D11DeviceContextVtbl;

struct ID3D11DeviceContext
{
	ID3D11DeviceContextVtbl *lpVtbl;
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
	HRESULT (*CreatePixelShader)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11PixelShader **ppPixelShader);
	HRESULT (*CreateHullShader)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11HullShader **ppHullShader);
	HRESULT (*CreateDomainShader)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11DomainShader **ppDomainShader);
	HRESULT (*CreateComputeShader)(ID3D11Device *This, const void *pShaderBytecode, SIZE_T BytecodeLength, ID3D11ClassLinkage *pClassLinkage, ID3D11ComputeShader **ppComputeShader);
	HRESULT (*CreateClassLinkage)(ID3D11Device *This, ID3D11ClassLinkage **ppLinkage);
	HRESULT (*CreateBlendState)(ID3D11Device *This, const D3D11_BLEND_DESC *pBlendDesc, ID3D11BlendState **ppBlendState);
	HRESULT (*CreateDepthStencilState)(ID3D11Device *This, const D3D11_DEPTH_STENCIL_DESC *pDepthStencilDesc, ID3D11DepthStencilState **ppDepthStencilState);
	HRESULT (*CreateRasterizerState)(ID3D11Device *This, const D3D11_RASTERIZER_DESC *pRasterizerDesc, ID3D11RasterizerState **ppRasterizerState);
	HRESULT (*CreateSamplerState)(ID3D11Device *This, const D3D11_SAMPLER_DESC *pSamplerDesc, ID3D11SamplerState **ppSamplerState);
	HRESULT (*CreateQuery)(ID3D11Device *This, const D3D11_QUERY_DESC *pQueryDesc, ID3D11Query **ppQuery);
	HRESULT (*CreatePredicate)(ID3D11Device *This, const D3D11_QUERY_DESC *pPredicateDesc, ID3D11Predicate **ppPredicate);
	HRESULT (*CreateCounter)(ID3D11Device *This, const D3D11_COUNTER_DESC *pCounterDesc, ID3D11Counter **ppCounter);
} ID3D11DeviceVtbl;

struct ID3D11Device
{
	ID3D11DeviceVtbl *lpVtbl;
};
