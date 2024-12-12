#include "processingtable.h"
using namespace std;
QMap<QString,QString> ProcessingTable::CreateWindow(int columns, QString text,QVector<QString> name){
    SqlBD *main = new SqlBD();
    for(int i = 0; i < columns;i++){
        main->SetupWindow(name[i]);
    }
    main->AddButton(text);
    main->exec();
    QMap<QString,QString> dataColumns = main->GetDataColumns();
    return dataColumns;
};


QMap<QString,QString> ProcessingTable::CreateWindow(int columns, QString text){
    SqlBD *main = new SqlBD();
    main->SetupWindow("id");
    main->AddButton(text);
    main->exec();
    QMap<QString,QString> dataColumns = main->GetDataColumns();
    return dataColumns;
};

QMap<QString,QString> ProcessingTable::CreateWindow(int columns, QString text,QMap<QString,QString> name){
    SqlBD *main = new SqlBD();
    for (const auto& key : name.keys()) {
        main->SetupWindow(key,name.value(key));
    }
    main->AddButton(text);
    main->exec();
    QMap<QString,QString> dataColumns = main->GetDataColumns();
    return dataColumns;
};
