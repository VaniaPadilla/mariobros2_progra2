//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_MAPA_H
#define MARIO2_MAPA_H

#include <vector>

#include "Elemento.h"
#include "Entidad.h"

class Mapa {
private:
    int filsMundo, colsMundo;
    std::vector<std::vector<int>> mundo;
    std::vector<std::vector<char>> mundoCod;

    int filsVentana, colsVentana;
    std::vector<std::vector<int>> ventana;

public:
    Mapa(int filsMundo, int colsMundo);
    ~Mapa();

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
