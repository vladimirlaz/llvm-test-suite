# Overview
SYCL related single source tests.
TODO: Manage to configure execution on specific device or SYCL backend.


# Steps to use
The tests can be automatically built and run with the whole test suite.
It is necessary to specify correct compiler and compilation options to be
able build SYCL code.

 - DPCPP compiler
```
# in llvm-test-suite source directory
mkdir build
cd build
CXX=dpcpp cmake -G Ninja -DTEST_SUITE_SUBDIRS=SYCL -C../cmake/caches/dpcpp.cmake ..
ninja all
llvm-lit -v .
```
 - Open source DPCPP compiler. Building for OpenCL target devices.
```
# in llvm-test-suite source directory
mkdir build
cd build
CXX=clang++ cmake -G Ninja -DTEST_SUITE_SUBDIRS=SYCL -C../cmake/caches/clang_fsycl.cmake ..
ninja all
llvm-lit -v .
```

 - Open source DPCPP compiler. Building for CUDA target devices.
```
# in llvm-test-suite source directory
mkdir build
cd build
CXX=clang++ cmake -G Ninja -DTEST_SUITE_SUBDIRS=SYCL -C../cmake/caches/clang_fsycl_cuda.cmake ..
ninja all
SYCL_BE=PI_CUDA SYCL_DEVICE_TYPE=GPU llvm-lit -v .
```


See examples below for running tests on different devices:
 - SYCL host:
```
SYCL_BE=PI_CUDA SYCL_DEVICE_TYPE=host llvm-lit -v .
```
 - OpenCL GPU
```
SYCL_BE=PI_OPENCL SYCL_DEVICE_TYPE=GPU llvm-lit -v .
```
 - OpenCL CPU
```
SYCL_BE=PI_OPENCL SYCL_DEVICE_TYPE=CPU llvm-lit -v .
```
 - OpenCL FPGA emulator
```
SYCL_BE=PI_OPENCL SYCL_DEVICE_TYPE=ACC llvm-lit -v .
```
 * CUDA GPU
```
SYCL_BE=PI_CUDA SYCL_DEVICE_TYPE=GPU llvm-lit -v .
```




