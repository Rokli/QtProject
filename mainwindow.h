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
