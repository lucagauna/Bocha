#include <iostream>
#include <cstring>
#include "funciones.h"
#include "jugador.h"
#include "equipos.h"


/// MODO DE BUSQUEDA ============
/// BUSCAR ARCHIVO JUGADORES ========
/// BUSCAR EQUIPO ======
/// STATS EQUIPOS ======
///

using namespace std;

int main() {
    mostrarMenu();
    Equipo club;
    Jugador jugador;
    archivoEquipo reg("Equipos.dat");
    archivoJugador lol("Jugadores.dat");

    //jugador.cargar();
    //lol.agregarJugador(jugador);
    //jugador = lol.listarJugador("Alan Velasco");
    //jugador.mostrarJugador();
    //lol.mostrarJugadores();

    //club = reg.listarRegistro(" ");
    //club.mostrarEquipo();
    //club.cargar();
    //reg.agregarRegistro(club);
    //reg.eliminarRegistro("River Plate");
    //reg.modificarRegistro(club); ///ARREGLAR!!!!!!!
    //reg.buscarRegistro();
    //reg.mostrarRegistro();


    //Revisar Vector Dinamico...
    //Revisar si se puede simplificar declarando chars...
    return 0;
}
