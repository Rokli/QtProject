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
    QMap<QString, QString> CreateWindow(int columns, QString text, QVector<QString> name);
    QMap<QString,QString> CreateWindow(int columns, QString text);
    QMap<QString,QString> CreateWindow(int columns, QString text,QMap<QString,QString> name);
};

#endif // PROCESSINGTABLE_H
