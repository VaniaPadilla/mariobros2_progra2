
#ifndef MARIO2_ELEMENTO_H
#define MARIO2_ELEMENTO_H

#include "Sprite.h"

class Elemento : public Sprite {

private:
    // Características de bloques específicos

    // Determina si Mario se choca con el bloque o no
    bool atravesable;

    // Determina si el estado de un bloque (Signo con moneda colectada, Bloque roto)
    char estado;

public:
    Elemento(std::string nombre, int alto, int ancho, MUNDO matriz, bool atravesable, char estado);
    virtual ~Elemento();

    bool getAtravesable() const;
    void setAtravesable(bool atravesable);

    char getEstado() const;
    void setEstado(char estado);

};


#endif //MARIO2_ELEMENTO_H
