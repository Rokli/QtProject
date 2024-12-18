
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
    if(!reg) main.AddDB(tablesMap[tmp]);
    else main.AddDB(tmp);
}

void MainWindow::on_lookButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    if(!reg)main.AllDB(tablesMap[tmp],ui->tableView);
    else main.AllDB(tmp,ui->tableView);
}

void MainWindow::on_deleteButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    if(!reg) main.DeleteDB(tablesMap[tmp]);
    else  main.DeleteDB(tmp);

}

void MainWindow::on_findButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    if(!reg) main.FindDB(tablesMap[tmp],ui->tableView);
    else main.FindDB(tmp,ui->tableView);

}

void MainWindow::on_changeButton_clicked()
{
    QString tmp = ui->comboBox->currentText();
    if(!reg) main.ChangeDB(tablesMap[tmp]);
    else main.ChangeDB(tmp);

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
    if(!reg) main.GetDocuments(ui->documents->currentText(),ui->documentsTableView);
    else main.GetDocuments(documentsMap[ui->documents->currentText()],ui->documentsTableView);
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

void MainWindow::on_ragSundry_clicked()
{
    if(!reg){
        //инглиш
        main.reg = true;
        reg = true;
        //разное
        ui->exitSundry->setText("Exit");
        ui->changeSundry->setText("Change password");
        ui->colorSundry->setText("Change color");
        ui->ragSundry->setText("Русский");
        //верх таба
        ui->mainTabWidget->setTabText(0,"Sundry");
        ui->mainTabWidget->setTabText(1,"Command");
        ui->mainTabWidget->setTabText(2,"Employess");
        ui->mainTabWidget->setTabText(3,"Documents");
        ui->mainTabWidget->setTabText(4,"Directories");
        ui->mainTabWidget->setTabText(5,"Reference");
        //справка
        ui->tabWidget_2->setTabText(0,"Content");
        ui->tabWidget_2->setTabText(1,"About the program");
        ui->sundryButton->setText("Sundry");
        ui->ordersButton->setText("Command");
        ui->documentsButton->setText("Documents");
        ui->employeesButton->setText("Employess");
        ui->directoriesButton->setText("Directories");
        //справочники
        ui->addButton->setText("Add");
        ui->deleteButton->setText("Delete");
        ui->changeButton->setText("Change");
        ui->findButton->setText("Find");
        ui->lookButton->setText("See");
        //Документы
        ui->documentButton->setText("See");
        ui->saveButton->setText("Save");
        //Сотрудники
        ui->pushButton->setText("See");
        ui->addEmployees->setText("Add");
        ui->deleteEmployess->setText("Delete");
        ui->changeEmploess->setText("Change");
        //комбобокс в справочниках
        ui->comboBox->clear();
        for (auto i = tablesMap.begin(); i != tablesMap.end(); ++i) ui->comboBox->addItem(i.value());
        //комбобокс в документах
        ui->documents->clear();
        for (auto i = documentsMap.begin(); i != documentsMap.end(); ++i) ui->documents->addItem(i.key());
        setWindowTitle("Film screenings");
    }else{
        //русский
        main.reg = false;
        reg = false;
        //разное
        ui->exitSundry->setText("Выход");
        ui->changeSundry->setText("Поменять пароль");
        ui->colorSundry->setText("Поменять тему");
        ui->ragSundry->setText("English");
        //верх таба
        ui->mainTabWidget->setTabText(0,"Разное");
        ui->mainTabWidget->setTabText(1,"Приказы");
        ui->mainTabWidget->setTabText(2,"Сотрудники");
        ui->mainTabWidget->setTabText(3,"Документы");
        ui->mainTabWidget->setTabText(4,"Справочники");
        ui->mainTabWidget->setTabText(5,"Справка");
        //справка
        ui->tabWidget_2->setTabText(0,"Содержание");
        ui->tabWidget_2->setTabText(1,"О программе");
        ui->sundryButton->setText("Разное");
        ui->ordersButton->setText("Приказы");
        ui->documentsButton->setText("Документы");
        ui->employeesButton->setText("Сотрудники");
        ui->directoriesButton->setText("Справочники");
        //справочники
        ui->addButton->setText("Добавить");
        ui->deleteButton->setText("Удалить");
        ui->changeButton->setText("Изменить");
        ui->findButton->setText("Поиск");
        ui->lookButton->setText("Просмотреть");
        //Документы
        ui->documentButton->setText("Просмотреть");
        ui->saveButton->setText("Сохранить");
        //Сотрудники
        ui->pushButton->setText("Просмотреть");
        ui->addEmployees->setText("Добавить");
        ui->deleteEmployess->setText("Удалить");
        ui->changeEmploess->setText("Изменить");
        //комбобокс в справочниках
        ui->comboBox->clear();
        for (auto i = tablesMap.begin(); i != tablesMap.end(); ++i) ui->comboBox->addItem(i.key());
        //комбобокс в документах
        ui->documents->clear();
        for (auto i = documentsMap.begin(); i != documentsMap.end(); ++i) ui->documents->addItem(i.value());
        setWindowTitle("Демонстрация кинофильмов");
    }
}

