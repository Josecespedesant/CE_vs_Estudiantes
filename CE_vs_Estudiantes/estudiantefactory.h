#ifndef ESTUDIANTEFACTORY_H
#define ESTUDIANTEFACTORY_H

#include "elfo_oscuro.h"
#include "ogro.h"
#include "harpia.h"
#include "mercenario.h"
#include "Estudiante.h"
#include <iostream>

class EstudianteFactory
{
protected:
    int health[10];

public:
    virtual Ogro* createOgroInstance() = 0;
    virtual Harpia* createHarpiaInstance() = 0;
    virtual Mercenario* createMercenarioInstance() = 0;
    virtual Elfo_oscuro* createElfoInstance() = 0;
};

#endif // ESTUDIANTEFACTORY_H
