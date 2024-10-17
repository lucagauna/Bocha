#ifndef EQUIPOS_H_INCLUDED
#define EQUIPOS_H_INCLUDED

#include <iostream>
#include <vector>
using namespace std;
#include "jugador.h"

class Equipo {

private:
    string nombre;
    string* jugadores; ///ELIMINAR VECTOR DINAMICO!!!!!
    int plantel=0;
public:
    // Constructor
    void cargar();
    // Destructor

    // Metodos

    string getNombre();
    string getJugador(int i);
    int getPlantel();
    void setNombre(string nombre);
    void setJugador(int pos, string jugador);
    void setPlantel(int plantel);
    void mostrarEquipo() const;

    //~Equipo();
};


class ArchivoEquipo{
private:
    char nombre[50];
public:
    ArchivoEquipo(const char* nombre);

    bool agregarRegistro(Equipo reg);
    bool eliminarRegistro(char* club);
    bool modificarRegistro(Equipo club);
    bool buscarRegistro();
    bool mostrarRegistro();
    Equipo listarRegistro(int pos);

};


#endif // EQUIPOS_H_INCLUDED
