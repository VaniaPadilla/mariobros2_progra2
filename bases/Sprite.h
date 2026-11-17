
#ifndef MARIO2_SPRITE_H
#define MARIO2_SPRITE_H

#include <iostream>
#include <vector>

using MUNDO = std::vector<std::vector<int>>;

class Sprite {
private:
    std::string nombre;
    MUNDO matriz;
    int alto, ancho;
    int posX, posY;

public:

    Sprite (std::string nombre, int alto, int ancho, MUNDO matriz, int posX, int posY);
    virtual ~Sprite();

    //

    static void dibujar(MUNDO& mundito, const Sprite& spritito, int posX, int posY);
    static void borrar(MUNDO& mundito, const Sprite& spritito, int posX, int posY);

    void modificar(MUNDO& nuevaMat);

    static Sprite clonar(Sprite spritito);

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
