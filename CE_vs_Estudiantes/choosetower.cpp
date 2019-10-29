#include "choosetower.h"
#include "ui_choosetower.h"
#include "iostream"
#include "arquero.h"
#include "artillero.h"
#include "lanzafuego.h"
#include "mago.h"
#include "BackTracking.h"
#include "cantaddtower.h"
#include "astaralgorithm.h"
ChooseTower::ChooseTower(QWidget *parent, Parcela* button, Player* player, QLabel* creditos, Grid *grid, int i, int j, QList<Estudiante*> *oleada) :
    QDialog(parent),
    ui(new Ui::ChooseTower)
{
    ui->setupUi(this);

    this->oleada = oleada;
    this->button = button;
    this->player = player;
    this->creditos = creditos;
    this->grid = grid;

    this->i = i;
    this->j = j;

    int h = ui->pushButton->height();
    int w = ui->pushButton->width();



    for(int n = 0; n<12; n++){
        for(int m = 0; m<10; m++){
            matrix[n][m] = QVariant(grid->tablero[n][m]->data(0)).toInt();
        }
    }

    if(player->getCreditosTotales() <= 0){
        QPixmap pixmap(":/images/questionmark.png");
        QIcon ButtonIcon(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setText("");
        ui->pushButton->setIconSize(pixmap.rect().size());
        ui->pushButton->setEnabled(false);

        QIcon ButtonIcon2(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_2->setIcon(ButtonIcon2);
        ui->pushButton_2->setText("");
        ui->pushButton_2->setIconSize(pixmap.rect().size());
        ui->pushButton_2->setEnabled(false);

        QIcon ButtonIcon3(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_3->setIcon(ButtonIcon3);
        ui->pushButton_3->setText("");
        ui->pushButton_3->setIconSize(pixmap.rect().size());
        ui->pushButton_3->setEnabled(false);


        QIcon ButtonIcon4(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_4->setIcon(ButtonIcon4);
        ui->pushButton_4->setText("");
        ui->pushButton_4->setIconSize(pixmap.rect().size());
        ui->pushButton_4->setEnabled(false);

    }

    if(player->getCreditosTotales() <= 2 && player->getCreditosTotales() > 0){
        QPixmap pixmap(":/images/archer.png");
        QIcon ButtonIcon(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setText("");
        ui->pushButton->setIconSize(pixmap.rect().size());

        QPixmap pixmap2(":/images/questionmark.png");
        QIcon ButtonIcon2(pixmap2.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_2->setIcon(ButtonIcon2);
        ui->pushButton_2->setText("");
        ui->pushButton_2->setIconSize(pixmap2.rect().size());
        ui->pushButton_2->setEnabled(false);

        QIcon ButtonIcon3(pixmap2.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_3->setIcon(ButtonIcon3);
        ui->pushButton_3->setText("");
        ui->pushButton_3->setIconSize(pixmap2.rect().size());
        ui->pushButton_3->setEnabled(false);

        QIcon ButtonIcon4(pixmap2.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_4->setIcon(ButtonIcon4);
        ui->pushButton_4->setText("");
        ui->pushButton_4->setIconSize(pixmap2.rect().size());
        ui->pushButton_4->setEnabled(false);
    }

    if(player->getCreditosTotales() >2  && player->getCreditosTotales()<6){
        QPixmap pixmap(":/images/archer.png");
        QIcon ButtonIcon(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setText("");
        ui->pushButton->setIconSize(pixmap.rect().size());

        QPixmap pixmap2(":/images/gunner.png");
        QIcon ButtonIcon2(pixmap2.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_2->setIcon(ButtonIcon2);
        ui->pushButton_2->setText("");
        ui->pushButton_2->setIconSize(pixmap2.rect().size());

        QPixmap pixmap3(":/images/mage.png");
        QIcon ButtonIcon3(pixmap3.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_3->setIcon(ButtonIcon3);
        ui->pushButton_3->setText("");
        ui->pushButton_3->setIconSize(pixmap3.rect().size());

        QPixmap pixmap4(":/images/questionmark.png");
        QIcon ButtonIcon4(pixmap4.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_4->setIcon(ButtonIcon4);
        ui->pushButton_4->setText("");
        ui->pushButton_4->setIconSize(pixmap4.rect().size());
        ui->pushButton_4->setEnabled(false);

    }

    if(player->getCreditosTotales()>=6){
        QPixmap pixmap(":/images/archer.png");
        QIcon ButtonIcon(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton->setIcon(ButtonIcon);
        ui->pushButton->setText("");
        ui->pushButton->setIconSize(pixmap.rect().size());

        QPixmap pixmap2(":/images/gunner.png");
        QIcon ButtonIcon2(pixmap2.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_2->setIcon(ButtonIcon2);
        ui->pushButton_2->setText("");
        ui->pushButton_2->setIconSize(pixmap2.rect().size());

        QPixmap pixmap3(":images/mage.png");
        QIcon ButtonIcon3(pixmap3.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_3->setIcon(ButtonIcon3);
        ui->pushButton_3->setText("");
        ui->pushButton_3->setIconSize(pixmap3.rect().size());

        QPixmap pixmap4(":/images/fire.png");
        QIcon ButtonIcon4(pixmap4.scaled(w,h,Qt::KeepAspectRatio));
        ui->pushButton_4->setIcon(ButtonIcon4);
        ui->pushButton_4->setText("");
        ui->pushButton_4->setIconSize(pixmap4.rect().size());
    }

}

ChooseTower::~ChooseTower()
{
    delete ui;
}

void ChooseTower::on_pushButton_clicked()
{
    if(grid->flagOfIntialization){

        std::cout<<"Si entra"<<std::endl;

        std::cout<<grid->enemiesInValidation->size()<<std::endl;

        for(int s=0; s<grid->enemiesInValidation->size(); s++){

            if(grid->enemiesInValidation->at(s)->typeofpath == 0){
                BackTracking *backtrack = new BackTracking(grid->tablero);
                backtrack->setColumnaSalida(grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setFilaSalida(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setColumnaLlegada(grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                if(backtrack->solveMaze(matrix)){

                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(backtrack->getPath());


                    Arquero *arch = new Arquero();
                    player->setCreditosTotales(player->getCreditosTotales()-2);
                    this->button->setCheckable(true);
                    QPixmap pixm(ui->pushButton->icon().pixmap(button->width(),button->height()));
                    arch->addPixmap(pixm);
                    this->button->setIcon(*arch);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Arch");
                    this->button->setType("Archer");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));

                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }

            if(grid->enemiesInValidation->at(s)->typeofpath == 1){

                AStarAlgorithm *astar = new AStarAlgorithm(grid->tablero);
                std::pair<int, int> src = std::make_pair(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index),grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                std::pair<int, int> dest = std::make_pair(0,grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                astar->aStarSearch(matrix,src,dest);

                if(astar->done){
                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(astar->getPath());

                    Arquero *arch = new Arquero();
                    player->setCreditosTotales(player->getCreditosTotales()-2);
                    this->button->setCheckable(true);
                    QPixmap pixm(ui->pushButton->icon().pixmap(button->width(),button->height()));
                    arch->addPixmap(pixm);
                    this->button->setIcon(*arch);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Arch");
                    this->button->setType("Archer");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));

                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }
        }
    }
    grid->tablero[i][j]->setData(0,0);

    Arquero *arch = new Arquero();
    player->setCreditosTotales(player->getCreditosTotales()-2);
    this->button->setCheckable(true);
    QPixmap pixm(ui->pushButton->icon().pixmap(button->width(),button->height()));
    arch->addPixmap(pixm);
    this->button->setIcon(*arch);
    this->button->setIconSize(pixm.rect().size());
    this->button->setObjectName("Arch");
    this->button->setType("Archer");
    creditos->setText(QString::number(this->player->getCreditosTotales()));
    hide();
}

void ChooseTower::on_pushButton_2_clicked()
{
    if(grid->flagOfIntialization){

        std::cout<<"Si entra"<<std::endl;

        std::cout<<grid->enemiesInValidation->size()<<std::endl;

        for(int s=0; s<grid->enemiesInValidation->size(); s++){

            if(grid->enemiesInValidation->at(s)->typeofpath == 0){
                BackTracking *backtrack = new BackTracking(grid->tablero);
                backtrack->setColumnaSalida(grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setFilaSalida(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setColumnaLlegada(grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                if(backtrack->solveMaze(matrix)){

                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(backtrack->getPath());


                    Artillero *arty = new Artillero();
                    player->setCreditosTotales(player->getCreditosTotales()-4);
                    this->button->setCheckable(true);
                    QPixmap pixm(ui->pushButton_2->icon().pixmap(button->width(),button->height()));
                    arty->addPixmap(pixm);
                    this->button->setIcon(*arty);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Arty");
                    this->button->setType("Gunner");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));


                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }

            if(grid->enemiesInValidation->at(s)->typeofpath == 1){

                AStarAlgorithm *astar = new AStarAlgorithm(grid->tablero);
                std::pair<int, int> src = std::make_pair(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index),grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                std::pair<int, int> dest = std::make_pair(0,grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                astar->aStarSearch(matrix,src,dest);

                if(astar->done){
                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(astar->getPath());

                    Artillero *arty = new Artillero();
                    player->setCreditosTotales(player->getCreditosTotales()-4);
                    this->button->setCheckable(true);
                    QPixmap pixm(ui->pushButton_2->icon().pixmap(button->width(),button->height()));
                    arty->addPixmap(pixm);
                    this->button->setIcon(*arty);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Arty");
                    this->button->setType("Gunner");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));


                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }
        }
    }
    grid->tablero[i][j]->setData(0,0);


    Artillero *arty = new Artillero();
    player->setCreditosTotales(player->getCreditosTotales()-4);
    this->button->setCheckable(true);
    QPixmap pixm(ui->pushButton_2->icon().pixmap(button->width(),button->height()));
    arty->addPixmap(pixm);
    this->button->setIcon(*arty);
    this->button->setIconSize(pixm.rect().size());
    this->button->setObjectName("Arty");
    this->button->setType("Gunner");
    creditos->setText(QString::number(this->player->getCreditosTotales()));


    hide();
}

void ChooseTower::on_pushButton_3_clicked()
{
    if(grid->flagOfIntialization){

        std::cout<<"Si entra"<<std::endl;

        std::cout<<grid->enemiesInValidation->size()<<std::endl;

        for(int s=0; s<grid->enemiesInValidation->size(); s++){

            if(grid->enemiesInValidation->at(s)->typeofpath == 0){
                BackTracking *backtrack = new BackTracking(grid->tablero);
                backtrack->setColumnaSalida(grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setFilaSalida(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setColumnaLlegada(grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                if(backtrack->solveMaze(matrix)){

                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(backtrack->getPath());


                    Mago *mag = new Mago();
                    this->button->setCheckable(true);
                    player->setCreditosTotales(player->getCreditosTotales()-4);
                    QPixmap pixm(ui->pushButton_3->icon().pixmap(button->width(),button->height()));
                    mag->addPixmap(pixm);
                    this->button->setIcon(*mag);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Mago");
                    this->button->setType("Mage");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));


                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }

            if(grid->enemiesInValidation->at(s)->typeofpath == 1){

                AStarAlgorithm *astar = new AStarAlgorithm(grid->tablero);
                std::pair<int, int> src = std::make_pair(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index),grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                std::pair<int, int> dest = std::make_pair(0,grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                astar->aStarSearch(matrix,src,dest);

                if(astar->done){
                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(astar->getPath());

                    Mago *mag = new Mago();
                    this->button->setCheckable(true);
                    player->setCreditosTotales(player->getCreditosTotales()-4);
                    QPixmap pixm(ui->pushButton_3->icon().pixmap(button->width(),button->height()));
                    mag->addPixmap(pixm);
                    this->button->setIcon(*mag);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Mago");
                    this->button->setType("Mage");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));



                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }
        }
    }
    grid->tablero[i][j]->setData(0,0);


    Mago *mag = new Mago();
    this->button->setCheckable(true);
    player->setCreditosTotales(player->getCreditosTotales()-4);
    QPixmap pixm(ui->pushButton_3->icon().pixmap(button->width(),button->height()));
    mag->addPixmap(pixm);
    this->button->setIcon(*mag);
    this->button->setIconSize(pixm.rect().size());
    this->button->setObjectName("Mago");
    this->button->setType("Mage");
    creditos->setText(QString::number(this->player->getCreditosTotales()));


    hide();
}

void ChooseTower::on_pushButton_4_clicked()
{
    if(grid->flagOfIntialization){

        std::cout<<"Si entra"<<std::endl;

        std::cout<<grid->enemiesInValidation->size()<<std::endl;

        for(int s=0; s<grid->enemiesInValidation->size(); s++){

            if(grid->enemiesInValidation->at(s)->typeofpath == 0){
                BackTracking *backtrack = new BackTracking(grid->tablero);
                backtrack->setColumnaSalida(grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setFilaSalida(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index));
                backtrack->setColumnaLlegada(grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                if(backtrack->solveMaze(matrix)){

                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(backtrack->getPath());


                    LanzaFuego *fire = new LanzaFuego();
                    this->button->setCheckable(true);
                    player->setCreditosTotales(player->getCreditosTotales()-6);
                    QPixmap pixm(ui->pushButton_4->icon().pixmap(button->width(),button->height()));
                    fire->addPixmap(pixm);
                    this->button->setIcon(*fire);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Fire");
                    this->button->setType("Fire");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));


                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }

            if(grid->enemiesInValidation->at(s)->typeofpath == 1){

                AStarAlgorithm *astar = new AStarAlgorithm(grid->tablero);
                std::pair<int, int> src = std::make_pair(grid->enemiesInValidation->at(s)->coordFilas.at(grid->enemiesInValidation->at(s)->point_index),grid->enemiesInValidation->at(s)->coordColumnas.at(grid->enemiesInValidation->at(s)->point_index));
                std::pair<int, int> dest = std::make_pair(0,grid->enemiesInValidation->at(s)->columnaLlegada);

                grid->tablero[i][j]->setData(0,0);
                matrix[i][j] = 0;

                astar->aStarSearch(matrix,src,dest);

                if(astar->done){
                    grid->enemiesInValidation->at(s)->points.clear();
                    grid->enemiesInValidation->at(s)->setPath(astar->getPath());

                    LanzaFuego *fire = new LanzaFuego();
                    this->button->setCheckable(true);
                    player->setCreditosTotales(player->getCreditosTotales()-6);
                    QPixmap pixm(ui->pushButton_4->icon().pixmap(button->width(),button->height()));
                    fire->addPixmap(pixm);
                    this->button->setIcon(*fire);
                    this->button->setIconSize(pixm.rect().size());
                    this->button->setObjectName("Fire");
                    this->button->setType("Fire");
                    creditos->setText(QString::number(this->player->getCreditosTotales()));

                }else{
                    std::cout<<"Si entra3"<<std::endl;
                    CantAddTower *add = new CantAddTower;
                    add->show();
                    grid->tablero[i][j]->setData(0,1);
                    return;
                }
            }
        }
    }
    grid->tablero[i][j]->setData(0,0);

    LanzaFuego *fire = new LanzaFuego();
    this->button->setCheckable(true);
    player->setCreditosTotales(player->getCreditosTotales()-6);
    QPixmap pixm(ui->pushButton_4->icon().pixmap(button->width(),button->height()));
    fire->addPixmap(pixm);
    this->button->setIcon(*fire);
    this->button->setIconSize(pixm.rect().size());
    this->button->setObjectName("Fire");
    this->button->setType("Fire");
    creditos->setText(QString::number(this->player->getCreditosTotales()));


    hide();
}
