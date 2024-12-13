#ifndef REGUSER_H
#define REGUSER_H

#include <QDialog>
#include <QString>

namespace Ui {
class RegUser;
}

class RegUser : public QDialog
{
    Q_OBJECT

public:
    explicit RegUser(QWidget *parent = nullptr);
    ~RegUser();
    QString GetPassword();
    QString GetName();

private slots:
    void on_regUserButton_clicked();

private:
    Ui::RegUser *ui;
    QString name;
    QString password;
};

#endif // REGUSER_H
