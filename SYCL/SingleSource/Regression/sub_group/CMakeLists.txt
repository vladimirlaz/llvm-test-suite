# Workaround to be able to build common_ocl.cpp which depends on OpenCL ICD loader directly.
list(APPEND LDFLAGS -lOpenCL)

llvm_singlesource()
