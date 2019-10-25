#include "harpia.h"

Harpia::Harpia(QGraphicsItem * parent)
{
    setHealth(30);
    QPixmap *elfo = new QPixmap(":/images/arpy.png");
    STEP_SIZE = 1;
    setPixmap(elfo->scaled(50,50,Qt::KeepAspectRatio));

    point_index = 0;
}
