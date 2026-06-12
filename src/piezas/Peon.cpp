#include "Peon.h"
#include "Movimientos.h"
#include "Tablero.h"

Peon::Peon(Color c):Pieza(c){}

char Peon::getSimbolo()const{
    return color ==Color::BLANCO ? 'P' : 'p';
}
std::vector<Movimiento> Peon::movimientosLegales(const Tablero& tablero, int fila, int columna)const{
    std::vector<Movimiento> movs;
    int dir=(color==Color::BLANCO) ? -1 : 1;
    int sigFila=fila+dir;
    if(tablero.posicionValida(sigFila, columna)&& !tablero.obtenerPieza(sigFila, columna)){
        movs.emplace_back(fila, columna, sigFila, columna);
    }
    int filaInicio=(color==Color::BLANCO) ? 6 : 1;
    if(fila==filaInicio){
        int dobleFila=fila+2*dir;
        if(tablero.posicionValida(dobleFila, columna)&& !tablero.obtenerPieza(dobleFila, columna)&& !tablero.obtenerPieza(sigFila, columna)){
            movs.emplace_back(fila, columna, dobleFila, columna);
        }
    }
    for(int dc= -1; dc<=1; dc+=2){
        int nc=columna+dc;
        if(tablero.posicionValida(sigFila, nc)){
            auto pieza=tablero.obtenerPieza(sigFila, nc);
            if(pieza&&pieza->getColor()!=color){
                movs.emplace_back(fila, columna, sigFila, nc);
            }
        }
    }
    return movs;
}
std::shared_ptr<Pieza> Peon::clonar()const{
    return std::make_shared<Peon>(*this);
}