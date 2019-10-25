#include "ogro.h"
#include <QTimer>

Ogro::Ogro(QGraphicsItem * parent)
{
    setHealth(70);

    //QPixmap *ogr = new QPixmap(":/images/ogro1.png");


    STEP_SIZE = 1.5;
    setPixmap(ogr->scaled(54,54,Qt::KeepAspectRatio));
    points.append(QPointF(469,570));
    points.append(QPointF(470,512));
    points.append(QPointF(410,460));
    points.append(QPointF(351,407));
    points.append(QPointF(355,359));
    points.append(QPointF(364,186));
    points.append(QPointF(418,133));
    points.append(QPointF(416,82));
    points.append(QPointF(350,33));
    point_index = 0;
    setPos(points[0]);
    dest = points[1];
    rotateToPoint(dest);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}
