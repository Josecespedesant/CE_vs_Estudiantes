#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include "player.h"
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
    Player *player = new Player(10);
    Grid *g = new Grid(nullptr,player);
    g->show();
    hide();
}
