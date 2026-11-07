//
// Created by User01 on 6/11/2026.
//

#include "Entidad.h"
#include "Mapa.h"

Entidad::Entidad(std::string nombre, int alto, int ancho, int vida)
        : Sprite(nombre, alto, ancho), vida(vida) {

        }

Entidad::~Entidad() {}

void Entidad::dibujar(Mapa& map) {
    
}

void Entidad::borrar(Mapa& map) {
    
}

Posicion Entidad::operator+(const Posicion& other) const {
    return {get_pos_x() + other.x, get_pos_y() + other.y};
}

int Entidad::getVida() const { return vida; }
void Entidad::setVida(int vida) { this->vida = vida; }