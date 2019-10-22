#include "ogro.h"

Ogro::Ogro(QGraphicsItem * parent)
{
    QPixmap *ogr = new QPixmap(":/images/ogro1.png");
    setPixmap(ogr->scaled(50,50,Qt::KeepAspectRatio));
}

void Ogro::move()
{
    setPos(x()+1,y()+1);
}
