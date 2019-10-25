#include "ogro.h"
#include <QTimer>

Ogro::Ogro(QGraphicsItem * parent)
{
    setHealth(70);
    QPixmap *ogr = new QPixmap(":/images/ogrebits.png");
    STEP_SIZE = 0.5;
    setPixmap(ogr->scaled(50,50,Qt::KeepAspectRatio));

    point_index = 0;
}
