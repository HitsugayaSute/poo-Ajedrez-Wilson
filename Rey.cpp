#include "Rey.h"
#include "Movimientos.h"
#include "Tablero.h"

Rey::Rey(Color c)
    : Pieza(c)
{}
char Rey::getSimbolo() const
{
    return color==BLANCO ? 'K' : 'k';
}
std::vector<Movimiento>
Rey::movimientosLegales(
    const Tablero& tablero,
    int fila,
    int columna
)const
{
   std::vector<Movimiento> movimientos;

    for(int df=-1;df<=1;df++){//df y dc es para distinguir entre filas y columnas sino me vuelvo lco
        for(int dc=-1; dc<=1; dc++){
            if(df==0 && dc==0)
                continue;
            int nf = fila+df;
            int nc = columna+dc;
            if(tablero.posicionValida(nf,nc)){
                movimientos.push_back(
                    Movimiento(
                        fila,
                        columna,
                        nf,
                        nc
                    )
                );
            }
        }
    }
    return movimientos;
}
std::shared_ptr<Pieza>
Rey::clonar() const{
    return std::make_shared<Rey>(*this);
}