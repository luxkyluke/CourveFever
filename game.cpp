#include <iostream>
#include <QTimer>
#include <QDebug>
#include <ctime>

#include "game.h"
#include "biggerbonus.h"
#include "cleanbonus.h"
#include "speedbonus.h"


using namespace std;

const static int FRAME_DURATION = 17;
const static int BONUS_CREATION_INTERVAL = 7000;
const static int PREPARATION_DURATION = 5000;
static const int WIDTH = 800;
static const int HEIGHT = 800;

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

    gameTimer = new QTimer(this);
    QObject::connect(gameTimer, SIGNAL(timeout()), this, SLOT(refresh()));
    gameTimer->start(FRAME_DURATION);

    bonusTimer = new QTimer(this);
    QObject::connect(bonusTimer, SIGNAL(timeout()), this, SLOT(createRandomBonus()));
    bonusTimer->start(BONUS_CREATION_INTERVAL);

    window->show();
    preparationTimer = clock();
}

void Game::createRandomBonus(){
    int nbRand = rand() %3;
    if(players.size()<2)
        nbRand = rand() %2;
    Bonus *b;
    switch(nbRand){
       case 0:
        b = new SpeedBonus(WIDTH, HEIGHT);
        break;
       case 1:
        b = new CleanBonus(WIDTH, HEIGHT);
        break;
       case 2:
        b = new BiggerBonus(WIDTH, HEIGHT);
        break;
       default :
        b = new SpeedBonus(WIDTH, HEIGHT);
        break;
    }
    addBonus(b);

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

bool Game::isPreparationTime(){
    return !((clock()-preparationTimer) > PREPARATION_DURATION);
}

int Game::getRemainingPrepTime(){
    return (int)(PREPARATION_DURATION - (clock()-preparationTimer));
}

void Game::updateScene(){
    if(isPreparationTime()){
        window->displayRemainingTime(getRemainingPrepTime());
        return;
    }
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
}

void Game::killPlayer(Player* dead){
    foreach(Player *p, players){
        if((*p)!=(*dead))
            p->increaseScore();
    }
    dead->kill();
    nbLivingPlayers--;
}

bool Game::isInTouch(Bonus* b, Player *p){
    Vector2D distance = Vector2D(b->getPosition(), p->getPosition());
    float radiusLenght = (b->getRadius()*b->getRadius())
            + (p->getRadius()*p->getRadius());
    if(distance.sqrNorm() > radiusLenght*2)
        return false;
    return true;
}

Bonus* Game::getBonus(QColor c, Player*p){
    foreach(Bonus *b, bonus){
        if(b->getColor() == c){
            if(isInTouch(b, p))
                return b;
        }

    }
    throw std::invalid_argument("Is not a bonus color");
}

void Game::checkCollision(){
    foreach(Player* p, players){
        if(!p->getIsLiving() )
            continue;
        QColor c;
        if(terrain->isInCollision(p, &c)){
            //if there are multiplayers, a player can't be killed by himself
            if(p->isMyColor(c)&& players.size()>1)
                return;
            //if there is only one player he can be killed by himself
            if(terrain->isBordersColor(c) || (players.size()<2 && p->isMyColor(c))){
                killPlayer(p);
                continue;
            }
            else if(Bonus::isBonusColor(c)){
                try{
                   Bonus *b = getBonus(c, p);
                   if(b->getType() == COMMUN){
                        terrain->clear();
                        b->erase();
                   }else if(b->getType() == BAD){
                       if(players.size()>1){
                           foreach(Player *player, players){
                               if(player == p)
                                   continue;
                               b->apply(player);
                               terrain->paint();
                               b->erase();
                           }
                       }
                   }
                   else{
                       b->apply(p);
                       terrain->paint();
                       b->erase();
                   }
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

int Game::getIdwinner(){
    int idWinner = 0;
    for(int i=1; i<players.size(); i++){
        if(players.at(i)->getScore() > players.at(idWinner)->getScore())
            idWinner = i;
    }
    return idWinner;
}

void Game::refresh(){
    if(nbLivingPlayers>1 || (players.size() == 1 && nbLivingPlayers>0)){
        updateScene();
        checkCollision();
    }
    else{
        window->theEnd(getIdwinner());
        end();
    }
    window->updateScores();
}

void Game::end(){
    gameTimer->stop();
    bonusTimer->stop();
}

bool Game::eventFilter(QObject *object, QEvent *event){
     if(event->type() == QEvent::Close){
        if(gameTimer->isActive())
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
    delete(gameTimer);
    gameTimer = NULL;

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
