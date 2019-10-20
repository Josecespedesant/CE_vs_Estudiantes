#ifndef ARQUERO_H
#define ARQUERO_H

#include <Curso.h>
#include <QIcon>

/**
 * @class Arquero
 * @brief Clase encargada de representar al arquero.
 */
class Arquero : public Curso, public QIcon
{
public:
    /**
     * @brief Constructor de la clase arquero.
     */
    Arquero();
};

#endif // ARQUERO_H
