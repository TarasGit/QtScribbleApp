#ifndef Q_DIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QtWidgets>

class Dialog : public QDialog {
public:
  Dialog();

private:
  void createMenu();
  void createBoxLayout();
  void createGridLayout();
  void createFormLayout();

  void createMySqlDataBase();
  QStringList getQueryResult();
  void closeDataBase();
  void addIdNameToDataBase(int id, QString name);
  void deleteRowId(int id);

  QGroupBox *hBoxGroupBox;
  QGroupBox *formGroupBox;
  QGroupBox *gridGroupBox;

  QMenuBar *menuBar;

  enum { NumRows = 3, NumButtons = 4 };

  QLineEdit *lineEdits[NumRows];
  QLabel *labels[NumRows];
  QPushButton *buttons[NumButtons];

  QTextEdit *smallEditor;
  QTextEdit *bigEditor;

  QDialogButtonBox *dialogButtonBox;

  // QtDataBase
  QSqlDatabase db;
};

#endif
