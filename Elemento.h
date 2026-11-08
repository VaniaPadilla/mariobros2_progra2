//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_ELEMENTO_H
#define MARIO2_ELEMENTO_H
#include "Sprite.h"


class Mapa;
class Elemento : public Sprite {

private:
    bool atravesable;
    char estado;

public:
    Elemento(std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz, bool atravesable, char estado);
    ~Elemento();

    bool getAtravesable() const;
    void setAtravesable(bool atravesable);

    char getEstado() const;
    void setEstado(char estado);

};


#endif //MARIO2_ELEMENTO_H
