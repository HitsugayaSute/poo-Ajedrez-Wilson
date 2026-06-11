bool JuegoAjedrez::terminado() const{
    return
        !tablero.existeRey(
            BLANCO
        )
        ||
        !tablero.existeRey(
            NEGRO
        );
}
//ME
bool JuegoAjedrez::jaqueMate(Color color){
    if(!tablero.reyEnJaque(color)){
        return false;
    }
    auto movimientos=tablero.movimientosValidos(color);
    return movimientos.empty();
}
bool JuegoAjedrez::tablas(Color color){
    if(tablero.reyEnJaque(color)){
        return false;
    }
    auto movimientos=tablero.movimientosValidos(color);
    return movimientos.empty();
}
const Tablero&
JuegoAjedrez::getTablero() const{
    return tablero;
}
Tablero&
JuegoAjedrez::getTablero(){
    return tablero;
}
bool JuegoAjedrez::realizarMovimiento(const Movimiento& movimiento){
    auto validos = tablero.movimientosValidos(turnoActual);
    for(auto& m : validos){
        if(m.filaOrigen == movimiento.filaOrigen && m.columnaOrigen == movimiento.columnaOrigen 
            && m.filaDestino == movimiento.filaDestino && m.columnaDestino == movimiento.columnaDestino){
            tablero.mover(m);
            historial.push_back(m);
            cambiarTurno();
            return true;
        }
    }
    return false;
}