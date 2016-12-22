#include <iostream>
#include <QTimer>
#include <QDebug>
#include <ctime>

#include "game.h"
#include "biggerbonus.h"
#include "cleanbonus.h"


using namespace std;

const static int FRAME_DURATION = 17;
static const int WIDTH = 800;
static const int HEIGHT = 800;


//Game::Game(): terrain(),
//    window(){

//}

Game::Game(){

}

Game::Game(QVector<Player *> &_players){

    players = _players;

    nbLivingPlayers = players.size();
    srand(time(NULL));
    initPlayers();

    terrain = new Terrain(this, WIDTH, HEIGHT);

    window = new GameWindow(WIDTH, HEIGHT, &players, this);
    window->installEventFilter(this);
    window->setCanvas(terrain);

    Bonus *b = new BiggerBonus(WIDTH, HEIGHT);
    addBonus(b);

    b = new CleanBonus(WIDTH, HEIGHT);
    addBonus(b);

    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(refresh()));
    timer->start(FRAME_DURATION);
    window->show();
}


bool Game::isNextToSth(Player *player){
    foreach(Player* p, players){
        if(p == player)
            continue;
        if(p->isNextTo(player)){
            return true;
        }
    }
    return false;
}

bool Game::colorAlreadyExist(QColor c){
    foreach(Player* p, players){
        if(p->hasSameColor(c))
            return true;
    }
    return false;
}

void Game::initPlayers(){
    foreach(Player* p, players){
        do{
            p->setPosition(Player::getRandPos());
        }while(isNextToSth(p));
        QColor c;
        do{
            c= Player::getRandColor();
        } while(colorAlreadyExist(c));
        p->setColor(c);
    }
}


void Game::addPlayer(Player *p){
    players.append(p);
    nbLivingPlayers ++;
}

//determiner quel touche appartienne a quelle joueur
bool Game::keyEvent(QKeyEvent* event){

    foreach(Player* p, players){
        p->checkKey(event);
    }
    return true;
}

Terrain* Game::getTerrain(){
    return terrain;
}

void Game::updateScene(){
    foreach(Player* p, players){
        p->moov();
    }
    for(int i=0; i<bonus.length(); i++){
        Bonus *b= bonus.at(i);
        if(b->isErased() && !b->isInAction())
            bonus.remove(i);
        if(b->isInAction())
            b->checkTimeout();
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
    foreach(Bonus* b, bonus){
        if(b->isErased())
            continue;
        b->drawItem(painter);
    }
    foreach (Player* p, players) {
        p->drawItem(painter);
    }
}

int Game::getWidth() const{
    return terrain->getWidth();
}

int Game::getHeight() const{
    return terrain->getHeight();
}

void Game::addBonus(Bonus *b){
    bonus.append(b);
    cout<<"bonus ajouté : "<<b->getColor().name().toStdString()<<endl;
}

void Game::killPlayer(Player* dead){
    foreach(Player *p, players){
        if((*p)!=(*dead))
            p->increaseScore();
    }
    dead->kill();
    nbLivingPlayers--;
}

Bonus* Game::getBonus(QColor c){
    foreach(Bonus *b, bonus){
        if(b->getColor() == c)
            return b;
    }
    throw std::invalid_argument("Is not a bonus color");
}

void Game::checkCollision(){
    foreach(Player* p, players){

        if(!p->getIsLiving())
            continue;
        QColor c;
        if(terrain->isInCollision(p, &c)){
            cout << "couleur " << c.red() << " "<< c.green() << " "<< c.blue() <<endl;
            if(p->isMyColor(c))
                return;
            if(terrain->isBordersColor(c) /*|| p->isMyColor(c)*/){
                killPlayer(p);
                continue;
            }
            else if(Bonus::isBonusColor(c)){
                try{
                   Bonus *b = getBonus(c);
                   if(b->getType() == COMMUN){
                        terrain->clear();
                   }else{
                       b->apply(p);
                       terrain->paint();
                   }
                   b->erase();
                   //verifier si on l'applique au player ou a tous
                }catch(exception& e){
                    cerr << e.what() << endl;
                    exit(EXIT_FAILURE);
                }
            }
            else{
                try{
                    Player killer = getPlayer(c);
                    killer.increaseScore();
                    killPlayer(p);
                }catch(exception& e){
                    cerr << e.what() << endl;
                    exit(EXIT_FAILURE);
                }
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
        cout<<"Tous le monde est mort"<<endl;
        window->theEnd();
        end();
//        exit(0);
    }
    window->updateScores();
}

void Game::end(){
    cout << "FIN DU GAME"<<endl;
    timer->stop();
}



bool Game::eventFilter(QObject *object, QEvent *event){
     if(event->type() == QEvent::Close){
        end();
     }
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

Game::~Game(){
    foreach(Player *p, players){
        delete(p);
        p=NULL;
    }
    foreach(Bonus *b, bonus){
        delete(b);
        b=NULL;

    }
    delete(timer);
    timer = NULL;

    delete(terrain);
    terrain = NULL;
    delete(window);
    window =NULL;
}

void Game::on_clickQuitButton(){
    window->close();
    delete(this);
    exit(0);
}

void Game::on_clickRestartButton(){
    window->close();
}
