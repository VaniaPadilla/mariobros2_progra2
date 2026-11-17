#include "Guardado.h"
#include "Juego.h"

#include <fstream>
#include <vector>

// --------------------------------------------------
// GUARDAR PARTIDA
// --------------------------------------------------

bool Guardado::guardar(const Juego& juego, const std::string& archivo) {

    std::ofstream salida(archivo);

    if (!salida) return false;

    // Identificador del formato de guardado.
    salida << "MARIO_POO_1\n";

    // Guardar posicion y monedas de Mario.
    salida << juego.jugador->get_pos_x() << ' '
           << juego.jugador->get_pos_y() << ' '
           << juego.jugador->get_coins() << '\n';

    // Guardar unicamente los Goombas supervivientes.
    salida << juego.entidades.size() - 1 << '\n';

    for (int i = 1; i < (int)juego.entidades.size(); i++) {

        salida << juego.entidades[i]->get_pos_x() << ' '
               << juego.entidades[i]->get_pos_y() << '\n';
    }

    // Guardar el escenario, incluidos los bloques modificados.
    MUNDO mundo = juego.mapa->get_mundo();

    std::vector<std::vector<char>> cod =
        juego.mapa->get_mundo_cod();

    salida << FILS_MUNDO << ' ' << COLS_MUNDO << '\n';

    for (int i = 0; i < FILS_MUNDO; i++) {
        for (int j = 0; j < COLS_MUNDO; j++) {
            salida << mundo[i][j] << ' ';
        }
        salida << '\n';
    }

    // Guardar tambien las colisiones del mundo.
    for (int i = 0; i < FILS_MUNDO; i++) {
        for (int j = 0; j < COLS_MUNDO; j++) {
            salida << cod[i][j] << ' ';
        }
        salida << '\n';
    }

    salida.close();

    return salida.good();
}


// --------------------------------------------------
// CARGAR PARTIDA
// --------------------------------------------------

bool Guardado::cargar(Juego& juego, const std::string& archivo) {

    std::ifstream entrada(archivo);

    if (!entrada) return false;

    // Comprobar que el archivo corresponde al juego.
    std::string version;

    if (!(entrada >> version) || version != "MARIO_POO_1") {
        return false;
    }

    int marioX, marioY, monedas;

    if (!(entrada >> marioX >> marioY >> monedas)) {
        return false;
    }

    // Evitar cargar posiciones imposibles.
    if (marioX < 0 || marioX + ALTO_MARIO > FILS_MUNDO ||
        marioY < 0 || marioY + ANCHO_MARIO > COLS_MUNDO ||
        monedas < 0) {
        return false;
    }

    // Recuperar los Goombas existentes al guardar.
    int cantidad;

    if (!(entrada >> cantidad) || cantidad < 0 || cantidad > 67) { //valor elegido de forma al azar
        return false;
    }

    std::vector<int> enemigosX(cantidad);
    std::vector<int> enemigosY(cantidad);

    for (int i = 0; i < cantidad; i++) {

        if (!(entrada >> enemigosX[i] >> enemigosY[i])) {
            return false;
        }

        if (enemigosX[i] < 0 ||
            enemigosX[i] + ALTO_GOOMBA > FILS_MUNDO ||
            enemigosY[i] < 0 ||
            enemigosY[i] + ANCHO_GOOMBA > COLS_MUNDO) {
            return false;
        }
    }

    int filas, columnas;

    if (!(entrada >> filas >> columnas) ||
        filas != FILS_MUNDO || columnas != COLS_MUNDO) {
        return false;
    }

    // Recuperar el escenario sin modificar aun la partida.
    MUNDO mundo(FILS_MUNDO, std::vector<int>(COLS_MUNDO));

    std::vector<std::vector<char>> cod(
        FILS_MUNDO, std::vector<char>(COLS_MUNDO)
    );

    for (int i = 0; i < FILS_MUNDO; i++) {
        for (int j = 0; j < COLS_MUNDO; j++) {

            if (!(entrada >> mundo[i][j])) {
                return false;
            }
        }
    }

    for (int i = 0; i < FILS_MUNDO; i++) {
        for (int j = 0; j < COLS_MUNDO; j++) {

            if (!(entrada >> cod[i][j])) {
                return false;
            }

            if (cod[i][j] != '0' && cod[i][j] != '1' &&
                cod[i][j] != '*' && cod[i][j] != '#' &&
                cod[i][j] != 'a' && cod[i][j] != 'b') {
                return false;
            }
        }
    }

    // --------------------------------------------------
    // APLICAR LOS DATOS RECUPERADOS
    // --------------------------------------------------

    // Eliminar los Goombas de la partida actual.
    for (int i = (int)juego.entidades.size() - 1; i >= 1; i--) {
        juego.eliminarGoomba(i);
    }

    // Recrear los Goombas guardados.
    for (int i = 0; i < cantidad; i++) {

        NpcEnemigo* goomba = new NpcEnemigo(
            "Goomba",
            ALTO_GOOMBA,
            ANCHO_GOOMBA,
            goombaS,
            enemigosX[i],
            enemigosY[i]
        );

        juego.entidades.push_back(goomba);
        (*juego.mapa) += goomba;
    }

    // Restaurar escenario y colisiones.
    juego.mapa->set_mundo(mundo);
    juego.mapa->set_mundo_cod(cod);

    // Restaurar a Mario.
    juego.jugador->set_pos_x(marioX);
    juego.jugador->set_pos_y(marioY);
    juego.jugador->set_coins(monedas);
    juego.jugador->set_aire(false);
    juego.jugador->set_vida(true);

    juego.terminado = false;

    // Ajustar la camara sin modificar su algoritmo.
    for (int i = 0; i < COLS_MUNDO / PASO_HORIZ + 1; i++) {
        juego.mapa->moverEscena();
    }

    return true;
}