#pragma once
#include "Jugador.h"
#include "Minimax.h"

class JugadorIA:public Jugador{
private:
    Minimax motor;
public:
    JugadorIA(Color c);
    Movimiento decidir(const Tablero& tablero, int profundidad);
};