#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "terrain.h"
#include "game.h"
#include <iostream>
#include <QVBoxLayout>

//Canvas *MainWindow::getRenderer() const
//{
//    return canva;
//}

//MainWindow::MainWindow(QWidget *parent):
//    QMainWindow(parent){

//}

MainWindow::MainWindow(const int w, const int h, QWidget *parent):QMainWindow(parent){
    this->resize(w, h);

    label = new QLabel("start", this);

    QVBoxLayout *vbl = new QVBoxLayout(this);

    vbl->addWidget(label);

    this->setCentralWidget(label);
    canva = NULL;
}


void MainWindow::setCanvas(Terrain* t){
    canva = t;
}

void MainWindow::keyPressEvent() {
}

void MainWindow::keyReleaseEvent(){
}

//void MainWindow::repaintRenderer(){
//    //canva->update();
//}

void MainWindow::paintEvent(QPaintEvent *e){
    if(canva == NULL){
        std::cerr << "Cannot paint window's canvas, null pointeur exception"<<std::endl;
        exit(EXIT_FAILURE);
    }
    canva->paintEvent(e);
    label->setPixmap(canva->getPic());
}

MainWindow::~MainWindow(){

}

