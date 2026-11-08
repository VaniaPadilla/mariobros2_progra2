//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_MAPA_H
#define MARIO2_MAPA_H

#include <vector>

#include "colores.h"
#include "Elemento.h"
#include "Entidad.h"
#include "Jugador.h"

class Mapa {
private:
    int filsMundo, colsMundo;
    std::vector<std::vector<int>> mundo;
    std::vector<std::vector<char>> mundoCod;

    int filsVentana, colsVentana;
    int colInicialVentana;
    std::vector<std::vector<int>> ventana;

    std::vector<Entidad*> entidades;
    Jugador jugadorcito;

    int coins;

public:
    Mapa(int filsMundo, int colsMundo, int filsVentana, int colsVentana, Jugador jugadorcito);
    ~Mapa();

    void crearMundo();

    void agregarElemento(Elemento elementito);

    void agregarEntidad(Entidad* entidad);

    void moverEscena();

    void dibujarEscena() const;



    int get_fils_mundo() const;
    void set_fils_mundo(int fils_mundo);

    int get_cols_mundo() const;
    void set_cols_mundo(int cols_mundo);

    std::vector<std::vector<int>> get_mundo() const;
    void set_mundo(std::vector<std::vector<int>> mundo);

    std::vector<std::vector<char>> get_mundo_cod() const;
    void set_mundo_cod(std::vector<std::vector<char>> mundo_cod);

    int get_fils_ventana() const;
    void set_fils_ventana(int fils_ventana);

    int get_cols_ventana() const;
    void set_cols_ventana(int cols_ventana);

    std::vector<std::vector<int>> get_ventana() const;
    void set_ventana(std::vector<std::vector<int>> ventana);
};


#endif //MARIO2_MAPA_H
