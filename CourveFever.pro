#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T17:33:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CourveFever
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    circle.cpp \
    vector.cpp \
    point.cpp \
    gameitem.cpp \
    bonus.cpp

HEADERS  += mainwindow.h \
    player.h \
    circle.h \
    vector.h \
    point.h \
    gameitem.h \
    bonus.h

FORMS    += mainwindow.ui
