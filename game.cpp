#include <iostream>
#include <QTimer>
#include <iostream>
#include <iostream>
#include <QDebug>

#include "game.h"
#include "biggerbonus.h"


using namespace std;

const static int FRAME_DURATION = 17;
static const int WIDTH = 800;
static const int HEIGHT = 800;


//Game::Game(): terrain(),
//    window(){

//}

Game::Game(){

}

Game::Game(QVector<Player *> &_players) :
        terrain(this, WIDTH, HEIGHT){
    nbLivingPlayers = 0;

    //Player *p1= new Player("michel", Qt::Key_Right, Qt::Key_Left);


    //addPlayer(p1);
    players = _players;


    nbLivingPlayers = players.size();
    cout<<"nb players = "<<nbLivingPlayers<<endl;

    foreach(Player* p, players){
        qDebug()<<p->getPseudo() << " " << p->getPosition();
    }

    window = new GameWindow(WIDTH, HEIGHT, &players);
    window->installEventFilter(this);

    //terrain.setParent(window);
    window->setCanvas(&terrain);

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(FRAME_DURATION);


    addBonus(new BiggerBonus(WIDTH, HEIGHT));

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
    throw std::invalid_argument("Is not a player color");
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

void Game::addBonus(Bonus *b){
    bonus.append(b);
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
                cout << e.what() << endl;
                exit(EXIT_FAILURE);
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
        timer->stop();
//        exit(0);
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

void Game::play(){
    window->show();
}

bool Game::isSafePosition(QPointF pos){
    return true;
}
