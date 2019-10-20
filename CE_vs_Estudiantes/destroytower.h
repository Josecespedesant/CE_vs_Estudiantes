#ifndef DESTROYTOWER_H
#define DESTROYTOWER_H

#include <QDialog>
#include "player.h"
#include "QLabel"
#include "parcela.h"
namespace Ui {
class DestroyTower;
}

class DestroyTower : public QDialog
{
    Q_OBJECT

public:
    explicit DestroyTower(QWidget *parent = nullptr, Parcela *button = NULL, Player *player = 0, QLabel* creditos = NULL);
    ~DestroyTower();

private slots:
    /**
     * @brief Se presiona en caso de no querer destruir la torre.
     */
    void on_pushButton_2_clicked();
    /**
     * @brief Se presioan si se quiere destruir la torre y se devuelve la mitad del coste en créditos de la torre.
     */
    void on_pushButton_clicked();

private:
    Ui::DestroyTower *ui;
    Parcela *button;
    Player *player;
    QLabel* creditos;
};

#endif // DESTROYTOWER_H
