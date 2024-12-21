#include "sqlbd.h"
#include "ui_sqlbd.h"

SqlBD::SqlBD(QWidget *parent, QString theme)
    : QDialog(parent)
    , ui(new Ui::SqlBD)
{
    ui->setupUi(this);
    layout = new QVBoxLayout(this);
    setLayout(layout);
    ChangeTheme(theme);
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
void SqlBD::SetupWindow(QString name, QString value){
    QHBoxLayout *hLayout = new QHBoxLayout();

    QLabel *label = new QLabel(name, this);
    hLayout->addWidget(label);

    QLineEdit *lineEdit = new QLineEdit(this);
    lineEdit->setText(value);
    hLayout->addWidget(lineEdit);

    lineEditData[name] = lineEdit;
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

    for (i = lineEditData.constBegin(); i != lineEditData.constEnd(); ++i){
        QString text = i.value()->text();
        if (text.isEmpty()) continue;
        if (i.key() == "password_hash") text = HashPassword::HashCode(text);

        qWarning() << text << " " << i.key();

        DataColumns[i.key()] = text;
    }

    close();
}
void SqlBD::SetTableView(QSqlQueryModel *model) {
    QTableView *tableView = new QTableView(this);
    tableView->setModel(model);
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);

    QLayout *existingLayout = this->layout;

    if (existingLayout) {
        existingLayout->addWidget(tableView);
    } else {
        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(tableView);
        setLayout(layout);
    }

    exec();
}
void SqlBD::ChangeTheme(QString theme){
    setStyleSheet(theme);
}
SqlBD::~SqlBD()
{
    delete ui;
}
