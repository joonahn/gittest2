#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T20:18:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gittest2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    character.cpp \
    map.cpp

HEADERS  += mainwindow.h \
    character.h \
    map.h \
    mapdata.h

FORMS    += mainwindow.ui

DISTFILES +=

RESOURCES += \
    resource.qrc
