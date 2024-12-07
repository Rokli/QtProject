#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked()
{
    // MainController main;
    // main.Route("sql","SelectSql");
}


void MainWindow::on_addButton_clicked()
{

}


void MainWindow::on_lookButton_clicked()
{

}

