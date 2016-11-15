#include "game.h"
#include <iostream>

Game::Game(){

}

Game::Game(const int w, const int h, Player &p1): terrain(w, h){
//    Mainwindow w(w, h);
//    w.installEventFilter(Game);
    players.append(p1);
}

void Game::addPlayer(Player &p){
    players.append(p);
}

//void Game::play(){
//    w.show();
//}

bool Game::keyPressed(int key){
    switch (key) {
        case Qt::Key_Up:
            //act on 'X'
            break;
        case Qt::Key_Y:
            //act on 'Y'
            break;
        default:
            return false;
    }
    return true;
}

void Game::draw(QPainter &painter, QGLWidget &window){
    foreach (Player p, players) {
        p.drawItem(painter, window);
    }
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
