#include "Evaluador.h"
#include "../piezas/Tablero.h"
#include "../piezas/Pieza.h"
#include <cctype>

int Evaluador::evaluar(const Tablero& tablero){
    std::map<char, int> valores={
        {'P', 100}, {'p', 100},
        {'N', 320}, {'n', 320},
        {'B', 330}, {'b', 330},
        {'R', 500}, {'r', 500},
        {'Q', 900}, {'q', 900},
        {'K', 20000}, {'k', 20000}
    };
    int puntuacion=0;
    for(int f=0; f < 8; ++f){
        for(int c=0; c<8; ++c){
            auto pieza=tablero.obtenerPieza(f, c);
            if(!pieza) 
            continue;
            int valor=valores[pieza->getSimbolo()];
            if(pieza->getColor()==Color::BLANCO)
                puntuacion+=valor;
            else
                puntuacion-=valor;
        }
    }
    return puntuacion;
}