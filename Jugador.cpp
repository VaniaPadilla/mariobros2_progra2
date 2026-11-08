//
// Created by User01 on 6/11/2026.
//

#include "Jugador.h"
#include "Entidad.h"


Jugador::Jugador(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz) : Entidad(nombre, alto, ancho, matriz) {

}

Jugador::~Jugador() {}

// retorna la posicion actualizada del jugador
void Jugador::moverse(std::vector<std::vector<int>>& mundo, int& posX, int& posY, std::string direccion) {
    if (direccion == "right") {
        posX += 12;
    }
    else if (direccion == "left") {
        posX -= 12;
    }
    else if (direccion == "top") {
        posY -= 16;
        aire = true;
    }
    else if (direccion == "up-right") {
        posX += 12;
        posY -= 16;
    }
    else if (direccion == "up-left") {
        posX -= 12;
        posY -= 16;
    }
}
