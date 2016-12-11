#include "player.h"
#include <QApplication>
//#include "terrain.h"
#include "game.h"
#include "menu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Game g (GAME_WIDTH, GAME_HEIGHT, &p);
    //g.play();
    MenuWindow m;
    m.show();
    //Play p;

//    Terrain t(9, 9);
//    t.print();

    return a.exec();
}
