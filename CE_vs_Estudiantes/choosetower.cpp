#include "choosetower.h"
#include "ui_choosetower.h"
#include "iostream"
#include "arquero.h"
#include "artillero.h"
#include "lanzafuego.h"
#include "mago.h"

ChooseTower::ChooseTower(QWidget *parent, QPushButton* button) :
    QDialog(parent),
    ui(new Ui::ChooseTower)
{
    ui->setupUi(this);

    this->button = button;

    int h = ui->pushButton->height();
    int w = ui->pushButton->width();

    QPixmap pixmap("/home/josecespedes/CE_vs_Estudiantes/CE_vs_Estudiantes/images/tower1.png");
    QIcon ButtonIcon(pixmap.scaled(w,h,Qt::KeepAspectRatio));
    ui->pushButton->setIcon(ButtonIcon);
    ui->pushButton->setText("");
    ui->pushButton->setIconSize(pixmap.rect().size());

    QPixmap pixmap2("/home/josecespedes/CE_vs_Estudiantes/CE_vs_Estudiantes/images/tower2.png");
    QIcon ButtonIcon2(pixmap2.scaled(w,h,Qt::KeepAspectRatio));
    ui->pushButton_2->setIcon(ButtonIcon2);
    ui->pushButton_2->setText("");
    ui->pushButton_2->setIconSize(pixmap2.rect().size());

    QPixmap pixmap3("/home/josecespedes/CE_vs_Estudiantes/CE_vs_Estudiantes/images/tower3.png");
    QIcon ButtonIcon3(pixmap3.scaled(w,h,Qt::KeepAspectRatio));
    ui->pushButton_3->setIcon(ButtonIcon3);
    ui->pushButton_3->setText("");
    ui->pushButton_3->setIconSize(pixmap3.rect().size());

    QPixmap pixmap4("/home/josecespedes/CE_vs_Estudiantes/CE_vs_Estudiantes/images/tower4.png");
    QIcon ButtonIcon4(pixmap4.scaled(w,h,Qt::KeepAspectRatio));
    ui->pushButton_4->setIcon(ButtonIcon4);
    ui->pushButton_4->setText("");
    ui->pushButton_4->setIconSize(pixmap4.rect().size());

}

ChooseTower::~ChooseTower()
{
    delete ui;
}

void ChooseTower::on_pushButton_clicked()
{
    Arquero *arch = new Arquero();
    this->button->setCheckable(true);
    QPixmap pixm(ui->pushButton->icon().pixmap(button->width(),button->height()));
    arch->addPixmap(pixm);
    this->button->setIcon(*arch);
    this->button->setIconSize(pixm.rect().size());
    hide();
}

void ChooseTower::on_pushButton_2_clicked()
{
    Artillero *arty = new Artillero();
    this->button->setCheckable(true);
    QPixmap pixm(ui->pushButton_2->icon().pixmap(button->width(),button->height()));
    arty->addPixmap(pixm);
    this->button->setIcon(*arty);
    this->button->setIconSize(pixm.rect().size());
    hide();
}

void ChooseTower::on_pushButton_3_clicked()
{
    Mago *mag = new Mago();
    this->button->setCheckable(true);
    QPixmap pixm(ui->pushButton_3->icon().pixmap(button->width(),button->height()));
    mag->addPixmap(pixm);
    this->button->setIcon(*mag);
    this->button->setIconSize(pixm.rect().size());
    hide();
}

void ChooseTower::on_pushButton_4_clicked()
{
    LanzaFuego *fire = new LanzaFuego();
    this->button->setCheckable(true);
    QPixmap pixm(ui->pushButton_4->icon().pixmap(button->width(),button->height()));
    fire->addPixmap(pixm);
    this->button->setIcon(*fire);
    this->button->setIconSize(pixm.rect().size());
    hide();
}
