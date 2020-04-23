
import sys

dpcpp_root_dir=lit_config.params.get('dpcpp_root_dir')

config.llvm_tools_dir = os.path.join(dpcpp_root_dir, 'bin')
#config.lit_tools_dir = ""
config.sycl_tools_dir = lit_config.params.get('sycl_tools_dir', os.path.join(dpcpp_root_dir, 'bin'))
config.sycl_include = os.path.join(dpcpp_root_dir, 'include', 'sycl')
config.sycl_obj_root = lit_config.params.get('sycl_obj_root', os.path.join(os.getcwd(), 'build'))
config.sycl_source_dir = "NOT_AVAILABLE"
config.sycl_libs_dir = os.path.join(dpcpp_root_dir, 'lib')
config.sycl_be =  lit_config.params.get('sycl_be', 'PI_OPENCL')
config.target_triple = lit_config.params.get('target_triple', 'x86_64-unknown-linux-gnu')
config.host_triple = lit_config.params.get('host_triple', 'x86_64-unknown-linux-gnu')
config.opencl_libs_dir = lit_config.params.get('opencl_libs_dir', os.path.join(dpcpp_root_dir, 'lib'))
config.opencl_include_dir = lit_config.params.get('opencl_include_dir', config.sycl_include)
config.cuda_toolkit_include = lit_config.params.get('cuda_toolkit_include', '')
config.dpcpp_compiler = os.path.join(config.llvm_tools_dir, lit_config.params.get('dpcpp_compiler', 'clang++'))

import lit.llvm
lit.llvm.initialize(lit_config, config)

# Let the main config do the real work.
lit_config.load_config(config, os.path.join(os.path.dirname(os.path.abspath(__file__)), 'lit.cfg.py'))

print (lit_config.params)
