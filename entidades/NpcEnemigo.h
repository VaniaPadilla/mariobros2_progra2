
#ifndef MARIO2_NPCENEMIGO_H
#define MARIO2_NPCENEMIGO_H

#include "Entidad.h"
#include "Constantes.h"

class NpcEnemigo : public Entidad 
{
    public:
    NpcEnemigo(std::string nombre, int alto, int ancho, MUNDO matriz, int posX, int posY);
    ~NpcEnemigo() override;

    void moverse(std::string direccion) override;

    // Goomba muere si Mario lo aplasta.
    void morir();
};

#endif //MARIO2_NPCENEMIGO_H
