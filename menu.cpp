#include "menu.h"
#include "equipos.h"
#include "jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

void Menu::mostrarMenu() {
    Menu submenues;
    int opcion = -1;
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       BOCHA1.0V   "  << endl;
        cout << "======================" << endl;
        cout << "1. EQUIPOS" << endl;
        cout << "2. JUGADORES" <<endl;
        cout << "0. Salir" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        switch(opcion){
        case 1:
            submenues.menuEquipos();
            break;
        case 2:
            submenues.menuJugadores();
            break;
        }
    }
}

void Menu::menuEquipos(){
    int opcion=-1;
    Menu menu;
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
            menu.subMenuEquipos();
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

void Menu::menuJugadores(){
    int opcion=-1;
    Jugador reg;
    archivoJugador listado("Jugadores.dat");
    char jugador[50]={0};
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
        cout << "2. POR EQUIPO" <<endl;
        cout << "3. POR EDAD" <<endl;
        cout << "4. POR POSICION" << endl;
        cout << "5. POR DORSAL" <<endl;
        cout << "6. POR GOLES" <<endl;
        cout << "7. POR ASISTENCIAS" <<endl;
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
            cout << "Ingrese el equipo a buscar: ";
            cin.getline(nombre,50);
            listado.buscarEquipo(nombre);
            system("pause");
            break;
        case 3:
            system("cls");
            cout << "Ingrese la edad a buscar: ";
            cin >> numero;
            listado.buscarEdad(numero);
            system("pause");
            break;
        case 4:
            system("cls");
            cout << "Ingrese la posicion a buscar: ";
            cin.getline(nombre,50);
            listado.buscarPosicion(nombre);
            system("pause");
            break;
        case 5:
            system("cls");
            cout << "Ingrese la dorsal a buscar: ";
            cin >> numero;
            listado.buscarDorsal(numero);
            system("pause");
            break;
        case 6:
            system("cls");
            cout << "Ingrese los goles a buscar: ";
            cin >> numero;
            listado.buscarGoles(numero);
            system("pause");
            break;
        case 7:
            system("cls");
            cout << "Ingrese las asistencias a buscar: ";
            cin >> numero;
            listado.buscarAsistencias(numero);
            system("pause");
            break;
        }
    }
}
