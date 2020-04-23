// XFAIL: cuda
// piextUSM*Alloc functions for CUDA are not behaving as described in
// https://github.com/intel/llvm/blob/sycl/sycl/doc/extensions/USM/USM.adoc
// https://github.com/intel/llvm/blob/sycl/sycl/doc/extensions/USM/cl_intel_unified_shared_memory.asciidoc
//
// RUN: %clangxx -fsycl -fsycl-targets=%sycl_triple %s -o %t1.out
// RUN: env SYCL_DEVICE_TYPE=HOST %t1.out
// RUN: %CPU_RUN_PLACEHOLDER %t1.out
// RUN: %GPU_RUN_PLACEHOLDER %t1.out

//==---- allocator_vector.cpp - Allocator Container test -------------------==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include <CL/sycl.hpp>

#include <vector>

using namespace cl::sycl;

const int N = 8;

class foo;
int main() {
  queue q;
  auto dev = q.get_device();
  auto ctxt = q.get_context();

  if (!dev.get_info<info::device::usm_host_allocations>()) 
    return 0;

  usm_allocator<int, usm::alloc::host> alloc(ctxt, dev);

  std::vector<int, decltype(alloc)> vec(alloc);
  vec.resize(N);

  for (int i = 0; i < N; i++) {
    vec[i] = i;
  }

  int *res = &vec[0];
  int *vals = &vec[0];

  auto e1 = q.submit([=](handler &cgh) {
    cgh.single_task<class foo>([=]() {
      for (int i = 1; i < N; i++) {
        res[0] += vals[i];
      }
    });
  });

  e1.wait();

  int answer = (N * (N - 1)) / 2;

  if (vec[0] != answer)
    return -1;

  return 0;
}
