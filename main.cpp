
#include <iostream>

#include "Juego.h"

int main() {
    Juego *superMarioBros = new Juego();

    std::cout << "Iniciar Juego\n";
    
    superMarioBros->iniciar();

    delete superMarioBros;
    return 0;
}
