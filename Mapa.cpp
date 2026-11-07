//
// Created by User01 on 6/11/2026.
//

#include "Mapa.h"

int Mapa::get_fils_mundo() const {
    return filsMundo;
}

void Mapa::set_fils_mundo(int fils_mundo) {
    filsMundo = fils_mundo;
}

int Mapa::get_cols_mundo() const {
    return colsMundo;
}

void Mapa::set_cols_mundo(int cols_mundo) {
    colsMundo = cols_mundo;
}

std::vector<std::vector<int>> Mapa::get_mundo() const {
    return mundo;
}

void Mapa::set_mundo(std::vector<std::vector<int>> mundo) {
    this->mundo = mundo;
}

std::vector<std::vector<char>> Mapa::get_mundo_cod() const {
    return mundoCod;
}

void Mapa::set_mundo_cod(std::vector<std::vector<char>> mundo_cod) {
    mundoCod = mundo_cod;
}

int Mapa::get_fils_ventana() const {
    return filsVentana;
}

void Mapa::set_fils_ventana(int fils_ventana) {
    filsVentana = fils_ventana;
}

int Mapa::get_cols_ventana() const {
    return colsVentana;
}

void Mapa::set_cols_ventana(int cols_ventana) {
    colsVentana = cols_ventana;
}

std::vector<std::vector<int>> Mapa::get_ventana() const {
    return ventana;
}

void Mapa::set_ventana(std::vector<std::vector<int>> ventana) {
    this->ventana = ventana;
}
