#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class Recursos{
public:
    static std::map<char, sf::Texture> texturas;
    static void cargar();
};