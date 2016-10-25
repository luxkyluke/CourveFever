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
        mainwindow.cpp \
    player.cpp \
    circle.cpp \
    bonus.cpp \
    renderer.cpp \
    matrix.cpp\
    terrain.cpp \
    point.cpp \
    vector2D.cpp

FORMS    += mainwindow.ui

HEADERS += \
    bonus.h \
    circle.h \
    mainwindow.h \
    player.h \
    terrain.h \
    renderer.h \
    matrix.h \
    gameitem.h \
    point.h \
    vector2D.h
