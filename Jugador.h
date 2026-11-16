//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_JUGADOR_H
#define MARIO2_JUGADOR_H

#include "Entidad.h"
#include "Constantes.h"

class Jugador : public Entidad {
private:
    int coins;
    bool aire;

public:
    Jugador(std::string nombre, int alto, int ancho, MUNDO matriz);
    virtual ~Jugador();

    // direccion: "right", "left", "top", "up-right", "up-left"
    void moverse(std::string direccion) override;

    int get_coins() const;
    void set_coins(int coins);
    void sumarMoneda();

    bool is_aire() const;
    void set_aire(bool aire);
};

#endif //MARIO2_JUGADOR_H
