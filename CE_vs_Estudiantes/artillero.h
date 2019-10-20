#ifndef ARTILLERO_H
#define ARTILLERO_H

#include <Curso.h>

/**
 * @class Artillero
 * @brief Clase encargada de representar al artillero.
 */
class Artillero : public Curso, public QIcon
{
public:
    /**
     * @brief Constructor de la clase Artillero.
     */
    Artillero();
};

#endif // ARTILLERO_H
