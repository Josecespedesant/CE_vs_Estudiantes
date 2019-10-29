#include "ind_mode.h"
#include "ui_ind_mode.h"

ind_mode::ind_mode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ind_mode)
{
    ui->setupUi(this);
}

ind_mode::~ind_mode()
{
    delete ui;
}

void ind_mode::on_pushButton_clicked()
{
    this->close();
}
