#include "parcela.h"
#include "iostream"
#include <typeinfo>
#include "evaluation.h"
#include <QTimer>
#include "Estudiante.h"
#include <QLineF>
extern Grid *grid;

Parcela::Parcela(QGraphicsItem *parent):QPushButton(), QGraphicsPixmapItem(parent)
{
    fire = nullptr;
    gunner = nullptr;
    arch = nullptr;
    mago = nullptr;
    setPixmap(QPixmap());

}

double Parcela::distanceTo(QGraphicsItem *item)
{
    QPointF a = item->pos();
    QPointF b = this->QGraphicsItem::pos();
    QLineF line(b, a);
    return line.length();

}

bool Parcela::isOcupada(){
    return this->ocupada;
}

void Parcela::setOcupada(bool isocupada){
    this->ocupada = isocupada;
}

void Parcela::setType(QString tipo){
    QTimer * timer = new QTimer();
    if(tipo.toStdString().compare("Archer") == 0){

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        arch = new Arquero();
        arch->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("Gunner") == 0){

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        gunner = new Artillero();
        gunner->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("Mage") == 0){

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        mago = new Mago();
        mago->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("Fire") == 0){

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        fire = new LanzaFuego();
        fire->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("") == 0){
        timer->stop();
        disconnect(timer, SIGNAL(timeout()), this, SLOT(adquire_target()));
        timer->stop();
        if(this->objectName().toStdString().compare("Arch") == 0){
            arch->setNivelActual(0);
        }
        else if(this->objectName().toStdString().compare("Arty") == 0){

            gunner->setNivelActual(0);
         }
        else if(this->objectName().toStdString().compare("Mago") == 0){
            mago->setNivelActual(0);
        }
        else if(this->objectName().toStdString().compare("Fire") == 0){
            fire->setNivelActual(0);
        }
    }

}

void Parcela::attack_target()
{

    Evaluation *evaluation = new Evaluation();
    evaluation->setPos(this->geometry().x(),this->geometry().y());
    evaluation->setPos(this->geometry().x(),this->geometry().y());
    QLineF line(QPointF(this->geometry().x(),this->geometry().y()),attack_dest);
    int angle = -1 * line.angle();
    evaluation->setRotation(angle);

    grid->scene->addItem(evaluation);

}

void Parcela::adquire_target()
{
    QList<QGraphicsItem *> collidin_items = this->collidingItems();

    if(collidin_items.size() == 1){
        has_target = false;
        return;
    }
    double closest_dist = 300;
    QPointF closest_pt = QPoint(0,0);
    for(size_t i=0, n = collidin_items.size(); i<n; i++){
        Estudiante * estudiante = dynamic_cast<Estudiante *>(collidin_items[i]);
        if(estudiante){
            double this_dist=distanceTo(estudiante);
            if(this_dist<closest_dist){
                closest_dist = this_dist;
                closest_pt = collidin_items[i]->pos();
                has_target = true;
                //Testear esto con Victoria
                attack_dest = closest_pt;
                attack_target();
            }
        }
    }

}

Arquero* Parcela::getArquero(){
    return this->arch;
}

Artillero* Parcela::getArtillero(){
    return this->gunner;
}

Mago* Parcela::getMago(){
    return this->mago;
}

LanzaFuego* Parcela::getLanzaFuego(){
    return this->fire;
}
