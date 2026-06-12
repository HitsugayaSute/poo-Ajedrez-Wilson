#include "Reina.h"
#include "Movimiento.h"
#include "Tablero.h"

Reina::Reina(Color c)
    : Pieza(c)
{
}
char Reina::getSimbolo()const
{
    return color == BLANCO ? 'Q' : 'q';
}
std::vector<Movimiento>
Reina::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
) const
{
    std::vector<Movimiento> movimientos;
    int dirs[8][2] =
    {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1},
        {-1,-1},
        {-1,1},
        {1,-1},
        {1,1}
    };
    for(int i=0;i<8;i++){
        int f=fila;
        int c=columna;
        while(true){
            //Amanda
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
Reina::clonar() const{
    return std::make_shared<Reina>(*this);
}