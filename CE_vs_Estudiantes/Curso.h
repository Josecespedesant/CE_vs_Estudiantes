#ifndef CURSO_H
#define CURSO_H
#include <QIcon>

/**
 * @class Curso
 * @brief Clase encargada de servir como clase padre del resto de cursos.
 */
class Curso{

protected:
    int cantCreditos;
    int cantHorasReales;
    int nivelExigencia;
    double velocidadEvaluacion;
    int alcance;
    double cooldown;
    int nivelActual;

public:
    /**
     * @brief Asigna la cantidad de créditos del curso.
     * @param cantCredi
     */
    void setCantCreditos(int cantCredi){
        this->cantCreditos = cantCredi;
    }
    /**
     * @brief Devuelve la cantidad de créditos del curso.
     * @return cantCreditos
     */
    int getCantCreditos(){
        return cantCreditos;
    }
    /**
     * @brief Asigna la cantidad de horas reales del curso.
     * @param cantHor
     */
    void setCantHorasReales(int cantHor){
        this->cantHorasReales = cantHor;
    }
    /**
     * @brief Devuelve la cantidad de horas reales del curso.
     * @return cantHorasReales
     */
    int getCantHorasReales(){
        return cantHorasReales;
    }
    /**
     * @brief Asigna el nivel de exigencia del curso.
     * @param cantCredi
     */
    void setNivelExigencia(int nivelExigencia){
        this->nivelExigencia = nivelExigencia;
    }
    /**
     * @brief Devuelve el nivel de exigencia del curso.
     * @return nivelExigencia
     */
    int getNivelExigencia(){
        return nivelExigencia;
    }
    /**
     * @brief Asigna la velocidad de evaluacion del curso.
     * @param cantCredi
     */
    void setVelocidadEvaluacion(double velocidad){
        this->velocidadEvaluacion = velocidad;
    }
    /**
     * @brief Devuelve la velocidad de evaluación del curso.
     * @return velocidadEvaluacion
     */
    double getVelocidadEvaluacion(){
        return velocidadEvaluacion;
    }
    /**
     * @brief Devuelve el alcance de evaluación del curso.
     * @return cantCreditos
     */
    int getAlcance(){
        return alcance;
    }
    /**
     * @brief Asigna el alcance de evaluación del curso.
     * @param cantCredi
     */
    void setAlcance(int alcance){
        this->alcance = alcance;
    }
    /**
     * @brief Devuelve el tiempo de recarga de evaluación del curso.
     * @return cantCreditos
     */
    double getCooldown(){
        return cooldown;
    }
    /**
     * @brief Asigna el tiempo de recarga de evaluació del curso.
     * @param cantCredi
     */
    void setCooldown(int cooldown){
        this->cooldown = cooldown;
    }

    /**
     * @brief Asigna el nivel actual del curso.
     * @param cantCredi
     */
    void setNivelActual(int nivel){
        this->nivelActual = nivel;
    }
    /**
     * @brief Devuelve el nivel actual del curso.
     * @return cantCreditos
     */
    int getNivelActual(){
        return nivelActual;
    }
    /**
     * @brief Mejora el nivel del curso si se tiene la cantidad necesaria de créditos.
     * @param creditos
     */
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
