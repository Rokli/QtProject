#include "maincontroller.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QFile>

void MainController::AllDB(QString tableName,QTableView *view){
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);

    qWarning() << tableName;
    QSqlQuery query(db);
    query.exec("SELECT * FROM " + tableName);

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
    QString sql = "SELECT * FROM usersQt";
    model->setQuery(sql, db);

    view->setModel(model);
}

QString MainController::Console(QString sql){
    SqlBD helpWindow(nullptr);
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);
    QSqlQuery query(db);
    query.prepare(sql);
    query.exec();
    if(sql.contains("SELECT")){
        model->setQuery(query);
        helpWindow.SetTableView(model);
        return "Запрос выполнен";
    }else{
        if (query.exec(sql)) {
            return "Запрос выполнен";
        } else {
            return "Произошла ошибка:" + query.lastError().text();
        }
    }
}

QString MainController::Console(QString sql,QTableView* view){
    QSqlQueryModel *model = new QSqlQueryModel(nullptr);;
    QSqlQuery query(db);
    query.prepare(sql);
    if (query.exec(sql)) {
        model->setQuery(query);
        view->setModel(model);
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

void MainController::SaveDocuments(QAbstractItemModel *model){
    QFile file("../../documents/documents.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);

        for (int col = 0; col < model->columnCount(); ++col) {
            out << model->headerData(col, Qt::Horizontal).toString();
            if (col < model->columnCount() - 1) out << "\t";
        }
        out << "\n";

        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                out << model->data(index).toString();
                if (col < model->columnCount() - 1) out << "\t";
            }
            out << "\n";
        }
    }

    file.close();
}

bool MainController::ConnectDB(QString name,QString password){
    db = QSqlDatabase::addDatabase("QMYSQL", "my_connection");
    db.setHostName("localhost");
    db.setDatabaseName("FilmScreening");
    db.setUserName(name);
    db.setPassword(password);

    if (!db.open()) {
        return false;
    }

    if (!db.isValid()) {
        return false;
    }

    return true;
}

bool MainController::GetUser(QString name, QString password){
    QSqlQuery query(db);
    QString sql = "SELECT COUNT(*) FROM usersQt WHERE username = :username AND  password_hash = :password";
    query.prepare(sql);
    query.bindValue(":username", name);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;


}

