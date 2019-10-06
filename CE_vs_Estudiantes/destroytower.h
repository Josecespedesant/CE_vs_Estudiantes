#ifndef DESTROYTOWER_H
#define DESTROYTOWER_H

#include <QDialog>
#include "player.h"
#include "QLabel"
namespace Ui {
class DestroyTower;
}

class DestroyTower : public QDialog
{
    Q_OBJECT

public:
    explicit DestroyTower(QWidget *parent = nullptr, QPushButton *button = NULL, Player *player = 0, QLabel* creditos = NULL);
    ~DestroyTower();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DestroyTower *ui;
    QPushButton *button;
    Player *player;
    QLabel* creditos;
};

#endif // DESTROYTOWER_H
