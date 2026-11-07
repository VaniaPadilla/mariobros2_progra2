//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_SPRITE_H
#define MARIO2_SPRITE_H

#include <iostream>
#include <vector>

class Sprite {
private:
    std::string nombre;
    std::vector<std::vector<int>> matriz;
    int alto, ancho;
    int posX, posY;

public:

    Sprite (std::string nombre, int alto, int ancho, int posX, int posY);
    ~Sprite();

    void dibujar(int** mundo);
    void borrar(int** mundo);
    void modificar(int ** mundo);
    Sprite clonar(Sprite spritito);
};


#endif //MARIO2_SPRITE_H
