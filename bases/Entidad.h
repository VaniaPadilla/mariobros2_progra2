
#ifndef MARIO2_ENTIDAD_H
#define MARIO2_ENTIDAD_H

#include "Sprite.h"

class Entidad: public Sprite {
private:
    // Determina si una entidad esta viva o muerta
    bool vida = true;

public:
    Entidad(std::string nombre, int alto, int ancho, MUNDO matriz);
    virtual ~Entidad();

    virtual void moverse(std::string direccion) = 0;

    bool is_vida() const;

    void set_vida(bool vida);
};

#endif //MARIO2_ENTIDAD
