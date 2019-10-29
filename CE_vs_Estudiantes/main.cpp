#include "mainwindow.h"
#include <QApplication>
#include "arquero.h"
#include <iostream>
#include "grid.h"

Grid * grid;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player *player = new Player(30);

    //MainWindow w;
    //w.show();
    grid = new Grid(nullptr, player);
    grid->show();
    return a.exec();
}
