#include "concreteestudiantefactory.h"

Ogro *ConcreteEstudianteFactory::createOgroInstance(std::vector<int> health)
{
    Ogro *ogro = new Ogro;
    ogro->setHealth(binaryToDecimal(health));
    return ogro;
}

Harpia *ConcreteEstudianteFactory::createHarpiaInstance(std::vector<int> health)
{
    Harpia *harpia = new Harpia;
    harpia->setHealth(binaryToDecimal(health));
    return harpia;
}

Mercenario *ConcreteEstudianteFactory::createMercenarioInstance(std::vector<int> health)
{
    Mercenario *mercenario = new Mercenario;
    mercenario->setHealth(binaryToDecimal(health));
    return mercenario;
}

Elfo_oscuro *ConcreteEstudianteFactory::createElfoInstance(std::vector<int> health)
{
    Elfo_oscuro *elfo = new Elfo_oscuro;
    elfo->setHealth(binaryToDecimal(health));
    return elfo;
}

int ConcreteEstudianteFactory::binaryToDecimal(std::vector<int> health)
{

    int i;
    int output = 0;
    int power = 1;

    for(i=0; i<10; i++){
        output += health.at(9-i) * power;
        power *=2;


    }

    return output;
}

