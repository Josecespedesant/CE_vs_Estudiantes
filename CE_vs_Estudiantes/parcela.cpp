#include "parcela.h"
#include "iostream"
#include <typeinfo>
#include "evaluation.h"
#include <QTimer>
#include "Estudiante.h"
#include <QLineF>
#include "QLine"
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

        QVector<QPointF> points;

        //Crear el cuadrado donde disparará.
        points.append(QPointF(this->geometry().x()-54,this->geometry().y()-54));
        points.append(QPointF(this->geometry().x()+108,this->geometry().y()-54));
        points.append(QPointF(this->geometry().x()+108,this->geometry().y()+108));
        points.append(QPointF(this->geometry().x()-54,this->geometry().y()+108));

        truesquare = new QGraphicsPolygonItem(QPolygonF(points),this);
        truesquare->setZValue(1);

        truesquare->setVisible(false);
        grid->scene->addItem(truesquare);

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        arch = new Arquero();
        arch->setNivelActual(1);
        timer->start(500);


    }
    else if(tipo.toStdString().compare("Gunner") == 0){

        QVector<QPointF> points;

        //Crear el cuadrado donde disparará.
        points.append(QPointF(this->geometry().x()-54*2,this->geometry().y()-54*2));
        points.append(QPointF(this->geometry().x()+162,this->geometry().y()-54*2));
        points.append(QPointF(this->geometry().x()+162,this->geometry().y()+162));
        points.append(QPointF(this->geometry().x()-54*2,this->geometry().y()+162));

        truesquare = new QGraphicsPolygonItem(QPolygonF(points),this);
        truesquare->setZValue(1);

        truesquare->setVisible(false);
        grid->scene->addItem(truesquare);


        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        gunner = new Artillero();
        gunner->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("Mage") == 0){

        QVector<QPointF> points;

        //Crear el cuadrado donde disparará.
        points.append(QPointF(this->geometry().x()-54*2,this->geometry().y()-54*2));
        points.append(QPointF(this->geometry().x()+162,this->geometry().y()-54*2));
        points.append(QPointF(this->geometry().x()+162,this->geometry().y()+162));
        points.append(QPointF(this->geometry().x()-54*2,this->geometry().y()+162));

        truesquare = new QGraphicsPolygonItem(QPolygonF(points),this);
        truesquare->setZValue(1);

        truesquare->setVisible(false);
        grid->scene->addItem(truesquare);

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        mago = new Mago();
        mago->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("Fire") == 0){

        QVector<QPointF> points;

        //Crear el cuadrado donde disparará.
        points.append(QPointF(this->geometry().x()-54*3,this->geometry().y()-54*3));
        points.append(QPointF(this->geometry().x()+216,this->geometry().y()-54*3));
        points.append(QPointF(this->geometry().x()+216,this->geometry().y()+216));
        points.append(QPointF(this->geometry().x()-54*3,this->geometry().y()+216));

        truesquare = new QGraphicsPolygonItem(QPolygonF(points),this);
        truesquare->setZValue(1);

        truesquare->setVisible(false);
        grid->scene->addItem(truesquare);

        connect(timer, SIGNAL(timeout()),this,SLOT(adquire_target()));
        fire = new LanzaFuego();
        fire->setNivelActual(1);
        timer->start(1000);
    }
    else if(tipo.toStdString().compare("") == 0){
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

void Parcela::attack_target(Estudiante * estudiante)
{
    std::cout<<estudiante->getHealth()<<std::endl;

    Evaluation *evaluation = new Evaluation();
    evaluation->setGrid(grid);

    if(this->objectName().toStdString().compare("Arch")==0){
        evaluation->setObjectName("Arch");
    }
    if(this->objectName().toStdString().compare("Arty") == 0){
        evaluation->setObjectName("Arty");
    }
    if(this->objectName().toStdString().compare("Mago")==0){
        evaluation->setObjectName("Mago");
    }

    evaluation->setPos(this->geometry().x()+34,this->geometry().y()+27);

    QPointF *positionOfEnemy = new QPointF(attack_dest.rx()+25,attack_dest.ry());

    QLineF line(QPointF(this->geometry().x()+27,this->geometry().y()+27), *positionOfEnemy);
    //grid->scene->addLine(line);
    evaluation->setEstudianteObjetivo(estudiante);

    int angle = -1 * line.angle();

    //std::cout<<-1*line.angle()<<std::endl;
    evaluation->setRotation(angle);

    grid->scene->addItem(evaluation);

}

void Parcela::adquire_target()
{
    QList<QGraphicsItem *> collidin_items = truesquare->collidingItems();

    int numOfParcelas = 0;
    int numOfCuadrados = 0;

    for(int j=0; j<collidin_items.size(); j++){
        Parcela*parcela = dynamic_cast<Parcela*>(collidin_items[j]);
        if(parcela){
            numOfParcelas++;
        }
        QGraphicsPolygonItem *cuadrado = dynamic_cast<QGraphicsPolygonItem *>(collidin_items[j]);
        if(cuadrado){
            numOfCuadrados++;
        }
    }

    if(collidin_items.size() == numOfParcelas+numOfCuadrados+1){
        has_target = false;
        return;
    }

    double closest_dist = 1000;
    QPointF closest_pt(0,0);

    for(size_t i=0, n = collidin_items.size(); i<n; i++){

        Estudiante * estudiante = dynamic_cast<Estudiante *>(collidin_items[i]);

        if(estudiante){

            double this_dist = distanceTo(estudiante);

            if(this_dist<closest_dist){
                closest_dist = this_dist;
                //closest_pt = estudiante->pos();
                has_target = true;
                //Testear esto con Victoria



            }
            if(has_target){
                QPointF posic(estudiante->pos().rx(),estudiante->pos().ry());
                attack_dest = posic;
                attack_target(estudiante);
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
