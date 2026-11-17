
#include <iostream>

#include "Juego.h"

int main() {

    Juego *superMarioBros = new Juego();

    superMarioBros->iniciar();

    delete superMarioBros;
    return 0;
}
