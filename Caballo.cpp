#include "Caballo.h"
#include "Movimientos.h"
#include "Tablero.h"

Caballo::Caballo(Color c)
    : Pieza(c)
{
}
char Caballo::getSimbolo() const
{
    return color == BLANCO ? 'N' : 'n';
}
std::vector<Movimiento>
Caballo::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
) const{
    std::vector<Movimiento> movimientos;
    int saltos[8][2] =
    {
        {-2,-1},
        {-2,1},
        {-1,-2},
        {-1,2},
        {1,-2},
        {1,2},
        {2,-1},
        {2,1}
    };
    //amanda
    for(int i=0;i<8;i++){
        int nf = fila + saltos[i][0];
        int nc = columna + saltos[i][1];
        auto pieza = tablero.obtenerPieza(nf, nc);
        if(!pieza || pieza->getColor() != color){
            movimientos.emplace_back(fila, columna, nf, nc);
        }
    }
return movimientos;
}
std::shared_ptr<Pieza>
Caballo::clonar() const{
    return std::make_shared<Caballo>(*this);
}