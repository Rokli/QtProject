#ifndef SQLBD_H
#define SQLBD_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QErrorMessage>

namespace Ui {
class SqlBD;
}

class SqlBD : public QDialog
{
    Q_OBJECT

public:
    explicit SqlBD(QWidget *parent = nullptr);
    ~SqlBD();
    void SetupWindow(QString text);
    QMap<QString,QString> GetDataColumns();
    void on_button_clicked();
    void AddButton(QString text);
private:
    Ui::SqlBD *ui;
    QVBoxLayout *layout;
    QMap<QString,QLineEdit*> lineEditData;
    QMap<QString,QString> DataColumns;
};

#endif // SQLBD_H
