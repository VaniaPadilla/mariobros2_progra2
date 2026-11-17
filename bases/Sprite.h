#ifndef MARIO2_SPRITE_H
#define MARIO2_SPRITE_H

#include <iostream>
#include <vector>

using MUNDO = std::vector<std::vector<int>>;

// Clase base que almacena la apariencia, dimensiones
// y posicion de los objetos graficos del videojuego.
class Sprite {
private:
    std::string nombre;
    MUNDO matriz;
    int alto, ancho;
    int posX, posY;

public:

    // Constructor y destructor
    Sprite(std::string nombre, int alto, int ancho,
           MUNDO matriz, int posX, int posY);

    virtual ~Sprite();

    // Getters & Setters

    std::string get_nombre() const;
    void set_nombre(std::string nombre);

    const MUNDO& get_matriz() const;
    void set_matriz(MUNDO matriz);

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
