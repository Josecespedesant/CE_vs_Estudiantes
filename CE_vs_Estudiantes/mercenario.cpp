#include "mercenario.h"

Mercenario::Mercenario(QGraphicsItem * parent)
{
    setHealth(60);
    QPixmap *merc = new QPixmap(":/images/mercenary.png");
    STEP_SIZE = 2.5;
    setPixmap(merc->scaled(50,50,Qt::KeepAspectRatio));

    setArcherResistance(1);
    setMageResistance(1);
    setFireResistance(0);
    setArtilleryResistance(1);
    point_index = 0;

}
