#include "menu.h"
#include "equipos.h"
#include "jugador.h"
#include "competencia.h"
#include <iostream>
#include <cstring>
using namespace std;

void Menu::mostrarMenu() {
    int opcion = -1;
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       BOCHA1.1V   "  << endl;
        cout << "======================" << endl;
        cout << "1. EQUIPOS" << endl;
        cout << "2. JUGADORES" <<endl;
        cout << "3. COMPETENCIAS" << endl;
        cout << "0. Salir" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            menuEquipos();
            break;
        case 2:
            menuJugadores();
            break;
        case 3:
            menuCompetencias();
            break;
        }
    }
}

void Menu::menuEquipos(){
    int opcion=-1;
    Equipo reg;
    archivoEquipo listado("Equipos.dat");
    char equipo[50]={0};
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       EQUIPOS   "  << endl;
        cout << "======================" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. QUITAR" <<endl;
        cout << "3. MODIFICAR" <<endl;
        cout << "4. LISTAR" <<endl;
        cout << "5. BUSCAR" <<endl;
        cout << "6. ORDENAR" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");
            reg.cargar();
            listado.agregarRegistro(reg);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese equipo a eliminar: ";
            cin.getline(equipo,50);
            listado.eliminarRegistro(equipo);
            system("pause");
            break;
        case 3:
            system("cls");
            reg.cargar();
            listado.modificarRegistro(reg);
            system("pause");
            break;
        case 4:
            system("cls");
            listado.mostrarRegistro();
            system("pause");
            break;
        case 5:
            system("cls");
            subMenuEquipos();
            break;
        case 6:
            system("cls");
            subMenuOrdenarEquipos();
            break;
        }
    }
}

void Menu::subMenuEquipos(){
    int opcion=-1;
    Equipo reg;
    archivoEquipo listado("Equipos.dat");
    char nombre[50]={0};
    int numero=0;
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       BUSCAR   "  << endl;
        cout << "======================" << endl;
        cout << "1. POR EQUIPO" << endl;
        cout << "2. POR JUGADOR" <<endl;
        cout << "3. POR PLANTEL" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");
            cout << "Ingrese el equipo buscado: ";
            cin.getline(nombre,50);
            reg = listado.buscarEquipo(nombre);
            reg.mostrarEquipo();
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el jugador buscado: ";
            cin.getline(nombre,50);
            reg = listado.buscarJugador(nombre);
            reg.mostrarEquipo();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Ingrese la cantidad de plantel buscado: ";
            cin >> numero;
            listado.buscarPlantel(numero);
            system("pause");
            break;
        }
    }
}

void Menu::subMenuOrdenarEquipos(){
    int opcion=-1;
    Equipo reg;
    archivoEquipo listado("Equipos.dat");
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       ORDENAR   "  << endl;
        cout << "======================" << endl;
        cout << "1. POR EQUIPO (A,Z)" << endl;
        cout << "2. POR EQUIPO (Z,A)" << endl;
        cout << "3. POR PLANTEL (Menor a Mayor)" <<endl;
        cout << "4. POR PLANTEL (Mayor a menor)" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");
            listado.ordenadosEquipo(0);
            system("pause");
            break;
        case 2:
            system("cls");
            listado.ordenadosEquipo(1);
            system("pause");
            break;
        case 3:
            system("cls");
            listado.ordenadosPlantel(0);
            system("pause");
            break;
        case 4:
            system("cls");
            listado.ordenadosPlantel(1);
            system("pause");
            break;
        }
    }
}

void Menu::menuJugadores(){
    int opcion=-1;
    char jugador[50];
    Jugador reg;
    archivoJugador listado("Jugadores.dat");
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       JUGADORES   "  << endl;
        cout << "======================" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. QUITAR" <<endl;
        cout << "3. MODIFICAR" <<endl;
        cout << "4. LISTAR" <<endl;
        cout << "5. BUSCAR" <<endl;
        cout << "6. ORDENAR" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");
            reg.cargar();
            listado.agregarJugador(reg);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese jugador a quitar: ";
            cin.getline(jugador,50);
            listado.eliminarJugador(jugador);
            system("pause");
            break;
        case 3:
            system("cls");
            reg.cargar();
            listado.modificarJugador(reg);
            system("pause");
            break;
        case 4:
            system("cls");
            listado.mostrarJugadores();
            system("pause");
            break;
        case 5:
            /// SUBMENU PARA FUNCIONES DE BUSCAR
            system("cls");
            subMenuJugadores();
            break;
        case 6:
            system("cls");
            subMenuOrdenarJugadores();
            break;
        }
    }
}

void Menu::subMenuJugadores(){
    int opcion=-1;
    Jugador reg;
    archivoJugador listado("Equipos.dat");
    char nombre[50]={0};
    int numero=0;
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       BUSCAR   "  << endl;
        cout << "======================" << endl;
        cout << "1. POR JUGADOR" << endl;
        cout << "2. POR ID" << endl;
        cout << "3. POR EQUIPO" <<endl;
        cout << "4. POR EDAD" <<endl;
        cout << "5. POR POSICION" << endl;
        cout << "6. POR DORSAL" <<endl;
        cout << "7. POR GOLES" <<endl;
        cout << "8. POR ASISTENCIAS" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");
            cout << "Ingrese el jugador a buscar: ";
            cin.getline(nombre,50);
            reg = listado.buscarJugador(nombre);
            reg.mostrarJugador();
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese el ID a buscar: ";
            cin >> numero;
            reg = listado.buscarID(numero);
            reg.mostrarJugador();
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Ingrese el equipo a buscar: ";
            cin.getline(nombre,50);
            listado.buscarEquipo(nombre);
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Ingrese la edad a buscar: ";
            cin >> numero;
            listado.buscarEdad(numero);
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Ingrese la posicion a buscar: ";
            cin.getline(nombre,50);
            listado.buscarPosicion(nombre);
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "Ingrese la dorsal a buscar: ";
            cin >> numero;
            listado.buscarDorsal(numero);
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "Ingrese los goles a buscar: ";
            cin >> numero;
            listado.buscarGoles(numero);
            system("pause");
            break;
        case 8:
            system("cls");
            cout << "Ingrese las asistencias a buscar: ";
            cin >> numero;
            listado.buscarAsistencias(numero);
            system("pause");
            break;
        }
    }
}

void Menu::subMenuOrdenarJugadores(){
    int opcion=-1;
    Equipo reg;
    archivoJugador listado("Jugadores.dat");
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       ORDENAR   "  << endl;
        cout << "======================" << endl;
        cout << "1. POR NOMBRE (A,Z)" << endl;
        cout << "2. POR NOMBRE (Z,A)" << endl;
        cout << "3. POR ID (Menor a Mayor)" << endl;
        cout << "4. POR ID (Mayor a Menor)" << endl;
        cout << "5. POR EQUIPO (A,Z)" <<endl;
        cout << "6. POR EQUIPO (Z,A)" <<endl;
        cout << "7. POR EDAD (Menor a Mayor)" << endl;
        cout << "8. POR EDAD (Mayor a Menor)" << endl;
        cout << "9. POR DORSAL (Menor a Mayor)" <<endl;
        cout << "10. POR DORSAL (Mayor a menor)" <<endl;
        cout << "11. POR GOLES (Menor a Mayor)" << endl;
        cout << "12. POR GOLES (Mayor a menor)" << endl;
        cout << "13. POR ASISTENCIAS (Menor a Mayor)" <<endl;
        cout << "14. POR ASISTENCIAS (Mayor a menor)" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");
            listado.ordenadosNombre(0);
            system("pause");
            break;
        case 2:
            system("cls");
            listado.ordenadosNombre(1);
            system("pause");
            break;
        case 3:
            system("cls");
            listado.ordenadosID(0);
            system("pause");
            break;
        case 4:
            system("cls");
            listado.ordenadosID(1);
            system("pause");
            break;
        case 5:
            system("cls");
            listado.ordenadosEquipo(0);
            system("pause");
            break;
        case 6:
            system("cls");
            listado.ordenadosEquipo(1);
            system("pause");
            break;
        case 7:
            system("cls");
            listado.ordenadosEdad(0);
            system("pause");
            break;
        case 8:
            system("cls");
            listado.ordenadosEdad(1);
            system("pause");
            break;
        case 9:
            system("cls");
            listado.ordenadosDorsal(0);
            system("pause");
            break;
        case 10:
            system("cls");
            listado.ordenadosDorsal(1);
            system("pause");
            break;
        case 11:
            system("cls");
            listado.ordenadosGoles(0);
            system("pause");
            break;
        case 12:
            system("cls");
            listado.ordenadosGoles(1);
            system("pause");
            break;
        case 13:
            system("cls");
            listado.ordenadosAsistencias(0);
            system("pause");
            break;
        case 14:
            system("cls");
            listado.ordenadosAsistencias(1);
            system("pause");
            break;
        }
    }
}

void Menu::menuCompetencias(){
    Competencia reg;
    archivoCompetencia listado("Competencias.dat");
    char nombre[50]={0};
    int opcion = -1;
    while(opcion!=0){
        system("cls");
        cout << "======================" << endl;
        cout << "       COMPETENCIAS   "  << endl;
        cout << "======================" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. ELIMINAR" <<endl;
        cout << "3. MODIFCAR" <<endl;
        cout << "4. LISTAR" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system ("cls");
            reg.cargar();
            listado.agregarCompetencia(reg);
            system("pause");
            break;
        case 2:
            system("cls");
            cout << "Ingrese nombre de la competencia: ";
            cin.getline(nombre,49);
            listado.eliminarCompetencia(nombre);
            system("pause");
            break;
        case 3:
            system("cls");
            reg.cargar();
            listado.modificarCompetencia(reg);
            system("pause");
            break;
        case 4:
            system ("cls");
            listado.listarCompetencia();
            system("pause");
            break;
        }
    }
}

