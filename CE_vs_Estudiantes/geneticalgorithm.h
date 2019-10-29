#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <QList>
#include "Estudiante.h"
#include "vector"

class GeneticAlgorithm
{
private:
    QList<Estudiante*> *poblacionInicial;
    QList<Estudiante*> *seleccionados;
    QList<Estudiante*> *oleada;
    int generationCount;



public:
    GeneticAlgorithm();
    std::vector<int> decimalToBinary(int n);
    int getGeneration();

    void initializePopulation();
    void fitnessFunction();
    void selection();
    void reproduction();
    void mutation();
    void inversion();

    QList<Estudiante*>* getOleada();

};

#endif // GENETICALGORITHM_H
