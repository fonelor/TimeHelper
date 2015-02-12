#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T15:11:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeHelper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    timerbutton.cpp \
    alarmdialog.cpp

HEADERS  += mainwindow.h \
    timerbutton.h \
    alarmdialog.h

FORMS    += mainwindow.ui \
    alarmdialog.ui

DISTFILES += \
    res/icon.png

RESOURCES += \
    resources.qrc
