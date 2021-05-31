// RUN: %clangxx -fsycl %s -o %t.out -g
// RUN: env SYCL_PI_TRACE=-1 SYCL_DEVICE_FILTER=%sycl_be %t.out | FileCheck %s
// REQUIRES: gpu
// UNSUPPORTED: cuda
#include "program-merge-options.hpp"

// CHECK: piProgramBuild
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <const char *>: -DBUILD_OPTS -g -vc-codegen

// CHECK: piProgramCompile(
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <const char *>: -DCOMPILE_OPTS -vc-codegen

// CHECK: piProgramLink(
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <unknown>
// CHECK-NEXT: <const char *>: -cl-fast-relaxed-math -vc-codegen
