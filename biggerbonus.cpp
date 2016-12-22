#include "biggerbonus.h"

#include <chrono>
#include <future>
#include <cstdio>

static const float FAT_RADIUS = 5.;

BiggerBonus::BiggerBonus(int w, int h) : Bonus(w, h, BAD){

}

void BiggerBonus::apply(Player *p){
    p->makeBigger(FAT_RADIUS);
    Bonus::setPlayer(p);
    Bonus::setTimer(clock());
    Bonus::action();
}

void BiggerBonus::cancel(){
    if(!player)
        return;
    player->makeSmaller(FAT_RADIUS);
    Bonus::stop();
}
