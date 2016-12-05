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
    nbLivingPlayers = 0;

    MainWindow* window = new MainWindow(w, h);
    window->installEventFilter(this);

    //terrain.setParent(window);
    window->setCanvas(&terrain);

    QTimer* timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(FRAME_DURATION);

    addPlayer(p1);
    window->show();
}

void Game::addPlayer(Player *p){
    players.append(p);
    nbLivingPlayers ++;
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
    }
}

Player &Game::getPlayer(QColor c){
    foreach (Player* p, players) {
        if(p->isMyColor(c))
            return *p;
    }
    throw ;
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

void Game::checkCollision(){
    foreach(Player* p, players){
        if(!p->getIsLiving())
            continue;
        QColor c;
        if(terrain.isInCollision(p, &c)){
            cout << "couleur " << c.red() << " "<< c.green() << " "<< c.blue() <<endl;
            if(terrain.isBordersColor(c) || p->isMyColor(c)){
                p->kill();
                nbLivingPlayers--;
                continue;
            }
            try{
                Player killer = getPlayer(c);
                killer.increaseScore();
            }catch(exception& e){
                cout << "Is not a player color" << endl;
            }

        }
    }
}

void Game::refresh(){
    if(nbLivingPlayers>0){
        updateScene();
        checkCollision();
    }
    else{
        cout << "C'EST LA FIN"<<endl;
        exit(0);
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
