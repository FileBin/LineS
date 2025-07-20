core_src = [ 'core.rs', 'bindings.rs' ]

core_c_bindings = include_directories('.', join_paths('.', 'bindings'))

run_command('cbindgen', 'bindings.rs' , '-l', 'c','-o', 'bindings/core.h')
run_command('cbindgen', 'bindings.rs' , '-l', 'c++','-o', 'bindings/core.hpp')

lib_core = static_library('core', 
    sources: core_src,
    rust_crate_type: 'staticlib',
    install: true)