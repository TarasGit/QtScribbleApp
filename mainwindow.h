#pragma once
#include <QList>
#include <QtWidgets>

namespace ns {
class ScribbleArea;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow();

public slots:
  bool openImage();
  bool saveImage();
  void setColor();
  void setWidth();
  void aboutQt();
  void about();

protected:
private:
  void createActions();
  void createMenus();
  ns::ScribbleArea *scribbleArea;

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
