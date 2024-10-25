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
    void cargar(); // Este settea los valores default


    // Getters
    string getNombre() const;
    string getEquipo() const;
    string getPosicion() const;
    int getEdad() const;
    int getNumero() const;
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

class archivoJugador {
private:
    char nombreArchivo[50];
public:
    archivoJugador(const char* nombreArchivo);
    bool agregarJugador(Jugador jugador);
    bool eliminarJugador(const char* nombreJugador);
    bool modificarJugador(Jugador jugador);
    Jugador listarJugador(const char* nombreJugador);
    bool mostrarJugadores();
    Jugador listarJugador(int pos);
};

#endif // JUGADOR_H
