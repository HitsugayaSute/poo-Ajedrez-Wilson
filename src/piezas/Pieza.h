#pragma once
#include <vector>
#include <memory>

class Movimiento;
class Tablero;
enum class Color{BLANCO, NEGRO};
class Pieza{
protected:
    Color color;
public:
    Pieza(Color c);
    virtual ~Pieza();
    Color getColor() const;
    virtual char getSimbolo() const = 0;
    virtual std::vector<Movimiento> movimientosLegales(const Tablero& tablero, int fila, int columna)const=0;
    virtual std::shared_ptr<Pieza> clonar()const=0;
};