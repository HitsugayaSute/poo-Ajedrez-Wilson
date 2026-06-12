#include "Recursos.h"

std::map<char, sf::Texture> Recursos::texturas;
void Recursos::cargar(){
    texturas['P'].loadFromFile("assets/wp.png");
    texturas['R'].loadFromFile("assets/wr.png");
    texturas['N'].loadFromFile("assets/wn.png");
    texturas['B'].loadFromFile("assets/wb.png");
    texturas['Q'].loadFromFile("assets/wq.png");
    texturas['K'].loadFromFile("assets/wk.png");
    texturas['p'].loadFromFile("assets/bp.png");
    texturas['r'].loadFromFile("assets/br.png");
    texturas['n'].loadFromFile("assets/bn.png");
    texturas['b'].loadFromFile("assets/bb.png");
    texturas['q'].loadFromFile("assets/bq.png");
    texturas['k'].loadFromFile("assets/bk.png");
}