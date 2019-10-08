#ifndef GRID_H
#define GRID_H

#include <QDialog>
#include <iostream>
#include "player.h"
#include <QMouseEvent>
#include "parcela.h"
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
    ~Grid();


private slots:
    void handleButton();

    void on_pushButton_clicked();

private:
    Parcela* grid[12][10];
    QGraphicsScene *gr;
    Ui::Grid *ui;
    Player* player;
};

#endif // GRID_H
