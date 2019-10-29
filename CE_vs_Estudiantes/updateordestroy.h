#ifndef UPDATEORDESTROY_H
#define UPDATEORDESTROY_H

#include <QDialog>
#include "player.h"
#include "QLabel"
#include "parcela.h"

namespace Ui {
class UpdateOrDestroy;
}
/**
 * @brief The UpdateOrDestroy class
 */
class UpdateOrDestroy : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief UpdateOrDestroy
     * @param parent
     * @param button
     * @param player
     * @param creditos
     * @param grid
     * @param i
     * @param j
     * @param oleada
     */
    explicit UpdateOrDestroy(QWidget *parent = nullptr, Parcela *button = NULL, Player* player = NULL, QLabel* creditos = NULL, Grid *grid = NULL, int i = 0, int j = 0, QList<Estudiante*> *oleada = nullptr);
    ~UpdateOrDestroy();

private slots:
    /**
     * @brief Update
     */
    void on_pushButton_clicked();

    /**
     * @brief Destroy
     */
    void on_pushButton_2_clicked();

private:

    Ui::UpdateOrDestroy *ui;
    Parcela *button;
    Player *player;
    QLabel *creditos;
    Grid* grid;
    QList<Estudiante*> *oleada;
    int matrix[12][10];

    int i;
    int j;

};

#endif // UPDATEORDESTROY_H
