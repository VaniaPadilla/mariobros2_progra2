
#ifndef MARIO2_NPCENEMIGO_H
#define MARIO2_NPCENEMIGO_H

#include "Entidad.h"


class NpcEnemigo : public Entidad 
{
    public:
    NpcEnemigo(std::string nombre, int alto, int ancho, MUNDO matriz, int posX, int posY);
    virtual ~NpcEnemigo();

    void moverse(std::string direccion) override;

};

#endif //MARIO2_NPCENEMIGO_H
