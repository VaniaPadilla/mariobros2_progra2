//
// Created by User01 on 6/11/2026.
//

#include "Elemento.h"
#include "Mapa.h"

Elemento::Elemento(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz, bool atravesable, char estado)
    : Sprite(nombre, alto, ancho, matriz){
    this->atravesable = atravesable;
    this->estado = estado;
}

Elemento::~Elemento() {}


bool Elemento::getAtravesable()const{ 
    return atravesable; }
void Elemento::setAtravesable(bool atravesable) {
    this->atravesable = atravesable; }

char Elemento::getEstado() const {
    return estado; }
void Elemento::setEstado(char estado) {
    this->estado = estado; }
