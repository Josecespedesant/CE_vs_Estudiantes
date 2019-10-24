#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <iostream>
#include <zconf.h>
#include "Lista.h"

using namespace std;

class BackTrack {
    Lista camino;
    Lista backtrack;
    int inicioX = 0;
    int inicioY = 0;
    int finalX = 19;
    int finalY = 19;
    int actualX = inicioX;
    int actualY = inicioY;
    int grid[20][20];

    // habilitado = 0
    // bloqueado =1

public:
    void setGrid(int matriz[20][20]) {

        for (int i = 0; i < 20; i++) {


            for (int h = 0; h < 20; h++) {
                grid[i][h] = matriz[h][i];

                cout<<grid[i][h]<<" ";
            }
            cout<<endl;
        }
    }

public:
    Lista backTracking(int grid[20][20]){

        camino.anadir_final(actualX);
        camino.anadir_final(actualY);
        backtrack.anadir_final(actualX);
        backtrack.anadir_final(actualY);
        cout << "\n--------------------------  coordenadas  (X, Y)  -----------------------\n";
        cout << "\n***  INICIO  ***  >>> ("<<actualX<<", "<<actualY<<")\n";
        while(actualY <= finalY && actualX <= finalX) {

            if (actualY==finalY && actualX==finalX){
                cout << "\n***  El gladiador llego a su destino  ***  >>> ("<<actualX<<", "<<actualY<<")\n";
                camino.print_lista();
                return camino;
            }
            else if (actualY==finalY && actualX<finalX){
                if(grid[actualY][actualX+1]==0){
                    actualX+=1;
                    camino.anadir_final(actualX);
                    camino.anadir_final(actualY);
                    backtrack.anadir_final(actualX);
                    backtrack.anadir_final(actualY);
                    cout << "\n llego al borde inferior pero no ha llegado al objetivo  ***  se movera hacia la derecha  ***  >>> ("<<actualX<<", "<<actualY<<")\n";
                    sleep(1);
                } else if(grid[actualY][actualX+1]!=0){
                    while(grid[actualY][actualX+1]!=0){
                        if(actualY==0){
                            cout << "\n -----  no hay camino  ----- \n";
                            sleep(1);
                            return camino;
                        } else if (grid[actualY-1][actualX+1] == 0) {
                            actualY-=1;
                            actualX+=1;
                            camino.anadir_final(actualX);
                            camino.anadir_final(actualY);
                            backtrack.anadir_final(actualX);
                            backtrack.anadir_final(actualY);
                            cout << "\n se mueve en diagonal hacia arriba y hacia la derecha  >>> ("<<actualX<<", "<<actualY<<")\n";
                            sleep(1);
                        } else if (grid[actualY-1][actualX] == 0) {
                            actualY -= 1;
                            camino.anadir_final(actualX);
                            camino.anadir_final(actualY);
                            backtrack.anadir_final(actualX);
                            backtrack.anadir_final(actualY);
                            cout << "\n se mueve hacia arriba   >>> ("<<actualX<<", "<<actualY<<")\n";
                            sleep(1);
                        }
                    }
                }
            } else if (actualX==finalX && actualY<finalY){
                if(grid[actualY+1][actualX]==0){
                    actualY+=1;
                    camino.anadir_final(actualX);
                    camino.anadir_final(actualY);
                    backtrack.anadir_final(actualX);
                    backtrack.anadir_final(actualY);
                    cout << "\n llego al borde derecho pero no ha llegado al objetivo  ***  se movera hacia abajo  ***   >>> ("<<actualX<<", "<<actualY<<")\n";
                    sleep(1);
                } else if(grid[actualY+1][actualX]!=0){
                    while(grid[actualY+1][actualX]!=0){
                        if(actualX==0){
                            cout << "\n -----  no hay camino  ----- \n";
                            sleep(1);
                            return camino;
                        } else if (grid[actualY+1][actualX-1] == 0) {
                            actualY+=1;
                            actualX-=1;
                            camino.anadir_final(actualX);
                            camino.anadir_final(actualY);
                            backtrack.anadir_final(actualX);
                            backtrack.anadir_final(actualY);
                            cout << "\n se mueve en diagonal hacia abajo y hacia la izquierda   >>> ("<<actualX<<", "<<actualY<<")\n";
                            sleep(1);
                        } else if (grid[actualY][actualX-1] == 0) {
                            actualX -= 1;
                            camino.anadir_final(actualX);
                            camino.anadir_final(actualY);
                            backtrack.anadir_final(actualX);
                            backtrack.anadir_final(actualY);
                            cout << "\n se mueve hacia la izquierda   >>> ("<<actualX<<", "<<actualY<<")\n";
                            sleep(1);
                        }
                    }
                }
            } else if(actualY<finalY && actualX<finalX) {
                if (grid[actualY + 1][actualX + 1] == 0) {
                    actualX += 1;
                    actualY += 1;
                    camino.anadir_final(actualX);
                    camino.anadir_final(actualY);
                    backtrack.anadir_final(actualX);
                    backtrack.anadir_final(actualY);
                    cout << "\n se mueve en diagonal hacia abajo y hacia la derecha   >>> ("<<actualX<<", "<<actualY<<")\n";
                    sleep(1);
                } else if (grid[actualY][actualX + 1] == 0) {
                    actualX += 1;
                    camino.anadir_final(actualX);
                    camino.anadir_final(actualY);
                    backtrack.anadir_final(actualX);
                    backtrack.anadir_final(actualY);
                    cout << "\n se mueve hacia la derecha   >>> ("<<actualX<<", "<<actualY<<")\n";
                    sleep(1);
                } else if (grid[actualY + 1][actualX] == 0) {
                    actualY += 1;
                    camino.anadir_final(actualX);
                    camino.anadir_final(actualY);
                    backtrack.anadir_final(actualX);
                    backtrack.anadir_final(actualY);
                    cout << "\n se mueve hacia abajo   >>> ("<<actualX<<", "<<actualY<<")\n";
                    sleep(1);
                } else{
                    actualX=backtrack.obtener_dato(backtrack.tamano()-4);
                    actualY=backtrack.obtener_dato(backtrack.tamano()-3);

                    camino.anadir_final(actualX);
                    camino.anadir_final(actualY);

                    grid[backtrack.obtener_dato(backtrack.tamano()-1)][backtrack.obtener_dato(backtrack.tamano()-2)]=1;

                    backtrack.borrar_Dato((backtrack.tamano()-1));
                    backtrack.borrar_Dato((backtrack.tamano()-1));

                    cout << "\n se devuelve porque el camino esta bloqueado   >>> ("<<actualX<<", "<<actualY<<")\n";
                    sleep(1);

                }
            }



        }
        return camino;


    }
};


#endif // BACKTRACKING_H
