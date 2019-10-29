#ifndef UPDATETOWER_H
#define UPDATETOWER_H

#include <QDialog>
#include "parcela.h"
#include "player.h"
#include "QLabel"

namespace Ui {
class UpdateTower;
}
/**
 * @brief The UpdateTower class
 */
class UpdateTower : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief UpdateTower
     * @param parent
     * @param button
     * @param player
     * @param creditos
     */
    explicit UpdateTower(QWidget *parent = 0, Parcela *button = NULL, Player *player = 0, QLabel* creditos = NULL);
    ~UpdateTower();

private slots:
    /**
     * @brief Update
     */
    void on_pushButton_clicked();

    /**
     * @brief Cancel
     */
    void on_pushButton_2_clicked();

private:
    Ui::UpdateTower *ui;
    Parcela *button;
    Player* player;
    QLabel* creditos;
};

#endif // UPDATETOWER_H
