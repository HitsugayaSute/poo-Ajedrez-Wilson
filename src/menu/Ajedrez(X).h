#include <set>
#include <vector>

class Ajedrez{
    private:
        Color turnoActual;
};

bool terminado() const;
std::vector<Movimiento>
historial;
std::set<std::string>
posicionesVisitadas;
const Tablero& getTablero() const;
Tablero& getTablero();
turnoActual = BLANCO;
Color getTurno() const;
Color JuegoAjedrez::getTurno() const{
    return turnoActual;
}
void JuegoAjedrez::cambiarTurno()
{
    turnoActual = turnoActual == BLANCO ? NEGRO : BLANCO;
}
bool realizarMovimiento(
    const Movimiento& movimiento
);