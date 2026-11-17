
#include "Mapa.h"

Mapa::Mapa(int filsMundo, int colsMundo, int filsVentana, int colsVentana, Jugador& jugadorcito) : jugadorcito(jugadorcito) {
    this->filsMundo = filsMundo;
    this->colsMundo = colsMundo;
    this->filsVentana = filsVentana;
    this->colsVentana = colsVentana;
    this->colInicialVentana = 0;

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

    for (int i = 0; i < elementito.get_alto(); i++) {
        for (int j = 0; j < elementito.get_ancho(); j++) {
            int fil = elementito.get_pos_x() + i;
            int col = elementito.get_pos_y() + j;

            if (fil<0 || fil>= filsMundo || col <0 || col >= colsMundo) continue;
            if (mundoMat[i][j] == TRANSPARENTE) continue;

            mundo[fil][col] = mundoMat[i][j];
            mundoCod[fil][col] = elementito.getEstado();
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

    // Mover la camara hacia la derecha
    if (colInicialVentana + colsVentana -(jugadorcito.get_pos_y()+jugadorcito.get_ancho()) < DIST_CAMARA_DER) {
        if(COLS_MUNDO - COLS_VENTANA < colInicialVentana + PASO_HORIZ){
            colInicialVentana = COLS_MUNDO - COLS_VENTANA;
        }
        else {
            colInicialVentana += PASO_HORIZ;
        }
    }
    // Mover la camara hacia la izquierda
    else if (jugadorcito.get_pos_y() - colInicialVentana < DIST_CAMARA_IZQ) {
        if(colInicialVentana - PASO_HORIZ < 0){
            colInicialVentana = 0;
        }
        else {
            colInicialVentana -= PASO_HORIZ;
        }
    }

}


void Mapa::dibujarEscena() const {

    // Código de escape ANSI para borrar la terminal completa y mover el cursor a [0,0] (evita parpadeos).
    std::cout << "\033[2J\033[H";

    std::string lienzo = "";
    for (int i = 0; i < filsVentana; i++) {
        for (int j = colInicialVentana; j < colInicialVentana + colsVentana; j++) {
            int celda = mundo[i][j];

            for (const Entidad* enti : entidades) {
                int pos_x = enti->get_pos_x();
                int pos_y = enti->get_pos_y();

                if (pos_x <= i && i < pos_x + enti->get_alto()
                    && pos_y <= j && j < pos_y + enti->get_ancho()) {
                    const MUNDO& matriz = enti->get_matriz();
                    if (matriz[i - pos_x][j - pos_y] != TRANSPARENTE) {
                        celda = matriz[i - pos_x][j - pos_y];
                    }
                }
            }
            lienzo += colorANSI(celda) + "  " + colorANSI(9);
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
