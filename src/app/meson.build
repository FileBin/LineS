app_include = [
  app_dir, core_c_bindings
]

app_headers = []
qt_moc_headers = []

app_sources = [
  'main.cpp',
]

qt_resources_src = [ 'app.qrc' ]
qt_ui_files = []

subdir('components/mainwindow')

qtprocessed = qt.preprocess(moc_headers: qt_moc_headers,
                             ui_files: qt_ui_files,
                             include_directories: app_include)

exe_app = executable('qt-app',
  sources: [app_sources, qtprocessed],
  include_directories: app_include,
  dependencies: qt_dep, # Link against Qt
  link_with: [lib_core], # Link with the Rust library
  install : true
)