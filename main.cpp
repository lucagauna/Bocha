#include <iostream>
#include <cstring>
#include "competencia.h"
#include "menu.h"
#include "jugador.h"
#include "equipos.h"


/// MODO DE BUSQUEDA ============
/// BUSCAR ARCHIVO JUGADORES ========
/// BUSCAR EQUIPO ======
/// STATS EQUIPOS ======
///

using namespace std;

int main() {
   // Menu menu;
    //Equipo club;
    //Jugador jugador;
    //archivoEquipo reg("Equipos.dat");
    //archivoJugador lol("Jugadores.dat");

    //menu.mostrarMenu();

    archivoCompetencia archivo("Competencias.dat");
    Competencia nuevaCompetencia;
    archivo.agregarCompetencia(nuevaCompetencia);





    return 0;
}
