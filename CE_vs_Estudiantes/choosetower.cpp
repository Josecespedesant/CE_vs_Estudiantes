#include "choosetower.h"
#include "ui_choosetower.h"
#include "iostream"
#include "arquero.h"
#include "artillero.h"
#include "lanzafuego.h"
#include "mago.h"
ChooseTower::ChooseTower(QWidget *parent, Parcela* button, Player* player, QLabel* creditos, Grid *grid, int i, int j) :
    QDialog(parent),
    ui(new Ui::ChooseTower)
{
    ui->setupUi(this);

    this->button = button;
    this->player = player;
    this->creditos = creditos;
    this->grid = grid;

    this->i = i;
    this->j = j;

    int h = ui->pushButton->height();
    int w = ui->pushButton->width();

    if(player->getCreditosTotales() <= 0){
        QPixmap pixmap(":/images/qu.png");
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

        QPixmap pixmap2(":/images/qu.png");
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

        QPixmap pixmap4(":/images/qu.png");
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

    grid->tablero[i][j]->setData(0,1);

    hide();
}

void ChooseTower::on_pushButton_2_clicked()
{
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
