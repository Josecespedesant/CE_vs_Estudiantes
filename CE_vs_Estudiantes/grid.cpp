#include "grid.h"
#include "ui_grid.h"
#include "QLabel"
#include "iostream"
#include "choosetower.h"
#include "destroytower.h"
Grid::Grid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);

    QPushButton grid[10][10];


    QLabel *zonadeaprobacion = new QLabel();
    zonadeaprobacion->setFixedSize(600,50);
    zonadeaprobacion->setStyleSheet("QLabel { background-color : blue; color : blue; }");
    zonadeaprobacion->setText("Zona de aprobación");
    zonadeaprobacion->setAlignment(Qt::AlignCenter);
    ui->gridLayout->addWidget(zonadeaprobacion,0,0);


    for(int i=1; i<11; i++){
        for(int j=0; j<10;j++){
            QPushButton *push = new QPushButton();
            push->setFixedSize(50,50);
            push->setCheckable(false);
            connect(push,SIGNAL(clicked()),this,SLOT(handleButton()));

            if((i+j)%2==0){
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::green));
                push->setPalette(pal);
                ui->gridLayout->addWidget(push, i, j);

            }else{
                QPalette pal;
                pal.setColor(QPalette::Button, QColor(Qt::darkGreen));
                push->setPalette(pal);
                ui->gridLayout->addWidget(push, i, j);

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
            if(pButton->isChecked()){
                DestroyTower *dr = new DestroyTower(nullptr, pButton);
                dr->show();

            }else{
                ChooseTower *ch = new ChooseTower(nullptr, pButton);
                ch->show();
            }
         }
}

Grid::~Grid()
{
    delete ui;
}
