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

public:
    void AddDB(QString tableName);
    void ConnectDB();
    void AllDB(string tableName, QTableView *view);
    void DeleteDB(QString tableName);
    void FindDB(QString tableName, QTableView *view);
    void ChangeDB(QString tableName);
};

#endif // MAINCONTROLLER_H
