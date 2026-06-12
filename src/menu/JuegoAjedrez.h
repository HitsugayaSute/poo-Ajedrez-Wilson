#pragma once
#include "../piezas/Tablero.h"
#include "../piezas/Movimientos.h"
#include "../piezas/Pieza.h"
#include <vector>
#include <string>
#include <set>

class JuegoAjedrez{
private:
    Tablero tablero;
    Color turnoActual;
    std::vector<Movimiento> historial;
    std::set<std::string> posicionesVisitadas;
public:
    JuegoAjedrez();
    void reiniciar();
    const Tablero& getTablero() const;
    Tablero& getTablero();
    Color getTurno()const;
    void cambiarTurno();
    bool realizarMovimiento(const Movimiento& movimiento);
    bool terminado()const;
    bool jaqueMate(Color color)const;
    bool tablas(Color color)const;
    EstadoJuego getEstado()const;
};