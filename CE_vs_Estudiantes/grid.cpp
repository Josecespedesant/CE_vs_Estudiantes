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
#include "astaralgorithm.h"
#include<bits/stdc++.h>
#include "unistd.h"
#include <thread>
#include <iostream>
#include "BackTracking.h"
#include <QFont>
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include "geneticalgorithm.h"
#include "end.h"
#include "ind_mode.h"
#include "col_mode.h"
#include <random>

Grid::Grid(QWidget *parent, Player* player) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);
    setFixedSize(829,660);
    scene = new QGraphicsScene();
    this->player = player;
    this->numeroOleada = 0;
    this->inversiones = 0;
    this->mutaciones = 0;
    enemiesInValidation = new QList<Estudiante*>();

    ui->pushButton->setEnabled(false);

    this->F = 0;

    ui->failed->setText(QString::number(F));
    ui->generations->setText(QString::number(numeroOleada));
    ui->inversiones->setText(QString::number(inversiones));
    ui->mutaciones->setText(QString::number(mutaciones));

    spawnTimer = new QTimer(this);

    flagOfIntialization = false;
    QPalette paleta;
    paleta.setColor(QPalette::WindowText, QColor(Qt::darkMagenta));
    QFont newFont("Suruma", 13, QFont::Bold, true);

    ui->label_2->setText(QString::number(this->player->getCreditosTotales()));
    ui->label_2->setGeometry(624,31,60,30);
    ui->label_2->setFont(newFont);
    ui->label_2->setPalette(paleta);


   QMediaPlayer *reproductor= new QMediaPlayer();
    // ...
   reproductor->setMedia(QUrl::fromLocalFile("/home/josecespedes/Downloads/cancion.mp3"));
    reproductor->setVolume(50);
    reproductor->play();

    //Zona de aprobación
    int I = 0;
    for(int j=0; j<10;j++){
        Parcela *zonaDeAprobacion = new Parcela(nullptr, ui->failed, ui->label_2);

        zonaDeAprobacion->setData(0,1);
        zonaDeAprobacion->setData(1,0);
        zonaDeAprobacion->setData(2,j);

        zonaDeAprobacion->setZValue(-1);
        zonaDeAprobacion->setGeometry(I,-54,54,54);
        I+=54;
        zonaDeAprobacion->setCheckable(false);

        zonaDeAprobacion->setPos(zonaDeAprobacion->geometry().x(),0);
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

            Parcela *parcela = new Parcela(nullptr, ui->failed, ui->label_2);

            //0 guarda si esta ocupado o no
            parcela->setData(0,1);
            parcela->setData(1,i);
            parcela->setData(2,j);

            parcela->setZValue(-1);
            parcela->setGeometry(K,S,54,54);
            parcela->setCheckable(false);

            parcela->setPos(parcela->geometry().x(),parcela->geometry().y()+54);



            connect(parcela,SIGNAL(clicked()),this,SLOT(handleButton()));

            if((i+j)%2==0){
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::darkCyan));
                parcela->setPalette(pal);
            }else{
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::white));
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
        Parcela *zonaDeSalida = new Parcela(nullptr, ui->failed, ui->label_2);
        zonaDeSalida->setData(0,1);
        zonaDeSalida->setData(1,11);
        zonaDeSalida->setData(2,j);

        zonaDeSalida->setZValue(-1);
        zonaDeSalida->setGeometry(B,542,54,54);
        zonaDeSalida->setCheckable(false);

        zonaDeSalida->setPos(zonaDeSalida->geometry().x(),zonaDeSalida->geometry().y()+54);

        B+=54;
        QPalette pal;
        pal.setColor(QPalette::Button, QColor(Qt::red));
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
   //std::cout<<pButton->QGraphicsPixmapItem::data(1).toInt()<<std::endl;
    //col
   // std::cout<<pButton->QGraphicsPixmapItem::data(2).toInt()<<std::endl;


    if (pButton)
    {
        if(pButton->isCheckable()){
            UpdateOrDestroy *upord = new UpdateOrDestroy(NULL, pButton, player, ui->label_2, this, pButton->QGraphicsPixmapItem::data(1).toInt(), pButton->QGraphicsPixmapItem::data(2).toInt(), oleada);
            upord->show();
        }
        if(!pButton->isCheckable()){
            ChooseTower *ch = new ChooseTower(nullptr, pButton, player, ui->label_2, this, pButton->QGraphicsPixmapItem::data(1).toInt(), pButton->QGraphicsPixmapItem::data(2).toInt(), oleada);
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

    if(numeroOleada == maxNumOfWaves){
        End*end = new End;
        end->show();
        hide();
    }

    srand(time(NULL));

    oleada = new QList<Estudiante*>();

    ui->pushButton->setEnabled(false);


    flagOfIntialization = true;

    int matrix[12][10];

    for(int n = 0; n<12; n++){
        for(int m = 0; m<10; m++){
            matrix[n][m] = QVariant(tablero[n][m]->data(0)).toInt();
        }
    }

    if(numeroOleada>0){

        GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm;


        geneticAlgorithm->setNextPopulation(enemiesInValidation);
        std::cout<<enemiesInValidation->size()<< std::endl;
        geneticAlgorithm->fitnessFunction();
        geneticAlgorithm->selection();
        geneticAlgorithm->reproduction();


        int probabilidadMutacion = 1 + (std::rand() % (100-1+1));
        int probabilidadInversion = 1 + (std::rand() % (100-1+1));


        if(probabilidadMutacion<=5){
            geneticAlgorithm->mutation();
            ui->mutaciones->setText(QString::number(++mutaciones));
        }
        if(probabilidadInversion == 6){
            geneticAlgorithm->inversion();
            ui->inversiones->setText(QString::number(++inversiones));
        }

        oleada = geneticAlgorithm->getOleada();
        ui->generations->setText(QString::number(++numeroOleada));

        for(int h = 0; h<3;h++){
            AStarAlgorithm *astar = new AStarAlgorithm(tablero);

            int randomSalida = std::rand()%10;
            int randomLlegada = std::rand()%10;

            std::pair<int, int> src = std::make_pair(11,randomSalida);
            std::pair<int, int> dest = std::make_pair(0,randomLlegada);

            astar->aStarSearch(matrix,src,dest);

            QList<QPointF> path;

            path = astar->getPath();

            oleada->at(h)->setPath(path);
            oleada->at(h)->typeofpath = 1;
            oleada->at(h)->columnaLlegada = randomLlegada;
            oleada->at(h)->coordFilas = astar->coordFilas;
            oleada->at(h)->coordColumnas = astar->coordColumnas;

        }


        for(int h = 3; h<30; h++){
            BackTracking *backtracking = new BackTracking(tablero);

            int randomSalida = std::rand()%10;
            int randomLlegada = std::rand()%10;

            backtracking->setColumnaSalida(randomSalida);
            backtracking->setColumnaLlegada(randomLlegada);
            backtracking->setFilaSalida(11);

            backtracking->solveMaze(matrix);

            QList<QPointF> path;

            path = backtracking->getPath();

            oleada->at(h)->setPath(path);
            oleada->at(h)->typeofpath = 0;
            oleada->at(h)->coordFilas = backtracking->getCoordFilas();
            oleada->at(h)->coordColumnas = backtracking->getCoordColumnas();
            oleada->at(h)->setPath(path);
        }


    }

    if(numeroOleada == 0){
        GeneticAlgorithm *geneticAlgorithm = new GeneticAlgorithm;

        geneticAlgorithm->initializePopulation();
        geneticAlgorithm->fitnessFunction();
        geneticAlgorithm->selection();
        geneticAlgorithm->reproduction();


        int probabilidadMutacion = 1 + (std::rand() % (100-1+1));
        int probabilidadInversion = 1 + (std::rand() % (100-1+1));


        if(probabilidadMutacion<=5){
            geneticAlgorithm->mutation();
            ui->mutaciones->setText(QString::number(++mutaciones));
        }
        if(probabilidadInversion == 6){
            geneticAlgorithm->inversion();
            ui->inversiones->setText(QString::number(++inversiones));

        }

        oleada = geneticAlgorithm->getOleada();

        ui->generations->setText(QString::number(++numeroOleada));

        for(int h = 0; h<3;h++){
            AStarAlgorithm *astar = new AStarAlgorithm(tablero);

            int randomSalida = std::rand()%10;
            int randomLlegada = std::rand()%10;

            std::pair<int, int> src = std::make_pair(11,randomSalida);
            std::pair<int, int> dest = std::make_pair(0,randomLlegada);

            astar->aStarSearch(matrix,src,dest);

            QList<QPointF> path;

            path = astar->getPath();

            oleada->at(h)->setPath(path);
            oleada->at(h)->typeofpath = 1;
            oleada->at(h)->columnaLlegada = randomLlegada;
            oleada->at(h)->coordFilas = astar->coordFilas;
            oleada->at(h)->coordColumnas = astar->coordColumnas;

        }


        for(int h = 3; h<30; h++){
            BackTracking *backtracking = new BackTracking(tablero);

            int randomSalida = std::rand()%10;
            int randomLlegada = std::rand()%10;

            backtracking->setColumnaSalida(randomSalida);
            backtracking->setColumnaLlegada(randomLlegada);
            backtracking->setFilaSalida(11);

            backtracking->solveMaze(matrix);

            QList<QPointF> path;

            path = backtracking->getPath();

            oleada->at(h)->setPath(path);
            oleada->at(h)->typeofpath = 0;
            oleada->at(h)->coordFilas = backtracking->getCoordFilas();
            oleada->at(h)->coordColumnas = backtracking->getCoordColumnas();
            oleada->at(h)->setPath(path);
        }
    }
    std::cout<<numeroOleada<<std::endl;

    enemiesSpawned = 0;
    maxNumberOfEnemies = oleada->size();
    connect(spawnTimer, SIGNAL(timeout()),this, SLOT(spawnEnemy()));
    spawnTimer->start(3500);

}

void Grid::spawnEnemy()
{
    enemiesInValidation->append(oleada->at(enemiesSpawned));

    scene->addItem(oleada->at(enemiesSpawned));
    oleada->at(enemiesSpawned)->start();
    enemiesSpawned+=1;

    if(enemiesSpawned>=maxNumberOfEnemies){
        spawnTimer->disconnect();
         ui->pushButton->setEnabled(true);
        oleada->clear();
    }
}

void Grid::verifyEnemyPos()
{
    for(int i=0; i<enemiesInValidation->size();i++){
        if(enemiesInValidation->at(i)->llego){
            End* end = new End;
            end->show();
            verifTimer->disconnect();
            return;
        }
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


void Grid::on_aprob_colectiva_clicked()
{


    maxNumOfWaves = NULL;

    col_mode *colectivo = new col_mode(nullptr, &maxNumOfWaves);
    colectivo->show();

    ui->pushButton->setEnabled(true);
    ui->aprob_individual->setVisible(false);
    ui->aprob_colectiva->setVisible(false);

}

void Grid::on_aprob_individual_clicked()
{
    ind_mode *individual = new ind_mode();
    individual->show();


    verifTimer = new QTimer(this);
    connect(verifTimer, SIGNAL(timeout()),this, SLOT(verifyEnemyPos()));
    verifTimer->start(1000);

    ui->pushButton->setEnabled(true);
    ui->aprob_individual->setVisible(false);
    ui->aprob_colectiva->setVisible(false);

}




