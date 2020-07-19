#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

class ScribbleArea;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
//    MainWindow(QWidget *parent = nullptr);
//
//protected:
//    void closeEvent(QCloseEvent *event) override;
//
// private slots:
//    void open();
//    void save();
//    void penColor();
//    void penWidth();
//    void about();

//private:
//    void createActions();
//    void createMenus();
//    void maybeSave();
//    bool saveFile(const QByteArray &fileFormat);

    ScribbleArea *ScribbleArea;

    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QList<QAction *> saveAsActs;
    QAction *exitAct;
    QAction *penColorAct;
    QAction *penWidthAct;
    QAction *printAct;
    QAction *clearScreenAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
};


#endif // MAINWINDOW_H