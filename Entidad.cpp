//
// Created by User01 on 6/11/2026.
//

#include "Entidad.h"

Entidad::Entidad(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz)
    : Sprite(nombre, alto, ancho, matriz){
    this->vida = true;
}

Entidad::~Entidad() {}

bool Entidad::is_vida() const {
    return vida;
}

void Entidad::set_vida(bool vida) {
    this->vida = vida;
}

