#ifndef UPDATETOWER_H
#define UPDATETOWER_H

#include <QDialog>
#include "parcela.h"
#include "player.h"
#include "QLabel"

namespace Ui {
class UpdateTower;
}

class UpdateTower : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateTower(QWidget *parent = 0, Parcela *button = NULL, Player *player = 0, QLabel* creditos = NULL);
    ~UpdateTower();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::UpdateTower *ui;
    Parcela *button;
    Player* player;
    QLabel* creditos;
};

#endif // UPDATETOWER_H
