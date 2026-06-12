#include "Minimax.h"
#include "Evaluador.h"
#include "../piezas/Tablero.h"
#include <algorithm>
#include <climits>

int Minimax::minimax(Tablero tablero, int profundidad, int alpha, int beta, bool maximizando, Color iaColor){
    if(profundidad==0){
        int eval = Evaluador::evaluar(tablero);
        return(iaColor==Color::NEGRO) ? -eval : eval;
    }
    Color colorActual=maximizando ? iaColor:(iaColor==Color::BLANCO ? Color::NEGRO : Color::BLANCO);
    auto movimientos=tablero.movimientosValidos(colorActual);
    if(movimientos.empty()){
        if(tablero.reyEnJaque(colorActual))
            return maximizando ? -100000 : 100000;
        else
            return 0;
    }
    if(maximizando){
        int mejor=INT_MIN;
        for(auto& mov : movimientos){
            Tablero copia=tablero;
            copia.mover(mov);
            int valor=minimax(copia, profundidad - 1, alpha, beta, false, iaColor);
            mejor=std::max(mejor, valor);
            alpha=std::max(alpha, valor);
            if(beta<=alpha) 
            break;
        }
        return mejor;
    }else{
        int mejor=INT_MAX;
        for(auto& mov : movimientos){
            Tablero copia=tablero;
            copia.mover(mov);
            int valor=minimax(copia, profundidad - 1, alpha, beta, true, iaColor);
            mejor=std::min(mejor, valor);
            beta=std::min(beta, valor);
            if(beta<=alpha) 
            break;
        }
        return mejor;
    }
}
Movimiento Minimax::mejorMovimiento(const Tablero& tablero, int profundidad, Color iaColor){
    auto movimientos=tablero.movimientosValidos(iaColor);
    if(movimientos.empty()) return Movimiento(-1, -1, -1, -1);
    int mejorValor=(iaColor==Color::NEGRO) ? INT_MAX : INT_MIN;
    Movimiento mejorMov=movimientos[0];
    for(auto& mov:movimientos){
        Tablero copia=tablero;
        copia.mover(mov);
        int valor=minimax(copia, profundidad - 1, INT_MIN, INT_MAX,(iaColor!=Color::NEGRO), iaColor);
        if(iaColor==Color::NEGRO){
            if(valor<mejorValor){
                mejorValor=valor;
                mejorMov=mov;
            }
        }else{
            if(valor>mejorValor){
                mejorValor=valor;
                mejorMov=mov;
            }
        }
    }
    return mejorMov;
}