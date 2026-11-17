
#include "Entidad.h"

Entidad::Entidad(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz, int posX, int posY)
    : Sprite(nombre, alto, ancho, matriz, posX, posY) {
    this->vida = true;
}

Entidad::~Entidad() {}

bool Entidad::is_vida() const {
    return vida;
}

void Entidad::set_vida(bool vida) {
    this->vida = vida;
}

