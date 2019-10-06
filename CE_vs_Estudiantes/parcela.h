#ifndef PARCELA_H
#define PARCELA_H

#define X_MAX 560
#define X_STEP 10
#define Y_MAX 660
#define Y_STEP 10

#include <QPushButton>
class Parcela : public QPushButton
{
private:
    bool ocupada;
    int y;
    int x;
    int parentX;
    int parentY;
    float gCost;
    float hCost;
    float fCost;

public:
    Parcela();
    bool isOcupada();
    void setOcupada(bool isocupada);
};

#endif // PARCELA_H
