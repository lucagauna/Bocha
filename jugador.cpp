#include "jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
void Jugador::cargar(){
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

int Jugador::getNumero() const {
    return numero;
}

int Jugador::getGoles() const {
    return goles;
}

int Jugador::getAsistencias() const {
    return asistencias;
}

// Setters
void Jugador::setNombre(string nombre) {
    this->nombre = nombre;
}

void Jugador::setEquipo(const string& equipo) {
    this->equipo = equipo;
}

void Jugador::setEdad(int edad) {
    if (edad >= 0) {
        this->edad = edad;
    } else {
        cout << "Error: No puedes poner ningún jugador que aun no haya nacido!!" << endl;
    }
}

void Jugador::setPosicion(string posicion) {
    this->posicion = posicion;
}

void Jugador::setGoles(int goles) {
    this->goles = goles;
}

void Jugador::setAsistencias(int asistencias) {
    this->asistencias = asistencias;
}

void Jugador::setNumero(int numero) {
    this->numero = numero;
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


archivoJugador::archivoJugador(const char* nombreArchivo = "Jugadores.dat") {
    strcpy(this->nombreArchivo, nombreArchivo);
}

bool archivoJugador::agregarJugador(Jugador jugador){
    FILE *punteroFile;

    char name[50] = {0};
    char team[50] = {0};
    char position[50] = {0};
    int age = jugador.getEdad();
    int number  = jugador.getNumero();
    int goals = jugador.getGoles();
    int assists = jugador.getAsistencias();

    punteroFile = fopen(nombreArchivo, "ab");
    if (punteroFile == nullptr){return false;}

    strncpy(name, jugador.getNombre().c_str(), 49);
    fwrite(&name, sizeof(char), 50, punteroFile);

    strncpy(team, jugador.getEquipo().c_str(), 49);
    fwrite(&team, sizeof(char), 50, punteroFile);

    fwrite(&age, sizeof(int), 1, punteroFile);

    strncpy(position, jugador.getPosicion().c_str(), 49);
    fwrite(&position, sizeof(char), 50, punteroFile);

    fwrite(&number, sizeof(int), 1, punteroFile);
    fwrite(&goals, sizeof(int), 1, punteroFile);
    fwrite(&assists, sizeof(int), 1, punteroFile);

    fclose(punteroFile);
    return true;
    system("pause");
}

bool archivoJugador::eliminarJugador(const char* nombreJugador) {
    FILE *punteroFile, *punteroTemp;
    Jugador jugador;
    char nombre[50] = {0};
    char posicion[50];
    bool encontrado = false;
    int edad, numero, goles, asistencias;

    punteroFile = fopen(nombreArchivo, "rb");
    if (punteroFile == nullptr) {return false;}
    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {return false;}

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
        if (strcmp(nombre, nombreJugador) != 0) {
            fwrite(&nombre, sizeof(char), 50, punteroTemp);
            fread(posicion, sizeof(char), 50, punteroFile);
            fwrite(posicion, sizeof(char), 50, punteroTemp);
            fread(&edad, sizeof(int), 1, punteroFile);
            fwrite(&edad, sizeof(int), 1, punteroTemp);
            fread(&numero, sizeof(int), 1, punteroFile);
            fwrite(&numero, sizeof(int), 1, punteroTemp);
            fread(&goles, sizeof(int), 1, punteroFile);
            fwrite(&goles, sizeof(int), 1, punteroTemp);
            fread(&asistencias, sizeof(int), 1, punteroFile);
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        } else {
            encontrado = true;
            fread(posicion, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if (encontrado) {
        remove(nombreArchivo);
        rename("temp.dat", nombreArchivo);
    } else {
        remove("temp.dat");
        cout << "Jugador no encontrado..." << endl;
    }

    return encontrado;
}


bool archivoJugador::modificarJugador(Jugador jugador) {
    FILE *punteroFile, *punteroTemp;
    char nombre[50] = {0};
    bool encontrado = false;

    punteroFile = fopen(nombreArchivo, "rb");
    if (punteroFile == nullptr) {
        return false;
    }

    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {
        fclose(punteroFile);
        return false;
    }

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
        if (strcmp(nombre, jugador.getNombre().c_str()) != 0) {
            fwrite(&nombre, sizeof(char), 50, punteroTemp);
            char posicion[50];
            int edad, numero, goles, asistencias;
            fread(posicion, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);

            fwrite(posicion, sizeof(char), 50, punteroTemp);
            fwrite(&edad, sizeof(int), 1, punteroTemp);
            fwrite(&numero, sizeof(int), 1, punteroTemp);          /// REVISA SI ESTA PARA EL OJAL
            fwrite(&goles, sizeof(int), 1, punteroTemp);
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        } else {
            encontrado = true;
            char nombreNuevo[50];
            strncpy(nombreNuevo, jugador.getNombre().c_str(), 49);
            fwrite(nombreNuevo, sizeof(char), 50, punteroTemp);

            char posicion[50];
            strncpy(posicion, jugador.getPosicion().c_str(), 49);
            fwrite(posicion, sizeof(char), 50, punteroTemp);

            int edad = jugador.getEdad();
            int numero = jugador.getNumero();
            int goles = jugador.getGoles();
            int asistencias = jugador.getAsistencias();

            fwrite(&edad, sizeof(int), 1, punteroTemp);
            fwrite(&numero, sizeof(int), 1, punteroTemp);
            fwrite(&goles, sizeof(int), 1, punteroTemp);
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if (encontrado) {
        remove(nombreArchivo);
        rename("temp.dat", nombreArchivo);
    }

    return encontrado;
}

bool archivoJugador::buscarJugador(const char* nombreJugador) {
    FILE *punteroFile;
    char nombre[50] = {0};
    char posicion[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen(nombreArchivo, "rb");
    if (punteroFile == nullptr) {
        cout << "Error al abrir el archivo." << endl;
        return false;
    }

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
        if (strcmp(nombre, nombreJugador) == 0) {
            fread(posicion, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);


            cout << "Nombre: " << nombre << endl;
            cout << "Posicion: " << posicion << endl;
            cout << "Edad: " << edad << endl;
            cout << "Numero: " << numero << endl;
            cout << "Goles: " << goles << endl;
            cout << "Asistencias: " << asistencias << endl;

            fclose(punteroFile);
            return true;
        } else {

            fseek(punteroFile, sizeof(char) * 50 + 4 * sizeof(int), SEEK_CUR);
        }
    }

    cout << "Jugador no encontrado." << endl;
    fclose(punteroFile);
    return false;
}

bool archivoJugador::mostrarJugadores(){
    FILE *punteroFile = fopen(nombreArchivo, "rb");
    if(punteroFile==nullptr){return 0;}
    Jugador reg;
    char name[50]={0};
    char team[50]={0};
    int age=0;
    char position[50]={0};
    int number=0;
    int goals=0;
    int assists=0;

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg.setNombre(name);
        fread(&team,sizeof(char),50,punteroFile);
        reg.setEquipo(team);
        fread(&age,sizeof(int),1,punteroFile);
        reg.setEdad(age);
        fread(&position,sizeof(char),50,punteroFile);
        reg.setPosicion(position);
        fread(&number,sizeof(int),1,punteroFile);
        reg.setNumero(number);
        fread(&goals,sizeof(int),1,punteroFile);
        reg.setGoles(goals);
        fread(&assists,sizeof(int),1,punteroFile);
        reg.setAsistencias(assists);
        reg.mostrarJugador();
    }
    fclose(punteroFile);
    return true;
}




