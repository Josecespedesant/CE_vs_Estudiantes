#ifndef NODO_H
#define NODO_H


class Nodo {

public: Nodo* siguiente;
public: int data;


    Nodo (int data){
        data= data;
        siguiente = NULL;
    }
};


#endif // NODO_H
