

#include "NpcEnemigo.h"

NpcEnemigo::NpcEnemigo(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz)
    : Entidad(nombre, alto, ancho, matriz) {
}

NpcEnemigo::~NpcEnemigo() {
}

void NpcEnemigo::moverse(std::string direccion) {
    const int xActual = this->get_pos_x();
    const int yActual = this->get_pos_y();

    this->set_pos_x(xActual - 12);

}
