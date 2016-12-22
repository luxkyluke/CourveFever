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
const static int MENU_TAB_HEIGHT = 25;

GameWindow::GameWindow(const int w, const int h,
                QVector<Player *> *p, Game* game, QWidget *parent):
                QMainWindow(parent){
    this->resize(w+SCORE_LABEL_WIDTH, h);

    terrainLabel =new QLabel("terrain");
    scoreWidget = new QWidget();
    title = new QLabel("scores", scoreWidget);

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

    QWidget* mainWidget = new QWidget();
    this->setCentralWidget(mainWidget);
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainWidget->setLayout(mainLayout);
    mainLayout->addWidget(scoreWidget);
    mainLayout->addWidget(terrainLabel);
    terrainCanva = NULL;

    //Overlay for the timer in the beginning
    preGameOverlay = new QWidget(terrainLabel);
    preGameOverlay->resize(w, h);
    preGameOverlay->setStyleSheet("background-color : rgba(200, 200, 200, 0.3)");
    remainingTime = new QLabel("100", preGameOverlay);
    remainingTime->setStyleSheet("color : #fff; font-size: 50px; background-color : rgba(0,0, 0, 0)");
    remainingTime->setGeometry(QRect(390, 375, 50, 50));
    preGameOverlay->setVisible(true);


    //Overlay for the end of the game
    terrainOverlay = new QWidget(terrainLabel);
    terrainOverlay->resize(w, h);
    terrainOverlay->setStyleSheet("background-color : rgba(200, 200, 200, 0.3)");
    terrainOverlay->setVisible(false);
    QPushButton *restartButton = new QPushButton("Play Again", terrainOverlay);
    restartButton->setStyleSheet("background-color: #757575; "
                                 "color : #fff; "
                                 "font-size: 35px; ");
    restartButton->setGeometry(QRect(150, 350, 200, 75));
    QObject::connect(restartButton, SIGNAL(clicked(bool)), game, SLOT(on_clickRestartButton()));
    QPushButton *quitButton = new QPushButton("Quit", terrainOverlay);
    quitButton->setStyleSheet("background-color: #757575; "
                              "color : #fff; "
                              "font-size: 35px; ");
    quitButton->setGeometry(QRect(450, 350, 200, 75));
    QObject::connect(quitButton, SIGNAL(clicked(bool)), game, SLOT(on_clickQuitButton()));
}


void GameWindow::setCanvas(Terrain* t){
    terrainCanva = t;
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


void GameWindow::paintEvent(QPaintEvent *e){
    if(terrainCanva == NULL){
        std::cerr << "Cannot paint window's canvas, null pointeur exception"<<std::endl;
        exit(EXIT_FAILURE);
    }
    terrainCanva->paintEvent(e);
    terrainLabel->setPixmap(terrainCanva->getPic());
}

GameWindow::~GameWindow(){
    delete (title);
    title = NULL;
    delete(terrainLabel);
    terrainLabel =NULL;
    foreach(PlayerInfoWidget *p, playersInfos){
        free(p);
        p = NULL;
    }
    free(scoreWidget);
    scoreWidget = NULL;
    free(terrainOverlay);
    terrainOverlay = NULL;
}

void GameWindow::displayRemainingTime(int time){
    int displayTime = time*0.001 + 1;
    if((time-100)>0)
        remainingTime->setText(QString::number(displayTime));
    else
        preGameOverlay->setVisible(false);
}

void GameWindow::theEnd(){
    terrainOverlay->setVisible(true);
}


