#pragma once
#include "scribblearea.h"
#include <QList>
#include <QtWidgets>

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

public slots:
  bool openImage();
  void setColor();
  bool saveImage();
  void setWidth();
  void aboutQt();
  void about();

protected:
private:
  int initValue;
  void createActions();
  void createMenus();
  ScribbleArea *scribbleArea;

  QMenu *fileMenu;
  QMenu *formatsMenu;
  QMenu *optionMenu;
  QMenu *helpMenu;

  QAction *openImageAction;
  QList<QAction *> fileFormatAction;
  QAction *setWidthAction;
  QAction *setColorAction;
  QAction *aboutQtAction;
  QAction *aboutAction;
  QAction *exitAction;
};
