#ifndef MERCENARIO_H
#define MERCENARIO_H

#include "Estudiante.h"
/**
 * @brief Clase Mercenario
 */
class Mercenario :public Estudiante
{
public:
    /**
    * @brief Constructor Mercenario
    * @param parent
    */
   Mercenario(QGraphicsItem * parent = 0);
};


#endif // MERCENARIO_H
