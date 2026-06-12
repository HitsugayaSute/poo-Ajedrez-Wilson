#include "Alfil.h"
#include "Movimientos.h"
#include "Tablero.h"

Alfil::Alfil(Color c)
    : Pieza(c)
{
}
char Alfil::getSimbolo()const
{
    return color == BLANCO ? 'B' : 'b';
}
std::vector<Movimiento>
Alfil::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
) const
{
    std::vector<Movimiento> movimientos;
    int dirs[4][2] =
    {
        {-1,-1},
        {-1,1},
        {1,-1},
        {1,1}
    };
    for(int i=0;i<4;i++){
        int f=fila;
        int c=columna;
        while(true){
            //amanda
            f += dirs[i][0];
            c += dirs[i][1];
            if(!tablero.posicionValida(f,c))
                break;
            movimientos.emplace_back(
                fila,columna,f,c
            );
            if(tablero.obtenerPieza(f,c))
                break;
            auto pieza = tablero.obtenerPieza(f, c);
            if(!pieza){
                movimientos.emplace_back(fila, columna, f, c);
                continue;
            }
            if(pieza->getColor() != color){
                movimientos.emplace_back(fila, columna, f, c);
            }
            break;
        }
    }

    return movimientos;
}
std::shared_ptr<Pieza>
Alfil::clonar() const{
    return std::make_shared<Alfil>(*this);
}
