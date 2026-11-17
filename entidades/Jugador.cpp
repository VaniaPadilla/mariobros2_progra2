
#include "Jugador.h"

Jugador::Jugador(std::string nombre, int alto,
                 int ancho, MUNDO matriz)
    : Entidad(nombre, alto, ancho, matriz, 27, 7),
      coins(0),
      aire(false),
      filaSuelo(27) {
}

Jugador::~Jugador() {
}

// --------------------------------------------------
// MOVIMIENTOS
// --------------------------------------------------

void Jugador::moverse(std::string direccion) {

    if (!is_vida() || aire) {
        return;
    }

    const int filaActual = get_pos_x();
    const int columnaActual = get_pos_y();

    if (direccion == "right") {
        set_pos_y(columnaActual + PASO_HORIZ);
    }
    else if (direccion == "left") {
        set_pos_y(columnaActual - PASO_HORIZ);
    }
    else if (esSalto(direccion)) {

        filaSuelo = filaActual;

        // Movimiento horizontal inmediato.
        if (direccion == "up-right") {
            set_pos_y(columnaActual + PASO_HORIZ);
        }
        else if (direccion == "up-left") {
            set_pos_y(columnaActual - PASO_HORIZ);
        }

        // Primer fotograma: Mario en el aire.
        set_pos_x(filaSuelo - PASO_VERT);
        aire = true;
    }
}

// --------------------------------------------------
// SEGUNDO FOTOGRAMA: ATERRIZAJE
// --------------------------------------------------

void Jugador::aterrizar() {

    if (!aire) {
        return;
    }

    set_pos_x(filaSuelo);
    aire = false;
}

// --------------------------------------------------
// IDENTIFICAR SALTOS
// --------------------------------------------------

bool Jugador::esSalto(const std::string& direccion) {

    return direccion == "top" ||
           direccion == "up" ||
           direccion == "up-right" ||
           direccion == "up-left";
}

// --------------------------------------------------
// MONEDAS
// --------------------------------------------------

void Jugador::sumarMoneda() {
    coins++;
}

int Jugador::get_coins() const {
    return coins;
}

void Jugador::set_coins(int coins) {

    if (coins >= 0) {
        this->coins = coins;
    }
}

// --------------------------------------------------
// ESTADO DEL SALTO
// --------------------------------------------------

bool Jugador::is_aire() const {
    return aire;
}

void Jugador::set_aire(bool aire) {

    this->aire = aire;

    if (!aire) {
        filaSuelo = get_pos_x();
    }
}

int Jugador::get_fila_suelo() const {
    return filaSuelo;
}
