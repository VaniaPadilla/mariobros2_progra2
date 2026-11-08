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
    int estado;

public:
    Elemento(std::string nombre, int alto, int ancho, bool atravesable, int estado);
    Elemento(const Elemento& other);
    ~Elemento();

    Elemento* clonar() const;

    void colocar(Mapa& map, int x, int y);
    void modificar(Mapa& map);
    void quitar(Mapa& map);

    bool getAtravesable() const;
    void setAtravesable(bool atravesable);

    int getEstado() const;
    void setEstado(int estado);

};


#endif //MARIO2_ELEMENTO_H
