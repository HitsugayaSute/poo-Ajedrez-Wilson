#include "Movimientos.h"

Movimiento::Movimiento(
    int fo, 
    int co,  //yo se que ustedes a lo mejor no saben jugar ajedrez
    //pero se usa un movimiento fila, columna. Ej. Alfil en c4. "c" seria la columna y "4" la fila
    //seria el destino
    int fd,
    int cd
){
    filaOrigen = fo;
    columnaOrigen = co;
    filaDestino = fd;
    columnaDestino = cd;
}