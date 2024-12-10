#include "db.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlError>
#include <QSqlDatabase>
#include <QDebug> // Для qWarning


using namespace std;
DB::DB(QTableView *tableView) : tableView(tableView){
    db = QSqlDatabase::addDatabase("QMYSQL");
}

void DB::connectDB(string userName,string dataBaseDB,string password) {

    qWarning() << password;
    db.setHostName("localhost");
    db.setDatabaseName(QString::fromStdString(dataBaseDB));
    db.setUserName(QString::fromStdString(userName));
    db.setPassword(QString::fromStdString(password));
    if (!db.open()) {
        qWarning() << "Ошибка подключения к базе данных:" << db.lastError().text();
        return; // Завершение программы в случае ошибки
    }
};

void DB::selectTable(const QString &nameTable, QTableView *tableView1) {
    QSqlDatabase db;
    if (QSqlDatabase::contains("my_connection")) {
        db = QSqlDatabase::database("my_connection");
    } else {
        db = QSqlDatabase::addDatabase("QMYSQL", "my_connection");
        db.setHostName("localhost");
        db.setDatabaseName("FilmScreening");
        db.setUserName("root");
        db.setPassword("xrxc321");
    }

    if (!db.open()) {
        qDebug() << "Не удалось подключиться к базе данных:" << db.lastError().text();
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(tableView1); // Устанавливаем родителя
    QSqlQuery query(db);
    query.exec(QString("SELECT name FROM Bank"));

    model->setQuery(query);
    tableView1->setModel(model);

    db.close();
    QSqlDatabase::removeDatabase("my_connection");
};

void DB::deleteTable(string nameTable) {};

void DB::findTable(string nameTable) {};

void DB::changeTable(string nameTable) {};

void DB::lookTable(string nameTable) {};
