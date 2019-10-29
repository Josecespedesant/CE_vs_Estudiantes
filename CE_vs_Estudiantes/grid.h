#ifndef GRID_H
#define GRID_H

#include <QDialog>
#include <iostream>
#include "player.h"
#include <QMouseEvent>
#include <QGraphicsScene>
#include "Estudiante.h"
#include <QTimer>
#include "parcela.h"
#include <QGraphicsPixmapItem>
namespace Ui {
class Grid;
}

class Grid : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor clase Grid
     * @param parent
     * @param player
     */
    explicit Grid(QWidget *parent = nullptr, Player* player = NULL);
    void mousePressEvent(QMouseEvent *event);
    QGraphicsScene *scene;

    bool flagOfIntialization;
    QList<Estudiante*> *enemiesInValidation;
    QGraphicsPixmapItem* tablero[12][10] {};
    int F;

    bool colective;
    int maxNumOfWaves;

    Player* player;
    ~Grid();


private slots:
    /**
     * @brief Se mejora o destruye la torre
     */
    void handleButton();
    /**
     * @brief Genera oleadas
     */
    void on_pushButton_clicked();
    /**
     * @brief Agrega a un enemigo a la pantalla
     */
    void spawnEnemy();
    /**
     * @brief Verifica pos del enemigo
     */
    void verifyEnemyPos();
    /**
     * @brief info del Estudiante
     */
    void infoZombie();
    /**
     * @brief Selecciona aprobación colectiva
     */
    void on_aprob_colectiva_clicked();

    /**
     * @brief Selecciona aprobación individual
     */
    void on_aprob_individual_clicked();

private:
    QList<Estudiante*> *oleada;
    QTimer *spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    QTimer* verifTimer;



    int mutaciones;
    int inversiones;

    int numeroOleada;

    Ui::Grid *ui;
};

#endif // GRID_H
