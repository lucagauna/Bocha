#include "partido.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Partido::Partido() {
    srand(time(0));

    cout << "Ingrese el nombre del primer equipo: ";
    getline(cin, equipo1);
    cout << "Ingrese el nombre del segundo equipo: ";
    getline(cin, equipo2);

    cout << "Fecha: ";
    cin >> fecha;
    cin.ignore();

    goles = new int[2];
    goles[0] = rand() % 5;
    goles[1] = rand() % 5;

    cout << "Goles: " << equipo1 << " [" << goles[0] << "] - "
         << equipo2 << " [" << goles[1] << "]" << endl;
}

string Partido::getEquipo1() { return equipo1; }
string Partido::getEquipo2() { return equipo2; }
int Partido::getGoles(int i) {
    if (i >= 0 && i < 2) {
        return goles[i];
    }
    return -1;
}
int Partido::getFecha() const { return fecha; }

void Partido::setEquipo1(string& valor) { equipo1 = valor; }
void Partido::setEquipo2(string& valor) { equipo2 = valor; }
void Partido::setGoles(int valor, int i) {
    if (i >= 0 && i < 2) {
        goles[i] = valor;
    }
}
void Partido::setFecha(int valor) { fecha = valor; }

void Partido::mostrarPartido() const {
    cout << "Fecha: " << fecha << endl;
    cout << "Equipo 1: " << equipo1 << " | Goles: " << goles[0] << endl;
    cout << "Equipo 2: " << equipo2 << " | Goles: " << goles[1] << endl;

    if (goles[0] > goles[1]) {
        cout << "Ganador: " << equipo1 << endl;
    } else if (goles[0] < goles[1]) {
        cout << "Ganador: " << equipo2 << endl;
    } else {
        cout << "Resultado: Empate" << endl;
    }
}
