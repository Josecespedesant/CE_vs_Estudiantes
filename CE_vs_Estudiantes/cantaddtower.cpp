#include "cantaddtower.h"
#include "ui_cantaddtower.h"

CantAddTower::CantAddTower(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CantAddTower)
{
    ui->setupUi(this);
}

CantAddTower::~CantAddTower()
{
    delete ui;
}

void CantAddTower::on_pushButton_clicked()
{
    hide();
}
