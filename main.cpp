#include "player.h"
#include <QApplication>
//#include "terrain.h"
#include "game.h"

static const int GAME_WIDTH = 800;
static const int GAME_HEIGHT = 800;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Player p(Qt::Key_Right, Qt::Key_Left);
    Game g (GAME_WIDTH, GAME_HEIGHT, &p);
    //g.play();
    //MainWindow w;
    //w.show();


//    Terrain t(9, 9);
//    t.print();

    return a.exec();
}
