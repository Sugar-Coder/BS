#-------------------------------------------------
#
# Project created by QtCreator 2019-04-29T10:57:38
#
#-------------------------------------------------

QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BookingSys
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwidget.cpp \
    mysqlapi.cpp \
    sqlop.cpp \
    logindialog.cpp \
    registerdialog.cpp \
    initer.cpp

HEADERS += \
        mainwidget.h \
    mysqlapi.h \
    sqlop.h \
    logindialog.h \
    registerdialog.h \
    initer.h

FORMS += \
        mainwidget.ui \
    logindialog.ui \
    registerdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/local/mysql-5.7.25-macos10.14-x86_64/lib/release/ -lmysqlclient.20
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/local/mysql-5.7.25-macos10.14-x86_64/lib/debug/ -lmysqlclient.20
else:unix: LIBS += -L$$PWD/../../../../../usr/local/mysql-5.7.25-macos10.14-x86_64/lib/ -lmysqlclient.20

INCLUDEPATH += $$PWD/../../../../../usr/local/mysql-5.7.25-macos10.14-x86_64/include
DEPENDPATH += $$PWD/../../../../../usr/local/mysql-5.7.25-macos10.14-x86_64/lib