#include "gamewindow.h"
#include "terrain.h"
#include "game.h"
#include <iostream>
#include <QHBoxLayout>
#include <QVectorIterator>
#include <QtCore>


//Canvas *MainWindow::getRenderer() const
//{
//    return canva;
//}

//MainWindow::MainWindow(QWidget *parent):
//    QMainWindow(parent){

//}

const static int SCORE_LABEL_WIDTH = 300;
const static int PLAYER_WIDGET_HEIGHT = 50;

GameWindow::GameWindow(const int w, const int h,
                QVector<Player *> *p, QWidget *parent):
                QMainWindow(parent){
    this->resize(w+SCORE_LABEL_WIDTH, h);

    terrainLabel = new QLabel("terrain");

    scoreWidget = new QWidget();
    titre = new QLabel("scores", scoreWidget);

    players = p;

    int height = PLAYER_WIDGET_HEIGHT;

    //---------------------------------
    //    /!\     ITERATOR     /!\
    //---------------------------------

    QVector<Player*>::iterator iterator;
    for(iterator = p->begin(); iterator != p->end(); iterator++) {
        PlayerInfoWidget *bloc = new PlayerInfoWidget(*iterator, SCORE_LABEL_WIDTH, height, scoreWidget);
        playersInfos.append(bloc);
        height += PLAYER_WIDGET_HEIGHT;
    }

    //titre->setStyleSheet("QLabel { background-color : red; color : blue; }");
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

void GameWindow::updateScores(){
    QVector<PlayerInfoWidget*>::iterator it;
    it = playersInfos.begin();
    foreach(Player *p, *players){
        (*it)->setScore(p->getScore());
        it++;
    }
}

//void GameWindow::addPlayerToScoreTab(const Player *p){

//}

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
//    foreach(PlayerInfoWidget* p, playersInfos){
//        p->paintEvent(e);
//    }
}

GameWindow::~GameWindow(){

}

