#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("FilmScreening");
    db.setUserName("root");
    db.setPassword("xrxc321");
    qDebug() << "Qt Version:" << QT_VERSION_STR;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{

}


void MainWindow::on_lookButton_clicked()
{

    QString tmp = ui->comboBox->currentText();
    MainController main;
    main.Route(this->tablesMap[tmp.toStdString()],"lookTable");
}

