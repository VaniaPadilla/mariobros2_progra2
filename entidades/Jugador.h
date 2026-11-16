
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

    // Direccion: "right", "left", "top", "up-right", "up-left"
    void moverse(std::string direccion) override;

    void sumarMoneda();

    // Getters & Setters

    int get_coins() const;
    void set_coins(int coins);

    bool is_aire() const;
    void set_aire(bool aire);
};

#endif //MARIO2_JUGADOR_H
