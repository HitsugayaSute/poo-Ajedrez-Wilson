#include "Caballo.h"
#include "Movimientos.h"
#include "Tablero.h"

Caballo::Caballo(Color c):Pieza(c){}
char Caballo::getSimbolo()const{
    return color==Color::BLANCO ? 'N' : 'n';
}
std::vector<Movimiento> Caballo::movimientosLegales(const Tablero& tablero, int fila, int columna)const{
    std::vector<Movimiento> movs;
    int saltos[8][2]={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
    for (auto& s:saltos){
        int nf=fila+s[0];
        int nc=columna+s[1];
        if(!tablero.posicionValida(nf, nc)) 
        continue;
        auto pieza=tablero.obtenerPieza(nf, nc);
        if(!pieza || pieza->getColor()!=color){
            movs.emplace_back(fila, columna, nf, nc);
        }
    }
    return movs;
}
std::shared_ptr<Pieza> Caballo::clonar()const{
    return std::make_shared<Caballo>(*this);
}