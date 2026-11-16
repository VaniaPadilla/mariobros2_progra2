#ifndef MARIO2_SPRITESDATA_H
#define MARIO2_SPRITESDATA_H

#include "Sprite.h"
#include "Constantes.h"

MUNDO matrizMario();      // 16 x 12
MUNDO matrizGoomba();     // 16 x 16
MUNDO matrizSigno();      // 9 x 9
MUNDO matrizLadrillo();   // 9 x 9 (bloque de madera)
MUNDO matrizArbusto();    // 7 x 8
MUNDO matrizTuberia();    // medir en la Figura 1


// -----------------------------------------------------------
// Dimensiones y declaración de sprites
// -----------------------------------------------------------

// Dimensiones del sprite de la moneda
const int ALTO_MONEDA = 7;
const int ANCHO_MONEDA = 7;
extern const MUNDO monedaS;

// Dimensiones del sprite del arbusto
const int ALTO_ARBUSTO = 7;
const int ANCHO_ARBUSTO = 8;
extern const MUNDO arbustoS;

// Dimensiones del sprite del signo
const int ALTO_SIGNO = 8;
const int ANCHO_SIGNO = 9;
extern const MUNDO signoS;

// Dimensiones del sprite del ladrillo
const int ALTO_LADRILLO = 8;
const int ANCHO_LADRILLO = 9;
extern const MUNDO ladrilloS;

// Dimensiones del sprite de mario
const int ALTO_MARIO = 16;
const int ANCHO_MARIO = 12;
extern const MUNDO marioS;

// Dimensiones del sprite del goomba
const int ALTO_GOOMBA = 16;
const int ANCHO_GOOMBA = 16;
extern const MUNDO goombaS;



#endif //MARIO2_SPRITESDATA_H