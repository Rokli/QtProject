#include "maincontroller.h"
#include <QSqlQuery>


void MainController::AllDB(string tableName,QTableView *view){
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);

    qWarning() << tableName;
    QSqlQuery query(db);
    query.exec("SELECT * FROM " + QString::fromStdString(tableName));

    model->setQuery(query);

    view->setModel(model);
};
void MainController::DeleteDB(){

};
void MainController::FindDB(){

};
void MainController::SelectDB(){

};

void MainController::AddDB(QString tableName){
    int count = 0;
    QVector<QString> name;
    QSqlQuery query(db);
    query.prepare(
        "SELECT COUNT(*) "
        "FROM information_schema.columns "
        "WHERE table_schema = DATABASE() AND table_name = :tablename"
    );


    query.bindValue(":tablename", tableName);
    query.exec();
    query.next();
    count = query.value(0).toInt() - 1;

    query.prepare(
        "SELECT COLUMN_NAME "
        "FROM information_schema.columns "
        "WHERE table_schema = DATABASE() AND table_name = :tablename "
        "ORDER BY ORDINAL_POSITION"
    );
    query.bindValue(":tablename", tableName);
    query.exec();

    while (query.next()) {
        qWarning() << query.value(0).toString();
        name.append(query.value(0).toString());
    }
    name.removeAt(0);

    QMap<QString,QString> values = helpWindow.CreateWindow(count,"Добавить",name);

    QStringList placeholders;
    QStringList columns;

    for (const auto &key : values.keys()) {
        columns.append(key);
        placeholders.append(":" + key);
    }
    QString insertQuery = QString(
                              "INSERT INTO %1 (%2) VALUES (%3)"
                              ).arg(tableName, columns.join(", "), placeholders.join(", "));
    query.prepare(insertQuery);

    for (const auto &key : values.keys()) {
        query.bindValue(":" + key, values[key]);
    }
    query.exec();

};

void MainController::ConnectDB(){
    db = QSqlDatabase::addDatabase("QMYSQL", "my_connection");
    db.setHostName("localhost");
    db.setDatabaseName("FilmScreening");
    db.setUserName("root");
    db.setPassword("xrxc321");
    db.open();
}
