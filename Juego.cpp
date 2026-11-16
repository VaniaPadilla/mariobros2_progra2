
#include "Juego.h"

Juego::Juego() {
    Jugador* jugador = new Jugador("Mario", ALTO_MARIO, ANCHO_MARIO, marioS );

    std::vector<Entidad*> entidades;
    entidades.push_back(jugador);

    Mapa* mapa = new Mapa(FILS_MUNDO, COLS_MUNDO, FILS_VENTANA, COLS_VENTANA, *jugador);
    // memoria dinamica

    crearElementos();

    // enemigos creados con new
    bool iniciado = false;                     // ya se escribio init
    bool terminado = false;
}

Juego::~Juego() {
}

void Juego::crearElementos() {
    NpcEnemigo* goomba1 = new NpcEnemigo("Goomba", ALTO_GOOMBA, ANCHO_GOOMBA, goombaS, 27, 104);
    NpcEnemigo* goomba2 = new NpcEnemigo("Goomba", ALTO_GOOMBA, ANCHO_GOOMBA, goombaS, 200, 104);
    entidades.push_back(goomba1);
    entidades.push_back(goomba2);

    Elemento* arbusto1 = new Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 21, false, 0);
    Elemento* arbusto2 = new Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 29, false, 0);
    Elemento* arbusto3 = new Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 37, false, 0);
    Elemento* arbusto4 = new Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 98, false, 0);

    Elemento* signo1 = new Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 29, false, '*');
    Elemento* signo2 = new Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 82, false, '*');
    Elemento* signo3 = new Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 100, false, '*');

    Elemento* ladrillo1 = new Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 73, false, '0');


    mapa->agregarElemento(*arbusto1);
    mapa->agregarElemento(*arbusto2);
    mapa->agregarElemento(*arbusto3);
    mapa->agregarElemento(*arbusto4);

    mapa->agregarElemento(*signo1);
    mapa->agregarElemento(*signo2);
    mapa->agregarElemento(*signo3);

    mapa->agregarElemento(*ladrillo1);

}


void Juego::iniciar() {
    std::string clave;
    do {
        std::cout << "ʕ⊙ᴥ⊙ʔ";
        std::cin >> clave;
    } while (clave != "init" && clave != "exit");

    if (clave == "init") {
        iniciado = true;
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
