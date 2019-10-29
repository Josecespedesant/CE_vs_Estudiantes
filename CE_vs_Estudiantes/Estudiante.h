#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <QGraphicsItem>
#include <QObject>
#include <qmath.h>
#include "iostream"
#include <QTimer>

/**
 * @brief Clase padre Estudiante
 */
class Estudiante : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
protected:

    int health;
    double speed;

    int archerResistance;
    int artilleryResistance;
    int mageResistance;
    int fireResistance;

    double STEP_SIZE;

public slots:
    /**
     * @brief Mantener moviendose hacia adelante
     */
    void move_forward(){
        QLineF line(pos(),dest);
        if(line.length()<5){
            point_index++;
            if(point_index>=points.size() && dest.y()==0){

                llego = true;

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

    QPointF dest;

    bool llego;

    int fitness;

    /**
     * @brief Convierte decimal a binario
     * @param n
     * @param binaryNum
     */
    void decToBinary(int n, int binaryNum[10]){
        int i =0;
        while(n>0){
            binaryNum[i]=n%2;
            n = n/2;
            i++;
        }
    }

    int typeofpath;

    int point_index;

    int columnaLlegada;

    void setPath(QList<QPointF> path){
        this->points = path;
    }

    /**
     * @brief Se obtiene el destino
     * @return  dest
     */
    QPointF getDest(){
        return dest;
    }



    /**
     * @brief Empieza a caminar
     */
    void start(){
            setPos(points[0]);
            dest = points[1];
            rotateToPoint(dest);

            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()),this,SLOT(move_forward()));
            timer->start(200);
    }

    /**
     * @brief Gira en la dirección del punto
     * @param p
     */
    void rotateToPoint(QPointF p){
        QLineF line(pos(),p);
        setRotation(-1*line.angle());
    }
// getters y setters
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

    int getArtilleryResistance()
    {
        return artilleryResistance;
    }

    void setArtilleryResistance(int value)
    {
        artilleryResistance = value;
    }
};


#endif // ESTUDIANTE_H
