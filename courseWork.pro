QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/maincontroller.cpp \
    Models/hashpassword.cpp \
    Models/processingtable.cpp \
    Models/user.cpp \
    main.cpp \
    mainwindow.cpp \
    reguser.cpp \
    sqlbd.cpp

HEADERS += \
    Controller/maincontroller.h \
    Models/hashpassword.h \
    Models/processingtable.h \
    Models/user.h \
    mainwindow.h \
    reguser.h \
    sqlbd.h

FORMS += \
    mainwindow.ui \
    reguser.ui \
    sqlbd.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
