#include "SpritesData.h"

MUNDO matrizMario() {
    return MUNDO(16, std::vector<int>(12, TRANSPARENTE));
}

MUNDO matrizGoomba() {
    return MUNDO(16, std::vector<int>(16, TRANSPARENTE));
}

MUNDO matrizSigno() {
    return MUNDO(9, std::vector<int>(9, C_AMARILLO));
}

MUNDO matrizLadrillo() {
    return MUNDO(9, std::vector<int>(9, C_ROJO));
}

MUNDO matrizArbusto() {
    return MUNDO(7, std::vector<int>(8, C_VERDE));
}

MUNDO matrizTuberia() {
    return MUNDO(1, std::vector<int>(1, C_VERDE));
}