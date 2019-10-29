#include "col_mode.h"
#include "ui_col_mode.h"
#include <sstream>
#include <iostream>

col_mode::col_mode(QWidget *parent, int* max) :
    QDialog(parent),
    ui(new Ui::col_mode)
{
    ui->setupUi(this);

    this->max = max;
}

col_mode::~col_mode()
{
    delete ui;
}

void col_mode::on_pushButton_clicked()
{
    if(checkInt(ui->lineEdit)){

        std::string info = ui->lineEdit->text().toStdString();

        std::stringstream conv(info);

        int x = 0;

        conv >> x;

        *max = x;

        hide();

    }else{
        ui->lineEdit->clear();
        ui->label->setText("Please insert a number");
    }

}

bool col_mode::checkInt(QLineEdit *text)
{
    std::string realtext = text->text().toStdString();

      std::string::const_iterator it = realtext.begin();
         while (it != realtext.end() && std::isdigit(*it)) ++it;
         return !realtext.empty() && it == realtext.end();
}
