#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "qtextedit.h"
#include <dirent.h>
#include <dlfcn.h>
#include <string>

using namespace std;

class MainController
{
private:
    bool regFlag;
    QTextEdit *test;
public:
    MainController(QTextEdit *ui);
    void Route(string controller,string method);
    void RegUser();
};

#endif // MAINCONTROLLER_H
