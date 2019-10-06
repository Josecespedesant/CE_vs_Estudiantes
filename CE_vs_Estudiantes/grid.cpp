#include "grid.h"
#include "ui_grid.h"
#include "QLabel"
#include "iostream"
#include "choosetower.h"
#include "destroytower.h"
#include "player.h"
#include <QPushButton>
#include "parcela.h"
Grid::Grid(QWidget *parent, Player* player) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);

    this->player = player;

    QPushButton* grid[12][10];



    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));

/*
    for(int i=0; i<10;i++){
        Parcela *parcela2 = new Parcela();
        parcela2->setFixedSize(50,50);
        parcela2->setCheckable(false);

    }*/

    QLabel *zonadeaprobacion = new QLabel();
    zonadeaprobacion->setFixedSize(600,50);
    zonadeaprobacion->setStyleSheet("QLabel { background-color : blue; color : blue; }");
    zonadeaprobacion->setText("Zona de aprobación");
    zonadeaprobacion->setAlignment(Qt::AlignCenter);
    ui->gridLayout->addWidget(zonadeaprobacion,0,0);


    for(int i=1; i<11; i++){
        for(int j=0; j<10;j++){
            Parcela *parcela = new Parcela();
            parcela->setFixedSize(50,50);
            parcela->setCheckable(false);

            connect(parcela,SIGNAL(clicked()),this,SLOT(handleButton()));

            if((i+j)%2==0){
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::green));
                parcela->setPalette(pal);
                ui->gridLayout->addWidget(parcela, i, j);

            }else{
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
                parcela->setPalette(pal);
                ui->gridLayout->addWidget(parcela, i, j);

          }

    }

        QLabel *zonadeaprobacion = new QLabel();
        zonadeaprobacion->setFixedSize(600,50);
        zonadeaprobacion->setStyleSheet("QLabel { background-color : red; color : red; }");
        zonadeaprobacion->setAlignment(Qt::AlignCenter);
        ui->gridLayout->addWidget(zonadeaprobacion,12,0);


   }

}

void Grid::handleButton(){
    QPushButton* pButton = qobject_cast<QPushButton*>(sender());
    if (pButton)
         {
            if(pButton->isCheckable()){
                DestroyTower *dr = new DestroyTower(nullptr, pButton, player, ui->label_2);
                dr->show();

            }
            if(!pButton->isCheckable()){
                ChooseTower *ch = new ChooseTower(nullptr, pButton, player, ui->label_2);
                ch->show();
            }
         }

}

Grid::~Grid()
{
    delete ui;
}
