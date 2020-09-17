#include "mainwindow.h"
#include "scribblearea.h"
#include "ui_dialog.h"
#include <QColorDialog>
#include <QImage>
#include <QMessageBox>
#include <QWidget>

void MainWindow::createActions() {

  openImageAction = new QAction(QIcon(":/ressources/light.png"), tr("Open"));

  for (QByteArray image_format : QImageWriter::supportedImageFormats()) {

    QAction *tmp = new QAction(QIcon(":/ressources/red_star.png"),
                               tr(image_format.toStdString().c_str()));
    tmp->setData(image_format);
    fileFormatAction.append(tmp);
    connect(tmp, SIGNAL(triggered(bool)), this, SLOT(saveImage()));
  }
  exitAction = new QAction(QIcon(":/ressources/water.png"), tr("Exit"));

  setWidthAction =
      new QAction(QIcon(":/ressources/light.png"), tr("Pen Width"));
  setColorAction = new QAction(QIcon(":/ressources/star.png"), tr("Pen Color"));

  aboutAction = new QAction(QIcon(":/ressources/light.png"), tr("About"));
  aboutQtAction = new QAction(QIcon(":/ressources/water.png"), tr("About Qt"));
}

void MainWindow::createMenus() {

  fileMenu = new QMenu(tr("File"));
  formatsMenu = new QMenu(tr("Save As"));
  formatsMenu->addActions(fileFormatAction);

  fileMenu->addAction(openImageAction);
  fileMenu->addMenu(formatsMenu);
  fileMenu->addAction(exitAction);

  optionMenu = new QMenu(tr("Option"));
  optionMenu->addAction(setColorAction);
  optionMenu->addAction(setWidthAction);

  helpMenu = new QMenu(tr("Help"));

  helpMenu->addAction(aboutAction);
  helpMenu->addAction(aboutQtAction);

  connect(openImageAction, SIGNAL(triggered()), this, SLOT(openImage()));
  connect(setWidthAction, SIGNAL(triggered(bool)), this, SLOT(setWidth()));
  connect(setColorAction, SIGNAL(triggered(bool)), this, SLOT(setColor()));
  connect(aboutQtAction, SIGNAL(triggered(bool)), this, SLOT(aboutQt()));
  connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));
  connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
}

MainWindow::MainWindow() {
  setWindowTitle("Vocation Scribble");
  setToolTip(tr("This is my own created scribble example"));
  setMinimumSize(600, 400);
  move(QPoint(500, 200));

  createActions();
  createMenus();

  menuBar()->addMenu(fileMenu);
  menuBar()->addMenu(optionMenu);
  menuBar()->addMenu(helpMenu);

  scribbleArea = new ScribbleArea;
  setCentralWidget(scribbleArea);
}

bool MainWindow::openImage() {
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open"), "/home/taras/Bilder/", tr("Image Files(*.png)"));

  if (not fileName.isEmpty()) {
    qDebug() << QString("openImage(%1)").arg(fileName);
    scribbleArea->openImage(fileName);
    return true;
  }
  return false;
}

bool MainWindow::saveImage() {
  qDebug() << "Save Image";
  QString filePath = QDir::currentPath() + "/" + "untitled";
  QAction *action = qobject_cast<QAction *>(sender());
  QByteArray data = action->data().toByteArray();

  scribbleArea->saveImage(filePath, data);
  return true;
}

void MainWindow::setColor() {
  QColor tmpColor;
  tmpColor = QColorDialog::getColor(Qt::white, this,
                                    tr("Select the color for the pen"),
                                    QColorDialog::DontUseNativeDialog);

  qDebug() << "Following color selected: " << tmpColor.name();
  if (tmpColor.isValid()) {
    scribbleArea->setPenColor(tmpColor);
  }
}

void MainWindow::setWidth() {
  qDebug() << "Set Width";
  bool ok;
  initValue = QInputDialog::getInt(this, tr("Set Pen Width"), tr("Title"),
                                   initValue, 0, 255, 1, &ok);
  if (ok) {
    qDebug() << "set Width:" << initValue;
    scribbleArea->setPenWidth(initValue);
  }
}

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
