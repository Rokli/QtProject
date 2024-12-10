
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

