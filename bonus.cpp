#include "bonus.h"
#include "terrain.h"
#include <ctime>
#include <stdlib.h>

const float Bonus::radius=20.;

Bonus::Bonus(){

}

Bonus::Bonus(int w, int h, QColor color){
    srand(time(NULL));
    int x = rand() %w;
    int y = rand() %h;
    QPointF pos(50.1, 150.);
    //QPointF pos = Terrain::getCoordInLandmarkDim(QPoint(x, y));
    Circle(radius, pos, color);
}

