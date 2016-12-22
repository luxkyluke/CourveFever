#include "speedbonus.h"

const static float SPEED = 1.5;

SpeedBonus::SpeedBonus(int w, int h): Bonus(w, h, GOOD){

}

void SpeedBonus::apply(Player *p){
    p->accelerate(SPEED);
    Bonus::setPlayer(p);
    Bonus::setTimer(clock());
    Bonus::action();
}

void SpeedBonus::cancel(){
    if(!player)
        return;
    player->accelerate(-SPEED);
    Bonus::stop();
}
