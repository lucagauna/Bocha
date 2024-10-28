#include "menu.h"
#include "equipos.h"
#include "jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

void Menu::mostrarMenu() {
    Menu submenues;
    int opcion;
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       BOCHA0.8V   "  << endl;
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
    int opcion;
    Equipo reg;
    archivoEquipo listado("Equipos.dat");
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       EQUIPOS   "  << endl;
        cout << "======================" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. QUITAR" <<endl;
        cout << "3. LISTAR" <<endl;
        cout << "4. BUSCAR" <<endl;
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
            break;
        case 2:
            system("cls");
            break;
        case 0:
            break;
        }
    }
}

void Menu::menuJugadores(){
    int opcion;
    Jugador reg;
    archivoJugador listado("Jugadores.dat");
    while(opcion!=0){
    system("cls");
        cout << "======================" << endl;
        cout << "       JUGADORES   "  << endl;
        cout << "======================" << endl;
        cout << "1. AGREGAR" << endl;
        cout << "2. QUITAR" <<endl;
        cout << "3. BUSCAR" <<endl;
        cout << "0. Volver" << endl;
        cout << "======================" << endl;
        cout << "OPCION: ";
        cin >> opcion;
        cin.ignore();
        switch(opcion){
        case 1:
            system("cls");

            break;
        case 2:
            system("cls");
            break;
        case 0:
            break;
        }
    }
}
