#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <QList>
#include "Estudiante.h"
#include "vector"

/**
 * @brief Clase algoritmo genético encargada de controlar las oleadas de estudiantes.
 * @authors José Antonio Céspedes Downing y Victoria Ruiz Vargas
 */
class GeneticAlgorithm
{
private:
    QList<Estudiante*> *poblacionInicial;
    QList<Estudiante*> *seleccionados;
    QList<Estudiante*> *oleada;
    bool primer;


public:
    GeneticAlgorithm();
    GeneticAlgorithm(QList<Estudiante*> *nuevaOleada, QList<int> *vidaInicial);

    /**
     * @brief Convierte decimal a binario
     * @param n
     * @return
     */
    std::vector<int> decimalToBinary(int n);
    /**
     * @brief Población inicial
     */
    void initializePopulation();
    /**
     * @brief Función de fitness
     */
    void fitnessFunction();
    /**
     * @brief Se seleccionan los mas aptos
     */
    void selection();
    /**
     * @brief Reproduccion entre individuos
     */
    void reproduction();
    /**
     * @brief Mutación si ocurre
     */
    void mutation();
    /**
     * @brief Inversion si ocurre
     */
    void inversion();

    /**
     * @brief Obtiene oleada actual
     * @return oleada
     */
    QList<Estudiante*>* getOleada();

};

#endif // GENETICALGORITHM_H
