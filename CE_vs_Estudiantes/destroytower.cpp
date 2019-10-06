#include "destroytower.h"
#include "ui_destroytower.h"

DestroyTower::DestroyTower(QWidget *parent, QPushButton *button) :
    QDialog(parent),
    ui(new Ui::DestroyTower)
{
    ui->setupUi(this);
    this->button = button;
}

DestroyTower::~DestroyTower()
{
    delete ui;
}

void DestroyTower::on_pushButton_2_clicked()
{
    this->button->setCheckable(true);
    hide();
}

void DestroyTower::on_pushButton_clicked()
{
    this->button->setCheckable(false);
    this->button->setIcon(QIcon());
    hide();
}
