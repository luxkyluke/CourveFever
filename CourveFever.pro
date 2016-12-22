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
    renderer.cpp \
    matrix.cpp\
    terrain.cpp \
    point.cpp \
    vector2D.cpp \
    play.cpp \
    menu.cpp \
    game.cpp \
    ctrlkey.cpp \
    gameitem.cpp \
    collision.cpp \
    canvas.cpp \
    biggerbonus.cpp \
    gamewindow.cpp \
    playerinfowidget.cpp \
    cleanbonus.cpp

FORMS    += \
    menuwindow.ui

HEADERS += \
    bonus.h \
    circle.h \
    player.h \
    terrain.h \
    renderer.h \
    matrix.h \
    gameitem.h \
    vector2D.h \
    point2D.h \
    play.h \
    menu.h \
    game.h \
    ctrlkey.h \
    collision.h \
    canvas.h \
    biggerbonus.h \
    gamewindow.h \
    playerinfowidget.h \
    timer.h \
    cleanbonus.h
