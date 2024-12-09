#ifndef BANKCONTROLLER_H
#define BANKCONTROLLER_H

#include "basisformethods.h"

class BankController : public BasisFormethods
{
public:
    BankController();
    static void selectTable();
    static void deleteTable();
    static void findTable();
    static void changeTable();
    static void lookTable();
};

#endif // BANKCONTROLLER_H
