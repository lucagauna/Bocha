#ifndef JUGADOR_H
#define JUGADOR_H

#include <iostream>
using namespace std;

class Jugador {
private:
    char nombre[50];
    int idJugador;
    char equipo[50];
    int edad;
    char posicion[50];
    int numero;
    int goles;
    int asistencias;

public:
    Jugador();

    void cargar();

    char* getNombre();
    int getIdJugador();
    char* getEquipo();
    char* getPosicion();
    int getEdad();
    int getNumero();
    int getGoles();
    int getAsistencias();

    void setNombre(char* nombre);
    void setIdJugador(int ID);
    void setEquipo(char* equipo);
    void setEdad(int edad);
    void setPosicion(char* posicion);
    void setGoles(int goles);
    void setAsistencias(int asistencias);
    void setNumero(int numero);


    void mostrarJugador() const;
};

class archivoJugador {
private:
    char nombreArchivo[50];
public:
    archivoJugador(const char* nombreArchivo);
    bool agregarJugador(Jugador jugador);
    bool eliminarJugador(char* nombreJugador);
    bool modificarJugador(Jugador jugador);
    bool mostrarJugadores();
    bool ordenadosNombre(bool valor);
    bool ordenadosID(bool valor);
    bool ordenadosEquipo(bool valor);
    bool ordenadosEdad(bool valor);
    bool ordenadosDorsal(bool valor);
    bool ordenadosGoles(bool valor);
    bool ordenadosAsistencias(bool valor);
    Jugador buscarJugador(char* nombreJugador);
    Jugador buscarID(int num);
    Jugador buscarEquipo(char* equipo);
    Jugador buscarEdad(int age);
    Jugador buscarPosicion(char* position);
    Jugador buscarDorsal(int dorsal);
    Jugador buscarGoles(int goals);
    Jugador buscarAsistencias(int asissts);
};

#endif // JUGADOR_H
