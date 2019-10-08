#include "updateordestroy.h"
#include "ui_updateordestroy.h"
#include "destroytower.h"
#include "updatetower.h"
#include "warningmaxlvl.h"

UpdateOrDestroy::UpdateOrDestroy(QWidget *parent, Parcela *button, Player* player, QLabel* creditos) :
    QDialog(parent),
    ui(new Ui::UpdateOrDestroy)
{
    ui->setupUi(this);

    this->button = button;
    this->player = player;
    this->creditos = creditos;
}

UpdateOrDestroy::~UpdateOrDestroy()
{
    delete ui;
}

void UpdateOrDestroy::on_pushButton_clicked()
{

    int max_lvl = 4;
    if(button->objectName().toStdString().compare("Arch") == 0){
        if(button->getArquero()->getNivelActual() < max_lvl){

            UpdateTower *updateTower = new UpdateTower(nullptr, button, player, creditos);
            updateTower->show();
            hide();
        }
        else{
            WarningMaxLvl *warningMaxLvl = new WarningMaxLvl;
            warningMaxLvl->show();
            hide();
        }
    }
    else if(button->objectName().toStdString().compare("Arty") == 0){
        if(button->getArtillero()->getNivelActual() < max_lvl){

            UpdateTower *updateTower = new UpdateTower(nullptr, button, player, creditos);
            updateTower->show();
            hide();

        }else{
            WarningMaxLvl *warningMaxLvl = new WarningMaxLvl;
            warningMaxLvl->show();
            hide();
        }
    }
    else if(button->objectName().toStdString().compare("Mago") == 0){
        if(button->getMago()->getNivelActual() < max_lvl){

            UpdateTower *updateTower = new UpdateTower(nullptr, button, player, creditos);
            updateTower->show();
            hide();

        }
        else{
            WarningMaxLvl *warningMaxLvl = new WarningMaxLvl;
            warningMaxLvl->show();
            hide();
        }
    }
    else if(button->objectName().toStdString().compare("Fire") == 0){
        if(button->getLanzaFuego()->getNivelActual() < max_lvl){

            UpdateTower *updateTower = new UpdateTower(nullptr, button, player, creditos);
            updateTower->show();
            hide();

        }else{
            WarningMaxLvl *warningMaxLvl = new WarningMaxLvl;
            warningMaxLvl->show();
            hide();
        }
    }

}

void UpdateOrDestroy::on_pushButton_2_clicked()
{
    DestroyTower *dr = new DestroyTower(nullptr, button, player, creditos);
    dr->show();
    hide();
}
