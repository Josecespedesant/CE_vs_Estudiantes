#include "elfo_oscuro.h"

Elfo_oscuro::Elfo_oscuro(QGraphicsItem * parent)
{
    setHealth(40);
    QPixmap *elfo = new QPixmap(":/images/darkelve.png");
    STEP_SIZE = 1.5;
    setPixmap(elfo->scaled(50,50,Qt::KeepAspectRatio));
    llego = false;
    setArcherResistance(1);
    setMageResistance(1);
    setFireResistance(0);
    setArtilleryResistance(0);
    point_index = 0;


}
