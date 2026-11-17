#ifndef MARIO2_CONSTANTES_H
#define MARIO2_CONSTANTES_H

#include <vector>
using MUNDO = std::vector<std::vector<int>>;

// -----------------------------------------------------------
// Medidas del mundo y de la ventana que se ve en consola
// -----------------------------------------------------------
const int FILS_MUNDO = 50;
const int COLS_MUNDO = 240;
const int FILS_VENTANA = 50;
const int COLS_VENTANA = 90;


// -----------------------------------------------------------
// Medidas de Mario
// -----------------------------------------------------------

// Pasos de Mario
const int PASO_HORIZ = 12;   // right / left
const int PASO_VERT = 16;    // up

// Distancia de Mario al borde de la ventana antes de mover la camara
const int DIST_CAMARA_DER = 42;
const int DIST_CAMARA_IZQ = 32;

// Fila donde empieza el piso de ladrillo
const int FILA_PISO = 43;

// Valor de celda que no se pinta (sirve para los sprites)
const int TRANSPARENTE = -1;


// -----------------------------------------------------------
// Colores
// -----------------------------------------------------------

// los mismos numeros de colorANSI
const int C_FONDO = 0;
const int C_ROJO = 1;
const int C_VERDE = 2;
const int C_AMARILLO = 3;
const int C_NEGRO = 4;
const int C_BLANCO = 5;
const int C_AZUL = 6;
const int C_AMARILLO_CLARO = 7;
const int C_MARRON = 8;
const int C_RESET = 9;

// Si es true, al caer al hueco Mario aparece dentro del hueco antes del game over
const bool TENER_QUE_CAERSE = true;

#endif //MARIO2_CONSTANTES_H