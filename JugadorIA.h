JugadorIA.h

#pragma once
#include "Jugador.h"
#include "Minimax.h"

class JugadorIA
    : public Jugador
{
private:
    Minimax motor;
public:
    JugadorIA(Color c);
    Movimiento decidir(
        Tablero tablero,
        int profundidad
    );
};