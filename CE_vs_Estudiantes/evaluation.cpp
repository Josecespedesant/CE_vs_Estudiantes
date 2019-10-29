#include "evaluation.h"
#include <QTimer>
#include <qmath.h>

Evaluation::Evaluation(QGraphicsItem *parent, QLabel * contMuertes)
{


    setMaxRange(400);

    setPixmap(QPixmap());

    QTimer *move_timer = new QTimer(this);
    connect(move_timer, SIGNAL(timeout()), this, SLOT(move()));
    move_timer->start(50);

    maxRange = 100;
    distaneTravelled = 0;
    contadorDisparoEspecial = 0;
    this->contMuertes = contMuertes;
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

void Evaluation::setCurso(Curso *curso)
{
    this->curso = curso;
}

void Evaluation::move(){




    double damageDealt = (curso->getCantCreditos()+curso->getCantHorasReales()+curso->getNivelExigencia())/2;
    double totalDamage;

    if(this->objectName().toStdString().compare("Arch")==0){
        totalDamage = damageDealt - estudianteObjetivo->getArcherResistance();
    }
    if(this->objectName().toStdString().compare("Arty")==0){
        totalDamage = damageDealt - estudianteObjetivo->getArtilleryResistance();
    }
    if(this->objectName().toStdString().compare("Mago")==0){
        totalDamage = damageDealt - estudianteObjetivo->getMageResistance();
    }
    if(this->objectName().toStdString().compare("Fire")==0){
        totalDamage = damageDealt - estudianteObjetivo->getFireResistance();
    }


    if(contadorDisparoEspecial < 10){
        totalDamage = totalDamage-1;
        QPixmap *pix = new QPixmap(":/images/normalshot2.png");
        setPixmap(pix->scaled(21,21,Qt::KeepAspectRatio));
    }

    if(contadorDisparoEspecial >= 10){
        totalDamage = totalDamage+1;
        QPixmap *pix = new QPixmap(":/images/questionmark.png");
        setPixmap(pix->scaled(21,21,Qt::KeepAspectRatio));
    }


    int STEP_SIZE;

    if(this->objectName().toStdString().compare("Arch")==0){
        STEP_SIZE = 25;
    }

    if(this->objectName().toStdString().compare("Arty")==0){
        STEP_SIZE = 20;
    }

    if(this->objectName().toStdString().compare("Mago")==0){
        STEP_SIZE = 15;
    }
    if(this->objectName().toStdString().compare("Fire")==0){
        STEP_SIZE = 10;
    }



    double theta = rotation(); //degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx,y()+dy);


    if(this->collidesWithItem(estudianteObjetivo)){
        estudianteObjetivo->setHealth(estudianteObjetivo->getHealth()-totalDamage);

        if(estudianteObjetivo->getHealth()<=0 && estudianteObjetivo->scene()!=NULL){
            grid->scene->removeItem(estudianteObjetivo);
            this->setVisible(false);

            contMuertes->setText(QString::number(++grid->F));
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
