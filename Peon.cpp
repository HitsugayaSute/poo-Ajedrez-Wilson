#include "Peon.h"
#include "Movimientos.h"
#include "Tablero.h"

Peon::Peon(Color c)
    : Pieza(c)
{
}
char Peon::getSimbolo() const
{
    return color == BLANCO ? 'P' : 'p';
}//Amanda
/*std::vector<Movimiento>
Peon::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
) const*/
 std::vector<Movimiento>
Peon::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
)const{
    std::vector<Movimiento> movimientos;
    int dir = color == BLANCO ? -1 : 1;
    int siguiente = fila + dir;
    if(tablero.posicionValida(siguiente, columna) && !tablero.obtenerPieza(siguiente, columna)){
        movimientos.emplace_back(fila, columna, siguiente, columna);
    }
    int inicio = color == BLANCO ? 6 : 1;
    if(fila == inicio){
        int doble = fila + dir * 2;
        if(!tablero.obtenerPieza(doble, columna) && !tablero.obtenerPieza(siguiente, columna)){
            movimientos.emplace_back(fila, columna, doble, columna);
        }
    }
    for(int dc=-1;dc<=1;dc+=2){   
        int nc = columna + dc;
        if(tablero.posicionValida(siguiente, nc)){
            auto pieza = tablero.obtenerPieza(siguiente, nc);
            if(pieza && pieza->getColor() != color){
                movimientos.emplace_back(fila, columna, siguiente, nc);
            }
        }
    }
    return movimientos;
}
{
    std::vector<Movimiento> movimientos;
    int direccion =
        color == BLANCO ? -1 : 1;
    int nuevaFila =
        fila + direccion;
    if(tablero.posicionValida(
        nuevaFila,
        columna))
    {
        if(!tablero.obtenerPieza(
            nuevaFila,
            columna))
        {
            movimientos.emplace_back(
                fila,
                columna,
                nuevaFila,
                columna
            );
        }
    }
    return movimientos;
}
std::shared_ptr<Pieza>
Peon::clonar() const{
    return std::make_shared<Peon>(*this);
}