#include "gamewindow.h"
#include "ui_mainwindow.h"
#include "terrain.h"
#include "game.h"
#include <iostream>
#include <QHBoxLayout>


//Canvas *MainWindow::getRenderer() const
//{
//    return canva;
//}

//MainWindow::MainWindow(QWidget *parent):
//    QMainWindow(parent){

//}

const static int SCORE_LABEL_WIDTH = 300;

GameWindow::GameWindow(const int w, const int h, QWidget *parent):QMainWindow(parent){
    this->resize(w+SCORE_LABEL_WIDTH, h);

    terrainLabel = new QLabel("terrain");



    scoreWidget = new QWidget();
    titre = new QLabel("scores",scoreWidget);

    //scoreLabel->resize(SCORE_LABEL_WIDTH, h);
    titre->setStyleSheet("QLabel { background-color : red; color : blue; }");
    QWidget* mainWidget = new QWidget();
    this->setCentralWidget(mainWidget);
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(scoreWidget);
    mainLayout->addWidget(terrainLabel);

    canva = NULL;
}


void GameWindow::setCanvas(Terrain* t){
    canva = t;
    terrainLabel->resize(t->getWidth(), t->getHeight());
}

void GameWindow::keyPressEvent() {
}

void GameWindow::keyReleaseEvent(){
}

//void MainWindow::repaintRenderer(){
//    //canva->update();
//}

void GameWindow::paintEvent(QPaintEvent *e){
    if(canva == NULL){
        std::cerr << "Cannot paint window's canvas, null pointeur exception"<<std::endl;
        exit(EXIT_FAILURE);
    }
    canva->paintEvent(e);
    terrainLabel->setPixmap(canva->getPic());
}

GameWindow::~GameWindow(){

}

