//
// Created by User01 on 6/11/2026.
//

#include "Jugador.h"
#include "Entidad.h"


Jugador::Jugador(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz) : Entidad(nombre, alto, ancho, matriz) {

}

Jugador::~Jugador() {}

// retorna la posicion actualizada del jugador
void Jugador::moverse(std::string direccion) {
    const int xActual = this->get_pos_x();
    const int yActual = this->get_pos_y();

    if (direccion == "right") {
        this->set_pos_x(xActual + 12);
    }
    else if (direccion == "left") {
        this->set_pos_x(xActual - 12);
    }
    else if (direccion == "top") {
        this->set_pos_y(yActual - 16);
        aire = true;
    }
    else if (direccion == "up-right") {
        this->set_pos_x(xActual + 12);
        this->set_pos_y(yActual - 16);
    }
    else if (direccion == "up-left") {
        this->set_pos_x(xActual - 12);
        this->set_pos_y(yActual - 16);
    }
}
