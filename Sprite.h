//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_SPRITE_H
#define MARIO2_SPRITE_H

#include <iostream>
#include <vector>

#include "Mapa.h"

class Sprite {
private:
    std::string nombre;
    std::vector<std::vector<int>> matriz;
    int alto, ancho;
    int posX, posY;

public:

    Sprite (std::string nombre, int alto, int ancho, std::vector<std::vector<int>> matriz);
    ~Sprite();

    static void dibujar(std::vector<std::vector<int>>& mundito, const Sprite& spritito, int posX, int posY);

    static void borrar(std::vector<std::vector<int>>& mundito, const Sprite& spritito, int posX, int posY);

    void modificar(std::vector<std::vector<int>> nuevaMat);

    static Sprite clonar(Sprite spritito);

    std::string get_nombre() const;
    void set_nombre(std::string nombre);

    std::vector<std::vector<int>> get_matriz() const;
    void set_matriz(std::vector<std::vector<int>> matriz);

    int get_alto() const;
    void set_alto(int alto);

    int get_ancho() const;
    void set_ancho(int ancho);

    int get_pos_x() const;
    void set_pos_x(int pos_x);

    int get_pos_y() const;
    void set_pos_y(int pos_y);
};


#endif //MARIO2_SPRITE_H
