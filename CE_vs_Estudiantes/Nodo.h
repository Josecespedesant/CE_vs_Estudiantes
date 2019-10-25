#ifndef NODO_H
#define NODO_H

#include <iostream>

/// Clase necesaria para que lla clase lista funcione
class Nodo {

public: Nodo* siguiente;
public: int Dato;

    Nodo (int dato){
        Dato = dato;
        siguiente = NULL;
    }
};

#endif // NODO_H
