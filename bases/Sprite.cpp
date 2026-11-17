
#include "Sprite.h"

// Constructor que inicializa las propiedades del sprite.
Sprite::Sprite(std::string nombre, int alto, int ancho,
               MUNDO matriz, int posX, int posY) {

    this->nombre = nombre;
    this->alto = alto;
    this->ancho = ancho;
    this->matriz = matriz;
    this->posX = posX;
    this->posY = posY;
}

// Destructor virtual que permite destruir objetos derivados.
Sprite::~Sprite() {
}

// Getters & Setters

std::string Sprite::get_nombre() const {
    return nombre;
}

void Sprite::set_nombre(std::string nombre) {
    this->nombre = nombre;
}

const MUNDO& Sprite::get_matriz() const {
    return matriz;
}

void Sprite::set_matriz(MUNDO matriz) {
    this->matriz = matriz;
}

int Sprite::get_alto() const {
    return alto;
}

void Sprite::set_alto(int alto) {
    this->alto = alto;
}

int Sprite::get_ancho() const {
    return ancho;
}

void Sprite::set_ancho(int ancho) {
    this->ancho = ancho;
}

int Sprite::get_pos_x() const {
    return posX;
}

void Sprite::set_pos_x(int pos_x) {
    posX = pos_x;
}

int Sprite::get_pos_y() const {
    return posY;
}

void Sprite::set_pos_y(int pos_y) {
    posY = pos_y;
}
