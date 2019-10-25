#ifndef GRID_H
#define GRID_H

#include "parcela.h"
#include <QDialog>
#include <iostream>
#include "player.h"
#include <QMouseEvent>
#include <QGraphicsScene>
#include "Estudiante.h"
#include <QTimer>
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

    void generateWave(QList<Estudiante*> oleada);

    ~Grid();


private slots:
    void handleButton();
    void on_pushButton_clicked();
    void spawnEnemy();

private:
    Parcela* tablero[12][10];


    QList<Estudiante*> oleada;
    QTimer *spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;

    Ui::Grid *ui;
    Player* player;
};

#endif // GRID_H
