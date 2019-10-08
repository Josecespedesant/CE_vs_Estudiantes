#include "parcela.h"
#include "iostream"
#include <typeinfo>

bool Parcela::isOcupada(){
    return this->ocupada;
}

void Parcela::setOcupada(bool isocupada){
    this->ocupada = isocupada;
}

void Parcela::setType(QString tipo){

    if(tipo.toStdString().compare("Archer") == 0){
        arch = new Arquero();
        arch->setNivelActual(1);
    }
    else if(tipo.toStdString().compare("Gunner") == 0){
        gunner = new Artillero();
        gunner->setNivelActual(1);
    }
    else if(tipo.toStdString().compare("Mage") == 0){
        mago = new Mago();
        mago->setNivelActual(1);
    }
    else if(tipo.toStdString().compare("Fire") == 0){
        fire = new LanzaFuego();
        fire->setNivelActual(1);
    }
    else if(tipo.toStdString().compare("") == 0){
        if(this->objectName().toStdString().compare("Arch") == 0){
            arch = nullptr;
            arch->setNivelActual(0);
        }
        else if(this->objectName().toStdString().compare("Arty") == 0){
            gunner = nullptr;
            gunner->setNivelActual(0);
         }
        else if(this->objectName().toStdString().compare("Mago") == 0){
            mago = nullptr;
            mago->setNivelActual(0);
        }
        else if(this->objectName().toStdString().compare("Fire") == 0){
            fire = nullptr;
            fire->setNivelActual(0);
        }
    }

}


Arquero* Parcela::getArquero(){
    return this->arch;
}

Artillero* Parcela::getArtillero(){
    return this->gunner;
}

Mago* Parcela::getMago(){
    return this->mago;
}

LanzaFuego* Parcela::getLanzaFuego(){
    return this->fire;
}
