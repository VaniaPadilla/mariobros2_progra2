
#include "Juego.h"

Juego::Juego() {
    Mapa* mapa{};                        // memoria dinamica
    std::vector<Entidad*> entidades;   // enemigos creados con new
    bool iniciado{};                     // ya se escribio init
    bool terminado{};
}

Juego::~Juego() {
}

void Juego::iniciar() {
    std::string clave;
    do {
        std::cout << "ʕ⊙ᴥ⊙ʔ";
        std::cin >> clave;
    } while (clave != "init" && clave != "exit");

    if (clave == "init") {
        ejecutar();
    }
    else {
        terminado = true;
    }
}


void Juego::ejecutar() {
    std::string eleccion;

    std::cout << "Welcome to the world of super mario bros xyz \n";

    do {
        std::cout << "Comando: ";
        std::cin >> eleccion;

        if (!procesarComando(eleccion)) {
            std::cout << "Comando invalido\n";
        }

        for (int i = 1; i < entidades.size(); i++) {
            entidades[i]->moverse("");
        }

        
    } while (eleccion != "exit");

}

bool Juego::procesarComando(const std::string &comando) {
    if (comando == "right" && entidades[0]->get_pos_x() + PASO_HORIZ*2 <= COLS_MUNDO) {
        entidades[0]->moverse(comando);
        return true;
    }
    if (comando == "left" && entidades[0]->get_pos_x() - PASO_HORIZ >= 0) {
        entidades[0]->moverse(comando);
        return true;
    }
    if (comando == "top") {
        entidades[0]->moverse(comando);
        return true;
    }
    if (comando == "up-right" && entidades[0]->get_pos_x()+PASO_HORIZ*2 <= COLS_MUNDO) {
        entidades[0]->moverse(comando);
        return true;
    }
    if (comando == "up-left" && entidades[0]->get_pos_x() - PASO_HORIZ >= 0) {
        entidades[0]->moverse(comando);
        return true;
    }

    if (comando == "save") {
        guardar();
        return true;
    }
    if (comando == "load") {
        cargar();
        return true;
    }

    return false;
}


//?
int Jugador::get_coins() const {
    return coins;
}

// Getters & Setters

Mapa * Juego::get_mapa() const {
    return mapa;}
void Juego::set_mapa(Mapa *mapa) {
    this->mapa = mapa;}

std::vector<Entidad *> Juego::get_entidades() const {
    return entidades;}
void Juego::set_entidades(std::vector<Entidad *> entidades) {
    this->entidades = entidades;}

bool Juego::is_iniciado() const {
    return iniciado;}
void Juego::set_iniciado(bool iniciado) {
    this->iniciado = iniciado;}

bool Juego::is_terminado() const {
    return terminado;}
void Juego::set_terminado(bool terminado) {
    this->terminado = terminado;}
