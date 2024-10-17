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
<<<<<<< Updated upstream
    club.cargar();
    //reg.agregarRegistro(club);
    //reg.eliminarRegistro("River Plate");
    reg.modificarRegistro(club); ///ARREGLAR!!!!!!!
=======
    //club = reg.listarRegistro(4);
    //club.mostrarEquipo();
    //club.cargar();
    //reg.agregarRegistro(club);
    //reg.eliminarRegistro("River Plate");
    //reg.modificarRegistro(club); ///ARREGLAR!!!!!!!
    //reg.buscarRegistro();
>>>>>>> Stashed changes
    reg.mostrarRegistro();
}
