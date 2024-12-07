#include "sqlcontroller.h"

SqlController::SqlController() {}

void SqlController::SelectSql() {
    perror("всё сработало");
}
extern "C" void SelectSql() {
    SqlController::SelectSql();
}
