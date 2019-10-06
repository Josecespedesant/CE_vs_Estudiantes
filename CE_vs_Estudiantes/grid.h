#ifndef GRID_H
#define GRID_H

#include <QDialog>
#include <iostream>
#include "player.h"

namespace Ui {
class Grid;
}

class Grid : public QDialog
{
    Q_OBJECT

public:
    explicit Grid(QWidget *parent = nullptr, Player* player = NULL);
    ~Grid();


private slots:
    void handleButton();

private:
    Ui::Grid *ui;
    Player* player;
};

#endif // GRID_H
