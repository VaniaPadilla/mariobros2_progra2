
#include "Mapa.h"

Mapa::Mapa(int filsMundo, int colsMundo, int filsVentana, int colsVentana, Jugador jugador) : jugadorcito(jugador) {
    this->filsMundo = filsMundo;
    this->colsMundo = colsMundo;
    this->filsVentana = filsVentana;
    this->colsVentana = colsVentana;
    this->colInicialVentana = 0;
    this->jugadorcito = jugador;

    mundo.assign(filsMundo, std::vector<int>(colsMundo, 0));
    mundoCod.assign(filsMundo, std::vector<char>(colsMundo, '0'));
    ventana.assign(filsVentana, std::vector<int>(colsVentana, 0));

    crearMundo();
}

Mapa::~Mapa() {
}


void Mapa::crearMundo() {
    for (int i = 0; i < filsMundo; i++) {
        for (int j = 0; j < colsMundo; j++) {
            if (i>=43 && (j<=165 || j>=181)) {
                mundo[i][j] = 1;
                mundoCod[i][j] = '1';
            }
            else {
                mundo[i][j] = 0;
                mundoCod[i][j] = '0';
            }
        }
    }
}

void Mapa::agregarElemento(Elemento elementito) {
    const MUNDO& mundoMat = elementito.get_matriz();
    for (int i = 0; i < elementito.get_ancho(); i++) {
        for (int j = 0; j < elementito.get_alto(); j++) {
            int fil = elementito.get_pos_x() + i;
            int col = elementito.get_pos_y() + j;

            if (fil<0 || fil>= filsMundo || col <0 || col >= colsMundo) continue;
            mundo[fil][col] = mundoMat[i][j];
            mundoCod[i][j] = elementito.getAtravesable();
        }
    }
}

void Mapa::operator+=(Entidad* entidad) {
    entidades.push_back(entidad);
}

void Mapa::operator+=(Elemento elemento) {
    agregarElemento(elemento);
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

    std::cout << lienzo;

    std::cout << "\ncoins: " << jugadorcito.get_coins() << "\n\n";
}


// Getters & Setters

int Mapa::get_fils_mundo() const {
    return filsMundo; }
void Mapa::set_fils_mundo(int fils_mundo) {
    filsMundo = fils_mundo; }

int Mapa::get_cols_mundo() const {
    return colsMundo; }
void Mapa::set_cols_mundo(int cols_mundo) {
    colsMundo = cols_mundo; }

MUNDO Mapa::get_mundo() const {
    return mundo; }
void Mapa::set_mundo(MUNDO mundo) {
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

MUNDO Mapa::get_ventana() const {
    return ventana; }
void Mapa::set_ventana(MUNDO ventana) {
    this->ventana = ventana; }
