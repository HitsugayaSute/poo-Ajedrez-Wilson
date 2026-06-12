#pragma once
#include "Pieza.h"

class Alfil:public Pieza{
public:
    Alfil(Color c);
    char getSimbolo()const override;
    std::vector<Movimiento> movimientosLegales(const Tablero& tablero, int fila, int columna)const override;
    std::shared_ptr<Pieza> clonar()const override;
};