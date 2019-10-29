#ifndef ESTUDIANTEFACTORY_H
#define ESTUDIANTEFACTORY_H

#include "elfo_oscuro.h"
#include "ogro.h"
#include "harpia.h"
#include "mercenario.h"
#include "Estudiante.h"
#include <iostream>

/**
 * @brief Clase abstracta parte del patrón de diseño Abstract Factory
 */
class EstudianteFactory
{
protected:
    int health[10];

public:
    /**
     * @brief Crea instancia de ogro
     * @return ogro
     */
    virtual Ogro* createOgroInstance() = 0;
    /**
     * @brief Crea instancia de harpia
     * @return harpia
     */
    virtual Harpia* createHarpiaInstance() = 0;
    /**
     * @brief Crea instancia de mercenario
     * @return mercenario
     */
    virtual Mercenario* createMercenarioInstance() = 0;
    /**
     * @brief Crea instancia de elfo
     * @return elfo
     */
    virtual Elfo_oscuro* createElfoInstance() = 0;
};

#endif // ESTUDIANTEFACTORY_H
