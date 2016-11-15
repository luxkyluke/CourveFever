#include "mainwindow.h"
#include <QApplication>
#include "terrain.h"

static const int GAME_WIDTH = 800;
static const int GAME_HEIGHT = 800;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //g.play();
    MainWindow w;
    w.show();


//    Terrain t(9, 9);
//    t.print();

    return a.exec();
}
