//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_ELEMENTO_H
#define MARIO2_ELEMENTO_H
#include "Sprite.h"


class Elemento : public Sprite {
private:
    bool atravesable;
    int estado;

public:
    Elemento(std::string nombre, int alto, int ancho, bool atravesable, int estado);
    ~Elemento();

};


#endif //MARIO2_ELEMENTO_H
