#include "Rey.h"
#include "Movimientos.h"
#include "Tablero.h"

Rey::Rey(Color c):Pieza(c){}
char Rey::getSimbolo() const{
    return color == Color::BLANCO ? 'K' : 'k';
}
std::vector<Movimiento> Rey::movimientosLegales(const Tablero& tablero, int fila, int columna)const{
    std::vector<Movimiento> movs;
    for(int df = -1;df<=1;++df){
        for(int dc = -1; dc <= 1; ++dc){
            if(df==0 && dc==0)continue;
            int nf=fila+df;
            int nc=columna+dc;
            if(tablero.posicionValida(nf, nc)){
                auto pieza=tablero.obtenerPieza(nf, nc);
                if(!pieza || pieza->getColor()!=color){
                    movs.emplace_back(fila, columna, nf, nc);
                }
            }
        }
    }
    return movs;
}
std::shared_ptr<Pieza> Rey::clonar()const{return std::make_shared<Rey>(*this);
}