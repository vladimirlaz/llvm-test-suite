// RUN: %clangxx -fsycl %s -o %t.out -g
// RUN: env SYCL_PI_TRACE=-1 SYCL_PROGRAM_COMPILE_OPTIONS=-DENV_COMPILE_OPTS SYCL_PROGRAM_LINK_OPTIONS=-DENV_LINK_OPTS SYCL_DEVICE_FILTER=%sycl_be %t.out | FileCheck %s
// REQUIRES: gpu
// UNSUPPORTED: cuda
#include "program-merge-options.hpp"

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
