#include "JuegoAjedrez.h"
#include "../piezas/Movimientos.h"

JuegoAjedrez::JuegoAjedrez():turnoActual(Color::BLANCO){
    tablero.inicializar();
}
void JuegoAjedrez::reiniciar(){
    tablero=Tablero();
    tablero.inicializar();
    turnoActual=Color::BLANCO;
    historial.clear();
    posicionesVisitadas.clear();
}
const Tablero& JuegoAjedrez::getTablero()const{ 
    return tablero; 
}
Tablero& JuegoAjedrez::getTablero(){ 
    return tablero; 
}
Color JuegoAjedrez::getTurno()const{
     return turnoActual; 
}
void JuegoAjedrez::cambiarTurno(){
    turnoActual=(turnoActual==Color::BLANCO) ? Color::NEGRO : Color::BLANCO;
}
bool JuegoAjedrez::realizarMovimiento(const Movimiento& movimiento){
    auto validos=tablero.movimientosValidos(turnoActual);
    for(auto& m:validos){
        if (m.filaOrigen== movimiento.filaOrigen && m.columnaOrigen==movimiento.columnaOrigen && m.filaDestino==movimiento.filaDestino && m.columnaDestino == movimiento.columnaDestino){
            tablero.mover(m);
            historial.push_back(m);
            cambiarTurno();
            return true;
        }
    }
    return false;
}
bool JuegoAjedrez::terminado()const{
    return !tablero.existeRey(Color::BLANCO) || !tablero.existeRey(Color::NEGRO);
}
bool JuegoAjedrez::jaqueMate(Color color)const{
    if(!tablero.reyEnJaque(color))return false;
    return tablero.movimientosValidos(color).empty();
}
bool JuegoAjedrez::tablas(Color color)const{
    if(tablero.reyEnJaque(color))return false;
    return tablero.movimientosValidos(color).empty();
}
EstadoJuego JuegoAjedrez::getEstado()const{
    if(jaqueMate(Color::BLANCO))return EstadoJuego::JAQUE_MATE_BLANCO;
    if(jaqueMate(Color::NEGRO))return EstadoJuego::JAQUE_MATE_NEGRO;
    if(tablas(Color::BLANCO) || tablas(Color::NEGRO))return EstadoJuego::TABLAS;
    if(tablero.reyEnJaque(Color::BLANCO))return EstadoJuego::JAQUE_BLANCO;
    if(tablero.reyEnJaque(Color::NEGRO))return EstadoJuego::JAQUE_NEGRO;
    return EstadoJuego::EN_CURSO;
}