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
#include<QDebug>
#include "ogro.h"
#include "elfo_oscuro.h"
#include "harpia.h"
#include "mercenario.h"

#include "unistd.h"
#include <thread>
#include <iostream>
#include "BackTracking.h"

#include <random>

Grid::Grid(QWidget *parent, Player* player) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);
    setFixedSize(829,660);
    scene = new QGraphicsScene();
    this->player = player;

    spawnTimer = new QTimer(this);

    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));

    //Zona de aprobación
    int I = 0;
    for(int j=0; j<10;j++){
        Parcela *zonaDeAprobacion = new Parcela();

        zonaDeAprobacion->setData(0,1);
        zonaDeAprobacion->setData(1,0);
        zonaDeAprobacion->setData(2,j);

        zonaDeAprobacion->setZValue(-1);
        zonaDeAprobacion->setGeometry(I,-54,54,54);
        I+=54;
        zonaDeAprobacion->setCheckable(false);

        zonaDeAprobacion->setPos(zonaDeAprobacion->geometry().x(),zonaDeAprobacion->geometry().y()+54);
        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::blue));
        zonaDeAprobacion->setPalette(pal);

        tablero[0][j] = zonaDeAprobacion;

        QGraphicsProxyWidget *proxy = scene->addWidget(zonaDeAprobacion);
    }

    //Zona de validación
    int S=0;
    for(int i=1; i<11; i++){
        int K = 0;

        for(int j=0; j<10;j++){

            Parcela *parcela = new Parcela();

            //0 guarda si esta ocupado o no
            parcela->setData(0,1);
            parcela->setData(1,i);
            parcela->setData(2,j);

            parcela->setZValue(-1);
            parcela->setGeometry(K,S,54,54);
            parcela->setCheckable(false);

            parcela->setPos(parcela->geometry().x(),parcela->geometry().y());

            connect(parcela,SIGNAL(clicked()),this,SLOT(handleButton()));

            if((i+j)%2==0){
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::magenta));
                parcela->setPalette(pal);
            }else{
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::darkMagenta));
                parcela->setPalette(pal);
            }

            tablero[i][j] = parcela;
            QGraphicsProxyWidget *proxy = scene->addWidget(parcela);
            K+=54;
        }
        S+=54;
    }
    //Zona de salida
    int B = 0;
    for(int j=0; j<10;j++){
        Parcela *zonaDeSalida = new Parcela();
        zonaDeSalida->setData(0,1);
        zonaDeSalida->setData(1,11);
        zonaDeSalida->setData(2,j);


        zonaDeSalida->setZValue(-1);
        zonaDeSalida->setGeometry(B,542,54,54);
        zonaDeSalida->setCheckable(false);

        zonaDeSalida->setPos(zonaDeSalida->geometry().x(),zonaDeSalida->geometry().y());

        B+=54;
        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
        zonaDeSalida->setPalette(pal);


        QGraphicsProxyWidget *proxy = scene->addWidget(zonaDeSalida);
        tablero[11][j] = zonaDeSalida;
    }

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


}

void Grid::handleButton(){
    Parcela* pButton = qobject_cast<Parcela*>(sender());

    //fila
    std::cout<<pButton->QGraphicsPixmapItem::data(1).toInt()<<std::endl;
    //col
    std::cout<<pButton->QGraphicsPixmapItem::data(2).toInt()<<std::endl;

    std::cout<<"-------------------------"<<std::endl;


    if (pButton)
    {
        if(pButton->isCheckable()){
            UpdateOrDestroy *upord = new UpdateOrDestroy(NULL, pButton, player, ui->label_2);
            upord->show();
        }
        if(!pButton->isCheckable()){
            ChooseTower *ch = new ChooseTower(nullptr, pButton, player, ui->label_2, this, pButton->QGraphicsPixmapItem::data(1).toInt(), pButton->QGraphicsPixmapItem::data(2).toInt());
            ch->show();
        }
    }

}

Grid::~Grid()
{
    delete ui;
}

void Grid::mousePressEvent(QMouseEvent *event){
    std::cout<<event->x()<<std::endl;
    std::cout<<event->y()<<std::endl;
}

//Genera oleada
void Grid::on_pushButton_clicked(){

    int matrix[12][10];

    for(int n = 0; n<12; n++){
        for(int m = 0; m<10; m++){
            matrix[n][m] = QVariant(tablero[n][m]->data(0)).toInt();
        }
    }

    srand(time(NULL));

    int randomSalida = std::rand()%10;
    int randomLlegada = std::rand()%10;

    std::cout<<randomSalida<<std::endl;
    std::cout<<randomLlegada<<std::endl;

    BackTracking *backtracking = new BackTracking(tablero);

    backtracking->setColumnaSalida(randomSalida);
    backtracking->setColumnaLlegada(randomLlegada);

    backtracking->solveMaze(matrix);

    QList<QPointF> pathforogro;

    pathforogro = backtracking->getPath();
    qDebug()<<pathforogro;

    Ogro *ogro1 = new Ogro();


    ogro1->setPath(pathforogro);

  //  connect(ogro1,SIGNAL(clicked()),this,SLOT(infoZombie()));

    oleada.append(ogro1);

    enemiesSpawned = 0;
    maxNumberOfEnemies = oleada.size();
    connect(spawnTimer, SIGNAL(timeout()),this, SLOT(spawnEnemy()));
    spawnTimer->start(3000);
}

void Grid::spawnEnemy()
{
    scene->addItem(oleada[enemiesSpawned]);
    oleada[enemiesSpawned]->start();
    enemiesSpawned+=1;

    if(enemiesSpawned>=maxNumberOfEnemies){
        spawnTimer->disconnect();
        oleada.clear();

    }
}

void Grid::infoZombie()
{
    Estudiante* estudiante = qobject_cast<Estudiante*>(sender());
    std::cout<<estudiante->getHealth()<<std::endl;
    std::cout<<estudiante->getSpeed()<<std::endl;
    std::cout<<estudiante->getFireResistance()<<std::endl;
    std::cout<<estudiante->getMageResistance()<<std::endl;
    std::cout<<estudiante->getArcherResistance()<<std::endl;
}
