#include "evaluation.h"
#include <QTimer>
#include <qmath.h>

Evaluation::Evaluation(QGraphicsItem *parent)
{
    QPixmap *pix = new QPixmap(":/images/questionmark.png");

    setPixmap(pix->scaled(21,21,Qt::KeepAspectRatio));

    QTimer *move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

    maxRange = 100;
    distaneTravelled = 0;

}

double Evaluation::getMaxRange()
{
    return maxRange;
}

double Evaluation::getDistanceTravelled()
{
    return distaneTravelled;
}

void Evaluation::setMaxRange(double rng)
{
    this->maxRange = rng;
}

void Evaluation::setDistanceTravelled(double dist)
{
    this->distaneTravelled = dist;
}

void Evaluation::move(){

    int STEP_SIZE = 15;
    double theta = rotation(); //degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);


    if(this->collidesWithItem(estudianteObjetivo) && this->objectName().toStdString().compare("Arch")==0){
        estudianteObjetivo->setHealth(estudianteObjetivo->getHealth()-0.5);
        if(estudianteObjetivo->getHealth()<=0 && estudianteObjetivo->scene()!=NULL){
            grid->scene->removeItem(estudianteObjetivo);
            this->setVisible(false);
            return;
        }
        this->setVisible(false);
        return;
    }

}

void Evaluation::setEstudianteObjetivo(Estudiante *estudiante)
{
    this->estudianteObjetivo = estudiante;
}

void Evaluation::setGrid(Grid *grid)
{
    this->grid = grid;
}
