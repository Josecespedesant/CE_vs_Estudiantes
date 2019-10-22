#ifndef OGRO_H
#define OGRO_H

#include "Estudiante.h"

class Ogro: public Estudiante
{
public:
    Ogro(QGraphicsItem * parent = 0);

public slots:
    void move();
};

#endif // OGRO_H
