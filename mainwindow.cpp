#include "mainwindow.h"
#include "ui_dialog.h"
#include <QWidget>

MainWindow::MainWindow() {

  fileMenu = new QMenu(tr("File"));
  fileMenu->addAction(QIcon(":/ressources/wurfel.png"), tr("Open Image"));

  fileMenu->addAction(QIcon(":/ressources/index.png"), tr("Save As"));
  fileMenu->addAction(QIcon(":/ressources/pic.png"), tr("Exit"));

  menuBar()->addMenu(fileMenu);
}
