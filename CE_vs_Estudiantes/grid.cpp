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
#include "QGraphicsView"
#include "ogro.h"

Grid::Grid(QWidget *parent, Player* player) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);
    setFixedSize(829,660);
    scene = new QGraphicsScene();

    Ogro *ogrocheche = new Ogro();
    ogrocheche->setZValue(1);
    ogrocheche->setY(150);
    ogrocheche->setX(150);
    scene->addItem(ogrocheche);


    this->player = player;

    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));

    int I = 0;
    for(int i=0; i<10;i++){
        Parcela *zonaDeAprobacion = new Parcela();
        zonaDeAprobacion->setZValue(-1);
        zonaDeAprobacion->setGeometry(I,-54,54,54);
        I+=54;
        zonaDeAprobacion->setCheckable(false);

        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        zonaDeAprobacion->setPalette(pal);

        tablero[0][i] = 5;

        QGraphicsProxyWidget *proxy = scene->addWidget(zonaDeAprobacion);

    }
    int S=0;
    for(int i=1; i<11; i++){
        int K = 0;
        for(int j=0; j<10;j++){
            Parcela *parcela = new Parcela();
            parcela->setZValue(-1);
            parcela->setGeometry(S,K,54,54);
            parcela->setCheckable(false);

            connect(parcela,SIGNAL(clicked()),this,SLOT(handleButton()));

            if((i+j)%2==0){
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::green));
                parcela->setPalette(pal);
            }else{
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
                parcela->setPalette(pal);
            }
           QGraphicsProxyWidget *proxy = scene->addWidget(parcela);
            tablero[i][j] = 0;
            K+=54;
        }
        S+=54;
    }
    int B = 0;
    for(int i=0; i<10;i++){
        Parcela *zonaDeSalida = new Parcela();
        zonaDeSalida->setZValue(-1);
        zonaDeSalida->setGeometry(B,542,54,54);
        zonaDeSalida->setCheckable(false);
        B+=54;
        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::red));
        zonaDeSalida->setPalette(pal);
        tablero[11][i] = 6;

        QGraphicsProxyWidget *proxy = scene->addWidget(zonaDeSalida);
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
    Evaluation *evaluation = new Evaluation();
    evaluation->setZValue(1);
    evaluation->setPos(event->pos());
    scene->addItem(evaluation);

    std::cout<<event->x()<<std::endl;
}

//Debugear la app
void Grid::on_pushButton_clicked()
{
    this->player->setCreditosTotales(1000);
    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));
}
