#include "destroytower.h"
#include "ui_destroytower.h"
#include "iostream"

DestroyTower::DestroyTower(QWidget *parent, QPushButton *button, Player* player, QLabel* creditos) :
    QDialog(parent),
    ui(new Ui::DestroyTower)
{
    ui->setupUi(this);
    this->button = button;
    this->player = player;
    this->creditos = creditos;
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

    if(button->objectName().toStdString().compare("Arch") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+1);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
    }
    else if(button->objectName().toStdString().compare("Arty") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+2);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
    }
    else if(button->objectName().toStdString().compare("Mago") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+2);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
    }
    else if(button->objectName().toStdString().compare("Fire") == 0){
        player->setCreditosTotales(player->getCreditosTotales()+3);
        creditos->setText(QString::number(this->player->getCreditosTotales()));
    }

    this->button->setCheckable(false);
    this->button->setIcon(QIcon());
    hide();
}
