#pragma once

#include "Pieza.h"
class Caballo : public Pieza
{
public:
    Caballo(Color c);
    char getSimbolo()const override;
    std::vector<Movimiento>
    movimientosLegales(
        const Tablero& tablero,
        int fila,
        int columna
    ) const override;
};