
#ifndef MARIO2_GUARDADO_H
#define MARIO2_GUARDADO_H

#include <string>

class Juego;

class Guardado {
public:
    // Devuelven false si no se pudo guardar o cargar.
    static bool guardar(const Juego& juego, const std::string& archivo);
    static bool cargar(Juego& juego, const std::string& archivo);
};

#endif // MARIO2_GUARDADO_H