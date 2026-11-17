
#include <iostream>

#include "Juego.h"

int main() {

    std::cout << "Constructor de Juego\n";
    Juego *superMarioBros = new Juego();
    std::cout << "Iniciar Juego\n";
    superMarioBros->iniciar();

    std::cout << "Crash\n";
    return 0;
}
