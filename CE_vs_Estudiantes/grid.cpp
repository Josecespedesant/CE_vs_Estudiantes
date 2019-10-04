#include "grid.h"
#include "ui_grid.h"

Grid::Grid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grid)
{
    ui->setupUi(this);
}

Grid::~Grid()
{
    delete ui;
}
