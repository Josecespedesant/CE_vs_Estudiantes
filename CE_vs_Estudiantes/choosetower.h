#ifndef CHOOSETOWER_H
#define CHOOSETOWER_H

#include <QDialog>
#include "player.h"
#include "QLabel"
#include "parcela.h"
#include "grid.h"
#include "Estudiante.h"
#include <QList>
namespace Ui {
class ChooseTower;
}

class ChooseTower : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseTower(QWidget *parent = nullptr, Parcela *button = NULL, Player* player = NULL, QLabel* creditos = NULL, Grid *grid = NULL, int i = 0, int j = 0, QList<Estudiante*> *oleada = nullptr);
    ~ChooseTower();

private slots:
    /**
     * @brief Selecciona la torre relacionada al tipo de curso "Arquero".
     */
    void on_pushButton_clicked();
    /**
     * @brief Selecciona la torre relacionada al tipo de curso "Artillero".
     */
    void on_pushButton_2_clicked();
    /**
     * @brief Selecciona la torre relacionada al tipo de curso "Mago".
     */
    void on_pushButton_3_clicked();
    /**
     * @brief Selecciona la torre relacioanda al tipo de curso "Lanza fuego"
     */
    void on_pushButton_4_clicked();

private:
    Ui::ChooseTower *ui;
    Parcela *button;
    Player* player;
    QLabel* creditos;
    Grid* grid;
    QList<Estudiante*> *oleada;
    int matrix[12][10];

    int i;
    int j;
};

#endif // CHOOSETOWER_H
