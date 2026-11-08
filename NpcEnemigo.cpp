//
// Created by User01 on 6/11/2026.
//

#include "NpcEnemigo.h"



    NpcEnemigo::NpcEnemigo(int x, int y) : Entidad("Goomba", 16, 16, 1) {  
        set_pos_x(x);
        set_pos_y(y);
    }

    NpcEnemigo::~NpcEnemigo() {}

    void NpcEnemigo::moverse(std::string direccion) {
    }
