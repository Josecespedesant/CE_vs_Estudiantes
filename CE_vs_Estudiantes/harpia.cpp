#include "harpia.h"

Harpia::Harpia(QGraphicsItem * parent)
{
    setHealth(30);
    QPixmap *elfo = new QPixmap(":/images/arpy.png");
    STEP_SIZE = 1.5;
    llego = false;
    setPixmap(elfo->scaled(50,50,Qt::KeepAspectRatio));
    setArcherResistance(1000000);
    setMageResistance(1000000);
    setFireResistance(0);
    setArtilleryResistance(0);
    point_index = 0;
}
