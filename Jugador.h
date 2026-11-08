//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_JUGADOR_H
#define MARIO2_JUGADOR_H
#include "Entidad.h"


class Jugador : public Entidad {
public:
    Jugador(int x, int y);
    ~Jugador();

    void moverse(std::string direccion) override;
};

#endif

