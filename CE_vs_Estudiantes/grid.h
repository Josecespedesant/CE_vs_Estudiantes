#ifndef GRID_H
#define GRID_H
#include "parcela.h"

#include <QDialog>
#include <iostream>
#include "player.h"
#include <QMouseEvent>
#include <QGraphicsScene>
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
    ~Grid();


private slots:
    void handleButton();
    void on_pushButton_clicked();

private:
    int tablero[12][10];


    Ui::Grid *ui;
    Player* player;
};

#endif // GRID_H
