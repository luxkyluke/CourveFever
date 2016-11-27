#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include "game.h"
#include <iostream>

Canvas *MainWindow::getRenderer() const
{
    return canva;
}

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent){

}

MainWindow::MainWindow(Game *g, QWidget *parent):
        game(g), QMainWindow(parent){
    this->resize(g->getWidth(), g->getHeight());

//    Player p(Qt::Key_Right, Qt::Key_Left);
//    game = Game(this->width(), this->height(), p);

//    w = new Renderer(game, this);
    label = new QLabel("start", this);
   //
    canva= new Canvas(game, this);
    QVBoxLayout *vbl = new QVBoxLayout(this);

    vbl->addWidget(label);

    this->setCentralWidget(label);

    //game = Game(this->width(), this->height());
   // label->show();
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
    //canva->update();
}

void MainWindow::paintEvent(QPaintEvent *e){
    canva->paintEvent(e);
    label->setPixmap(canva->getPic());
}

MainWindow::~MainWindow(){

}

