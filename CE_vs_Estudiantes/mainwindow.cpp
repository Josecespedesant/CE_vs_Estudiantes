#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Grid *g = new Grid();
    g->show();
    hide();
}
