// RUN: %clangxx -fsycl %s -o %t.out -g
// RUN: %GPU_RUN_PLACEHOLDER SYCL_PI_TRACE=-1 SYCL_PROGRAM_COMPILE_OPTIONS=-DENV_COMPILE_OPTS SYCL_PROGRAM_LINK_OPTIONS=-DENV_LINK_OPTS %t.out %GPU_CHECK_PLACEHOLDER
// REQUIRES: gpu
// UNSUPPORTED: cuda
#include "kernel-bundle-merge-options.hpp"

// CHECK: piProgramBuild
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <const char *>: -DENV_COMPILE_OPTS -vc-codegen

// CHECK: piProgramCompile(
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <const char *>: -DENV_COMPILE_OPTS -vc-codegen

// CHECK: piProgramLink(
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <const char *>: -DENV_LINK_OPTS -vc-codegen
