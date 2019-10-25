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
#include "unistd.h"
#include <thread>
#include <iostream>

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

        zonaDeAprobacion->setData(0,0);
        zonaDeAprobacion->setData(1,0);
        zonaDeAprobacion->setData(2,j);

        zonaDeAprobacion->setZValue(-1);
        zonaDeAprobacion->setGeometry(I,-54,54,54);
        I+=54;
        zonaDeAprobacion->setCheckable(false);

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
            parcela->setData(0,0);
            parcela->setData(1,i);
            parcela->setData(2,j);


            parcela->setZValue(-1);
            parcela->setGeometry(K,S,54,54);
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
        zonaDeSalida->setData(0,0);
        zonaDeSalida->setData(1,11);
        zonaDeSalida->setData(2,j);


        zonaDeSalida->setZValue(-1);
        zonaDeSalida->setGeometry(B,542,54,54);
        zonaDeSalida->setCheckable(false);
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

void Grid::generateWave(QList<Estudiante *> oleada)
{
    for(int i=0; i<oleada.size();i++){
        Ogro * ogro = dynamic_cast<Ogro *>(oleada[i]);
        std::cout << i <<std::endl;
        if(ogro){
            ogro->setZValue(1);
            scene->addItem(ogro);
            usleep(1000000);
        }
    }
}

//Genera oleada
void Grid::on_pushButton_clicked()
{
std::cout<<std::endl;

    for(int x=0; x<12 ;x++)  // loop 3 times for three lines
        {
            for(int y=0;y<10;y++)  // loop for the three elements on the line
            {

                std::cout<< QVariant(tablero[x][y]->data(0)).toString().toStdString();  // display the current element out of the array
            }
        std::cout<<std::endl;  // when the inner loop is done, go to a new line
        }

    Ogro *ogro1 = new Ogro();
    Ogro *ogro2 = new Ogro();
    Ogro *ogro3 = new Ogro();
    Ogro *ogro4 = new Ogro();
    Ogro *ogro5 = new Ogro();
    oleada.append(ogro1);
   // oleada.append(ogro2);
    //oleada.append(ogro3);
    //oleada.append(ogro4);
    //oleada.append(ogro5);

    enemiesSpawned = 0;
    maxNumberOfEnemies = oleada.size();
    connect(spawnTimer, SIGNAL(timeout()),this, SLOT(spawnEnemy()));
    spawnTimer->start(3000);



}

void Grid::spawnEnemy()
{
    scene->addItem(oleada[enemiesSpawned]);
    enemiesSpawned+=1;

    if(enemiesSpawned>=maxNumberOfEnemies){
        spawnTimer->disconnect();
    }
}
