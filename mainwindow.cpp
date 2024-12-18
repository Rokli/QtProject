
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main.ConnectDB("root","xrxc321");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupWindow(){
    RegUser reg;
    reg.exec();
    if(main.GetUser(reg.GetName(),HashPassword::HashCode(reg.GetPassword()))){
        reg.close();
        show();
    }else{
        QMessageBox* msgBox = new QMessageBox(nullptr);
        msgBox->setText("Произошла ошибка");
        msgBox->setIcon(QMessageBox::Warning);
        msgBox->show();
    }
}

void MainWindow::on_addButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.AddDB(tablesMap[tmp]);
}

void MainWindow::on_lookButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.AllDB(tablesMap[tmp],ui->tableView);
}

void MainWindow::on_deleteButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.DeleteDB(tablesMap[tmp]);
}

void MainWindow::on_findButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.FindDB(tablesMap[tmp],ui->tableView);
}

void MainWindow::on_changeButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    main.ChangeDB(tablesMap[tmp]);
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
    SqlBD helpwindow;
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
    main.SaveDocuments(ui->documentsTableView->model());
}

void MainWindow::on_lineEdit_returnPressed()
{

}

void MainWindow::on_consoleDocuments_returnPressed()
{
    QString text = ui->consoleDocuments->text();
    main.Console(text,ui->documentsTableView);
}

void MainWindow::on_addEmployees_clicked()
{
    main.AddDB(tablesMap["Сотрудники"]);
}

void MainWindow::on_deleteEmployess_clicked()
{
    main.DeleteDB(tablesMap["Сотрудники"]);
}

void MainWindow::on_changeEmploess_clicked()
{
    main.ChangeDB(tablesMap["Сотрудники"]);
}

