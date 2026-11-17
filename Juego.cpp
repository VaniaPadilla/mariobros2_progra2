
#include "Juego.h"

#include <chrono>
#include <thread>

Juego::Juego() : mapa(nullptr), jugador(nullptr), iniciado(false), terminado(false) {
    jugador = new Jugador("Mario", ALTO_MARIO, ANCHO_MARIO, marioS );
    // memoria dinamica.
    entidades.push_back(jugador);

    mapa = new Mapa(FILS_MUNDO, COLS_MUNDO, FILS_VENTANA, COLS_VENTANA, *jugador);
    // memoria dinamica, en el atributo
    // Registrar a Mario dentro del mapa.
    (*mapa) += jugador;     // Utilizamos la sobrecarga de operadores.
    std::cout << "antes de crear elementos";
    crearElementos();
}

Juego::~Juego() {
    // Liberar la memoria dinamica del mapa.
    delete mapa;

    // Liberar a Mario y los dos Goombas.
    // Todos fueron creados con new.
    int cantidad = entidades.size();

    for (int i = 0; i < cantidad; i++) {
        delete entidades[i];
    }

    entidades.clear();
}

void Juego::crearElementos() {
    NpcEnemigo* goomba1 = new NpcEnemigo("Goomba", ALTO_GOOMBA, ANCHO_GOOMBA, goombaS, 27, 104);
    NpcEnemigo* goomba2 = new NpcEnemigo("Goomba", ALTO_GOOMBA, ANCHO_GOOMBA, goombaS, 27, 219);
    entidades.push_back(goomba1);
    entidades.push_back(goomba2);
    // El mapa necesita conocerlos para dibujarlos.
    (*mapa) += goomba1;
    (*mapa) += goomba2;     // Se usa la sobrecarga de operadores.
    // Se usa la otra sobrecarga de operadores.
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 21, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 29, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 37, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 98, false, '0');

    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 29, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 82, false, '*');
    (*mapa) +=  Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 100, false, '*');

    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 166, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 204, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 223, false, '*');

    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 73, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 91, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 109, false, '0');

    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 195, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 213, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 232, false, '0');

    (*mapa) += Elemento("Tuberia", ALTO_TUBERIA, ANCHO_TUBERIA, tuberiaS, 25, 141, false, '0');

}


void Juego::iniciar() {

    std::string clave;

    do {
        std::cout << "ʕ⊙ᴥ⊙ʔ ";

        // Si falla la lectura, terminar el programa.
        if (!(std::cin >> clave)) { //Es una medida de seguridad
            terminado = true;
            return;
        }

        //En caso quiero recargar una partida
        if (clave != "init" && clave != "exit") {

            if (clave == "load") {
                cargar();
            }
            else {
                std::cout << "invalid operation\n";
            }
        }

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

    std::cout
        << "Welcome to the world of super mario bros xyz\n";

    // Mostrar el escenario al comenzar el juego.
    mapa->dibujarEscena();

    do {
        std::cout << "Comando: ";

        if (!(std::cin >> eleccion)) { //Misma lógica que el anterior
            terminado = true;
            break;
        }

        // Exit termina inmediatamente, el goomba ni llega a moverse
        if (eleccion == "exit") {
            terminado = true;
            break;
        }

        // Procesar el comando de Mario.
        bool valido = procesarComando(eleccion);

        if (!valido) {
            std::cout << "invalid operation\n";
        }

        // Ambos Goombas se mueven una vez por comando,
        // incluso cuando la instruccion es invalida. Decisión estilistica
        moverEnemigos();

        if (valido && Jugador::esSalto(eleccion)) {

            // En caso que salto, ejecutar animación como en el proyecto 1
            animarSalto();
        }
        else {

            // Para right y left no hay animacion, no alcanzo el presupuesto OwO (bromita)
            mapa->moverEscena();
            mapa->dibujarEscena();
        }

    } while (!terminado);

    std::cout << "Se salio del juego\n";
}

void Juego::moverEnemigos() {

    // entidades[0] es Mario.
    // entidades[1] y entidades[2] son Goombas.
    // Cada enemigo vivo se mueve una sola vez.

    int cantidad = entidades.size(); //POO, permite reutilizar código, por si se desea añadir más goombas

    for (int i = 1; i < cantidad; i++) {

        if (entidades[i] != nullptr &&
            entidades[i]->is_vida()) 
            {
            // El Goomba ignora la direccion recibida
            entidades[i]->moverse("");  // Siempre camina hacia la izquierda.
        }
    }
}

void Juego::animarSalto() {

    // PRIMER FOTOGRAMA:
    // Mario ya esta arriba porque antes ejecutamos
    // jugador->moverse("top") o un salto diagonal.
    mapa->moverEscena(); 
    mapa->dibujarEscena();

    // Pausa para visualizar a Mario en el aire.
    std::this_thread::sleep_for(
        std::chrono::milliseconds(350)
    );

    // SEGUNDO FOTOGRAMA:

    jugador->aterrizar();     // Mario vuelve a su fila inicial. 
    //Conservo columna nueva, en caso de salto diagonal
    mapa->moverEscena();
    mapa->dibujarEscena();
}

bool Juego::procesarComando(const std::string &comando) {

    //Confunde que este inverso, pero: 
    const int columna = jugador->get_pos_y(); // posY representa la columna horizontal.
    if (comando == "right" || comando == "up-right") {

        if (columna + PASO_HORIZ + jugador->get_ancho() > COLS_MUNDO) {
            return false;
        }
        jugador->moverse(comando);
        return true;
    }
    if (comando == "left" || comando == "up-left") {

        if (columna - PASO_HORIZ < 0) {
            return false;
        }
        jugador->moverse(comando);
        return true;
    }
    //Por como funciona, ahora se ahorra código!
    if (comando == "top" || comando == "up") {
        jugador->moverse(comando);
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

void Juego::guardar() {
    std::cout << "Quiero al profesor Wilder\n";
}

void Juego::cargar() {
    std::cout << "Quiero al profesor Wilder x2\n";
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
