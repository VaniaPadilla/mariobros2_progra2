cmake_minimum_required(VERSION 4.3)
project(mario2)

set(CMAKE_CXX_STANDARD 20)

add_executable(mario2 main.cpp
        Sprite.cpp
        Sprite.h
        Elemento.cpp
        Elemento.h
        Entidad.cpp
        Entidad.h
        Jugador.cpp
        Jugador.h
        NpcEnemigo.cpp
        NpcEnemigo.h
        Mapa.cpp
        Mapa.h
        Juego.cpp
        Juego.h)
