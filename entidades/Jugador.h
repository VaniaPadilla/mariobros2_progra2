
#ifndef MARIO2_JUGADOR_H
#define MARIO2_JUGADOR_H

#include "Entidad.h"
#include "Constantes.h"

class Jugador : public Entidad {
private:
    int coins;
    bool aire;

    // Fila a la que Mario regresa despues del salto.
    int filaSuelo;

public:
    Jugador(std::string nombre, int alto,
            int ancho, MUNDO matriz);

    ~Jugador() override;

    // right, left, top, up-right, up-left
    void moverse(std::string direccion) override;

    // Segundo fotograma del salto.
    void aterrizar();

    // Permite identificar comandos de salto.
    static bool esSalto(const std::string& direccion);

    void sumarMoneda();

    // Getters y setters.
    int get_coins() const;
    void set_coins(int coins);

    bool is_aire() const;
    void set_aire(bool aire);

    int get_fila_suelo() const;
};

#endif // MARIO2_JUGADOR_H
