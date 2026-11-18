
#include "Juego.h"
#include <chrono>
#include <thread>

//--------------------------------------------
// Constructor y destructor
//--------------------------------------------

Juego::Juego() : mapa(nullptr), jugador(nullptr), iniciado(false), terminado(false) {

    // Crear jugador con memoria dinamica
    jugador = new Jugador("Mario", ALTO_MARIO, ANCHO_MARIO, marioS );
    entidades.push_back(jugador);

    // Crear mapa con memoria dinamica
    mapa = new Mapa(FILS_MUNDO, COLS_MUNDO, FILS_VENTANA, COLS_VENTANA, *jugador);
    
    // Registrar a Mario dentro del mapa.
    (*mapa) += jugador;     // Utilizamos la sobrecarga de operadores.

    // Crear los elementos en el mapa: Goombas, arbustos, signos y ladrillos.
    crearElementos();
}

Juego::~Juego() {
    // Liberar la memoria dinamica del mapa.
    delete mapa;

    // Liberar a Mario y los dos Goombas.
    // Todos fueron creados con new.
    int cantidad = entidades.size();

    for (int i = 0; i < cantidad; i++) {
        delete entidades[i];
    }

    entidades.clear();
}


//--------------------------------------------
// Métodos escenciales del juego
//--------------------------------------------

// Método que crea los elementos del mapa: Goombas, arbustos, signos y ladrillos.

void Juego::crearElementos() {

    // Crear los dos Goombas con memoria dinamica
    NpcEnemigo* goomba1 = new NpcEnemigo("Goomba", ALTO_GOOMBA, ANCHO_GOOMBA, goombaS, 27, 104);
    NpcEnemigo* goomba2 = new NpcEnemigo("Goomba", ALTO_GOOMBA, ANCHO_GOOMBA, goombaS, 27, 219);
    entidades.push_back(goomba1);
    entidades.push_back(goomba2);

    // El mapa necesita conocerlos para dibujarlos.
    (*mapa) += goomba1;
    (*mapa) += goomba2;     // Se usa la sobrecarga de operadores para Entidades.

    // Se usa la sobrecarga de operadores para Elementos.
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 21, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 29, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 37, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 98, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 189, false, '0');
    (*mapa) += Elemento("Arbusto", ALTO_ARBUSTO, ANCHO_ARBUSTO, arbustoS, 36, 217, false, '0');
    
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 29, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 82, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 100, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 166, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 204, false, '*');
    (*mapa) += Elemento("Signo", ALTO_SIGNO, ANCHO_SIGNO, signoS, 7, 222, false, '*');

    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 73, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 91, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 109, false, '0');

    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 195, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 213, false, '0');
    (*mapa) += Elemento("Ladrillo", ALTO_LADRILLO, ANCHO_LADRILLO, ladrilloS, 7, 231, false, '0');

    (*mapa) += Elemento("Tuberia", ALTO_TUBERIA, ANCHO_TUBERIA, tuberiaS, FILA_TUBERIA, COL_TUBERIA, false, '0');
}


// Método que inicia el juego, espera el comando "init" o "exit".

void Juego::iniciar() {

    std::string clave;

    do {
        std::cout << "(°<°)o/ ";

        // Si falla la lectura, terminar el programa.
        if (!(std::cin >> clave)) { //Es una medida de seguridad
            terminado = true;
            return;
        }

        //En caso quiero recargar una partida
        if (clave != "init" && clave != "exit") {

            if (clave == "load") {
                mensajeTurno.clear();
                cargar();
                std::cout << mensajeTurno;
                mensajeTurno.clear();
            }
            else {
                std::cout << "invalid operation\n";
            }
        }

    } while (clave != "init" && clave != "exit");

    if (clave == "init") {
        iniciado = true;
        ejecutar();
    }
    else {
        terminado = true;
    }
}


// Método que ejecuta el bucle principal del juego, hasta que Mario muere o se sale del programa.

void Juego::ejecutar() {

    std::string eleccion;
    // Mostrar el escenario al comenzar el juego.
    mapa->dibujarEscena();
    // Evitar que se borre por el codigo ANSI
    std::cout << "Welcome to the world of super mario bros xyz\n";
    do {
        std::cout << "Comando: ";

        if (!(std::cin >> eleccion)) { //Misma lógica que el anterior
            terminado = true;
            break;
        }

        // Exit termina inmediatamente, el goomba ni llega a moverse
        if (eleccion == "exit") {
            terminado = true;
            break;
        }

        // Preparar los avisos correspondientes a este comando.
        mensajeTurno.clear();

        // Verificaciones en preparación a un posible salto especial.

        bool saltoTuberia = CercaTUBERIA(eleccion); //Ver si activa el supersalto
        bool saltoHueco = CercaHUECO(eleccion); //Ver si activa el supersalto


        // Procesar el comando de Mario.
        // En caso ser válido, se actualiza la posición de Mario y del mapa.
        bool valido = procesarComando(eleccion);

        if (!valido) {
            
            if (eleccion == "right" || eleccion == "left" ||
            eleccion == "top" || eleccion == "up" ||
            eleccion == "up-right" || eleccion == "up-left") {
            mensajeTurno += "Esta seccion es inaccesible\n"; }
            
            else {
            mensajeTurno += "invalid operation\n";
            }
        }

        // Ambos Goombas se mueven una vez por comando,
        // incluso cuando la instruccion es invalida. Decisión estilistica
        if (eleccion != "save" && eleccion != "load") {
            moverEnemigos();}
            //Excepto si recarga partida, ya que sería incoherente

        // Ambos supersaltos llegan directamente a una zona segura.
        if (valido && (saltoTuberia || saltoHueco)) {
            mapa->moverEscena();
            mapa->dibujarEscena();
        }

        else  {
            if (valido && (eleccion == "right" || eleccion == "left")) {
                revisarApoyoTuberia();}
        
            if (valido && Jugador::esSalto(eleccion)) {
                // En caso que salto, ejecutar animación como en el proyecto 1
                animarSalto();}
            else {
                // Los movimientos horizontales se dibujan sin animacion intermedia.
                mapa->moverEscena();
                mapa->dibujarEscena();
                }
            }
        // Comprobar colisiones ordinarias con los Goombas.
        if (!terminado) {
            revisarChoqueGoombas(false, 0);}
        if (!terminado && !jugador->is_aire() && centroSobreHueco())
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(350));
            jugador->muerte_dano_caida(); // Mario se muere dentro del hueco
            mapa->moverEscena();
            mapa->dibujarEscena();
            std::this_thread::sleep_for(std::chrono::milliseconds(600));
            jugador->set_vida(false);
            terminado = true;
            std::cout << "Game Over: Mario cayo al vacio\n";
        }

        // Mostrar los mensajes cuando termina el ultimo redibujado.
        if (!mensajeTurno.empty()) {
            std::cout << mensajeTurno;
        }

    } while (!terminado);

    if (jugador->is_vida()) {
    std::cout << "Se salio del juego\n";}
}


// Método que procesa un comando de Mario, devuelve true si es valido y false si no lo es.
// De ser válido se llama al método moverse de Mario, que actualiza su posición y la del mapa.

bool Juego::procesarComando(const std::string &comando) {
    
    // Verificación de saltos especiales

    // Prioridad al salto del hueco para no rechazarlo en Supervisor.
    if (CercaHUECO(comando)) {
        saltarHueco(comando);
        return true; }

    if (CercaTUBERIA(comando)) {
        reposicionar(comando);
        return true; }

    if(!Supervisor(comando)){
        return false; }


    // PosY representa la columna horizontal, PosX representa la fila vertical.
    const int columna = jugador->get_pos_y();
    
    // Validación de comandos de movimiento para que no se salgan del mapa.
    if (comando == "right" || comando == "up-right") {

        if (columna + PASO_HORIZ + jugador->get_ancho() > COLS_MUNDO) {
            return false;
        }
        jugador->moverse(comando);
        return true;
    }

    if (comando == "left" || comando == "up-left") {

        if (columna - PASO_HORIZ < 0) {
            return false;
        }
        jugador->moverse(comando);
        return true;
    }

    //Por como funciona, ahora se ahorra código!
    if (comando == "top" || comando == "up") {
        jugador->moverse(comando);
        return true;
    }

    // Comandos para guardar y cargar el juego.

    if (comando == "save") {
        guardar();
        return true;
    }

    if (comando == "load") {
        cargar();
        return true;
    }

    return false;
}


// Método que mueve a los enemigos, si es que estan vivos.

void Juego::moverEnemigos() {

    // entidades[0] es Mario.
    // Los demas elementos son enemigos creados con new.
    // Cada enemigo vivo se mueve una sola vez.

    for (int i = 1; i < (int)entidades.size(); i++) {

        if (entidades[i] != nullptr &&
            entidades[i]->is_vida()) {
            // Siempre camina hacia la izquierda.
            entidades[i]->moverse(""); 
            // Los Goombas se desplazan automaticamente hacia la izquierda.

            int columna = entidades[i]->get_pos_y();
            int ancho = entidades[i]->get_ancho();

            // Apoyo determinado por el centro del Goomba.
            int centro = columna + ancho / 2;

            bool fueraDelMapa =
                columna < 0 || columna + ancho > COLS_MUNDO;

            bool sobreHueco =
                centro >= INICIO_HUECO && centro < FIN_HUECO;

            if (fueraDelMapa || sobreHueco) {
                eliminarGoomba(i);
                mensajeTurno += "Un Goomba ha caido o salido del mapa\n";
                // El vector ahora tiene un elemento menos.
                i--; // Retroceder el indice tras eliminar un elemento del vector.
            }
        }
    }
}


// Método que dibuja la animación del salto de Mario, con dos fotogramas.

void Juego::animarSalto() {

    // PRIMER FOTOGRAMA:
    // Mario ya esta arriba porque antes ejecutamos
    // jugador->moverse("top") o un salto diagonal.
    mapa->moverEscena(); 
    mapa->dibujarEscena();

    // Guardar la fila aerea antes de aterrizar.
    int filaAerea = jugador->get_pos_x();

    int columnaBloque = -1;
    int monedas = 0;

    char tipo = mapa->golpearBloque(
        filaAerea,
        jugador->get_pos_y(),
        jugador->get_ancho(),
        columnaBloque,
        monedas
    ); // Detectar si la parte superior de Mario golpea un bloque.

    // Pausa para visualizar a Mario en el aire.

    std::this_thread::sleep_for(std::chrono::milliseconds(350));

    //Caja agotada o ladrillo
    if (tipo != '0') {
        mapa->dibujarEscena();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    // SEGUNDO FOTOGRAMA:

    jugador->aterrizar();     // Mario vuelve a su fila inicial. 
    mapa->terminarGolpe(tipo, columnaBloque); //Desaparecer ladrillo
    //Conservo columna nueva, en caso de salto diagonal

    if (tipo == '*') 
    {
        for (int i = 0; i < monedas; i++){
            jugador->sumarMoneda();}

        mensajeTurno += "Recibiste " + std::to_string(monedas) + " monedas\n";

        if (monedas == 3){
            mensajeTurno += "Tuviste buena suerte\n";}
    } //Resultado del sorteo de monedas

    mapa->moverEscena();
    mapa->dibujarEscena();
    //Muere o matas goomba
    revisarChoqueGoombas(true, filaAerea);
}



//--------------------------------------------
// Métodos auxiliares para la tuberia y el hueco
//--------------------------------------------

// Método que detecta si Mario esta en cercanía con la tuberia y puede subir a ella con un salto diagonal.
// Retorna si es posible o no

bool Juego::CercaTUBERIA(const std::string& eleccion) {

    // Solo aceptar saltos diagonales desde el suelo.
    if (jugador->is_aire() || jugador->get_pos_x() != FILA_PISO - jugador->get_alto()) {
        return false;}

    int columna = jugador->get_pos_y();

    int bordeMario = columna + jugador->get_ancho();
    int bordeTuberia = COL_TUBERIA + ANCHO_TUBERIA;

    // Subir desde el lado izquierdo.
    if (eleccion == "up-right") {
        if (bordeMario <= COL_TUBERIA && COL_TUBERIA - bordeMario <= PASO_HORIZ) {
            return true;}
    }

    // Subir desde el lado derecho.
    else if (eleccion == "up-left") {
        if (columna >= bordeTuberia && columna - bordeTuberia <= PASO_HORIZ) {
            return true;}
    }

    return false;
}


// Reposiciona a Mario sobre la tuberia, si es que cercaTUBERIA() retorno true.

void Juego::reposicionar(const std::string& eleccion) {

    if (!CercaTUBERIA(eleccion)) {
        return;
    }

    // La parte inferior de Mario queda apoyada
    // exactamente en la parte superior de la tuberia.
    jugador->set_pos_x(FILA_TUBERIA - jugador->get_alto());

    if (eleccion == "up-right") {
        jugador->set_pos_y(COL_TUBERIA);
    }

    else if (eleccion == "up-left") {
        jugador->set_pos_y(COL_TUBERIA + ANCHO_TUBERIA - jugador->get_ancho());
    }

    // Actualizar la altura de aterrizaje de Mario.
    jugador->set_aire(false);
}


// Método que detecta si Mario esta en cercanía con el hueco y puede saltarlo con un salto diagonal.
// Retorna si es posible o no

bool Juego::CercaHUECO(const std::string& eleccion) {

    if (jugador->is_aire()) return false;

    int fila = jugador->get_pos_x();
    int columna = jugador->get_pos_y();
    int bordeTuberia = COL_TUBERIA + ANCHO_TUBERIA;

    // Desde el extremo derecho de la tuberia hacia la otra orilla.
    if (eleccion == "up-right" &&
        fila == FILA_TUBERIA - jugador->get_alto() &&
        columna >= bordeTuberia - jugador->get_ancho() &&
        columna < bordeTuberia) {
        return true; //forma de irse seguro
    } //Decison coherente relacionada a desarrollo de videojuegos

    // Desde la orilla derecha hacia el suelo al costado de la tuberia.
    if (eleccion == "up-left" &&
        fila == FILA_PISO - jugador->get_alto() &&
        columna >= FIN_HUECO &&
        columna <= FIN_HUECO + PASO_HORIZ) {
        return true; //forma de regresar seguro
    } //Manera de probar el regreso unica forma posible, para poder ayudar a volver

    return false;
}

// Método que reposiciona a Mario sobre el piso

void Juego::saltarHueco(const std::string& eleccion) {

    if (eleccion == "up-right") {
        // El piso reaparece en FIN_HUECO.
        jugador->set_pos_y(FIN_HUECO);
    }
    else if (eleccion == "up-left") {
        // Franja de tierra inmediatamente a la derecha de la tuberia.
        jugador->set_pos_y(COL_TUBERIA + ANCHO_TUBERIA);
    }

    jugador->set_pos_x(FILA_PISO - jugador->get_alto());
    jugador->set_aire(false);
}



bool Juego::chocaTuberia(int fila, int columna) const {

    // Comprobar superposicion de dos rectangulos
    return fila < FILA_TUBERIA + ALTO_TUBERIA &&
           fila + jugador->get_alto() > FILA_TUBERIA &&
           columna < COL_TUBERIA + ANCHO_TUBERIA &&
           columna + jugador->get_ancho() > COL_TUBERIA;
}

void Juego::revisarApoyoTuberia() {

    int filaSuperior =
        FILA_TUBERIA - jugador->get_alto();

    // Solo comprobar cuando Mario esta encima.
    if (jugador->get_pos_x() != filaSuperior) {
        return;
    }

    int bordeIzquierdo = jugador->get_pos_y();
    int bordeDerecho = bordeIzquierdo + jugador->get_ancho();

    int bordeDerechoTuberia =
        COL_TUBERIA + ANCHO_TUBERIA;

    // Si Mario abandona la superficie, cae al suelo.
    if (bordeDerecho <= COL_TUBERIA ||
        bordeIzquierdo >= bordeDerechoTuberia) {

        jugador->set_pos_x(
            FILA_PISO - jugador->get_alto()
        );

        jugador->set_aire(false); //Con esto logramos que mario no vuele
    }
}

bool Juego::centroSobreHueco() const {
    int centro = jugador->get_pos_y() + jugador->get_ancho() / 2;
    return centro >= INICIO_HUECO && centro < FIN_HUECO;
}

bool Juego::Supervisor(const std::string &comando)
{
    // Impedir atravesar la tuberia con movimientos horizontales o diagonales.
    if (comando == "right" || comando == "up-right" || comando == "left" || comando == "up-left") {

        int filaActual = jugador->get_pos_x();
        int columnaNueva = jugador->get_pos_y();

        if (comando == "right" || comando == "up-right") {
            columnaNueva += PASO_HORIZ;
        }
        else {
            columnaNueva -= PASO_HORIZ;
        }
        // Comprobar el recorrido horizontal.
        if (chocaTuberia(filaActual, columnaNueva)) {
            return false;
        }

        // Comprobar tambien la posicion elevada.
        if (comando == "up-right" || comando == "up-left") 
        {
            if (filaActual - PASO_VERT < 0) {
                return false;
            }
            if (chocaTuberia(filaActual - PASO_VERT, columnaNueva)) {
                return false;
            }
        }
    }
        // Impedir saltos fuera del mapa o a traves de la tuberia.
    if (comando == "top" || comando == "up") {

        int filaNueva = jugador->get_pos_x() - PASO_VERT;

        if (filaNueva < 0 || chocaTuberia(filaNueva, jugador->get_pos_y())) {
            return false;
        }
    }
    // Si ninguna comprobacion rechazo el comando, el Supervisor permite continuar.
    return true;
}


void Juego::eliminarGoomba(int indice) {

    if (indice <= 0 || indice >= (int)entidades.size()) {
        return;
    }

    Entidad* enemigo = entidades[indice];

    (*mapa) -= enemigo; // Primero retirarlo del escenario.
    //operador sobrecargado
    entidades.erase(entidades.begin() + indice); // Retirarlo del vector que controla Juego.

    // Liberar la memoria dinamica.
    delete enemigo;
}


void Juego::revisarChoqueGoombas(bool aterrizando, int filaAerea) {

    if (!jugador->is_vida()) {
        return;
    }

    for (int i = 1; i < (int)entidades.size(); i++) {

        Entidad* goomba = entidades[i];

        if (goomba == nullptr || !goomba->is_vida()) {
            continue;
        }

        // Bordes horizontales de Mario.
        int marioIzq = jugador->get_pos_y();
        int marioDer = marioIzq + jugador->get_ancho();

        // Bordes horizontales del Goomba.
        int goombaIzq = goomba->get_pos_y();
        int goombaDer = goombaIzq + goomba->get_ancho();

        // Comprobar superposicion horizontal.
        bool choqueHorizontal =
            marioIzq < goombaDer && marioDer > goombaIzq;

        // Comprobar superposicion vertical.
        bool choqueVertical =
            jugador->get_pos_x() < goomba->get_pos_x() + goomba->get_alto() &&
            jugador->get_pos_x() + jugador->get_alto() > goomba->get_pos_x();

        if (!choqueHorizontal || !choqueVertical) {
            continue;
        }

        // Aplastamiento: Mario venia desde arriba durante el salto.
        if (aterrizando &&
            filaAerea + jugador->get_alto() <= goomba->get_pos_x()) {

            goomba->set_vida(false);

            eliminarGoomba(i);

            jugador->sumarMoneda();

            mapa->dibujarEscena();

            mensajeTurno += "Goomba aplastado! +1 moneda\n";

            i--;
        }
        else {

            // Contacto lateral o colision sin aplastamiento.
            jugador->set_vida(false);
            terminado = true;

            std::cout << "Game Over: Mario fue golpeado por un Goomba\n";
            return;
        }
    }
}


//--------------------------------------------
// Métodos para guardar y cargar el juego
//--------------------------------------------


void Juego::guardar() {

    if (Guardado::guardar(*this, "partida.txt")) {
        mensajeTurno += "Partida guardada\n";}
    else {
        mensajeTurno += "No se pudo guardar la partida\n";}
}

void Juego::cargar() {

    if (Guardado::cargar(*this, "partida.txt")) {
        mensajeTurno += "Partida cargada\n";}
    else {
        mensajeTurno += "No existe una partida valida para cargar\n";}
}

//--------------------------------------------
// Constructor y destructor
//--------------------------------------------

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
