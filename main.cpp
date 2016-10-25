#include "mainwindow.h"
#include <QApplication>
#include "terrain.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

//    Terrain t(9, 9);
//    t.print();

    return a.exec();
}
