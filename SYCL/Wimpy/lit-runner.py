# Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
# See https://llvm.org/LICENSE.txt for license information.
# SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception


import os
import sys

#skiplist = [ "test/test_02", "test/test_06"] # Enable to choose a 'skip list'

file_location=os.path.dirname(os.path.abspath(__file__))
sys.path.append(os.path.join(os.path.dirname(file_location),'lit'))
import subprocess
if __name__ == "__main__":
  builtin_parameters = {
    'build_mode' : "Release",
#    'llvm_site_config' : os.path.join(file_location, 'test', 'lit.site.cfg'),
#    'clang_site_config': os.path.join(file_location, 'test', 'lit.site.cfg')
    # , skip_list: skiplist          # if skiplist is not empty
    }
  from lit.main import main
  main(builtin_parameters)

