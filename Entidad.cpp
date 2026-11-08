//
// Created by User01 on 6/11/2026.
//

#include "Entidad.h"
#include "Mapa.h"

Entidad::Entidad(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz)
    : Sprite(nombre, alto, ancho, matriz){
}

Entidad::~Entidad() {}
