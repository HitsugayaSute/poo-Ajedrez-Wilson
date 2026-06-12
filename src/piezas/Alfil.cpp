#include "Alfil.h"
#include "Movimientos.h"
#include "Tablero.h"

Alfil::Alfil(Color c):Pieza(c){}
char Alfil::getSimbolo()const{
    return color==Color::BLANCO ? 'B' : 'b';
}
std::vector<Movimiento> Alfil::movimientosLegales(const Tablero& tablero, int fila, int columna)const{
    std::vector<Movimiento> movs;
    int dirs[4][2]={{-1,-1},{-1,1},{1,-1},{1,1}};
    for (auto& d:dirs){
        int f=fila, c=columna;
        while(true){
            f+=d[0];
            c+=d[1];
            if(!tablero.posicionValida(f, c)) 
            break;
            auto pieza=tablero.obtenerPieza(f, c);
            if(!pieza){
                movs.emplace_back(fila, columna, f, c);
            }else{
                if(pieza->getColor()!=color)
                    movs.emplace_back(fila, columna, f, c);
                break;
            }
        }
    }
    return movs;
}
std::shared_ptr<Pieza> Alfil::clonar()const{
    return std::make_shared<Alfil>(*this);
}