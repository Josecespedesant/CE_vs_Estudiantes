#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

class Estudiante{

private:
    int health;
    double speed;
    int archerResistance;
    int artilleryResistance;
    int fireResistance;

public:
    virtual int getHealth() = 0;
    virtual void setHealth(int health) = 0;
    virtual double getSpeed() = 0;
    virtual void setSpeed(double) = 0;
    virtual int getArcherResistance() = 0;
    virtual void setArcherResistance(int archerResistance) = 0;
    virtual int getFireResistance() = 0;
    virtual void setFireResistance(int fireResistance) = 0;

};


#endif // ESTUDIANTE_H
