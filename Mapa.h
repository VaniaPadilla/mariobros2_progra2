
#ifndef MARIO2_MAPA_H
#define MARIO2_MAPA_H

#include <vector>

#include "no_clases/colores.h"
#include "bases/Elemento.h"
#include "bases/Entidad.h"
#include "entidades/Jugador.h"

class Mapa {
private:
    int filsMundo, colsMundo;
    MUNDO mundo;
    std::vector<std::vector<char>> mundoCod;

    int filsVentana, colsVentana;
    int colInicialVentana;
    MUNDO ventana;

    std::vector<Entidad*> entidades;
    Jugador jugadorcito;

public:
    Mapa(int filsMundo, int colsMundo, int filsVentana, int colsVentana, Jugador jugadorcito);
    ~Mapa();

    void crearMundo();

    void agregarElemento(Elemento elementito);

    void operator+=(Entidad* entidad);

    void moverEscena();

    void dibujarEscena() const;



    int get_fils_mundo() const;
    void set_fils_mundo(int fils_mundo);

    int get_cols_mundo() const;
    void set_cols_mundo(int cols_mundo);

    MUNDO get_mundo() const;
    void set_mundo(MUNDO mundo);

    std::vector<std::vector<char>> get_mundo_cod() const;
    void set_mundo_cod(std::vector<std::vector<char>> mundo_cod);

    int get_fils_ventana() const;
    void set_fils_ventana(int fils_ventana);

    int get_cols_ventana() const;
    void set_cols_ventana(int cols_ventana);

    MUNDO get_ventana() const;
    void set_ventana(MUNDO ventana);
};


#endif //MARIO2_MAPA_H
