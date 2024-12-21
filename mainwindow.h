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
#include "reguser.h"
#include "Models/hashpassword.h"
#include "Models/user.h"
#include "Models/theme.h"

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

    void on_lineEdit_returnPressed();

    void on_consoleDocuments_returnPressed();

    void on_addEmployees_clicked();

    void on_deleteEmployess_clicked();

    void on_changeEmploess_clicked();

    void on_ragSundry_clicked();

    void on_changeSundry_clicked();

    void on_exitSundry_clicked();

    void on_colorSundry_clicked();

private:
    Ui::MainWindow *ui;
    User *user = new User();
    bool reg = false;
    QMap<QString, QString> tablesMap = {
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
        {"Поставщик","Supplier"},
        {"Сотрудники","usersQt"}
    };
    QMap<QString, QString> documentsMap = {
        {"Movie dates","Даты фильмов"},
        {"Cinema addresses","Адреса кинотеатров"},
        {"Supplier Bank","Банк поставщиков"}
    };
    bool theme = true;
    Theme *mainTheme = new Theme;
    MainController main;
public:
    void SetupWindow();
    void StyleSheet();
};
#endif // MAINWINDOW_H
