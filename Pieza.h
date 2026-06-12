#pragma once
#include <vector>

class Movimiento;
class Tablero;
enum Color
{
    BLANCO,
    NEGRO
};
class Pieza
{
protected:
    Color color;
public:
    Pieza(Color c); //use un virtual y ahora que lo termine me acorde que eso no se puede usar...
    //shit y ahora? despues vere que hago
    virtual ~Pieza();
    Color getColor()const;
    virtual char getSimbolo()const=0;
    virtual std::vector<Movimiento>
    movimientosLegales(
        const Tablero& tablero,
        int fila,
        int columna
    )const=0;
};
virtual std::shared_ptr<Pieza>
clonar() const = 0;