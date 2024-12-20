#pragma once

typedef enum D3D_DRIVER_TYPE {
  D3D_DRIVER_TYPE_UNKNOWN = 0,
  D3D_DRIVER_TYPE_HARDWARE,
  D3D_DRIVER_TYPE_REFERENCE,
  D3D_DRIVER_TYPE_NULL,
  D3D_DRIVER_TYPE_SOFTWARE,
  D3D_DRIVER_TYPE_WARP
};

typedef enum D3D_FEATURE_LEVEL {
  D3D_FEATURE_LEVEL_1_0_GENERIC,
  D3D_FEATURE_LEVEL_1_0_CORE,
  D3D_FEATURE_LEVEL_9_1,
  D3D_FEATURE_LEVEL_9_2,
  D3D_FEATURE_LEVEL_9_3,
  D3D_FEATURE_LEVEL_10_0,
  D3D_FEATURE_LEVEL_10_1,
  D3D_FEATURE_LEVEL_11_0,
  D3D_FEATURE_LEVEL_11_1,
  D3D_FEATURE_LEVEL_12_0,
  D3D_FEATURE_LEVEL_12_1,
  D3D_FEATURE_LEVEL_12_2
};
