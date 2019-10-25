#ifndef ASTAR_H
#define ASTAR_H

#include<bits/stdc++.h>
#include "Lista.h"
#include "grid.h"


using namespace std;

#define FILA 20
#define COLUMNA 20


class AStar {



    // Creating a shortcut for int, int pair type
    typedef pair<int, int> Pair;

// Creating a shortcut for pair<int, pair<int, int>> type
    typedef pair<double, pair<int, int>> pPair;

// Una estructura para mantener los parámetros necesarios.
    struct cell
    {
        // Índice de filas y columnas de su padre
        // Tenga en cuenta que 0 <= i <= ROW-1 & 0 <= j <= COL-1
        int parent_i, parent_j;
        // f = g + h
        double f, g, h;
    };


private:

// Una función de utilidad para verificar si una celda dada (fila, columna) es una celda válida o no
    bool isValid(int row, int col)
    {
        // Devuelve true si el número de fila y el número de columna esta en el rango
        return (row >= 0) && (row < FILA) &&
               (col >= 0) && (col < COLUMNA);
    }

// Una función de utilidad para verificar si la celda dada esta bloqueada o no
    bool isUnBlocked(int grid[][COLUMNA], int row, int col)
    {
        // Devuelve true si la celda NO está bloqueada
        if (grid[row][col] == 0)
            return (true);
        else
            return (false);
    }

// Una función de utilidad para verificar si se ha llegado a la celda de destino
    bool isDestination(int row, int col, Pair dest)
    {
        if (row == dest.first && col == dest.second)
            return (true);
        else
            return (false);
    }

// Una función de utilidad para calcular las heurísticas 'h'
    double calculateHValue(int row, int col, Pair dest)
    {
        // Regresa usando la fórmula de distancia
        return ((double)sqrt ((row-dest.first)*(row-dest.first)
                              + (col-dest.second)*(col-dest.second)));
    }

// Una función de utilidad para rastrear la ruta desde la fuente al destino
    void tracePath(cell cellDetails[][COLUMNA], Pair dest)
    {
        //Lista camino;
        printf ("   La Ruta del gladiador es ");
        int row = dest.first;
        int col = dest.second;

        stack<Pair> Path;

        while (!(cellDetails[row][col].parent_i == row
                 && cellDetails[row][col].parent_j == col ))
        {
            Path.push (make_pair (row, col));
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }

        Path.push (make_pair (row, col));
        while (!Path.empty())
        {
            pair<int,int> p = Path.top();
            Path.pop();
            printf("-> (%d,%d) ",p.first,p.second);

            //camino.anadir_final(p.first);
            //camino.anadir_final(p.second);

        }
        //printf ("\n se imprimira el camino  \n");
        //camino.print_lista();

        return;
    }

    Lista listaCamino(cell cellDetails[][COLUMNA]){
        Lista camino;

        int row = 19;
        int col = 19;

        stack<Pair> Path;

        while (!(cellDetails[row][col].parent_i == row
                 && cellDetails[row][col].parent_j == col ))
        {
            Path.push (make_pair (row, col));
            int temp_row = cellDetails[row][col].parent_i;
            int temp_col = cellDetails[row][col].parent_j;
            row = temp_row;
            col = temp_col;
        }

        Path.push (make_pair (row, col));
        while (!Path.empty())
        {
            pair<int,int> p = Path.top();
            Path.pop();
            //printf("-> (%d,%d) ",p.first,p.second);

            camino.anadir_final(p.first);
            camino.anadir_final(p.second);

        }
        printf ("\n \n *** se imprimira el camino en forma de lista (x1, y1, x2, y2, ... , xn, yn) \n");
        camino.print_lista();

        return camino;
    }

public:
    void analizarCamino(Pair inicio, Pair fin)
    {
        Grid matriz;

       // aStarSearch(matriz.grid,inicio,fin);

    }


public:
    // Una función para encontrar el camino más corto entre una celda de origen dada a una celda de destino
        Lista aStarSearch(int grid[][COLUMNA], Pair src, Pair dest)
        {
            Lista recorrido_Nulo;


            // Si la fuente está fuera de rango
            if (isValid (src.first, src.second) == false)
            {
                printf ("La celda de comienzo no es valida\n");
                return recorrido_Nulo;
            }

            // Si el destino está fuera de rango
            if (isValid (dest.first, dest.second) == false)
            {
                printf ("El destino no es valido\n");
                return recorrido_Nulo;
            }

            // O la fuente o el destino están bloqueados
            if (isUnBlocked(grid, src.first, src.second) == false ||
                isUnBlocked(grid, dest.first, dest.second) == false)
            {
                printf ("La fuente o el destino están bloqueados\n");
                return recorrido_Nulo;
            }

            // Si la celda de destino es la misma que la celda de origen
            if (isDestination(src.first, src.second, dest) == true)
            {
                printf ("La celda de destino es la misma que la celda de origen\n");
                return recorrido_Nulo;
            }

            // Crea una lista cerrada e inicializada en falso, lo que significa que aún no se ha incluido ninguna celda
            // Esta lista cerrada se implementa como una matriz 2D booleana
            bool closedList[FILA][COLUMNA];
            memset(closedList, false, sizeof (closedList));

            // Declara una matriz de estructura 2D para mantener los detalles de esa celda
            cell cellDetails[FILA][COLUMNA];

            int i, j;
            for (i=0; i<FILA; i++)
            {
                for (j=0; j<COLUMNA; j++)
                {
                    cellDetails[i][j].f = FLT_MAX;
                    cellDetails[i][j].g = FLT_MAX;
                    cellDetails[i][j].h = FLT_MAX;
                    cellDetails[i][j].parent_i = -1;
                    cellDetails[i][j].parent_j = -1;
                }
            }

            // Inicializando los parámetros del nodo inicial.
            i = src.first, j = src.second;
            cellDetails[i][j].f = 0.0;
            cellDetails[i][j].g = 0.0;
            cellDetails[i][j].h = 0.0;
            cellDetails[i][j].parent_i = i;
            cellDetails[i][j].parent_j = j;

            /*
            Crear una lista abierta con información <f, <i, j >> donde f = g + h,
            y i, j son el índice de fila y columna de esa celda
            Tenga en cuenta que 0 <= i <= ROW-1 & 0 <= j <= COL-1
            Esta lista abierta está implícita como un conjunto de pares. */

            set<pPair> openList;

            // Coloque la celda de inicio en la lista abierta y establezca su 'f' como 0
            openList.insert(make_pair (0.0, make_pair (i, j)));

            // Establecemos este valor booleano como falso porque inicialmente el destino no se ha alcanzado
            bool foundDest = false;

            while (!openList.empty())
            {
                pPair p = *openList.begin();

                // Eliminar este vértice de la lista abierta
                openList.erase(openList.begin());

                // Añadir este vértice a la lista cerrada
                i = p.second.first;
                j = p.second.second;
                closedList[i][j] = true;

                /*
                    Generando todas las 8 celdas adyacentes.
                         N.O   N   N.E
                            \  |  /
                             \ | /
                        O----Celda----E
                             / | \
                            /  |  \
                         S.O   S   S.E
                    Celda --> Celda analizada (i, j)
                    N --> Norte	       (i-1, j)
                    S --> Sur	       (i+1, j)
                    E --> Este	       (i, j+1)
                    O --> Oeste	       (i, j-1)
                    N.E--> NorEste     (i-1, j+1)
                    N.O--> NorOeste    (i-1, j-1)
                    S.E--> SurEste     (i+1, j+1)
                    S.O--> SurOeste    (i+1, j-1)
                */

                // Para almacenar la 'g', la 'h' y la 'f' de las 8 celdas adyacentes
                double gNew, hNew, fNew;

                //----------- 1st Sucesor (Norte) ------------

                // Procesa esta celda solo si es válida
                if (isValid(i-1, j) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    //
                    if (isDestination(i-1, j, dest) == true)
                    {
                        // Establece el padre de la celda de destino
                        cellDetails[i-1][j].parent_i = i;
                        cellDetails[i-1][j].parent_j = j;
                        printf ("La celda de destino se ha encontrado\n");
                        tracePath (cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }
                    //Si el sucesor NO está en el la lista cerrada. o si NO está bloqueado, entonces haga lo siguiente.
                    //De lo contrario ignorelo
                    else if (closedList[i-1][j] == false && isUnBlocked(grid, i-1, j) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.0;
                        hNew = calculateHValue (i-1, j, dest);
                        fNew = gNew + hNew;


                        // Si no está en la lista abierta, agrégela a la lista abierta.
                        //  Hacer el cuadrado actual el padre de esta celda.
                        //  Grabar el f, g, y h de la celda
                        //
                        // O si ya está en la lista abierta, verifique si este camino a ese cuadrado es el mejor usando f como la medida.

                        if (cellDetails[i-1][j].f == FLT_MAX ||
                            cellDetails[i-1][j].f > fNew)
                        {
                            openList.insert( make_pair(fNew,
                                                       make_pair(i-1, j)));

                            // Actualiza los detalles de esta celda.
                            cellDetails[i-1][j].f = fNew;
                            cellDetails[i-1][j].g = gNew;
                            cellDetails[i-1][j].h = hNew;
                            cellDetails[i-1][j].parent_i = i;
                            cellDetails[i-1][j].parent_j = j;
                        }
                    }
                }

                //----------- 2nd Sucesor (Sur) ------------

                // Procesa esta celda solo si es válida
                if (isValid(i+1, j) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination(i+1, j, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i+1][j].parent_i = i;
                        cellDetails[i+1][j].parent_j = j;
                        printf("La celda de destino se ha encontrado\n");
                        tracePath(cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }
                    // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                    // Sino haga lo siguiente
                    else if (closedList[i+1][j] == false &&
                             isUnBlocked(grid, i+1, j) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.0;
                        hNew = calculateHValue(i+1, j, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i+1][j].f == FLT_MAX ||
                            cellDetails[i+1][j].f > fNew)
                        {
                            openList.insert( make_pair (fNew, make_pair (i+1, j)));
                            // Actualizar los detalles de esta celda.
                            cellDetails[i+1][j].f = fNew;
                            cellDetails[i+1][j].g = gNew;
                            cellDetails[i+1][j].h = hNew;
                            cellDetails[i+1][j].parent_i = i;
                            cellDetails[i+1][j].parent_j = j;
                        }
                    }
                }

                //----------- 3rd Sucesor (Este) ------------

                // Procesa esta celda solo si es válida
                if (isValid (i, j+1) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination(i, j+1, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i][j+1].parent_i = i;
                        cellDetails[i][j+1].parent_j = j;
                        printf("La celda de destino se ha encontrado\n");
                        tracePath(cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }

                        // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                        // Sino haga lo siguiente
                    else if (closedList[i][j+1] == false &&
                             isUnBlocked (grid, i, j+1) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.0;
                        hNew = calculateHValue (i, j+1, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i][j+1].f == FLT_MAX ||
                            cellDetails[i][j+1].f > fNew)
                        {
                            openList.insert( make_pair(fNew,
                                                       make_pair (i, j+1)));

                            // Actualizar los detalles de esta celda.
                            cellDetails[i][j+1].f = fNew;
                            cellDetails[i][j+1].g = gNew;
                            cellDetails[i][j+1].h = hNew;
                            cellDetails[i][j+1].parent_i = i;
                            cellDetails[i][j+1].parent_j = j;
                        }
                    }
                }

                //----------- 4th Sucesor (Oeste) ------------

                // Solo procesar esta celda si esta es válida
                if (isValid(i, j-1) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination(i, j-1, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i][j-1].parent_i = i;
                        cellDetails[i][j-1].parent_j = j;
                        printf("La celda de destino se ha encontrado\n");
                        tracePath(cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }

                        // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                        // Sino haga lo siguiente
                    else if (closedList[i][j-1] == false &&
                             isUnBlocked(grid, i, j-1) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.0;
                        hNew = calculateHValue(i, j-1, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i][j-1].f == FLT_MAX ||
                            cellDetails[i][j-1].f > fNew)
                        {
                            openList.insert( make_pair (fNew,
                                                        make_pair (i, j-1)));

                            // Actualizar los detalles de esta celda.
                            cellDetails[i][j-1].f = fNew;
                            cellDetails[i][j-1].g = gNew;
                            cellDetails[i][j-1].h = hNew;
                            cellDetails[i][j-1].parent_i = i;
                            cellDetails[i][j-1].parent_j = j;
                        }
                    }
                }

                //----------- 5th Sucesor (NorEste) ------------

                // Solo procesar esta celda si esta es válida
                if (isValid(i-1, j+1) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination(i-1, j+1, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i-1][j+1].parent_i = i;
                        cellDetails[i-1][j+1].parent_j = j;
                        printf ("La celda de destino se ha encontrado\n");
                        tracePath (cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }

                        // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                        // Sino haga lo siguiente
                    else if (closedList[i-1][j+1] == false &&
                             isUnBlocked(grid, i-1, j+1) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.414;
                        hNew = calculateHValue(i-1, j+1, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i-1][j+1].f == FLT_MAX ||
                            cellDetails[i-1][j+1].f > fNew)
                        {
                            openList.insert( make_pair (fNew,
                                                        make_pair(i-1, j+1)));

                            // Actualizar los detalles de esta celda.
                            cellDetails[i-1][j+1].f = fNew;
                            cellDetails[i-1][j+1].g = gNew;
                            cellDetails[i-1][j+1].h = hNew;
                            cellDetails[i-1][j+1].parent_i = i;
                            cellDetails[i-1][j+1].parent_j = j;
                        }
                    }
                }

                //----------- 6th Sucesor (NorOeste) ------------

                // Solo procesar esta celda si esta es válida
                if (isValid (i-1, j-1) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination (i-1, j-1, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i-1][j-1].parent_i = i;
                        cellDetails[i-1][j-1].parent_j = j;
                        printf ("La celda de destino se ha encontrado\n");
                        tracePath (cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }

                        // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                        // Sino haga lo siguiente
                    else if (closedList[i-1][j-1] == false &&
                             isUnBlocked(grid, i-1, j-1) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.414;
                        hNew = calculateHValue(i-1, j-1, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i-1][j-1].f == FLT_MAX ||
                            cellDetails[i-1][j-1].f > fNew)
                        {
                            openList.insert( make_pair (fNew, make_pair (i-1, j-1)));
                            // Actualizar los detalles de esta celda.
                            cellDetails[i-1][j-1].f = fNew;
                            cellDetails[i-1][j-1].g = gNew;
                            cellDetails[i-1][j-1].h = hNew;
                            cellDetails[i-1][j-1].parent_i = i;
                            cellDetails[i-1][j-1].parent_j = j;
                        }
                    }
                }

                //----------- 7th Sucesor (SurEste) ------------

                // Solo procesar esta celda si esta es válida
                if (isValid(i+1, j+1) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination(i+1, j+1, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i+1][j+1].parent_i = i;
                        cellDetails[i+1][j+1].parent_j = j;
                        printf ("La celda de destino se ha encontrado\n");
                        tracePath (cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }

                        // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                        // Sino haga lo siguiente
                    else if (closedList[i+1][j+1] == false &&
                             isUnBlocked(grid, i+1, j+1) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.414;
                        hNew = calculateHValue(i+1, j+1, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i+1][j+1].f == FLT_MAX ||
                            cellDetails[i+1][j+1].f > fNew)
                        {
                            openList.insert(make_pair(fNew,
                                                      make_pair (i+1, j+1)));

                            // Actualizar los detalles de esta celda.
                            cellDetails[i+1][j+1].f = fNew;
                            cellDetails[i+1][j+1].g = gNew;
                            cellDetails[i+1][j+1].h = hNew;
                            cellDetails[i+1][j+1].parent_i = i;
                            cellDetails[i+1][j+1].parent_j = j;
                        }
                    }
                }

                //----------- 8th Sucesor (SurOeste) ------------

                // Solo procesar esta celda si esta es válida
                if (isValid (i+1, j-1) == true)
                {
                    // Si la celda de destino es la misma que el sucesor actual
                    if (isDestination(i+1, j-1, dest) == true)
                    {
                        // Establecer el padre de la celda de destino
                        cellDetails[i+1][j-1].parent_i = i;
                        cellDetails[i+1][j-1].parent_j = j;
                        printf("La celda de destino se ha encontrado\n");
                        tracePath(cellDetails, dest);




                        foundDest = true;
                        return listaCamino(cellDetails);
                    }

                        // Si el sucesor ya está en la lista cerrada o si está bloqueado, ignorarlo.
                        // Sino haga lo siguiente
                    else if (closedList[i+1][j-1] == false &&
                             isUnBlocked(grid, i+1, j-1) == true)
                    {
                        gNew = cellDetails[i][j].g + 1.414;
                        hNew = calculateHValue(i+1, j-1, dest);
                        fNew = gNew + hNew;

                        // Si no está en la lista abierta, agrégala a la lista abierta.
                        // Hacer el cuadrado actual el padre de esta celda.
                        // Grabar el f, g, y h de la celda
                        // O
                        // Si ya está en la lista abierta, verifique si este camino a ese cuadrado es mejor usando f como la medida

                        if (cellDetails[i+1][j-1].f == FLT_MAX ||
                            cellDetails[i+1][j-1].f > fNew)
                        {
                            openList.insert(make_pair(fNew,
                                                      make_pair(i+1, j-1)));

                            // Actualizar los detalles de esta celda.
                            cellDetails[i+1][j-1].f = fNew;
                            cellDetails[i+1][j-1].g = gNew;
                            cellDetails[i+1][j-1].h = hNew;
                            cellDetails[i+1][j-1].parent_i = i;
                            cellDetails[i+1][j-1].parent_j = j;
                        }
                    }
                }
            }


            // Cuando la celda de destino no se encuentra y la lista está vacía
            // entonces llegamos a la conclusión de que no pudimos llegar a la celda de destino
            // Esto puede suceder cuando no hay manera de llegar a la celda de destino (debido a bloqueos)
            if (foundDest == false)
                printf("Error al encontrar la celda de destino (no se encontro una ruta\n");



            return recorrido_Nulo;
        }

};





#endif // ASTAR_H
