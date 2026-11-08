//
// Created by User01 on 6/11/2026.
//

#include "Elemento.h"
#include "Mapa.h"

Elemento::Elemento(std::string nombre, int alto, int ancho, bool atravesable, int estado)
        : Sprite(nombre, alto, ancho), atravesable(atravesable), estado(estado) {

        }

Elemento::Elemento(const Elemento& otro)
        : Sprite(otro), atravesable(otro.atravesable), estado(otro.estado) {

        }

Elemento::~Elemento() {}

Elemento* Elemento::clonar() const {
    return new Elemento(*this);
}

void Elemento::colocar(Mapa& mapa, int x, int y) {
    
}

void Elemento::modificar(Mapa& mapa) {

}

void Elemento::quitar(Mapa& mapa) {
    
}


bool Elemento::getAtravesable()const{ 
    return atravesable; }
void Elemento::setAtravesable(bool atravesable) {
     this->atravesable = atravesable; }
int Elemento::getEstado() const {
     return estado; }
void Elemento::setEstado(int estado) { 
    this->estado = estado; }
