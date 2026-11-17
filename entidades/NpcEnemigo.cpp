

#include "NpcEnemigo.h"

NpcEnemigo::NpcEnemigo(std::string nombre, int alto, int ancho, MUNDO matriz, int posX, int posY)
    : Entidad(nombre, alto, ancho, matriz, posX, posY) {
}

NpcEnemigo::~NpcEnemigo() {
}

void NpcEnemigo::moverse(std::string) {
    if (!is_vida()) {
        return;
    }

    // Goomba siempre avanza hacia la izquierda.
    // posY representa la columna horizontal.
    set_pos_y(get_pos_y() - PASO_HORIZ);
}

void NpcEnemigo::morir() {
    set_vida(false);
}
