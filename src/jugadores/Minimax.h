#pragma once
#include "../piezas/Movimientos.h"
#include "../piezas/Pieza.h"
class Tablero;
class Minimax{
public:
    Movimiento mejorMovimiento(const Tablero& tablero, int profundidad, Color iaColor);
private:
    int minimax(Tablero tablero, int profundidad, int alpha, int beta, bool maximizando, Color iaColor);
};