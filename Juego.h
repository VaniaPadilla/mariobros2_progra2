
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
    Mapa* mapa{};                       // memoria dinamica
    Jugador* jugador{};                 // puntero al mismo Mario de entidades[0]
    std::vector<Entidad*> entidades;    // Mario y enemigos creados con new

    bool iniciado;                      // ya se escribio init
    bool terminado;                     // Mario perdio o se salio del programa

public:
    Juego();
    ~Juego();

    // Metodos

    void iniciar();     // init
    void ejecutar();    // bucle principal: leer comandos y procesarlos

    void guardar();     // save
    void cargar();      // load

    void crearElementos();   // piso, tuberia, arbustos, signos, ladrillos

    bool procesarComando(const std::string& comando);
    bool Supervisor(const std::string& comando); //Implementado para la tuberia
    // Tuberia: detectar proximidad y subir a ella.
    bool CercaTUBERIA(const std::string& eleccion); //Si Mario esta cerca, usar su movimiento especial
    void reposicionar(const std::string& eleccion); //Ejecuta el movimiento especial
    // Hueco: detectar proximidad y esquivarlo.
    bool CercaHUECO(const std::string& eleccion); //Si Mario esta cerca, usar su movimiento especial
    void saltarHueco(const std::string& eleccion); //Ejecuta el movimiento especial
    // Impedir atravesar la tuberia y permitir bajar de ella.
    bool chocaTuberia(int fila, int columna) const; //No atravesar
    void revisarApoyoTuberia();
    //muerte por caida parcial
    bool centroSobreHueco() const;
    // Movimiento y animaciones
    void moverEnemigos();    // mueve los dos Goombas una vez por turno
    void animarSalto();      // dibuja los dos fotogramas del salto
    void eliminarGoomba(int indice); // Retirar y liberar un Goomba.
    // Detectar contacto lateral o aplastamiento.
    void revisarChoqueGoombas(bool aterrizando, int filaAerea);

    // Evitar copias accidentales de los punteros.
    Juego(const Juego&);
    Juego& operator=(const Juego&);
    // Getters & Setters

    Mapa* get_mapa() const;
    void set_mapa(Mapa* mapa);

    std::vector<Entidad*> get_entidades() const;
    void set_entidades(std::vector<Entidad*> entidades);

    bool is_iniciado() const;
    void set_iniciado(bool iniciado);

    bool is_terminado() const;
    void set_terminado(bool terminado);
};

#endif // MARIO2_JUEGO_H