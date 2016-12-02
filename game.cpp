#include "game.h"
#include <iostream>
#include <QTimer>
#include <iostream>
#include <iostream>

using namespace std;

const static int FRAME_DURATION = 17;

//Game::Game(): terrain(),
//    window(){

//}

Game::Game(const int w, const int h, Player* p1) :
        terrain(this, w, h){

    MainWindow* window = new MainWindow(w, h);
    window->installEventFilter(this);

    //terrain.setParent(window);
    window->setCanvas(&terrain);

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(FRAME_DURATION);

    players.append(p1);
    window->show();
}

void Game::addPlayer(Player *p){
    players.append(p);
}

//void Game::play(){

//}


//determiner quel touche appartienne a quelle joueur
bool Game::keyEvent(QKeyEvent* event){

    foreach(Player* p, players){
        p->checkKey(event);
    }
    return true;
}

Terrain* Game::getTerrain(){
    return &terrain;
}

void Game::updateScene(){
    foreach(Player* p, players){
        p->moov();
        //std::cout<<p.getPosition().x() << " " <<p.getPosition().y()<<std::endl;
        //updateTerrain(p.id(), p.position());
    }
}

void Game::draw(QPainter *painter)const{
    foreach (Player* p, players) {
        p->drawItem(painter);
    }
}

int Game::getWidth() const{
    return terrain.getWidth();
}

int Game::getHeight() const{
    return terrain.getHeight();
}


void Game::refresh(){
    updateScene();
    //window.repaintRenderer();
    //terrain.update();
    foreach(Player* p, players){
        terrain.checkCollisions(p);
    }
}

bool Game::eventFilter(QObject *object, QEvent *event){

    if(event->type() == QEvent::KeyPress){
        QKeyEvent *kEvent = static_cast<QKeyEvent *>(event);
        keyEvent(kEvent);
        return true;
    }
    if(event->type() == QEvent::KeyRelease){
        QKeyEvent *kEvent = static_cast<QKeyEvent *>(event);
        keyEvent(kEvent);
        return true;
    }
    return false;
}
