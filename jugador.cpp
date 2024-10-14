#include "jugador.h"
#include <iostream>
using namespace std;

// Constructor
Jugador::Jugador(){
    cout<<"Ingrese el Nombre del Jugador: ";
    getline(cin,nombre);
    cout<<"Ingrese el equipo del Jugador: ";
    getline(cin,equipo);
    cout<<"Ingrese la edad del Jugador: ";
    cin>>edad;
    cin.ignore();
    cout<<"Ingrese la posicion del Jugador: ";
    getline(cin, posicion);
    cout<<"Ingrese la dorsal del jugador: ";
    cin>>numero;
    cout<<"Ingrese los goles anotados del jugador: ";
    cin>>goles;
     cout<<"Ingrese las asistencias realizadas del jugador: ";
    cin>>asistencias;


}
// Getters
string Jugador::getNombre() const {
    return nombre;
}

string Jugador::getEquipo() const {
    return equipo;
}

int Jugador::getEdad() const {
    return edad;
}

string Jugador::getPosicion() const {
    return posicion;
}

int Jugador::getGoles() const {
    return goles;
}

int Jugador::getAsistencias() const {
    return asistencias;
}

// Setters
void Jugador::setNombre(string _nombre) {
    nombre = _nombre;
}

void Jugador::setEquipo(const string& _equipo) {
    equipo = _equipo;
}

void Jugador::setEdad(int _edad) {
    if (_edad >= 0) {
        edad = _edad;
    } else {
        cout << "Error: No puedes poner ningún jugador que aun no haya nacido!!" << endl;
    }
}

void Jugador::setPosicion(string _posicion) {
    posicion = _posicion;
}

void Jugador::setGoles(int _goles) {
    goles = _goles;
}

void Jugador::setAsistencias(int _asistencias) {
    asistencias = _asistencias;
}

void Jugador::setNumero(int _numero) {
    numero = _numero;
}


void Jugador::mostrarJugador() const {
    cout << "Nombre: " << nombre << endl;
    cout << "Equipo: " << equipo << endl;
    cout << "Edad: " << edad << endl;
    cout << "Posicion: " << posicion << endl;
    cout << "Dorsal: " << numero << endl;
    cout << "Goles: " << goles << endl;
    cout << "Asistencias: " << asistencias << endl;
}

