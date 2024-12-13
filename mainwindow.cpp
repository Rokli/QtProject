
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main.ConnectDB();
    SetupWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupWindow(){
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

void MainWindow::on_sundryButton_clicked()
{
    ui->mainTabWidget->setCurrentIndex(0);
}


void MainWindow::on_employeesButton_clicked()
{
    ui->mainTabWidget->setCurrentIndex(1);
}


void MainWindow::on_ordersButton_clicked()
{
    ui->mainTabWidget->setCurrentIndex(2);
}


void MainWindow::on_documentsButton_clicked()
{
    ui->mainTabWidget->setCurrentIndex(3);
}


void MainWindow::on_directoriesButton_clicked()
{
    ui->mainTabWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_clicked()
{
    main.GetEmployees(ui->employessView);
}


void MainWindow::on_consoleEdit_returnPressed()
{
    QString text = ui->consoleEdit->text();
    ui->consoleText->append(">>"+text);
    ui->consoleText->append(">>"+main.Console(text));
    ui->consoleEdit->clear();
}


void MainWindow::on_documentButton_clicked()
{
    main.GetDocuments(ui->documents->currentText(),ui->documentsTableView);
}


void MainWindow::on_saveButton_clicked()
{
    main.SaveDocuments(ui->documents->currentText());
}

