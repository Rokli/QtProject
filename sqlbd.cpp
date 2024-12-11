#include "sqlbd.h"
#include "ui_sqlbd.h"

SqlBD::SqlBD(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SqlBD)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(this);
    setLayout(layout);
}

void SqlBD::SetupWindow(QString text){
    QHBoxLayout *hLayout = new QHBoxLayout();

    QLabel *label = new QLabel(text, this);
    hLayout->addWidget(label);

    QLineEdit *lineEdit = new QLineEdit(this);
    hLayout->addWidget(lineEdit);

    lineEditData[text] = lineEdit;
    layout->addLayout(hLayout);
}
void SqlBD::AddButton(QString text){
    QPushButton *button = new QPushButton(text,this);
    connect(button, &QPushButton::clicked, this, &SqlBD::on_button_clicked);
    layout->addWidget(button);
}

QMap<QString,QString> SqlBD::GetDataColumns(){
    return DataColumns;
}
void SqlBD::on_button_clicked(){
    QMap<QString, QLineEdit*>::const_iterator i;

    for (i = lineEditData.constBegin(); i != lineEditData.constEnd(); ++i)
        DataColumns[i.key()] = i.value()->text();

    close();
}
SqlBD::~SqlBD()
{
    delete ui;
}
