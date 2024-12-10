#include "maincontroller.h"
#include <QSqlQuery>


void MainController::AllDB(string tableName,QTableView *view){
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);

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
    count = query.value(0).toInt();

    query.prepare(
        "SELECT COLUMN_NAME "
        "FROM information_schema.columns "
        "WHERE table_schema = DATABASE() AND table_name = :tablename"
    );
    query.bindValue(":tablename", tableName);
    query.exec();
    while (query.next()) {
        name.append(query.value(0).toString());
    }

    helpWindow.GetData(count,"Добавить",name);

    // QStringList columns;
    // QStringList placeholders;

    // query.prepare("INSERT INTO " + QString::fromStdString("Street") + " (name) VALUES (:name)");

    // query.bindValue(":name", QString::fromStdString(name));

    // query.exec();
};

void MainController::ConnectDB(){
    db = QSqlDatabase::addDatabase("QMYSQL", "my_connection");
    db.setHostName("localhost");
    db.setDatabaseName("FilmScreening");
    db.setUserName("root");
    db.setPassword("xrxc321");
    db.open();
}
