#pragma once
#include <SFML/Graphics.hpp>
#include "JuegoAjedrez.h"
#include "EstadoPantalla.h"

class VentanaJuego{
private:
    sf::RenderWindow ventana;
    JuegoAjedrez juego;
    int casillaSeleccionadaFila;
    int casillaSeleccionadaColumna;
    EstadoPantalla estado;
    sf::Font fuente;
    sf::Text textoEstado;
public:
    VentanaJuego();
    void ejecutar();
private:
    void procesarEventos();
    void actualizar();
    void dibujar();
    void clickMouse(int x, int y);
    void manejarMenu();
};