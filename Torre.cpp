#include "Torre.h"
#include "Tablero.h"
#include "Movimientos.h"

Torre::Torre(Color c)
    : Pieza(c)
{
}
char Torre::getSimbolo()const
{
    return color == BLANCO ? 'R' : 'r';
}
std::vector<Movimiento>
Torre::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
)const
{
    std::vector<Movimiento> movimientos;
    int direcciones[4][2] =
    {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    for(int i=0;i<4;i++){
        int f = fila;
        int c = columna;
        while(true){
//Amanda
            f += direcciones[i][0];
            c += direcciones[i][1];
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
        }// Despues yo les explico el arroz con mango este x ws
    }
    return movimientos;
}
std::shared_ptr<Pieza>
Torre::clonar() const{
    return std::make_shared<Torre>(*this);
}