# Default open source clang configuration with SYCL support.

set(CMAKE_BUILD_TYPE "Release" CACHE STRING "")
set(CMAKE_CXX_FLAGS "-fsycl -fsycl-targets=nvptx64-nvidia-cuda-sycldevice -Xsycl-target-backend --cuda-gpu-arch=sm_32" CACHE STRING "")
