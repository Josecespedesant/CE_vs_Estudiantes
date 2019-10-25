#include "elfo_oscuro.h"

Elfo_oscuro::Elfo_oscuro(QGraphicsItem * parent)
{
    setHealth(40);
    QPixmap *elfo = new QPixmap(":/images/darkelve.png");
    STEP_SIZE = 1;
    setPixmap(elfo->scaled(50,50,Qt::KeepAspectRatio));

    point_index = 0;
}
