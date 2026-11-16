
#include "Juego.h"




//?
int Jugador::get_coins() const {
    return coins;
}

// Getters & Setters

Mapa * Juego::get_mapa() const {
    return mapa;}
void Juego::set_mapa(Mapa *mapa) {
    this->mapa = mapa;}

std::vector<Entidad *> Juego::get_entidades() const {
    return entidades;}
void Juego::set_entidades(std::vector<Entidad *> entidades) {
    this->entidades = entidades;}

bool Juego::is_iniciado() const {
    return iniciado;}
void Juego::set_iniciado(bool iniciado) {
    this->iniciado = iniciado;}

bool Juego::is_terminado() const {
    return terminado;}
void Juego::set_terminado(bool terminado) {
    this->terminado = terminado;}
