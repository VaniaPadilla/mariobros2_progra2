//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_ENTIDAD_H
#define MARIO2_ENTIDAD_H
#include "Sprite.h"

class Entidad
{
    private:
    bool vida;
    Sprite sprite;
    public:
    
    Entidad(bool _vida, Sprite _s);
    ~Entidad();

    virtual void moverse(std::string direccion) = 0;
    void dibujar(Mapa& mapa);
    void borrar(Mapa& mapa);
};

#endif //MARIO2_ENTIDAD
