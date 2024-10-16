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
    archivoEquipo reg("Equipos.dat");
    club.cargar();
    //reg.agregarRegistro(club);
    //reg.eliminarRegistro("River Plate");
    reg.modificarRegistro(club); ///ARREGLAR!!!!!!!
    reg.mostrarRegistro();
}
