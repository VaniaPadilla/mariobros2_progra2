#ifndef MARIO2_GUARDADO_H
#define MARIO2_GUARDADO_H

#include <fstream>
#include <string>

#include "Mapa.h"

class Guardado {
public:
    // devuelven false si no se pudo abrir el archivo
    static bool guardar(const Mapa& mapa, const std::string& archivo);
    static bool cargar(Mapa& mapa, const std::string& archivo);
};

#endif //MARIO2_GUARDADO_H