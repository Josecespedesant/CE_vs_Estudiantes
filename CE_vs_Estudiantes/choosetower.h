#ifndef CHOOSETOWER_H
#define CHOOSETOWER_H

#include <QDialog>
#include "player.h"
#include "QLabel"
#include "parcela.h"
namespace Ui {
class ChooseTower;
}

class ChooseTower : public QDialog
{
    Q_OBJECT

public:
    explicit ChooseTower(QWidget *parent = nullptr, Parcela *button = NULL, Player* player = NULL, QLabel* creditos = NULL);
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
};

#endif // CHOOSETOWER_H
