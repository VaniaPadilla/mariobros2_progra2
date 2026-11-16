//
// Created by User01 on 6/11/2026.
//

#ifndef MARIO2_JUEGO_H
#define MARIO2_JUEGO_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "Mapa.h"
#include "Guardado.h"
#include "NpcEnemigo.h"
#include "SpritesData.h"

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

    Juego(const Juego&);
    Juego& operator=(const Juego&);

    void iniciar();    // init
    void ejecutar();   // bucle principal: leer linea, separar comandos, procesar
    void guardar();    // save
    void cargar();     // load
};

#endif //MARIO2_JUEGO_H