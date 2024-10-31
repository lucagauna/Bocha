#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador {
private:
    string nombre;
    int idJugador;
    string equipo;
    int edad;
    string posicion;
    int numero;
    int goles;
    int asistencias;

public:
    // Constructor
    Jugador();

    void cargar(); // Este settea los valores default


    // Getters
    string getNombre();
    int getIdJugador();
    string getEquipo();
    string getPosicion();
    int getEdad();
    int getNumero();
    int getGoles();
    int getAsistencias();

    // Setters
    void setNombre(string _nombre);
    void setIdJugador(int ID);
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
    bool mostrarJugadores();
    bool ordenadosNombre(bool valor);
    bool ordenadosID(bool valor);
    bool ordenadosEquipo(bool valor);
    bool ordenadosEdad(bool valor);
    bool ordenadosDorsal(bool valor);
    bool ordenadosGoles(bool valor);
    bool ordenadosAsistencias(bool valor);
    Jugador buscarJugador(const char* nombreJugador);
    Jugador buscarID(int num);
    Jugador buscarEquipo(const char* equipo);
    Jugador buscarEdad(int age);
    Jugador buscarPosicion(const char* position);
    Jugador buscarDorsal(int dorsal);
    Jugador buscarGoles(int goals);
    Jugador buscarAsistencias(int asissts);
};

#endif // JUGADOR_H
