#ifndef SQLBD_H
#define SQLBD_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QErrorMessage>
#include <QSqlQueryModel>
#include <QTableView>
#include <Models/hashpassword.h>

namespace Ui {
class SqlBD;
}

class SqlBD : public QDialog
{
    Q_OBJECT

public:
    explicit SqlBD(QWidget *parent = nullptr,QString theme = " ");
    ~SqlBD();
    void SetupWindow(QString text);
    void SetupWindow(QString name, QString value);
    QMap<QString,QString> GetDataColumns();
    void on_button_clicked();
    void AddButton(QString text);
    void SetTableView(QSqlQueryModel *model);
    void ChangeTheme(QString theme);
private:
    Ui::SqlBD *ui;
    QVBoxLayout *layout;
    QMap<QString,QLineEdit*> lineEditData;
    QMap<QString,QString> DataColumns;

};

#endif // SQLBD_H
