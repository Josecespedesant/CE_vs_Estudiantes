#ifndef CURSO_H
#define CURSO_H

class Curso{

protected:
    int cantCreditos;
    int cantHorasReales;
    int nivelExigencia;
    double velocidadEvaluacion;
    int alcance;
    double cooldown;

public:
    void setCantCreditos(int cantCredi){
        this->cantCreditos = cantCredi;
    }
    int getCantCreditos(){
        return cantCreditos;
    }
    void setCantHorasReales(int cantHor){
        this->cantHorasReales = cantHor;
    }
    int getCantHorasReales(){
        return cantHorasReales;
    }
    void setNivelExigencia(int nivelExigencia){
        this->nivelExigencia = nivelExigencia;
    }
    int getNivelExigencia(){
        return nivelExigencia;
    }
    void setVelocidadEvaluacion(double velocidad){
        this->velocidadEvaluacion = velocidad;
    }
    double getVelocidadEvaluacion(){
        return velocidadEvaluacion;
    }
    int getAlcance(){
        return alcance;
    }
    void setAlcance(int alcance){
        this->alcance = alcance;
    }
    double getCooldown(){
        return cooldown;
    }
    void setCooldown(int cooldown){
        this->cooldown = cooldown;
    }
    void upgrade(int *creditos){
        if(*creditos >= getCantCreditos()){
            *creditos -= getCantCreditos();
            setAlcance(getAlcance()+1);
            setCantCreditos(getCantCreditos()+1);
            setCantHorasReales(getCantHorasReales()+1);
            setNivelExigencia(getNivelExigencia()+1);
            setVelocidadEvaluacion(getVelocidadEvaluacion()+0.5);
        }
    }
};

#endif // CURSO_H
