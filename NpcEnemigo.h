//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_NPCENEMIGO_H
#define MARIO2_NPCENEMIGO_H
#include "Entidad.h"


class NpcEnemigo : public Entidad {
    public:
    NpcEnemigo(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz);
    virtual ~NpcEnemigo();

    void moverse(std::vector<std::vector<int>>& mundo, int& posX, int& posY, std::string direccion) override;

};

#endif //MARIO2_NPCENEMIGO_H
