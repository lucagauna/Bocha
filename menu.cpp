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
        cout << "       BOCHA0.9V   "  << endl;
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
            /// SUBMENU PARA FUNCIONES DE BUSCAR
            system("cls");
            cout << "Ingrese el Equipo Buscado: ";
            cin.getline(equipo,50);
            reg = listado.listarRegistro(equipo);
            reg.mostrarEquipo();
            system("pause");
            break;
        }
    }
}

void Menu::menuJugadores(){
    int opcion;
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
            cout << "Ingrese el jugador a buscar: ";
            cin.getline(jugador,50);
            reg = listado.listarJugador(jugador);
            reg.mostrarJugador();
            system("pause");
            break;
        }
    }
}
