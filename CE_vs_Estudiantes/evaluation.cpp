#include "evaluation.h"
#include <QTimer>
#include <qmath.h>
Evaluation::Evaluation(QGraphicsItem *parent)
{
    QPixmap *pix = new QPixmap(":/images/questionmark.png");

    setPixmap(pix->scaled(15,15,Qt::KeepAspectRatio));

    QTimer *move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);
}

void Evaluation::move(){
    int STEP_SIZE = 30;
    double theta = rotation(); //degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);

}
