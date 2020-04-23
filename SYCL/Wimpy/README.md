# Overview
SYCL related test based on SYCL-LIT. These tests support
execution on all supported devices and SYCL backends.


# Main parameters
It is possible to change tets scope my specifying test directory/file in first
argument to for th elit-runner.py script.

***dpcpp_root_dir*** should point to the directory containing DPCPP compiler

***dpcpp_compiler*** contains name of DPCPP compiler file (default value is clang++)

***target_devices*** defines comma separated target device types (defaul values is
 cpu,gpu,acc,host). Supported target_devices values are:
 - cpu  - CPU device available in OpenCL backend only;
 - gpu  - GPU device available in OpenCL and CUDA backend;
 - acc  - FPGA emulator device available in OpenCL backend only;
 - host - SYCL Host device availabel with all backends.

***sycl_be*** defined SYCL backend to be used for testing (default is PI_OPENCL).
Supported sycl_be values:
 - PI_OPENCL - for OpenCL backend;
 - PI_CUDA - for CUDA backend;
 - PI_HOST - host only device supported.

It is asssumed that all dependencies (OpenCL runtimes,
CUDA SDK, AOT compilers, etc) are available in the system.


See examples below for running tetss on diffrent devices:
 - SYCL host:
```
python  SYCL/Wimpy/lit-runner.py SYCL/Wimpy/test --param dpcpp_root_dir=<DPCPP_COMPILER> --param sycl_be=PI_HOST --param target_devices=host
```
 - OpenCL GPU
```
python  SYCL/Wimpy/lit-runner.py SYCL/Wimpy/test --param dpcpp_root_dir=<DPCPP_COMPILER> --param sycl_be=PI_OPENCL --param target_devices=gpu
```
 - OpenCL CPU
```
python  SYCL/Wimpy/lit-runner.py SYCL/Wimpy/test --param dpcpp_root_dir=<DPCPP_COMPILER> --param sycl_be=PI_OPENCL --param target_devices=cpu
```
 - OpenCL FPGA emulator
```
python  SYCL/Wimpy/lit-runner.py SYCL/Wimpy/test --param dpcpp_root_dir=<DPCPP_COMPILER> --param sycl_be=PI_OPENCL --param target_devices=acc
```
 * CUDA GPU
```
python  SYCL/Wimpy/lit-runner.py SYCL/Wimpy/test --param dpcpp_root_dir=<DPCPP_COMPILER> --param sycl_be=PI_CUDA --param target_devices=gpu
```




