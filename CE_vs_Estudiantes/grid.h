#ifndef GRID_H
#define GRID_H

#include <QDialog>
#include <iostream>
#include "player.h"
#include <QMouseEvent>
#include <QGraphicsScene>
#include "Estudiante.h"
#include <QTimer>
#include "parcela.h"
#include <QGraphicsPixmapItem>
namespace Ui {
class Grid;
}

class Grid : public QDialog
{
    Q_OBJECT

public:
    explicit Grid(QWidget *parent = nullptr, Player* player = NULL);
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene *scene;

    QGraphicsPixmapItem* tablero[12][10] {};

    ~Grid();


private slots:
    void handleButton();
    void on_pushButton_clicked();
    void spawnEnemy();
    void infoZombie();

private:



    QList<Estudiante*> oleada;
    QTimer *spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;

    Ui::Grid *ui;
    Player* player;
};

#endif // GRID_H
