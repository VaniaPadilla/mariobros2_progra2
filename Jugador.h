//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_JUGADOR_H
#define MARIO2_JUGADOR_H
#include "Entidad.h"

class Jugador : public Entidad {
private:
    int coins;
    bool aire;

public:
    Jugador(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz);
    virtual ~Jugador();

    void moverse(std::string direccion) override;
};
#endif //MARIO2_JUGADOR_H
