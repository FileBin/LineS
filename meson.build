project('rust-example', ['rust', 'c', 'cpp'],
    version         : '0.1.0',
    license         : 'MIT',
    meson_version   : '>=0.59.0')

# dependencies
qt = import('qt6')
qt_dep = dependency('qt6', modules: ['Core', 'Gui', 'Widgets', 'OpenGL', 'OpenGLWidgets'])


subdir('src')

# install_data(
#     sources: [ 'code_of_conduct.md', 'license.md', 'readme.md' ],
#     install_dir: join_paths(get_option('datadir'), meson.project_name()))