#include "mainwindow.h"
#include "ui_dialog.h"
#include <QImage>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow() {
  // Window configuration
  setWindowTitle("Vocation Scribble");
  setToolTip(tr("This is my own created scribble example"));
  setMinimumSize(600, 400);
  move(QPoint(500, 200));

  // File Menu
  fileMenu = new QMenu(tr("File"));
  openImageAction = new QAction(QIcon(":/ressources/wurfel.png"), tr("Open"));

  for (QByteArray image_format : QImageWriter::supportedImageFormats()) {

    QAction *tmp = new QAction(QIcon(":/ressources/index.png"),
                               tr(image_format.toStdString().c_str()));
    fileFormatAction.append(tmp);
    connect(tmp, SIGNAL(triggered(bool)), this, SLOT(saveImage()));
  }
  exitAction = new QAction(QIcon(":/ressources/pic.png"), tr("Exit"));

  formatsMenu = new QMenu(tr("Save As"));
  formatsMenu->addActions(fileFormatAction);

  fileMenu->addAction(openImageAction);
  fileMenu->addMenu(formatsMenu);
  fileMenu->addAction(exitAction);

  // Option Menu
  optionMenu = new QMenu(tr("Option"));
  setWidthAction =
      new QAction(QIcon(":/ressources/wurfel.png"), tr("Pen Width"));
  optionMenu->addAction(setWidthAction);
  setColorAction =
      new QAction(QIcon(":/ressources/index.png"), tr("Pen Color"));
  optionMenu->addAction(setColorAction);

  // Help Menu
  helpMenu = new QMenu(tr("Help"));
  aboutAction = new QAction(QIcon(":/ressources/wurfel.png"), tr("About"));
  helpMenu->addAction(aboutAction);
  aboutQtAction = new QAction(QIcon(":/ressources/pic.png"), tr("About Qt"));
  helpMenu->addAction(aboutQtAction);

  menuBar()->addMenu(fileMenu);
  menuBar()->addMenu(optionMenu);
  menuBar()->addMenu(helpMenu);

  connect(openImageAction, SIGNAL(triggered()), this, SLOT(openImage()));
  connect(setWidthAction, SIGNAL(triggered(bool)), this, SLOT(setWidth()));
  connect(setColorAction, SIGNAL(triggered(bool)), this, SLOT(setColor()));
  connect(aboutQtAction, SIGNAL(triggered(bool)), this, SLOT(aboutQt()));
  connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));
  connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
}

bool MainWindow::openImage() {
  qDebug() << "Open Image";

  return true;
}

bool MainWindow::saveImage() {
  qDebug() << "Save Image";
  return true;
}

void MainWindow::setColor() { qDebug() << "Set Color"; }

void MainWindow::setWidth() { qDebug() << "Set Width"; }

void MainWindow::aboutQt() {
  qDebug() << "About Qt";
  QMessageBox::aboutQt(this, tr("About Qt"));
}

void MainWindow::about() {
  qDebug() << "About";
  QMessageBox::about(this, tr("About this application"),
                     "<h1 style='color:'red''> This </h1> info box supports "
                     "also html formatting");
}
