#ifndef CONCRETEESTUDIANTEFACTORY_H
#define CONCRETEESTUDIANTEFACTORY_H

#include "estudiantefactory.h"
#include "vector"

/**
 * @brief Clase concreta parte del patrón de diseño Abstract Factory
 */
class ConcreteEstudianteFactory
{


public:

    Ogro* createOgroInstance(std::vector<int> health);
    Harpia* createHarpiaInstance(std::vector<int> health);
    Mercenario* createMercenarioInstance(std::vector<int> health);
    Elfo_oscuro* createElfoInstance(std::vector<int> health);

    int binaryToDecimal(std::vector<int> health);

};

#endif // CONCRETEESTUDIANTEFACTORY_H
