#pragma once

#include "Pieza.h"
class Peon : public Pieza
{
public:
    Peon(Color c);
    char getSimbolo() const override;
    std::vector<Movimiento>
    movimientosLegales(
        const Tablero& tablero,
        int fila,
        int columna
    ) const override;
};