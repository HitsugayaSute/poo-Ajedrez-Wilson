#include "VentanaJuego.h"
#include "Recursos.h"
#include "../jugadores/JugadorIA.h"
#include <iostream>

VentanaJuego::VentanaJuego()
    : ventana(sf::VideoMode(800, 800), "Ajedrez"),
      casillaSeleccionadaFila(-1),
      casillaSeleccionadaColumna(-1),
      estado(EstadoPantalla::MENU)
{
    Recursos::cargar();
    if(!fuente.loadFromFile("assets/arial.ttf")){}
    textoEstado.setFont(fuente);
    textoEstado.setCharacterSize(30);
    textoEstado.setFillColor(sf::Color::Black);
    textoEstado.setPosition(300, 20);
}
void VentanaJuego::ejecutar(){
    while(ventana.isOpen()){
        procesarEventos();
        actualizar();
        dibujar();
    }
}
void VentanaJuego::procesarEventos(){
    sf::Event evento;
    while(ventana.pollEvent(evento)){
        if(evento.type==sf::Event::Closed)
            ventana.close();
        if(evento.type==sf::Event::MouseButtonPressed && estado==EstadoPantalla::JUGANDO){
            clickMouse(evento.mouseButton.x, evento.mouseButton.y);
        }
        if(evento.type==sf::Event::KeyPressed && estado==EstadoPantalla::MENU){
            if(evento.key.code==sf::Keyboard::Space){
                estado=EstadoPantalla::JUGANDO;
                juego.reiniciar();
                casillaSeleccionadaFila = -1;
            }
        }
    }
}
void VentanaJuego::actualizar(){
    if(estado!=EstadoPantalla::JUGANDO) 
    return;
    static bool iaPensando=false;
    if(juego.getTurno()==Color::NEGRO && !iaPensando && !juego.terminado()){
        iaPensando=true;
        JugadorIA ia(Color::NEGRO);
        Movimiento mov=ia.decidir(juego.getTablero(), 3);
        if(mov.filaOrigen != -1){
            juego.realizarMovimiento(mov);
        }
        iaPensando=false;
    }
    if(juego.terminado()){
        estado=EstadoPantalla::DERROTA;
    }else if(juego.jaqueMate(Color::BLANCO)){
        estado=EstadoPantalla::DERROTA;
    }else if(juego.jaqueMate(Color::NEGRO)){
        estado=EstadoPantalla::VICTORIA;
    }
}
void VentanaJuego::dibujar(){
    ventana.clear();
    float tam = 100.f;
    for(int f = 0; f<8;++f){
        for(int c =0; c< 8; ++c){
            sf::RectangleShape casilla(sf::Vector2f(tam, tam));
            casilla.setPosition(c * tam, f * tam);
            if((f+c) % 2==0)
                casilla.setFillColor(sf::Color(240, 217, 181));
            else
                casilla.setFillColor(sf::Color(181, 136, 99));
            ventana.draw(casilla);
            if(f==casillaSeleccionadaFila && c==casillaSeleccionadaColumna){
                sf::RectangleShape resaltado(sf::Vector2f(tam, tam));
                resaltado.setPosition(c * tam, f * tam);
                resaltado.setFillColor(sf::Color(255, 0, 0, 128));
                ventana.draw(resaltado);
            }
            auto pieza=juego.getTablero().obtenerPieza(f, c);
            if(pieza){
                char simbolo=pieza->getSimbolo();
                if(Recursos::texturas.find(simbolo) != Recursos::texturas.end()){
                    sf::Sprite sprite(Recursos::texturas[simbolo]);
                    sprite.setPosition(c * tam, f * tam);
                    sprite.setScale(tam / sprite.getLocalBounds().width, tam / sprite.getLocalBounds().height);
                    ventana.draw(sprite);
                }
            }
        }
    }    
    if(estado==EstadoPantalla::MENU){
        sf::Text menuText;
        menuText.setFont(fuente);
        menuText.setString("Presiona ESPACIO para empezar :)");
        menuText.setCharacterSize(40);
        menuText.setFillColor(sf::Color::White);
        menuText.setPosition(150, 350);
        ventana.draw(menuText);
    }else if(estado==EstadoPantalla::VICTORIA){
        textoEstado.setString("Yeei ganaste... sht");
        ventana.draw(textoEstado);
    }else if(estado==EstadoPantalla::DERROTA){
        textoEstado.setString("Como mismo te ganaron a ti ahora, los codigos me ganaron a mi haciendo esto");
        ventana.draw(textoEstado);
    }else{
        std::string turnoStr=(juego.getTurno()==Color::BLANCO) ? "Turno: Blancas" : "Turno: Negras (Leroy)";
        textoEstado.setString(turnoStr);
        ventana.draw(textoEstado);
    }
    ventana.display();
}
void VentanaJuego::clickMouse(int x, int y){
    int columna = x/100;
    int fila = y/100;
    if(fila<0 || fila >= 8 || columna<0 || columna >= 8) 
    return;
    if(casillaSeleccionadaFila == -1){
        auto pieza=juego.getTablero().obtenerPieza(fila, columna);
        if(!pieza)
        return;
        if(pieza->getColor()!=juego.getTurno())return;
        casillaSeleccionadaFila=fila;
        casillaSeleccionadaColumna =columna;
    }else{
        Movimiento movimiento(casillaSeleccionadaFila, casillaSeleccionadaColumna, fila, columna);
        juego.realizarMovimiento(movimiento);
        casillaSeleccionadaFila = -1;
        casillaSeleccionadaColumna = -1;
    }
}//AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAH