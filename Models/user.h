#ifndef USER_H
#define USER_H
#include <QString>

class User
{
private:
    QString name;
    QString password;
public:
    User();
    QString GetName();
    void SetName(QString name);
    void SetPassword(QString password);
    QString GetPassword();

};

#endif // USER_H
