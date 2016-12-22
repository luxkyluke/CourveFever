#include "bonus.h"
#include "terrain.h"
#include <ctime>
#include <stdlib.h>

const float Bonus::radius=20.;
const int Bonus::duration = 5000;

const QMap<bonusType, QColor> Bonus::bonusColorRelation = Bonus::createRelationMap();


Bonus::Bonus(){

}

Bonus::Bonus(int w, int h, bonusType type) : Circle(radius, Bonus::getRandPos(w, h), bonusColorRelation[type]){
    timer =0;
    player = NULL;
    inAction = false;
    erased = false;
    this->type = type;
}

bool Bonus::isInAction() const{
    return inAction;
}

void Bonus::erase(){
    erased = true;
}

bool Bonus::isErased() const{
    return erased;
}

Bonus::~Bonus(){

}

void Bonus::setPlayer(Player *p){player = p;}

void Bonus::setTimer(int t){timer = t;}

void Bonus::action(){
    Circle::setColor(Qt::black);
    inAction = true;
}

void Bonus::stop(){
    inAction = false;
}

QColor Bonus::getColor(){
    return Circle::getColor();
}

void Bonus::checkTimeout(){
    if(clock()-timer > Bonus::duration)
        cancel();
}

QPointF Bonus::getRandPos(int w, int h){
    int newW = w-(radius*4);
    int newH = h-(radius*4);
    int x = rand() %newW + (int)(radius*2) ;
    int y = rand() %newH + (int)(radius*2) ;
    QPoint p = QPoint(x, y);
    QPointF pos = Terrain::getCoordInLandmarkDim(p, w, h);
    return pos;
}

bool Bonus::isBonusColor(QColor c){
    return c == Bonus::bonusColorRelation[GOOD]
            || c == Bonus::bonusColorRelation[BAD]
            || c == Bonus::bonusColorRelation[COMMUN];
}

bonusType Bonus::getType(QColor c){
    return Bonus::bonusColorRelation.key(c);
}

bonusType Bonus::getType(){
    return type;
}

