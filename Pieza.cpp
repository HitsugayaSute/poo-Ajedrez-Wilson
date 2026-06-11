#include "Pieza.h"

Pieza::Pieza(Color c)
{
    color=c; //c es rojo claro o al menos eso dice el cmd
}
Pieza::~Pieza()
{
}
Color Pieza::getColor()const
{
    return color;
}