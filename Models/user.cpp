#include "user.h"

User::User() {}

QString User::GetName() { return name; }

void User::SetName(QString name) { this->name = name;}

void User::SetPassword(QString password) { this->password = password; }

QString User::GetPassword() { return password; }
