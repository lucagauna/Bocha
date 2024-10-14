#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador {
private:
    string nombre;
    string equipo;
    int edad;
    string posicion;
    int numero;
    int goles;
    int asistencias;

public:
    // Constructor
    Jugador(); // Este settea los valores default


    // Getters
    string getNombre() const;
    string getEquipo() const;
    string getPosicion() const;
    int getEdad() const;
    int getGoles() const;
    int getAsistencias() const;

    // Setters
    void setNombre(string _nombre);
    void setEquipo(const string& _equipo);
    void setEdad(int _edad);
    void setPosicion(string _posicion);
    void setGoles(int _goles);
    void setAsistencias(int _asistencias);
    void setNumero(int _numero);


    void mostrarJugador() const;
};

#endif // JUGADOR_H
