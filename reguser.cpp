#include "reguser.h"
#include "ui_reguser.h"

RegUser::RegUser(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegUser)
{
    ui->setupUi(this);
    ui->passwordUser->setEchoMode(QLineEdit::Password);
}

RegUser::~RegUser()
{
    delete ui;
}

void RegUser::on_regUserButton_clicked()
{
    password =ui->passwordUser->text();
    name = ui->userName->text();
    close();
}

QString RegUser::GetPassword() {
    return password;
}

QString RegUser::GetName() {
    return name;
}

