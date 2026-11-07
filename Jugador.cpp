//
// Created by User01 on 6/11/2026.
//

#include "Jugador.h"
#include "Entidad.h"


Jugador::Jugador(int x, int y) : Entidad("Mario", 16, 12, 1) {
    set_pos_x(x);
    set_pos_y(y);
}

Jugador::~Jugador() {}

void Jugador::moverse(std::string direccion) {
    //movimiento
}