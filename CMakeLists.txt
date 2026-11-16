cmake_minimum_required(VERSION 4.3)
project(mario2)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/bases
        ${CMAKE_SOURCE_DIR}/entidades
        ${CMAKE_SOURCE_DIR}/no_clases
)

add_executable(mario2
        main.cpp
        bases/Sprite.cpp
        bases/Sprite.h
        bases/Elemento.cpp
        bases/Elemento.h
        bases/Entidad.cpp
        bases/Entidad.h
        entidades/Jugador.cpp
        entidades/Jugador.h
        entidades/NpcEnemigo.cpp
        entidades/NpcEnemigo.h
        Mapa.cpp
        Mapa.h
        Juego.cpp
        Juego.h
        Guardado.cpp
        Guardado.h
        no_clases/SpritesData.cpp
        no_clases/SpritesData.h
        no_clases/Constantes.h
        no_clases/colores.cpp
        no_clases/colores.h

)