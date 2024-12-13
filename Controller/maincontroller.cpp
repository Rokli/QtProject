#include "maincontroller.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>
void MainController::AllDB(string tableName,QTableView *view){
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);

    qWarning() << tableName;
    QSqlQuery query(db);
    query.exec("SELECT * FROM " + QString::fromStdString(tableName));

    model->setQuery(query);

    view->setModel(model);
};

void MainController::DeleteDB(QString tableName){
    QSqlQuery query(db);
    QMap<QString,QString> values = helpWindow.CreateWindow(1,"Удалить");

    QString sql = QString("DELETE FROM %1 WHERE id=%2").arg(tableName, values["id"]);
    query.prepare(sql);
    query.exec();
};

void MainController::FindDB(QString tableName,QTableView *view){
    QMap<QString,QString> values = helpWindow.CreateWindow(1,"Найти");
    QString sql = QString("SELECT * FROM %1 WHERE id=%2").arg(tableName, values["id"]);

    QSqlQueryModel *model = new QSqlQueryModel(nullptr);

    QSqlQuery query(db);
    query.exec(sql);

    model->setQuery(query);

    view->setModel(model);
}

void MainController::ChangeDB(QString tableName){
    QSqlQuery query(db);
    QMap<QString,QString> getID = helpWindow.CreateWindow(1,"Выбрать");

    QString sql = QString("SELECT * FROM %1 WHERE id=%2").arg(tableName, getID["id"]);

    query.prepare(sql);
    query.exec();
    query.next();

    QSqlRecord record = query.record();
    int columnCount = record.count();

    QMap<QString,QString> name;
    for (int i = 0; i < columnCount; ++i) {
        QString columnName = record.fieldName(i);
        QVariant value = query.value(i);
        name[columnName] = value.toString();
        qWarning() << query.value(i);
    }
    name.remove("id");
    QMap<QString,QString> updatedValues = helpWindow.CreateWindow(columnCount-1,"Изменить",name);

    QString updateSQL = QString("UPDATE %1 SET ").arg(tableName);
    QStringList updateParts;
    for (auto it = updatedValues.begin(); it != updatedValues.end(); ++it) {
        updateParts << QString("%1='%2'").arg(it.key(), it.value());
    }
    updateSQL += updateParts.join(", ");
    updateSQL += QString(" WHERE id=%1").arg(getID["id"]);

    query.prepare(updateSQL);
    query.exec();
}

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


}

void MainController::GetEmployees(QTableView *view){
    QSqlQueryModel* model = new QSqlQueryModel(nullptr);
    QString sql = "SELECT User, Host, authentication_string FROM mysql.user";
    model->setQuery(sql, db);

    view->setModel(model);
}

QString MainController::Console(QString sql){
    QSqlQuery query(db);
    query.prepare(sql);
    if (query.exec(sql)) {
        return "Запрос выполнен";
    } else {
        return "Произошла ошибка:" + query.lastError().text();
    }
}

void MainController::GetDocuments(QString sql, QTableView *view){
    QSqlQueryModel* model = new QSqlQueryModel(nullptr);
    model->setQuery(dataSQL[sql], db);
    view->setModel(model);
}

void MainController::SaveDocuments(QString sql){
    QSqlQuery query;

    if (!query.exec(dataSQL[sql])) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    QFile file("../../documents");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла для записи:" << file.errorString();
        return;
    }

    QTextStream out(&file);

    QSqlRecord record = query.record();
    int columnCount = record.count();

    for (int i = 0; i < columnCount; ++i) {
        out << record.fieldName(i);
        if (i < columnCount - 1) {
            out << "\t";
        }
    }
    out << "\n";

    while (query.next()) {
        for (int i = 0; i < columnCount; ++i) {
            out << query.value(i).toString();
            if (i < columnCount - 1) {
                out << "\t";
            }
        }
        out << "\n";
    }

    file.close();
}

void MainController::ConnectDB(){
    db = QSqlDatabase::addDatabase("QMYSQL", "my_connection");
    db.setHostName("localhost");
    db.setDatabaseName("FilmScreening");
    db.setUserName("root");
    db.setPassword("xrxc321");
    db.open();
}
