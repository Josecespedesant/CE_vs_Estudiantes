#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <stdio.h>
#include "iostream"
#include "QGraphicsPixmapItem"
#include <QList>
#include <QPointF>

class BackTracking{
public:

    QGraphicsPixmapItem* tablero[12][10] {};

    int filaSalida;
    int columnaSalida;

    int columnaLlegada;


    QList<QPointF> path;
    QList<int> coordFilas;
    QList<int> coordColumnas;


    BackTracking(QGraphicsPixmapItem* tablero[12][10]){

        for(int i = 0; i<12; i++){
            for(int j = 0; j<10; j++){
                this->tablero[i][j] = tablero[i][j];
            }
        }
        path = QList<QPointF>();
        coordColumnas = QList<int>();
        coordFilas = QList<int>();
    }

    QList<QPointF> getPath(){
        std::cout <<path.size()<<std::endl;
        return path;
    }

    QList<int> getCoordFilas(){
        return coordFilas;
    }

    QList<int> getCoordColumnas(){
        return coordColumnas;
    }


    void setFilaSalida(int filaSalida){
        this->filaSalida = filaSalida;
    }

    void setColumnaSalida(int columnaSalida){
        this->columnaSalida = columnaSalida;
    }

    void setColumnaLlegada(int columnaLlegada){
        this->columnaLlegada = columnaLlegada;
    }

    void printSolution(int sol[12][10]){
        for(int i = 0; i<12; i++){
            for (int j = 0; j < 10; j++)
                        printf(" %d ", sol[i][j]);
                    printf("\n");
        }
    }

    bool isSafe(int maze[12][10], int x, int y)
    {
        if (x >= 0 && x < 12 && y >= 0 && y < 10 && maze[x][y] == 1)
            return true;

        return false;
    }

    bool solveMaze(int maze[12][10])
    {
        int sol[12][10] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                          { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }};
                                //variar y random
        if (solveMazeUtil(maze, filaSalida, columnaSalida, sol) == false) {
            printf("Solution doesn't exist");
            return false;
        }

        printSolution(sol);
        return true;
    }

    bool solveMazeUtil(int maze[12][10], int x, int y, int sol[12][10])
    {
        // if (x, y is goal) return true
        if (x == 0 && y == columnaLlegada) { //variar y
            sol[x][y] = 1;
            path.append(tablero[x][y]->pos());
            coordFilas.append(x);
            coordColumnas.append(y);
            return true;
        }

        // Check if maze[x][y] is valid
        if (isSafe(maze, x, y) == true) {
            // mark x, y as part of solution path
            sol[x][y] = 1;
            path.append(tablero[x][y]->pos());
            coordFilas.append(x);
            coordColumnas.append(y);


            if(columnaSalida<=columnaLlegada){
                if (solveMazeUtil(maze, x - 1, y, sol) == true)
                    return true;

                if (solveMazeUtil(maze, x, y + 1, sol) == true)
                    return true;
                if (solveMazeUtil(maze, x -1  , y + 1, sol) == true && maze[x-1][y] != 0 && maze[x][y+1] != 0)
                    return true;
            }

            if(columnaSalida>columnaLlegada){
                if (solveMazeUtil(maze, x - 1, y, sol) == true)
                    return true;

                if (solveMazeUtil(maze, x , y - 1, sol) == true)
                    return true;

                if (solveMazeUtil(maze, x -1 , y - 1, sol) == true&& maze[x-1][y] != 0 && maze[x][y-1] != 0)
                    return true;
            }


            /* If none of the above movements work then BACKTRACK:
                unmark x, y as part of solution path */
            sol[x][y] = 0;
            return false;
        }

        return false;
    }

};


#endif // BACKTRACKING_H
