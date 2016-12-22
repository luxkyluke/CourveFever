#-------------------------------------------------
#
# Project created by QtCreator 2016-10-04T17:33:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = CourveFever
TEMPLATE = app

LIBS += -LD:\Qt\Tools\mingw492_32\lib \
        -lopengl32


SOURCES += main.cpp\
    player.cpp \
    circle.cpp \
    bonus.cpp \
    terrain.cpp \
    vector2D.cpp \
    menu.cpp \
    game.cpp \
    ctrlkey.cpp \
    gameitem.cpp \
    biggerbonus.cpp \
    gamewindow.cpp \
    playerinfowidget.cpp \
    cleanbonus.cpp \
    speedbonus.cpp

FORMS    += \
    menuwindow.ui

HEADERS += \
    bonus.h \
    player.h \
    terrain.h \
    gameitem.h \
    vector2D.h \
    menu.h \
    game.h \
    ctrlkey.h \
    biggerbonus.h \
    gamewindow.h \
    playerinfowidget.h \
    cleanbonus.h \
    speedbonus.h
