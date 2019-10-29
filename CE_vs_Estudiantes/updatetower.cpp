#include "updatetower.h"
#include "ui_updatetower.h"

UpdateTower::UpdateTower(QWidget *parent, Parcela *button, Player* player, QLabel* creditos) :
    QDialog(parent),
    ui(new Ui::UpdateTower)
{
    ui->setupUi(this);

    this->button = button;
    this->player = player;
    this->creditos = creditos;

    if(button->objectName().toStdString().compare("Arch") == 0){
        if(button->getArquero()->getNivelActual() == 1){
            ui->label_5->setText("credit?");
        }else{
            ui->label_5->setText("credits?");
        }
        ui->label_2->setText("Archer");
        ui->label_4->setText(QString::number(button->getArquero()->getNivelActual()));
    }
    else if(button->objectName().toStdString().compare("Arty") == 0){
        if(button->getArtillero()->getNivelActual() == 1){
            ui->label_5->setText("credit?");
        }else{
            ui->label_5->setText("credits?");
        }
        ui->label_5->setText("credits?");
        ui->label_2->setText("Gunner");
        ui->label_4->setText(QString::number(button->getArtillero()->getNivelActual()+1));
    }
    else if(button->objectName().toStdString().compare("Mago") == 0){
        if(button->getMago()->getNivelActual() == 1){
            ui->label_5->setText("credit?");
        }else{
            ui->label_5->setText("credits?");
        }
        ui->label_5->setText("credits?");
        ui->label_2->setText("Magician");
        ui->label_4->setText(QString::number(button->getMago()->getNivelActual()+1));
    }
    else if(button->objectName().toStdString().compare("Fire") == 0){
        if(button->getLanzaFuego()->getNivelActual() == 1){
            ui->label_5->setText("credit?");
        }else{
            ui->label_5->setText("credits?");
        }
        ui->label_5->setText("credits?");
        ui->label_2->setText("Fire Launcher");
        ui->label_4->setText(QString::number(button->getLanzaFuego()->getNivelActual()+2));
    }

}

UpdateTower::~UpdateTower()
{
    delete ui;
}

void UpdateTower::on_pushButton_clicked()
{
    if(button->objectName().toStdString().compare("Arch") == 0){
        player->setCreditosTotales(player->getCreditosTotales()-button->getArquero()->getNivelActual());
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        button->getArquero()->setNivelActual(button->getArquero()->getNivelActual()+1);
        hide();
    }

    else if(button->objectName().toStdString().compare("Arty") == 0){
        player->setCreditosTotales(player->getCreditosTotales()-button->getArtillero()->getNivelActual());
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        button->getArtillero()->setNivelActual(button->getArtillero()->getNivelActual()+1);
        hide();
    }
    else if(button->objectName().toStdString().compare("Mago") == 0){
        player->setCreditosTotales(player->getCreditosTotales()-button->getMago()->getNivelActual());
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        button->getMago()->setNivelActual(button->getMago()->getNivelActual()+1);
        hide();
    }
    else if(button->objectName().toStdString().compare("Fire") == 0){
        player->setCreditosTotales(player->getCreditosTotales()-button->getLanzaFuego()->getNivelActual());
        creditos->setText(QString::number(this->player->getCreditosTotales()));
        button->getLanzaFuego()->setNivelActual(button->getLanzaFuego()->getNivelActual()+1);
        hide();
    }

}

void UpdateTower::on_pushButton_2_clicked()
{
    hide();
}
