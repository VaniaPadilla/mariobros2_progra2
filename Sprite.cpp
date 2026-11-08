//
// Created by User01 on 6/11/2026.
//

#include "Sprite.h"

#include "Mapa.h"

Sprite::Sprite (std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz) {
    this->nombre = nombre;
    this->alto = alto;
    this->ancho = ancho;
    this->matriz = matriz;
    posX = 0;
    posY = 0;
}

Sprite::~Sprite() {
}

void Sprite::dibujar(std::vector<std::vector<int>>& mundito, const Sprite& spritito, int posX, int posY) {
    for (int i=0; i <= spritito.alto; i++) {
        for (int j=0; j <= spritito.ancho; j++) {
            mundito[posX][posY] = spritito.get_matriz()[i][j];
        }
    }
}

void Sprite::borrar(std::vector<std::vector<int>>& mundito, const Sprite& spritito, int posX, int posY) {
    for (int i=0; i <= spritito.alto; i++) {
        for (int j=0; j <= spritito.ancho; j++) {
            if (posX >= 43){
                mundito[posX][posY] = 1;
            } else{
                mundito[posX][posY] = 0;
            }
        }
    }
}


void Sprite::modificar(std::vector<std::vector<int>>& nuevaMat) {
    int fil = nuevaMat.size();
    int col = nuevaMat[0].size();
    for (int i=0; i <= fil; i++) {
        for (int j=0; j <= col; j++) {
            matriz[i][j] = nuevaMat[i][j];
        }
    }
}

Sprite Sprite::clonar(Sprite spritito) {
    return {spritito.nombre, spritito.alto, spritito.ancho, spritito.matriz};
}


std::string Sprite::get_nombre() const {
    return nombre; }
void Sprite::set_nombre(std::string nombre) {
    this->nombre = nombre; }

std::vector<std::vector<int>> Sprite::get_matriz() const {
    return matriz; }
void Sprite::set_matriz(std::vector<std::vector<int>> matriz) {
    this->matriz = matriz; }

int Sprite::get_alto() const {
    return alto; }
void Sprite::set_alto(int alto) {
    this->alto = alto; }

int Sprite::get_ancho() const {
    return ancho; }
void Sprite::set_ancho(int ancho) {
    this->ancho = ancho; }

int Sprite::get_pos_x() const {
    return posX; }
void Sprite::set_pos_x(int pos_x) {
    posX = pos_x; }

int Sprite::get_pos_y() const {
    return posY; }
void Sprite::set_pos_y(int pos_y) {
    posY = pos_y; }

