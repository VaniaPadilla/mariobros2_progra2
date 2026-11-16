

#include "NpcEnemigo.h"

NpcEnemigo::NpcEnemigo(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz, int posX, int posY)
    : Entidad(nombre, alto, ancho, matriz, posX, posY) {
}

NpcEnemigo::~NpcEnemigo() {
}

void NpcEnemigo::moverse(std::string direccion) {
    const int xActual = this->get_pos_x();
    const int yActual = this->get_pos_y();

    this->set_pos_x(xActual - 12);

}
