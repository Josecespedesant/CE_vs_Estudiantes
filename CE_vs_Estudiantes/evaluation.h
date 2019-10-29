#ifndef EVALUATION_H
#define EVALUATION_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QLabel>
#include "Estudiante.h"
#include "grid.h"
#include "Curso.h"

class Evaluation : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Evaluation(QGraphicsItem * parent = 0, QLabel* contMuertes = 0);
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dist);
    void setCurso(Curso *curso);
    int contadorDisparoEspecial;

    QLabel *contMuertes;

public slots:
    void move();
    void setEstudianteObjetivo(Estudiante* estudiante);
    void setGrid(Grid *grid);

private:
    double maxRange;
    double distaneTravelled;
    Grid* grid;
    Curso *curso;

    Estudiante* estudianteObjetivo;
};

#endif // EVALUATION_H
