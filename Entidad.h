//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_ENTIDAD_H
#define MARIO2_ENTIDAD_H
#include "Sprite.h"


class Mapa;

struct Posicion {
    int x;
    int y;

};

class Entidad: public Sprite {
    protected:
    int vida;

    public:
    Entidad(std::string nombre, int alto, int ancho, int vida);
    virtual ~Entidad();

    virtual void moverse(std::string direccion) = 0;
    void dibujar(Mapa& map);
    void borrar(Mapa& map);
    Posicion operator+(const Posicion& other) const;

    int getVida() const;
    void setVida(int vida);


};


#endif //MARIO2_ENTIDAD_H
