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

    layout->addLayout(hLayout);
}
void SqlBD::AddButton(QString text){
    QPushButton *button = new QPushButton(text,this);
    connect(button, &QPushButton::clicked, this, &SqlBD::on_button_clicked);
    layout->addWidget(button);
}

void SqlBD::ClearLayout(){
    if (layout) {
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            QWidget* widget = item->widget();
            if (widget) {
                widget->deleteLater();
            }
            delete item;
        }
    }
}

void SqlBD::on_button_clicked(){
    qWarning() << "123";
}
SqlBD::~SqlBD()
{
    delete ui;
}
