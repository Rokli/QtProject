#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Controller/maincontroller.h"
#include "qsqldatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QLoggingCategory>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();

    void on_lookButton_clicked();

    void on_deleteButton_clicked();

    void on_findButton_clicked();

    void on_changeButton_clicked();

    void on_sundryButton_clicked();

    void on_employeesButton_clicked();

    void on_ordersButton_clicked();

    void on_documentsButton_clicked();

    void on_directoriesButton_clicked();

    void on_pushButton_clicked();

    void on_consoleEdit_returnPressed();

    void on_documentButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::MainWindow *ui;
    map<string, string> tablesMap = {
        {"Банк","Bank"},
        {"Категория","Category"},
        {"Кинотеатр","Cinema"},
        {"Город","City"},
        {"Улица","Street"},
        {"Режиссёр","Director"},
        {"Компания-производитель","Production_Company"},
        {"Рента","Renta"},
        {"Кино","Movie"},
        {"Правообладатель","Copyright_holder"},
        {"Сценарист","Screenwriter"},
        {"Поставщик","Supplier"}
    };
    MainController main;
};
#endif // MAINWINDOW_H
