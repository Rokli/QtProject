#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QTableView>
#include <QStandardItemModel>
#include "../Models/processingtable.h"
using namespace std;

class MainController
{
private:
    ProcessingTable helpWindow;
    QSqlDatabase db;
    QMap<QString,QString> dataSQL = {
        {"Даты фильмов","SELECT c.name, r.start_date, r.end_date FROM Movie c INNER JOIN Renta r ON c.id =  r.id_movie"},
        {"Адреса кинотеатров","SELECT c.name, s.name, d.name FROM Cinema c LEFT JOIN City s ON c.id_city = s.id LEFT JOIN Street d ON c.id_street = d.id"},
        {"Банк поставщиков","SELECT s.INN,b.name FROM Supplier s LEFT JOIN Bank b ON s.id_bank = b.id"}
    };
public:
    bool reg = false;
    void AddDB(QString tableName);
    bool ConnectDB(QString name, QString password);
    void AllDB(QString tableName, QTableView *view);
    void DeleteDB(QString tableName);
    void FindDB(QString tableName, QTableView *view);
    void ChangeDB(QString tableName);
    bool ChangeUserPasswordDB(QString username);
    void GetEmployees(QTableView *view);
    QString Console(QString sql);
    QString Console(QString sql,QTableView* view);
    void GetDocuments(QString sql, QTableView *view);
    void SaveDocuments(QAbstractItemModel *model);
    bool GetUser(QString name, QString password);
    void ChangeTheme(QString theme);
};

#endif // MAINCONTROLLER_H
