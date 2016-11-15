#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderer.h"
#include "circle.h"
#include <iostream>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent){
    this->resize(800, 800);

    Player p;
    game = Game(this->width(), this->height(), p);

    w = new Renderer(game, this);
    this->setCentralWidget(w);

    //game = Game(this->width(), this->height());
    QTimer* timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(TIMEOUT()), this, SLOT(refresh()));
    timer->start();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if(!game.keyPressed(event->key()))
        event->ignore();
}

MainWindow::~MainWindow(){

}

void MainWindow::refresh(){
    update();
}
