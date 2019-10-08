#include "warningmaxlvl.h"
#include "ui_warningmaxlvl.h"

WarningMaxLvl::WarningMaxLvl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WarningMaxLvl)
{
    ui->setupUi(this);
}

WarningMaxLvl::~WarningMaxLvl()
{
    delete ui;
}

void WarningMaxLvl::on_pushButton_clicked()
{
    hide();
}
