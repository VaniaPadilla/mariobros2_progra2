//
// Created by User01 on 6/11/2026.
//

#include "NpcEnemigo.h"

NpcEnemigo::NpcEnemigo(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz)
    : Entidad(nombre, alto, ancho, matriz) {
}

NpcEnemigo::~NpcEnemigo() {
}

void moverse(std::vector<std::vector<int>>& mundo, int& posX, int& posY, std::string direccion) {
    posX -= 12;
}
