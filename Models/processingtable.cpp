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
