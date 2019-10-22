#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include "QGraphicsItem"
class Estudiante : public QGraphicsItem{

protected:
    int health;
    double speed;
    int archerResistance;
    int artilleryResistance;
    int mageResistance;
    int fireResistance;

public:
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
