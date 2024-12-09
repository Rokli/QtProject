#include "bankcontroller.h"
#include <cstdio>

BankController::BankController() {}

void BankController::selectTable() {}

void BankController::deleteTable() {}

void BankController::findTable()  {}

void BankController::changeTable() {}

void BankController::lookTable() {
    perror("123");
}

extern "C" void lookTable() {
    BankController::lookTable();
}
