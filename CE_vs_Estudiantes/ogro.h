#ifndef OGRO_H
#define OGRO_H

#include "Estudiante.h"


class Ogro: public Estudiante, public QObject
{
Q_OBJECT
public:

    Ogro(QGraphicsPixmapItem *parent = 0);
};

#endif // OGRO_H
