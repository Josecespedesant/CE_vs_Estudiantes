#ifndef EVALUATION_H
#define EVALUATION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QLabel>
#include "Estudiante.h"
#include "grid.h"
#include "Curso.h"

/**
 * @brief Evaluación del estudiante
 */

class Evaluation : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    /**
     * @brief Constructor
     * @param parent
     * @param contMuertes
     * @param creditos
     */
    Evaluation(QGraphicsItem * parent = 0, QLabel* contMuertes = 0, QLabel* creditos = 0);

    //getters y setters
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);
    void setCurso(Curso *curso);
    int contadorDisparoEspecial;
    QLabel *creditos;
    QLabel *contMuertes;

public slots:
    /**
     * @brief Mueve la bala
     */
    void move();
    /**
     * @brief Estudiante por evaluar
     * @param estudiante
     */
    void setEstudianteObjetivo(Estudiante* estudiante);
    /**
     * @brief settea el Grid
     * @param grid
     */
    void setGrid(Grid *grid);

private:
    double maxRange;
    double distaneTravelled;
    Grid* grid;
    Curso *curso;

    Estudiante* estudianteObjetivo;
};

#endif // EVALUATION_H
