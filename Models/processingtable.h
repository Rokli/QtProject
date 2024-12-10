#ifndef PROCESSINGTABLE_H
#define PROCESSINGTABLE_H
#include"../sqlbd.h"
#include <QLabel>
#include <QLineEdit>

using namespace std;
class ProcessingTable
{
private:
    SqlBD window;
public:
    string GetData(int columns, QString text, QVector<QString> name);
};

#endif // PROCESSINGTABLE_H
