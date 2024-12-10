#ifndef DB_H
#define DB_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

using namespace std;
class DB
{
private:
    QSqlDatabase db;
    // QSqlQueryModel *model;
    QTableView *tableView;

public:
    DB(QTableView *tableView);
    void connectDB(string userName,string dataBaseDB,string password);
    void selectTable(const QString &nameTable, QTableView *tableView1);
    void deleteTable(string nameTable);
    void findTable(string nameTable);
    void changeTable(string nameTable);
    void lookTable(string nameTable);
};

#endif // DB_H
