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
