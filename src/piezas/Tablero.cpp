#include "Tablero.h"
#include "Pieza.h"
#include "Movimientos.h"
#include "Torre.h"
#include "Caballo.h"
#include "Alfil.h"
#include "Reina.h"
#include "Rey.h"
#include "Peon.h"

Tablero::Tablero(){casillas.resize(8, std::vector<std::shared_ptr<Pieza>>(8, nullptr));}
void Tablero::inicializar(){
    for(int i=0; i<8;++i){colocarPieza(1, i, std::make_shared<Peon>(Color::NEGRO));colocarPieza(6, i, std::make_shared<Peon>(Color::BLANCO));}
    colocarPieza(0, 0, std::make_shared<Torre>(Color::NEGRO));colocarPieza(0, 7, std::make_shared<Torre>(Color::NEGRO));colocarPieza(7, 0, std::make_shared<Torre>(Color::BLANCO));colocarPieza(7, 7, std::make_shared<Torre>(Color::BLANCO));
    colocarPieza(0, 1, std::make_shared<Caballo>(Color::NEGRO));colocarPieza(0, 6, std::make_shared<Caballo>(Color::NEGRO));colocarPieza(7, 1, std::make_shared<Caballo>(Color::BLANCO));colocarPieza(7, 6, std::make_shared<Caballo>(Color::BLANCO));
    colocarPieza(0, 2, std::make_shared<Alfil>(Color::NEGRO));colocarPieza(0, 5, std::make_shared<Alfil>(Color::NEGRO));colocarPieza(7, 2, std::make_shared<Alfil>(Color::BLANCO));colocarPieza(7, 5, std::make_shared<Alfil>(Color::BLANCO));
    colocarPieza(0, 3, std::make_shared<Reina>(Color::NEGRO));colocarPieza(7, 3, std::make_shared<Reina>(Color::BLANCO));
    colocarPieza(0, 4, std::make_shared<Rey>(Color::NEGRO));colocarPieza(7, 4, std::make_shared<Rey>(Color::BLANCO));
}
bool Tablero::posicionValida(int fila, int columna)const{return fila>=0&&fila<8&&columna>=0&&columna< 8;}
std::shared_ptr<Pieza> Tablero::obtenerPieza(int fila, int columna)const{
    if(!posicionValida(fila, columna)) 
    return nullptr;
    return casillas[fila][columna];
}
void Tablero::colocarPieza(int fila, int columna, std::shared_ptr<Pieza> pieza){
    if(posicionValida(fila, columna))
        casillas[fila][columna]=pieza;
}
void Tablero::mover(const Movimiento& m){
    auto pieza=obtenerPieza(m.filaOrigen, m.columnaOrigen);
    if(!pieza) 
    return;
    char s=pieza->getSimbolo();
    if((s=='P' && m.filaDestino==0) || (s=='p'&&m.filaDestino==7)){
        casillas[m.filaDestino][m.columnaDestino]=std::make_shared<Reina>(pieza->getColor());
    }else{
        casillas[m.filaDestino][m.columnaDestino] =pieza;
    }
    casillas[m.filaOrigen][m.columnaOrigen]=nullptr;
}
std::vector<Movimiento> Tablero::obtenerMovimientos(Color color)const{
    std::vector<Movimiento> todos;
    for(int f=0;f<8;++f){
        for(int c=0; c<8;++c){
            auto pieza=obtenerPieza(f, c);
            if(pieza&&pieza->getColor()==color){auto movs=pieza->movimientosLegales(*this, f, c);todos.insert(todos.end(), movs.begin(), movs.end());}
        }
    }
    return todos;
}
bool Tablero::esEnemigo(int fila, int columna,Color color)const{
    auto pieza =obtenerPieza(fila, columna);
    return pieza&& pieza->getColor()!=color;
}
bool Tablero::existeRey(Color color) const {
    char target=(color==Color::BLANCO) ? 'K' : 'k';
    for(int f=0;f<8;++f)
        for(int c=0;c<8;++c){
            auto p=obtenerPieza(f, c);
            if(p&&p->getSimbolo()==target) 
            return true;
        }
    return false;
}
bool Tablero::reyEnJaque(Color color)const{
    int reyF = -1, reyC = -1;
    char target=(color==Color::BLANCO) ? 'K' : 'k';
    for(int f =0;f<8; ++f)
        for (int c=0; c<8;++c){
            auto p=obtenerPieza(f, c);
            if(p&& p->getSimbolo()== target){
                reyF = f; reyC =c; 
                break;
            }
        }
    if(reyF == -1) 
    return false;
    Color enemigo=(color==Color::BLANCO) ? Color::NEGRO : Color::BLANCO;
    auto movsEnemigos=obtenerMovimientos(enemigo);
    for(auto& m:movsEnemigos){
        if(m.filaDestino== reyF&& m.columnaDestino==reyC)
            return true;
    }
    return false;
}
std::vector<Movimiento> Tablero::movimientosValidos(Color color)const{
    std::vector<Movimiento> validos;
    auto movs=obtenerMovimientos(color);
    for(auto& m:movs){
        Tablero copia= *this;
        copia.mover(m);
        if (!copia.reyEnJaque(color))
            validos.push_back(m);
    }
    return validos;
}
Tablero::Tablero(const Tablero& otro){
    casillas.resize(8, std::vector<std::shared_ptr<Pieza>>(8, nullptr));
    for(int f=0; f <8; ++f)
        for(int c=0;c<8; ++c)
            if(otro.casillas[f][c])
                casillas[f][c] = otro.casillas[f][c]->clonar();
}
EstadoJuego Tablero::obtenerEstado()const{
    for(auto color:{Color::BLANCO, Color::NEGRO}){
        if(!existeRey(color)){
            return(color==Color::BLANCO) ? EstadoJuego::JAQUE_MATE_NEGRO : EstadoJuego::JAQUE_MATE_BLANCO;
        }
    }
    if(reyEnJaque(Color::BLANCO))return EstadoJuego::JAQUE_BLANCO;
    if(reyEnJaque(Color::NEGRO))return EstadoJuego::JAQUE_NEGRO;
    return EstadoJuego::EN_CURSO;
}