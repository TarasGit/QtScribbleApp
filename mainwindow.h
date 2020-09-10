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

protected:
private:
  void createActions();
  void createMenus();
  ns::ScribbleArea *scribbleArea;

  QMenu *fileMenu;
  QMenu *optionMenu;
  QMenu *helpMenu;

  QAction *openImageAction;
  QList<QAction *> *fileFormatAction;
  QAction *setWidthAction;
  QAction *setColorAction;
  QAction *aboutQtAction;
  QAction *aboutAction;
};
