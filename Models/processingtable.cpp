#include "processingtable.h"
using namespace std;
string ProcessingTable::GetData(int columns, QString text,QVector<QString> name){
    for(int i = 0; i < columns;i++){
        window.SetupWindow(name[i]);
    }
    window.AddButton(text);
    window.show();
    // window.ClearLayout();
    return "123";
};
