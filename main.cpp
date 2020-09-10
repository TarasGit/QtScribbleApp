#include "dialog.h"
#include <QApplication>
#include <mainwindow.h>
#include <scribblearea.h>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  // Dialog w;
  // ScribbleArea w;
  MainWindow w;

  w.show();

  return a.exec();
}
