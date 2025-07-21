core_src = [ 'core.rs', 'bindings.rs' ]

core_c_bindings = include_directories('.', join_paths('.', 'bindings'))

run_command('cbindgen', 'bindings.rs' , '-l', 'c','-o', 'bindings/core.h')
run_command('cbindgen', 'bindings.rs' , '-l', 'c++','-o', 'bindings/core.hpp')

sub_cmesoncargo = subproject('meson-cargo')

#
# Configure cargo integration
#

lib_core = custom_target(
        'lines-core',
        kwargs: sub_cmesoncargo.get_variable('build_dict') + {
                'input': meson.current_source_dir() / 'Cargo.toml',
                'output': 'liblines_core.a',
        },
)

lib_core_dep = declare_dependency(
        include_directories: include_directories('.'),
        link_with: lib_core,
        version: meson.project_version(),
)

meson.add_dist_script(
        sub_cmesoncargo.get_variable('dist_cmd') + [
                meson.current_source_dir() / 'Cargo.toml',
        ],
)

run_target(
        'vendor',
        kwargs: sub_cmesoncargo.get_variable('vendor_dict') + {
                'command': sub_cmesoncargo.get_variable('vendor_cmd') + [
                        meson.current_source_dir() / 'Cargo.toml',
                ],
        },
)


