#pragma once
#include <string>

class Tablero;
class GuardarPartida{
public:
    static void guardar(const Tablero& tablero, const std::string& archivo);
    static void cargar(Tablero& tablero, const std::string& archivo);
};