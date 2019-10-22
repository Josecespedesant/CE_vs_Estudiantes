#include "ogro.h"

Ogro::Ogro(QGraphicsPixmapItem * parent)
{
 QPixmap *ogr = new QPixmap(":/images/ogro1.png");
 setPixmap(ogr->scaled(50,50,Qt::KeepAspectRatio));
}
