#include "player.h"
#include <QApplication>
//#include "terrain.h"
#include "game.h"
#include "menu.h"

static const int GAME_WIDTH = 800;
static const int GAME_HEIGHT = 800;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Game g (GAME_WIDTH, GAME_HEIGHT, &p);
    //g.play();
    MenuWindow m;
    m.show();


//    Terrain t(9, 9);
//    t.print();

    return a.exec();
}
