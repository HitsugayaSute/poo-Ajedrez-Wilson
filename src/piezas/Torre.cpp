// Torre.cpp
#include "Torre.h"
#include "Movimientos.h"
#include "Tablero.h"

Torre::Torre(Color c):Pieza(c){}
char Torre::getSimbolo()const{
    return color == Color::BLANCO ? 'R' : 'r';
}
std::vector<Movimiento> Torre::movimientosLegales(const Tablero& tablero, int fila, int columna)const{
    std::vector<Movimiento> movs;
    int dirs[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
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
std::shared_ptr<Pieza> Torre::clonar()const{
    return std::make_shared<Torre>(*this);
}