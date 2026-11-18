
#include "Mapa.h"
#include <random>

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
            if (i>=FILA_PISO && (j< INICIO_HUECO || j>=FIN_HUECO)) {
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

            if (elementito.get_nombre() == "Tuberia" && fil >= FILA_PISO) continue; //Tapar error de tuberia
            mundo[fil][col] = mundoMat[i][j];
            if (elementito.get_nombre() == "Signo") {
                mundoCod[fil][col] = '*';}
            else if (elementito.get_nombre() == "Ladrillo") {
                mundoCod[fil][col] = '#';}
            else {
                mundoCod[fil][col] = elementito.getAtravesable() ? '0' : '1';}
        }
    }
}


char Mapa::golpearBloque(int filaMario, int columnaMario,
                        int anchoMario, int& columnaBloque,
                        int& monedas) {

    monedas = 0;     // Inicialmente no se obtiene ninguna moneda.
    columnaBloque = -1; // -1 indica que aun no se encontro un bloque.

    // La cabeza debe alcanzar la ultima fila del bloque.
    if (filaMario > 15 || filaMario + PASO_VERT <= 15)
        return '0';

    // Revisar las columnas que ocupa la cabeza de Mario.
    for (int j = columnaMario; j < columnaMario + anchoMario; j++) {

        // Evitar acceder a columnas fuera del mundo.
        if (j < 0 || j >= COLS_MUNDO) continue; 

        char tipo = mundoCod[15][j];

        // '#' = ladrillo; '*', 'a' y 'b' = cajas disponibles.
        // Otros codigos no corresponden a bloques activables.
        if (tipo != '#' && tipo != '*' &&
            tipo != 'a' && tipo != 'b') continue;

        // Encontrar el comienzo del bloque.
        int inicio = j;

        while (inicio > 0 && mundoCod[15][inicio - 1] == tipo)
            inicio--;

        // Contar cuantas de las 9 columnas del bloque
        // coinciden horizontalmente con el ancho de Mario.
        int toques = 0;

        for (int k = 0; k < 9; k++) {
            if (inicio + k >= columnaMario &&
                inicio + k < columnaMario + anchoMario)
                toques++;
        }

        if (toques < 5) continue;

        columnaBloque = inicio;

        // LADRILLO: crear una grieta diagonal negra.
        if (tipo == '#') {

            for (int k = 0; k < 9; k++) {
                mundo[7 + k][inicio + k] = C_NEGRO;
            }

            return '#'; // Informar que se golpeo un ladrillo.
        }

        // LUCKY BOX: determinar cuantas monedas quedan.
        int restantes = 3;

        if (tipo == 'a') {restantes = 2;}
        if (tipo == 'b') {restantes = 1;}

        // Crear un generador pseudoaleatorio una sola vez.
        static std::mt19937 generador(std::random_device{}());
        std::uniform_int_distribution<int> sorteo(0, restantes); // Elegir una cantidad entre 0 y las monedas restantes.

        monedas = sorteo(generador);
        restantes -= monedas;

        // Actualizar el estado de la caja.
        char nuevoEstado = '*';

        if (restantes == 2) {nuevoEstado = 'a';}
        if (restantes == 1) {nuevoEstado = 'b';}
        if (restantes == 0) {nuevoEstado = '1';}

        // Actualizar las 9 x 9 celdas de la lucky box.
        for (int i = 7; i < 16; i++) {
            for (int k = inicio; k < inicio + 9; k++) {

                mundoCod[i][k] = nuevoEstado;

                // Solo queda negra cuando se agota.
                if (restantes == 0)
                    mundo[i][k] = C_NEGRO;
            }
        }

        return '*'; // Informar que se golpeo una lucky box.
    }

    return '0'; // No se encontro ningun bloque golpeable.
}

void Mapa::terminarGolpe(char tipo, int columnaBloque) {

    // Solo desaparecen los ladrillos.
    if (tipo != '#') return;

    for (int i = 0; i < ALTO_LADRILLO; i++) {
        for (int j = 0; j < ANCHO_LADRILLO; j++) {

            mundo[7 + i][columnaBloque + j] = C_FONDO;
            mundoCod[7 + i][columnaBloque + j] = '0';
        }
    }
}

void Mapa::operator+=(Entidad* entidad) {
    entidades.push_back(entidad);
}

void Mapa::operator-=(Entidad* entidad) {

    for (int i = 0; i < (int)entidades.size(); i++) {

        if (entidades[i] == entidad) {
            entidades.erase(entidades.begin() + i);
            return;
        }
    }
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

            for (int indice = (int)entidades.size() - 1; indice >= 0; indice--) {
                const Entidad* enti = entidades[indice];
                int pos_x = enti->get_pos_x();
                int pos_y = enti->get_pos_y();

                if (pos_x <= i && i < pos_x + enti->get_alto()
                    && pos_y <= j && j < pos_y + enti->get_ancho()) {
                    const MUNDO& matriz = enti->get_matriz();
                     // para conservar visibles los elementos posteriores.
                    if (matriz[i - pos_x][j - pos_y] != TRANSPARENTE && matriz[i - pos_x][j - pos_y] != C_FONDO) { // para conservar visibles los elementos posteriores.
                        celda = matriz[i - pos_x][j - pos_y];}  // Superponer el color de la entidad sobre el escenario.
                }
            }
            // Convertir el color numerico a su codigo ANSI y añadir dos espacios coloreados que representan un pixel.
            lienzo += colorANSI(celda) + "  " + colorANSI(9);
        }
        lienzo += "\n";
    }
    
    // Imprimir todo el escenario construido en una sola operacion.
    std::cout << lienzo;
    // Mostrar debajo del escenario las monedas acumuladas por Mario.
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
