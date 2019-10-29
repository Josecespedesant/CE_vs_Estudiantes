#ifndef PARCELA_H
#define PARCELA_H

#define X_MAX 560
#define X_STEP 10
#define Y_MAX 660
#define Y_STEP 10

#include "grid.h"
#include <QPushButton>
#include "Curso.h"
#include "arquero.h"
#include "lanzafuego.h"
#include "artillero.h"
#include "mago.h"
#include <QGraphicsPixmapItem>
#include "Estudiante.h"
#include <QLabel>
#include <QPointF>

/**
 * @brief The Parcela class
 */

class Parcela : public QPushButton, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool ocupada;

    int i;
    int j;
    int parentI;
    int parentJ;
    float gCost;
    float hCost;
    float fCost;

    int timesShot;



    Arquero *arch;
    Artillero *gunner;
    Mago *mago;
    LanzaFuego *fire;

    bool has_target;
    QPointF attack_dest;
    QGraphicsPolygonItem *truesquare;

public slots:
    /**
     * @brief Apunta al enemigo
     */
    void adquire_target();


public:
    /**
     * @brief Ataca al enemigo
     * @param estudiante
     */
    void attack_target(Estudiante* estudiante);
    /**
     * @brief Parcela
     * @param parent
     * @param contMuertes
     * @param creditos
     */
    Parcela(QGraphicsItem * parent = 0, QLabel* contMuertes = 0, QLabel* creditos = 0);

    /**
     * @brief Distancia al enemigo
     * @param item
     * @return distancia
     */
    double distanceTo(QGraphicsItem *item);
    /**
     * @brief Tipo de torre
     */
    void setType(QString);

    QLabel *contMuertes;
    QLabel *creditos;
//Getters
    Arquero* getArquero();
    Artillero* getArtillero();
    Mago* getMago();
    LanzaFuego* getLanzaFuego();

    /**
     * @brief Si esta ocupada
     * @return true or false
     */
    bool isOcupada();
    /**
     * @brief Settear si esta ocupada
     * @param isocupada
     */
    void setOcupada(bool isocupada);
};

#endif // PARCELA_H
