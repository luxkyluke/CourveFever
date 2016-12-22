#include "cleanbonus.h"


CleanBonus::CleanBonus(int w, int h): Bonus(w, h, COMMUN){

}

void CleanBonus::apply(Player *p){
    Bonus::stop();
}

void CleanBonus::cancel(){

}
