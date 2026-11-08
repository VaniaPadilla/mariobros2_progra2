//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_ENTIDAD_H
#define MARIO2_ENTIDAD_H
#include "Sprite.h"

class Entidad: public Sprite {
private:
    bool vida = true;

public:
    Entidad(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz);
    virtual ~Entidad();

    virtual void moverse(std::vector<std::vector<int>>& mundo, int& posX, int& posY, std::string direccion) = 0;

};

#endif //MARIO2_ENTIDAD
