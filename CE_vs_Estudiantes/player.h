#ifndef PLAYER_H
#define PLAYER_H

/**
 * @brief The Player class
 */
class Player
{
private:
    int creditosTotales;

public:
    /**
     * @brief Player
     * @param creditos
     */
    Player(int creditos);
    /**
     * @brief Obtiene creditos del jugador
     * @return creditos
     */
    int getCreditosTotales();
    /**
     * @brief set Creditos Totales del jugador
     * @param creditos
     */
    void setCreditosTotales(int creditos);



};

#endif // PLAYER_H
