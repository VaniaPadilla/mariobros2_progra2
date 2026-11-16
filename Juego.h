
#ifndef MARIO2_JUEGO_H
#define MARIO2_JUEGO_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Mapa.h"
#include "Guardado.h"
#include "entidades/NpcEnemigo.h"
#include "no_clases/SpritesData.h"

class Juego {
private:
    Mapa* mapa;                        // memoria dinamica
    std::vector<Entidad*> entidades;   // enemigos creados con new
    bool iniciado;                     // ya se escribio init
    bool terminado;                    // Mario toco al goomba o se salio del programa

    void crearElementos();                                       // piso, tuberia, arbustos, signos, ladrillos
    void procesarComando(const std::string& comando, int veces); // veces = n si se repite en la linea

public:
    Juego();
    ~Juego();

    // Métodos

    Juego(const Juego&);
    Juego& operator=(const Juego&);

    void iniciar();    // init
    void ejecutar();   // bucle principal: leer linea, separar comandos, procesar
    void guardar();    // save
    void cargar();     // load

    // Getters & Setters

    Mapa * get_mapa() const;

    void set_mapa(Mapa *mapa);

    std::vector<Entidad *> get_entidades() const;

    void set_entidades(std::vector<Entidad *> entidades);

    bool is_iniciado() const;

    void set_iniciado(bool iniciado);

    bool is_terminado() const;

    void set_terminado(bool terminado);
};

#endif //MARIO2_JUEGO_H