#include "GuardarPartida.h"
#include "../piezas/Tablero.h"
#include "../piezas/Pieza.h"
#include <fstream>
#include <iostream>

void GuardarPartida::guardar(const Tablero& tablero, const std::string& archivo){
    std::ofstream file(archivo);
    if(!file) 
    return;
    for(int f=0; f<8; ++f){
        for(int c=0; c<8; ++c){
            auto pieza=tablero.obtenerPieza(f, c);
            if(pieza){
                file << f << "," << c << "," << pieza->getSimbolo() << "\n";
            }
        }
    }
    file.close();
}
void GuardarPartida::cargar(Tablero& tablero, const std::string& archivo){
    tablero=Tablero();
    std::ifstream file(archivo);
    if(!file)
    return;
    std::string linea;
    while(std::getline(file, linea)){
        int f, c;
        char s;
        sscanf(linea.c_str(), "%d,%d,%c", &f, &c, &s);
    }
}