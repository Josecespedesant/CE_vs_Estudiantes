#include "mainwindow.h"
#include <QApplication>
#include "arquero.h"
#include <iostream>
#include "grid.h"
#include "BackTracking.h"

Grid * grid;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Player *player = new Player(1000);
    BackTracking backTrack;
        int maze[N][N] = { { 1, 0, 0, 0 },
                           { 1, 1, 0, 1 },
                           { 0, 1, 0, 0 },
                           { 1, 1, 1, 1 } };

        backTrack.solveMaze(maze);
    //MainWindow w;
    //w.show();
    grid = new Grid(nullptr, player);
    grid->show();
    return a.exec();
}
