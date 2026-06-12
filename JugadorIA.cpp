#include "JugadorIA.h"

JugadorIA::JugadorIA(
    Color c
)
:
Jugador(c){}
Movimiento JugadorIA::decidir(
    Tablero tablero,
    int profundidad
)
{
    return motor.mejorMovimiento(tablero, profundidad);
}