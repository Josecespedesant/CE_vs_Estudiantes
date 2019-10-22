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

#include <QPointF>

class Parcela : public QPushButton, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    bool ocupada;
    int y;
    int x;
    int parentX;
    int parentY;
    float gCost;
    float hCost;
    float fCost;

    Arquero *arch;
    Artillero *gunner;
    Mago *mago;
    LanzaFuego *fire;

    bool has_target;
    QPointF attack_dest;

public slots:
    void adquire_target();


public:
    void attack_target();
    Parcela(QGraphicsItem * parent = 0);

    double distanceTo(QGraphicsItem *item);
    void setType(QString);

    Arquero* getArquero();
    Artillero* getArtillero();
    Mago* getMago();
    LanzaFuego* getLanzaFuego();


    bool isOcupada();
    void setOcupada(bool isocupada);
};

#endif // PARCELA_H
