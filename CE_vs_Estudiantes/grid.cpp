#include "grid.h"
#include "ui_grid.h"
#include "QLabel"
#include "iostream"
#include "choosetower.h"
#include "destroytower.h"
#include "player.h"
#include <QPushButton>
#include "updateordestroy.h"
#include "evaluation.h"
#include <QWidget>

Grid::Grid(QWidget *parent, Player* player) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);


    gr = new QGraphicsScene(this);
    gr->setSceneRect(700,200,1000,1000);
    this->player = player;

    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));


    for(int i=0; i<10;i++){
        Parcela *zonaDeAprobacion = new Parcela;
        zonaDeAprobacion->setFixedSize(50,50);
        zonaDeAprobacion->setCheckable(false);

        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        zonaDeAprobacion->setPalette(pal);
        ui->gridLayout->addWidget(zonaDeAprobacion,0,i);

        grid[0][i] = zonaDeAprobacion;
    }

    for(int i=1; i<11; i++){
        for(int j=0; j<10;j++){
            Parcela *parcela = new Parcela;
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
            grid[i][j] = parcela;

    }

        for(int i=0; i<10;i++){
            Parcela *zonaDeSalida = new Parcela;
            zonaDeSalida->setFixedSize(50,50);
            zonaDeSalida->setCheckable(false);

            QPalette pal;
            pal.setColor(QPalette::Button, QColor(Qt::red));
            zonaDeSalida->setPalette(pal);
            ui->gridLayout->addWidget(zonaDeSalida,12,i);
            grid[11][i] = zonaDeSalida;
        }


   }

}

void Grid::handleButton(){
    Parcela* pButton = qobject_cast<Parcela*>(sender());
    if (pButton)
         {
            if(pButton->isCheckable()){
                UpdateOrDestroy *upord = new UpdateOrDestroy(NULL, pButton, player, ui->label_2);
                upord->show();
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

void Grid::mousePressEvent(QMouseEvent *event){
    Evaluation *ev = new Evaluation();
    ev->setPos(event->pos());
    gr->addItem(ev);
    std::cout<<event->pos().x()<<std::endl;
}

//Debugear la app
void Grid::on_pushButton_clicked()
{
    this->player->setCreditosTotales(1000);
    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));
}
