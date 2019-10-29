#ifndef OGRO_H
#define OGRO_H

#include "Estudiante.h"
/**
 * @brief Clase Ogro
 */
class Ogro: public Estudiante
{
public:
    /**
     * @brief Constructor Ogro
     * @param parent
     */
    Ogro(QGraphicsItem * parent = 0);
};

#endif // OGRO_H
