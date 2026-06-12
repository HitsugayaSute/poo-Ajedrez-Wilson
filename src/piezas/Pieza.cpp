#include "Pieza.h"

Pieza::Pieza(Color c):color(c){}
Pieza::~Pieza(){}
Color Pieza::getColor()const{
    return color;
}