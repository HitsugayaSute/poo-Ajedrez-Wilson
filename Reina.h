#pragma once

#include "Pieza.h"
class Reina : public Pieza
{
public:
    Reina(Color c);
    char getSimbolo() const override;
    std::vector<Movimiento>
    movimientosLegales(
        const Tablero& tablero,
        int fila,
        int columna
    )const override;
};