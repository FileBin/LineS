app_include = [
  app_dir, core_c_bindings
]

app_headers = []
qt_moc_headers = []

app_sources = [
  'main.cpp',
]

qt_resources_src = [ 'resources/tools/SVG/16/tools-svg-16-icons.qrc' ]

qt_ui_files = []

subdir('components/mainwindow')
subdir('components/canvas')

qtprocessed = qt.preprocess(moc_headers: qt_moc_headers,
                             qresources: qt_resources_src,
                             ui_files: qt_ui_files,
                             include_directories: app_include)

exe_app = executable('qt-app',
  sources: [app_sources, qtprocessed],
  include_directories: app_include,
  dependencies: [qt_dep, lib_core_dep], # Link against Qt
  install : true
)