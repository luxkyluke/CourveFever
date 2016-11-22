#include "game.h"
#include <iostream>
#include <QTimer>
#include <iostream>
#include <iostream>

using namespace std;

const static int FRAME_DURATION = 17;

Game::Game(): terrain(),
    window(){

}

Game::Game(const int w, const int h, Player* p1): terrain(w, h),
     window(this){

    //w.installEventFilter(Game);

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(FRAME_DURATION);

    players.append(p1);
    window.show();
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

void Game::updateScene(){
    foreach(Player* p, players){
        p->moov();
        //std::cout<<p.getPosition().x() << " " <<p.getPosition().y()<<std::endl;
        //updateTerrain(p.id(), p.position());
    }
}

void Game::draw(QPainter *painter, QGLWidget &window){
    foreach (Player* p, players) {
        p->drawItem(painter, window);
    }
}

int Game::getWidth(){
    return terrain.getWidth();
}

int Game::getHeight(){
    return terrain.getHeight();
}


void Game::refresh(){
    updateScene();
    window.repaintRenderer();
    terrain.update(window.getRenderer());

}

//bool FilterObject::eventFilter(QObject *object, QEvent *event){
//    if (object == target && event->type() == QEvent::KeyPress) {
//        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
//        if (keyEvent->key() == Qt::Key_Tab) {
//            // Special tab handling
//            std::cout<<"samarche"<<std::endl;
//            return true;
//        } else
//            return false;
//    }
//    return false;
//}
