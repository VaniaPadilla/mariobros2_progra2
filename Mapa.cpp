//
// Created by User01 on 6/11/2026.
//

#include "Mapa.h"

Mapa::Mapa(int filsMundo, int colsMundo, int filsVentana, int colsVentana, Jugador jugador) : jugadorcito(jugador) {
    this->filsMundo = filsMundo;
    this->colsMundo = colsMundo;
    this->filsVentana = filsVentana;
    this->colsVentana = colsVentana;
    this->colInicialVentana = 0;
    this->jugadorcito = jugador;
    crearMundo();
} ;

Mapa::~Mapa() {
}


void Mapa::crearMundo() {
    for (int i = 0; i < filsMundo; i++) {
        for (int j = 0; j < colsMundo; j++) {
            if (i>=43) mundo[i][j] = 1;
            else mundo[i][j] = 0;
            mundoCod[i][j] = 0;
        }
    }
}

void Mapa::agregarElemento(Elemento elementito) {
    for (int i = 0; i < elementito.get_ancho(); i++) {
        for (int j = 0; j < elementito.get_alto(); j++) {
            mundo[i][j] = elementito.get_matriz()[i][j];
            mundoCod[i][j] = elementito.getAtravesable();
        }
    }
}

void Mapa::agregarEntidad(Entidad* enti) {
    entidades.push_back(enti);
}

void Mapa::moverEscena() {

    if (colInicialVentana+colsVentana - jugadorcito.get_pos_x()+12 == 42 && colInicialVentana<=150) {
        colInicialVentana += 12;
    }

    if (jugadorcito.get_pos_x()+12 - colInicialVentana == 32 && colInicialVentana>=0) {
        colInicialVentana -=12;
    }

}

void Mapa::dibujarEscena() const {

    // Código de escape ANSI para borrar la terminal completa y mover el cursor a [0,0] (evita parpadeos).
    std::cout << "\033[2J\033[H";

    std::string lienzo = "";

    for (int i=0; i<filsVentana; i++) {
        for (int j=colInicialVentana; j<colsVentana; j++) {
            int celda = mundo[i][j];

            for (const Entidad* enti : entidades) {
                if (enti->get_pos_x() == i && enti->get_pos_y() == j) {
                    if (enti->get_matriz()[i][j] != -1) celda = enti->get_matriz()[i][j];
                }
            }

            lienzo += colorANSI(celda) + " " + colorANSI(9);
        }
        lienzo += "\n";
    }

    std::cout << "lienzo";

    std::cout << "\ncoins: " << coins << "\n\n";
}




int Mapa::get_fils_mundo() const {
    return filsMundo; }
void Mapa::set_fils_mundo(int fils_mundo) {
    filsMundo = fils_mundo; }

int Mapa::get_cols_mundo() const {
    return colsMundo; }
void Mapa::set_cols_mundo(int cols_mundo) {
    colsMundo = cols_mundo; }

std::vector<std::vector<int>> Mapa::get_mundo() const {
    return mundo; }
void Mapa::set_mundo(std::vector<std::vector<int>> mundo) {
    this->mundo = mundo; }

std::vector<std::vector<char>> Mapa::get_mundo_cod() const {
    return mundoCod; }
void Mapa::set_mundo_cod(std::vector<std::vector<char>> mundo_cod) {
    mundoCod = mundo_cod; }

int Mapa::get_fils_ventana() const {
    return filsVentana; }
void Mapa::set_fils_ventana(int fils_ventana) {
    filsVentana = fils_ventana; }

int Mapa::get_cols_ventana() const {
    return colsVentana; }
void Mapa::set_cols_ventana(int cols_ventana) {
    colsVentana = cols_ventana; }

std::vector<std::vector<int>> Mapa::get_ventana() const {
    return ventana; }
void Mapa::set_ventana(std::vector<std::vector<int>> ventana) {
    this->ventana = ventana; }
