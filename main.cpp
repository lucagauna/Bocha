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
    ArchivoEquipo reg("Equipos.dat");
    club.cargar();
    reg.agregarRegistro(club);
    //reg.eliminarRegistro("Boca Juniors");
    //reg.modificarRegistro(club);
    reg.mostrarRegistro();


    //Revisar Vector Dinamico...
    //Revisar si se puede simplificar declarando chars...
    return 0;
}
