#pragma once

#include "Pieza.h"
class Rey : public Pieza
{
public:
    Rey(Color c);
    char getSimbolo() const override;
    std::vector<Movimiento>
    movimientosLegales(
        const Tablero& tablero,
        int fila,
        int columna
    )const override;
};