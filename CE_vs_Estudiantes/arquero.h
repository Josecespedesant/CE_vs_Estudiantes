#ifndef ARQUERO_H
#define ARQUERO_H

#include <Curso.h>
#include <QIcon>

class Arquero : public Curso, public QIcon
{
public:
    Arquero();
    ~Arquero();
};

#endif // ARQUERO_H
