#include <dialog.h>

#include <QDebug>
#include <QSqlField>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlResult>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtWidgets>

/*
$ docker run --name=test-mysql --env="MYSQL_ROOT_PASSWORD=mypassword" mysql

$ apt-get install mysql-client
$ mysql -uroot -pmypassword -h 172.17.0.20 -P 3306


QSqlDatabase: QMYSQL driver not loaded
taras@taras-774:~$ sudo apt-get install libqt4-sql-mysql
sudo apt-get install libqt5sql5-mysql
*/

void Dialog::createMySqlDataBase() {
  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("172.17.0.2");
  db.setDatabaseName("test_database");
  db.setUserName("root");
  db.setPassword("mypassword");

  if (not db.open()) {
    qDebug() << (db.open() ? "Open" : "Close");
  }

  // Read from db
  QSqlQuery myQuery = db.exec("select * from test;");
  while (myQuery.next()) {
    QSqlRecord res = myQuery.record();
    QSqlField field1 = res.field("id");
    int id = field1.value().toInt();
    QSqlField field2 = res.field("firstname");
    QString name = field2.value().toString();

    qDebug() << "DB Result: " << id << " : " << name;
  }

  db.close();
}

Dialog::Dialog() {

  createMySqlDataBase();

  createMenu();
  createBoxLayout();
  createGridLayout();
  createFormLayout();

  bigEditor = new QTextEdit;
  bigEditor->setText(tr("This is the big editor"));

  QVBoxLayout *layout = new QVBoxLayout;
  layout->setMenuBar(menuBar);
  layout->addWidget(bigEditor);
  layout->addWidget(hBoxGroupBox);
  layout->addWidget(gridGroupBox);
  layout->addWidget(formGroupBox);

  QDialogButtonBox *buttonBox =
      new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
  connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
  connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

  layout->addWidget(buttonBox);

  setLayout(layout);
  setWindowTitle("My Basic Editor");
}

void Dialog::createMenu() {
  QMenu *mainMenu = new QMenu(tr("File"));
  QAction *exitAction = new QAction(tr("Close"));
  mainMenu->addAction(exitAction);
  connect(exitAction, SIGNAL(triggered(bool)), this, SLOT(close()));
  menuBar = new QMenuBar;
  menuBar->addMenu(mainMenu);
}

void Dialog::createBoxLayout() {
  hBoxGroupBox = new QGroupBox;

  QHBoxLayout *layout = new QHBoxLayout;
  for (int i = 0; i < NumButtons; i++) {
    buttons[i] = new QPushButton(tr("Button %1").arg(i + 1));
    layout->addWidget(buttons[i]);
  }

  hBoxGroupBox->setLayout(layout);
}

void Dialog::createGridLayout() {

  this->gridGroupBox = new QGroupBox;

  QGridLayout *layout = new QGridLayout;
  for (int i = 0; i < NumRows; i++) {
    labels[i] = new QLabel(tr("Label %1").arg(i));
    lineEdits[i] = new QLineEdit("");
    layout->addWidget(labels[i], i + 1, 0);
    layout->addWidget(lineEdits[i], i + 1, 1);
  }

  smallEditor = new QTextEdit;
  smallEditor->setPlainText("This is the small editor");
  layout->addWidget(smallEditor, 0, 2, 4, 1);

  layout->setColumnStretch(1, 10);
  layout->setColumnStretch(2, 30);

  gridGroupBox->setLayout(layout);
}

void Dialog::createFormLayout() {
  formGroupBox = new QGroupBox;

  QFormLayout *formLayout = new QFormLayout;

  formLayout->addRow(new QLabel(tr("Line 1")), new QLineEdit);
  formLayout->addRow(new QLabel(tr("Line 2")), new QComboBox);
  formLayout->addRow(new QLabel(tr("Line 3")), new QSpinBox);

  formGroupBox->setLayout(formLayout);
}
