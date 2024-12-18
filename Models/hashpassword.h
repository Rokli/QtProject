#ifndef HASHPASSWORD_H
#define HASHPASSWORD_H
#include <QString>
#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDebug>

class HashPassword
{
public:
    static QString HashCode(QString password);
};

#endif // HASHPASSWORD_H
