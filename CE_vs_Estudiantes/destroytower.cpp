#include "destroytower.h"
#include "ui_destroytower.h"
#include "iostream"

DestroyTower::DestroyTower(QWidget *parent, Parcela* button, Player* player, QLabel* creditos, Grid *grid, int i, int j, QList<Estudiante*> *oleada) :
    QDialog(parent),
    ui(new Ui::DestroyTower)
{
    ui->setupUi(this);
    this->oleada = oleada;
    this->button = button;
    this->player = player;
    this->creditos = creditos;

    this->grid = grid;

    this->i = i;
    this->j = j;

    for(int n = 0; n<12; n++){
        for(int m = 0; m<10; m++){
            matrix[n][m] = QVariant(grid->tablero[n][m]->data(0)).toInt();
        }
    }

}

DestroyTower::~DestroyTower()
{
    delete ui;
}

void DestroyTower::on_pushButton_2_clicked()
{
    this->button->setCheckable(true);
    hide();
}

void DestroyTower::on_pushButton_clicked()
{

    this->button->setCheckable(false);
    this->button->setIcon(QIcon());
    this->button->setType("");

    if(button->objectName().toStdString().compare("Arch") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+1);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        grid->tablero[i][j]->setData(0,1);
        matrix[i][j] = 1;
    }
    else if(button->objectName().toStdString().compare("Arty") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+2);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        grid->tablero[i][j]->setData(0,1);
        matrix[i][j] = 1;
    }
    else if(button->objectName().toStdString().compare("Mago") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+2);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        grid->tablero[i][j]->setData(0,1);
        matrix[i][j] = 1;
    }
    else if(button->objectName().toStdString().compare("Fire") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+3);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        grid->tablero[i][j]->setData(0,1);
        matrix[i][j] = 1;
    }

    hide();
}
