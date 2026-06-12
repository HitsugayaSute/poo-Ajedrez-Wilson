#pragma once
#include <vector>
#include <memory>
#include "Estado.h"

class Pieza;
class Movimiento;
class Tablero{
private:
    std::vector<std::vector<std::shared_ptr<Pieza>>> casillas;
public:
    Tablero();
    void inicializar();
    bool posicionValida(int fila, int columna)const;
    std::shared_ptr<Pieza> obtenerPieza(int fila, int columna) const;
    void colocarPieza(int fila, int columna, std::shared_ptr<Pieza>pieza);
    void mover(const Movimiento& movimiento);
    std::vector<Movimiento> obtenerMovimientos(Color color)const;
    bool esEnemigo(int fila, int columna, Color color)const;
    bool existeRey(Color color)const;
    bool reyEnJaque(Color color)const;
    std::vector<Movimiento> movimientosValidos(Color color)const;
    Tablero(const Tablero&otro);
    EstadoJuego obtenerEstado()const;
};