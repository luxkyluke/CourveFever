#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "renderer.h"
#include "game.h"
#include <iostream>

QGLWidget *MainWindow::getRenderer() const
{
    return w;
}

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent){

}

MainWindow::MainWindow(Game *g, QWidget *parent):
        game(g), QMainWindow(parent){
    this->resize(g->getWidth(), g->getHeight());

//    Player p(Qt::Key_Right, Qt::Key_Left);
//    game = Game(this->width(), this->height(), p);

    w = new Renderer(game, this);
    this->setCentralWidget(w);

    //game = Game(this->width(), this->height());

}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    if(!game->keyEvent(event))
        event->ignore();
}

void MainWindow::keyReleaseEvent(QKeyEvent* event){
    if(!game->keyEvent(event))
        event->ignore();
}

void MainWindow::repaintRenderer(){
    w->update();
}



MainWindow::~MainWindow(){

}

