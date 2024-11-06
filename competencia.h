#ifndef COMPETENCIA_H_INCLUDED
#define COMPETENCIA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Competencia{
private:
    string nameCompetencia;
    string* equipo;
    int numEquipo;
public:

    Competencia();

    void cargar();

    string getCompetencia();
    string getEquipo(int i);
    int getNumEquipo();

    void setCompetencia(const string& valor);
    void setEquipo(int i, char* valor);
    void setNumEquipo(int valor);

    void agregarEquipo(string& nombreEquipo);
    void mostrarCompetencia();


};

class archivoCompetencia {
private:
     char nombre[50];

public:
    archivoCompetencia(const char* nombreCompetencia);

    bool agregarCompetencia(Competencia reg);
    bool eliminarCompetencia(char* nombreCompetencia);
    bool modificarCompetencia(Competencia reg);
    bool listarCompetencia();
    Competencia buscarCompetencia(char* nombreCompetencia);

};






#endif // COMPETENCIA_H_INCLUDED
