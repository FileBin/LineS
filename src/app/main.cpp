#include <QApplication>
#include "./components/mainwindow/mainwindow.hpp"
#include "core.hpp"

Core* core;

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  
  if(lines_core_create(&core) != 0) {
    return -1;
  }

  w.show();

  return a.exec();
}
