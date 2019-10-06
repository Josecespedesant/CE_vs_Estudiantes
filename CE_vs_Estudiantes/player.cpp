#include "player.h"

Player::Player(int creditos)
{
    this->creditosTotales = creditos;
}

int Player::getCreditosTotales(){
    return creditosTotales;
}

void Player::setCreditosTotales(int creditos){
    this->creditosTotales = creditos;
}
