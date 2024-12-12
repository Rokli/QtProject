
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main.ConnectDB();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.AddDB(QString::fromStdString(tablesMap[tmp.toStdString()]));
}


void MainWindow::on_lookButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.AllDB(tablesMap[tmp.toStdString()],ui->tableView);
}


void MainWindow::on_deleteButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.DeleteDB(QString::fromStdString(tablesMap[tmp.toStdString()]));
}


void MainWindow::on_findButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.FindDB(QString::fromStdString(tablesMap[tmp.toStdString()]),ui->tableView);
}


void MainWindow::on_changeButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.ChangeDB(QString::fromStdString(tablesMap[tmp.toStdString()]));
}

