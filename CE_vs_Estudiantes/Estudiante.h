#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QGraphicsItem>
#include <QObject>
#include <qmath.h>
#include "iostream"
#include <QTimer>
class Estudiante : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
protected:
    int health;
    double speed;
    int archerResistance;
    int artilleryResistance;
    int mageResistance;
    int fireResistance;



    QPointF dest;


    double STEP_SIZE;

public slots:
    void move_forward(){

        QLineF line(pos(),dest);
        if(line.length()<5){
            point_index++;
            if(point_index>=points.size()||dest.y()==0){
                return;
            }
            dest = points[point_index];
            rotateToPoint(dest);
        }

        double theta = rotation();
        double dy = STEP_SIZE*qSin(qDegreesToRadians(theta));
        double dx = STEP_SIZE*qCos(qDegreesToRadians(theta));


        setPos(x()+dx,y()+dy);
    }

public:
    QList<QPointF> points;
    QList<int> coordFilas;
    QList<int> coordColumnas;

    int point_index;

    int columnaLlegada;

    void setPath(QList<QPointF> path){
        this->points = path;
    }

    QPointF getDest(){
        return dest;
    }



    void start(){
            setPos(points[0]);
            dest = points[1];
            rotateToPoint(dest);

            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()),this,SLOT(move_forward()));
            timer->start(200);
    }

    void rotateToPoint(QPointF p){
        QLineF line(pos(),p);
        setRotation(-1*line.angle());
    }

    int getHealth(){
        return health;
    }
    void setHealth(int health){
        this->health = health;
    }
    double getSpeed(){
        return speed;
    }
    void setSpeed(double speed){
        this->speed = speed;
    }
    int getArcherResistance(){
        return archerResistance;
    }
    void setArcherResistance(int archerResistance){
        this->archerResistance = archerResistance;
    }
    int getFireResistance(){
        return fireResistance;
    }
    void setFireResistance(int fireResistance){
        this->fireResistance = fireResistance;
    }
    int getMageResistance(){
        return mageResistance;
    }
    void setMageResistance(int mageResistance){
        this->mageResistance = mageResistance;
    }

};


#endif // ESTUDIANTE_H
