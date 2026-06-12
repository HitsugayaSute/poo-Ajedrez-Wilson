#pragma once

#include "Pieza.h"
class Torre : public Pieza
{
public:
    Torre(Color c);
    char getSimbolo() const override;
    std::vector<Movimiento>
    movimientosLegales(
        const Tablero& tablero,
        int fila,
        int columna
    ) const override;
};