#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include<QTableView>
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
    void AddDB(QString tableName);
    void ConnectDB();
    void AllDB(string tableName, QTableView *view);
    void DeleteDB(QString tableName);
    void FindDB(QString tableName, QTableView *view);
    void ChangeDB(QString tableName);
    void GetEmployees(QTableView *view);
    QString Console(QString sql);
    void GetDocuments(QString sql, QTableView *view);
    void SaveDocuments(QString sql);
};

#endif // MAINCONTROLLER_H
