#include "player.h"
#include <QApplication>
//#include "terrain.h"
#include "game.h"
#include "menu.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    MenuWindow m;
    m.show();

    return a.exec();
}
