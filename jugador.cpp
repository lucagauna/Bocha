#include "jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
Jugador::Jugador(){
    nombre="Undefined";
    equipo="Undefined";
    idJugador = -1;
    edad=-1;
    posicion="Undefined";
    numero=-1;
    goles=-1;
    asistencias=-1;

}

void Jugador::cargar(){
    FILE *punteroFile = fopen("Equipos.dat", "rb");
    if(punteroFile==nullptr){return;}
    char team[50] = {0};
    int plantel = 0;
    char jugador[50] = {0};
    bool verificacionJugador=false;
    bool verificacionEquipo=false;

    cout<<"Ingrese el Nombre del Jugador: ";
    getline(cin,nombre);
    while(verificacionJugador==false){
        fseek(punteroFile,0,0);
        while(fread(&team,sizeof(char),50,punteroFile)==50){
            fread(&plantel,sizeof(int),1,punteroFile);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                if(nombre==jugador){
                    verificacionJugador=true;
                }
            }

        }
        if(!verificacionJugador){
            cout<<"Reingrese el Nombre del Jugador: ";
            getline(cin,nombre);
        }
    }

    cout << "Ingrese el ID del Jugador: ";
    cin >> idJugador;

    if(idJugador<=0){
        cout << "Reingrese el ID del Jugador: ";
        cin >> idJugador;
    }

    cin.ignore();

    cout<<"Ingrese el equipo del Jugador: ";
    getline(cin,equipo);
    while(verificacionEquipo==false){
        fseek(punteroFile,0,0);
        while(fread(&team,sizeof(char),50,punteroFile)==50){
            fread(&plantel,sizeof(int),1,punteroFile);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                if(equipo==team && jugador==nombre){
                    verificacionEquipo=true;
                }
            }

        }
        if(!verificacionEquipo){
            cout<<"Reingrese el equipo del Jugador: ";
            getline(cin,equipo);
        }
    }
    fclose(punteroFile);

    cout<<"Ingrese la edad del Jugador: ";
    cin>>edad;
    cin.ignore();

    while(edad<1||edad>99){
        cout<<"Reingrese la edad del jugador: ";
        cin>>edad;
        cin.ignore();
    }

    cout<<"Ingrese la posicion del Jugador: ";
    getline(cin, posicion);
    while(posicion!="Delantero"&&posicion!="Mediocampista"&&posicion!="Defensor"&&posicion!="Arquero"){
        cout<<"Reingrese la posicion del Jugador: ";
        getline(cin, posicion);
    }

    cout<<"Ingrese la dorsal del jugador: ";
    cin>>numero;
    while(numero<1||numero>99){
        cout<<"Reingrese la dorsal del jugador: ";
        cin>>numero;
    }

    cout<<"Ingrese los goles anotados por el jugador: ";
    cin>>goles;
    while(goles<0){
        cout<<"Reingrese los goles anotados por el jugador: ";
        cin>>goles;
    }

    cout<<"Ingrese las asistencias realizadas por el jugador: ";
    cin>>asistencias;
    while(asistencias<0){
        cout<<"Reingrese las asistencias realizadas por el jugador: ";
        cin>>asistencias;

    }


}
// Getters
int Jugador::getIdJugador(){
    return idJugador;
}

string Jugador::getNombre(){
    return nombre;
}

string Jugador::getEquipo(){
    return equipo;
}

int Jugador::getEdad(){
    return edad;
}

string Jugador::getPosicion(){
    return posicion;
}

int Jugador::getNumero(){
    return numero;
}

int Jugador::getGoles(){
    return goles;
}

int Jugador::getAsistencias(){
    return asistencias;
}

// Setters
void Jugador::setIdJugador(int ID){
    idJugador=ID;
}

void Jugador::setNombre(string nombre) {
    this->nombre = nombre;
}

void Jugador::setEquipo(const string& equipo) {
    this->equipo = equipo;
}

void Jugador::setEdad(int edad) {
    if (edad >= 0 && edad < 100) {
        this->edad = edad;
    } else {
        cout << "Error: Edad Incoherente!!" << endl;
    }
}

void Jugador::setPosicion(string posicion) {
    if(posicion=="Delantero"||posicion=="Mediocampista"||posicion=="Defensor"||posicion=="Arquero"){
        this->posicion = posicion;
    } else {
        cout << "Error: Posicion Incorrecta!!" <<endl;
    }
}

void Jugador::setGoles(int goles) {
    if(goles>=0){
        this->goles = goles;
    } else {
        cout << "Error: Goles Incoherentes!!" <<endl;
    }
}

void Jugador::setAsistencias(int asistencias) {
    if(asistencias>=0){
        this->asistencias = asistencias;
    } else {
        cout << "Error: Asistencias Incoherentes!!" <<endl;
    }

}

void Jugador::setNumero(int numero) {
    if(numero>0 && numero<100){
        this->numero = numero;
    } else{
        cout << "Error: Numero Imposible!!" <<endl;
    }
}


void Jugador::mostrarJugador() const {
    cout << "Nombre: " << nombre << endl;
    cout << "ID: " << idJugador <<endl;
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
    int ID=0;
    int n;
    char team[50] = {0};
    char position[50] = {0};
    int age = 0;
    int number  = 0;
    int goals = 0;
    int assists = 0;


    punteroFile = fopen("Jugadores.dat", "rb+");
    if (punteroFile == nullptr){
        punteroFile = fopen("Jugadores.dat", "wb+");
        if(punteroFile==nullptr){
            fclose(punteroFile);
            return 0;
        }
    }

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        if(name==jugador.getNombre()){
            cout << "Jugador ya ingresado..." <<endl;
            return 0;
        }
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&age,sizeof(int),1,punteroFile);
        fread(&position,sizeof(char),50,punteroFile);
        fread(&number,sizeof(int),1,punteroFile);
        fread(&goals,sizeof(int),1,punteroFile);
        fread(&assists,sizeof(int),1,punteroFile);
        while(ID == jugador.getIdJugador() ||  jugador.getIdJugador()<=0){
            cout << "Reingresar el ID del jugador: ";
            cin >> n;
            jugador.setIdJugador(n);
            fseek(punteroFile,0,0);
        }
    }
    fclose(punteroFile);

    punteroFile = fopen("Jugadores.dat", "ab");
    if (punteroFile == nullptr){return false;}


    strncpy(name, jugador.getNombre().c_str(), 49);
    fwrite(&name, sizeof(char), 50, punteroFile);

    ID = jugador.getIdJugador();
    fwrite(&ID,sizeof(int),1,punteroFile);

    strncpy(team, jugador.getEquipo().c_str(), 49);
    fwrite(&team, sizeof(char), 50, punteroFile);

    age = jugador.getEdad();
    fwrite(&age, sizeof(int), 1, punteroFile);

    strncpy(position, jugador.getPosicion().c_str(), 49);
    fwrite(&position, sizeof(char), 50, punteroFile);

    number  = jugador.getNumero();
    fwrite(&number, sizeof(int), 1, punteroFile);

    goals = jugador.getGoles();
    fwrite(&goals, sizeof(int), 1, punteroFile);

    assists = jugador.getAsistencias();
    fwrite(&assists, sizeof(int), 1, punteroFile);

    fclose(punteroFile);
    return true;
    system("pause");
}

bool archivoJugador::eliminarJugador(const char* nombreJugador) {
    FILE *punteroFile, *punteroTemp;
    Jugador jugador;
    char team[50]={0};
    int ID;
    char nombre[50] = {0};
    char posicion[50]={0};
    bool encontrado = false;
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return false;}
    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {return false;}

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
        if (strcmp(nombre, nombreJugador) != 0) {
            fwrite(&nombre, sizeof(char), 50, punteroTemp);
            fread(&ID,sizeof(int),1,punteroFile);
            fwrite(&ID,sizeof(int),1,punteroTemp);
            fread(&team, sizeof(char), 50, punteroFile);
            fwrite(&team, sizeof(char), 50, punteroTemp);
            fread(&edad, sizeof(int), 1, punteroFile);
            fwrite(&edad, sizeof(int), 1, punteroTemp);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fwrite(&posicion, sizeof(char), 50, punteroTemp);
            fread(&numero, sizeof(int), 1, punteroFile);
            fwrite(&numero, sizeof(int), 1, punteroTemp);
            fread(&goles, sizeof(int), 1, punteroFile);
            fwrite(&goles, sizeof(int), 1, punteroTemp);
            fread(&asistencias, sizeof(int), 1, punteroFile);
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        } else {
            encontrado = true;
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if (!encontrado) {
        cout << "No se encontro el jugador..." <<endl;
        remove("temp.dat");
    }
    remove("Jugadores.dat");
    rename("temp.dat", "Jugadores.dat");

    return encontrado;
}


bool archivoJugador::modificarJugador(Jugador jugador) {
    FILE *punteroFile, *punteroTemp;
    char nombre[50] = {0};
    int ID;
    char posicion[50]={0};
    char team[50]={0};
    int edad, numero, goles, asistencias;
    bool encontrado = false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return false;}
    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {return false;}

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
        fread(&ID, sizeof(int), 1, punteroFile);
        fread(&team, sizeof(char), 50, punteroFile);
        fread(&edad, sizeof(int), 1, punteroFile);
        fread(&posicion, sizeof(char), 50, punteroFile);
        fread(&numero, sizeof(int), 1, punteroFile);
        fread(&goles, sizeof(int), 1, punteroFile);
        fread(&asistencias, sizeof(int), 1, punteroFile);

        if (strcmp(nombre, jugador.getNombre().c_str()) == 0) {
            encontrado = true;

            strncpy(nombre, jugador.getNombre().c_str(), 49);
            fwrite(&nombre, sizeof(char), 50, punteroTemp);

            ID = jugador.getIdJugador();
            fwrite(&ID, sizeof(int), 1, punteroTemp);

            strncpy(team, jugador.getEquipo().c_str(), 49);
            fwrite(&team, sizeof(char), 50, punteroTemp);

            edad = jugador.getEdad();
            fwrite(&edad, sizeof(int), 1, punteroTemp);

            strncpy(posicion, jugador.getPosicion().c_str(), 49);
            fwrite(&posicion, sizeof(char), 50, punteroTemp);

            numero = jugador.getNumero();
            fwrite(&numero, sizeof(int), 1, punteroTemp);

            goles = jugador.getGoles();
            fwrite(&goles, sizeof(int), 1, punteroTemp);

            asistencias = jugador.getAsistencias();
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        } else {
            // Escribir registro sin cambios en temp.dat
            fwrite(&nombre, sizeof(char), 50, punteroTemp);
            fwrite(&ID, sizeof(int), 1, punteroTemp);
            fwrite(&team, sizeof(char), 50, punteroTemp);
            fwrite(&edad, sizeof(int), 1, punteroTemp);
            fwrite(&posicion, sizeof(char), 50, punteroTemp);
            fwrite(&numero, sizeof(int), 1, punteroTemp);
            fwrite(&goles, sizeof(int), 1, punteroTemp);
            fwrite(&asistencias, sizeof(int), 1, punteroTemp);
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if (!encontrado) {
        cout << "No se encontro el jugador..." <<endl;
        remove("temp.dat");
    }
    remove("Jugadores.dat");
    rename("temp.dat", "Jugadores.dat");

    return encontrado;
}


bool archivoJugador::mostrarJugadores(){
    FILE *punteroFile = fopen(nombreArchivo, "rb");
    if(punteroFile==nullptr){return 0;}
    Jugador reg;
    char name[50]={0};
    int ID;
    char team[50]={0};
    int age=0;
    char position[50]={0};
    int number=0;
    int goals=0;
    int assists=0;

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg.setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg.setIdJugador(ID);
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

Jugador archivoJugador::buscarJugador(const char* nombreJugador){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            reg.setNombre(nombre);
            fread(&ID,sizeof(int),1,punteroFile);
            reg.setIdJugador(ID);
            fread(&team, sizeof(char), 50, punteroFile);
            reg.setEquipo(team);
            fread(&edad, sizeof(int), 1, punteroFile);
            reg.setEdad(edad);
            fread(&posicion, sizeof(char), 50, punteroFile);
            reg.setPosicion(posicion);
            fread(&numero, sizeof(int), 1, punteroFile);
            reg.setNumero(numero);
            fread(&goles, sizeof(int), 1, punteroFile);
            reg.setGoles(goles);
            fread(&asistencias, sizeof(int), 1, punteroFile);
            reg.setAsistencias(asistencias);
        if (strcmp(nombre, nombreJugador) == 0) {
            fclose(punteroFile);
            return reg;
        }
    }

    cout << "Jugador no encontrado..." << endl;
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarID(int num){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            reg.setNombre(nombre);
            fread(&ID,sizeof(int),1,punteroFile);
            reg.setIdJugador(ID);
            fread(&team, sizeof(char), 50, punteroFile);
            reg.setEquipo(team);
            fread(&edad, sizeof(int), 1, punteroFile);
            reg.setEdad(edad);
            fread(&posicion, sizeof(char), 50, punteroFile);
            reg.setPosicion(posicion);
            fread(&numero, sizeof(int), 1, punteroFile);
            reg.setNumero(numero);
            fread(&goles, sizeof(int), 1, punteroFile);
            reg.setGoles(goles);
            fread(&asistencias, sizeof(int), 1, punteroFile);
            reg.setAsistencias(asistencias);
        if (num == reg.getIdJugador()) {
            fclose(punteroFile);
            return reg;
        }
    }

    cout << "Jugador no encontrado..." << endl;
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarEquipo(const char* equipo){
    FILE *punteroFile;
    Jugador reg;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            encontrado=false;
            reg.setNombre(nombre);
            fread(&ID,sizeof(int),1,punteroFile);
            reg.setIdJugador(ID);
            fread(&team, sizeof(char), 50, punteroFile);
            reg.setEquipo(team);
            fread(&edad, sizeof(int), 1, punteroFile);
            reg.setEdad(edad);
            fread(&posicion, sizeof(char), 50, punteroFile);
            reg.setPosicion(posicion);
            fread(&numero, sizeof(int), 1, punteroFile);
            reg.setNumero(numero);
            fread(&goles, sizeof(int), 1, punteroFile);
            reg.setGoles(goles);
            fread(&asistencias, sizeof(int), 1, punteroFile);
            reg.setAsistencias(asistencias);
        if (strcmp(team, equipo) == 0) {
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Equipo no encontrado..." << endl;
        fclose(punteroFile);
        return reg;
    }
    return reg;
}

Jugador archivoJugador::buscarEdad(int age){
    FILE *punteroFile;
    Jugador reg;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        if (age == edad) {
            encontrado=true;

            reg.setNombre(nombre);
            reg.setIdJugador(ID);
            reg.setEquipo(team);
            reg.setEdad(edad);
            reg.setPosicion(posicion);
            reg.setNumero(numero);
            reg.setGoles(goles);
            reg.setAsistencias(asistencias);

            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Edad no encontrada..." << endl;
        fclose(punteroFile);
    }
    return reg;
}

Jugador archivoJugador::buscarPosicion(const char* position){
    FILE *punteroFile;
    Jugador reg;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        if (strcmp(position,posicion)==0) {
            encontrado=true;

            reg.setNombre(nombre);
            reg.setIdJugador(ID);
            reg.setEquipo(team);
            reg.setEdad(edad);
            reg.setPosicion(posicion);
            reg.setNumero(numero);
            reg.setGoles(goles);
            reg.setAsistencias(asistencias);

            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Posicion no encontrada..." << endl;
        fclose(punteroFile);
    }
    return reg;
}
Jugador archivoJugador::buscarDorsal(int dorsal){
    FILE *punteroFile;
    Jugador reg;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        if (dorsal==numero) {
            encontrado=true;

            reg.setNombre(nombre);
            reg.setIdJugador(ID);
            reg.setEquipo(team);
            reg.setEdad(edad);
            reg.setPosicion(posicion);
            reg.setNumero(numero);
            reg.setGoles(goles);
            reg.setAsistencias(asistencias);

            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Dorsal no encontrada..." << endl;
        fclose(punteroFile);
    }
    return reg;
}

Jugador archivoJugador::buscarGoles(int goals){
    FILE *punteroFile;
    Jugador reg;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        if (goals==goles) {
            encontrado=true;

            reg.setNombre(nombre);
            reg.setIdJugador(ID);
            reg.setEquipo(team);
            reg.setEdad(edad);
            reg.setPosicion(posicion);
            reg.setNumero(numero);
            reg.setGoles(goles);
            reg.setAsistencias(asistencias);

            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Goles no encontrades..." << endl;
        fclose(punteroFile);
    }
    return reg;
}

Jugador archivoJugador::buscarAsistencias(int asissts){
    FILE *punteroFile;
    Jugador reg;
    char nombre[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&nombre, sizeof(char), 50, punteroFile) == 50) {
            fread(&ID,sizeof(int),1,punteroFile);
            fread(&team, sizeof(char), 50, punteroFile);
            fread(&edad, sizeof(int), 1, punteroFile);
            fread(&posicion, sizeof(char), 50, punteroFile);
            fread(&numero, sizeof(int), 1, punteroFile);
            fread(&goles, sizeof(int), 1, punteroFile);
            fread(&asistencias, sizeof(int), 1, punteroFile);
        if (asissts==asistencias) {
            encontrado=true;

            reg.setNombre(nombre);
            reg.setIdJugador(ID);
            reg.setEquipo(team);
            reg.setEdad(edad);
            reg.setPosicion(posicion);
            reg.setNumero(numero);
            reg.setGoles(goles);
            reg.setAsistencias(asistencias);

            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Asistencias no encontradas..." << endl;
        fclose(punteroFile);
    }
    return reg;
}

bool archivoJugador::ordenadosNombre(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(strcmp(reg[i].getNombre().c_str(),reg[y].getNombre().c_str())>0){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(strcmp(reg[i].getNombre().c_str(),reg[y].getNombre().c_str())<0){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}

bool archivoJugador::ordenadosID(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getIdJugador()>reg[y].getIdJugador()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getIdJugador()<reg[y].getIdJugador()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}

bool archivoJugador::ordenadosEquipo(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(strcmp(reg[i].getEquipo().c_str(),reg[y].getEquipo().c_str())>0){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(strcmp(reg[i].getEquipo().c_str(),reg[y].getEquipo().c_str())<0){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}
bool archivoJugador::ordenadosEdad(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getEdad()>reg[y].getEdad()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getEdad()<reg[y].getEdad()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}
bool archivoJugador::ordenadosDorsal(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getNumero()>reg[y].getNumero()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getNumero()<reg[y].getNumero()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}
bool archivoJugador::ordenadosGoles(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getGoles()>reg[y].getGoles()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fread(&ID,sizeof(int),1,punteroFile);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getGoles()<reg[y].getGoles()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}
bool archivoJugador::ordenadosAsistencias(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador *reg;
    Jugador temp;
    int iteraciones=0;
    int x=0;
    char name[50] = {0};
    int ID;
    char posicion[50] = {0};
    char team[50] = {0};
    int edad, numero, goles, asistencias;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&ID,sizeof(int),1,punteroFile);
        fread(&team,sizeof(char),50,punteroFile);
        fread(&edad,sizeof(int),1,punteroFile);
        fread(&posicion,sizeof(char),50,punteroFile);
        fread(&numero,sizeof(int),1,punteroFile);
        fread(&goles,sizeof(int),1,punteroFile);
        fread(&asistencias,sizeof(int),1,punteroFile);
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Jugador[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&ID,sizeof(int),1,punteroFile);
        reg[x].setIdJugador(ID);
        fread(&team,sizeof(char),50,punteroFile);
        reg[x].setEquipo(team);
        fread(&edad,sizeof(int),1,punteroFile);
        reg[x].setEdad(edad);
        fread(&posicion,sizeof(char),50,punteroFile);
        reg[x].setPosicion(posicion);
        fread(&numero,sizeof(int),1,punteroFile);
        reg[x].setNumero(numero);
        fread(&goles,sizeof(int),1,punteroFile);
        reg[x].setGoles(goles);
        fread(&asistencias,sizeof(int),1,punteroFile);
        reg[x].setAsistencias(asistencias);
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getAsistencias()>reg[y].getAsistencias()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getAsistencias()<reg[y].getAsistencias()){ ////LOGICA MAL HECHA!!!!!
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(),49);
            fwrite(&name,sizeof(char),50,punteroTemp);
            ID = reg[i].getIdJugador();
            fwrite(&ID,sizeof(int),1,punteroTemp);
            strncpy(team, reg[i].getEquipo().c_str(),49);
            fwrite(&team,sizeof(char),50,punteroTemp);
            edad = reg[i].getEdad();
            fwrite(&edad,sizeof(int),1,punteroTemp);
            strncpy(posicion, reg[i].getPosicion().c_str(),49);;
            fwrite(&posicion,sizeof(char),50,punteroTemp);
            numero = reg[i].getNumero();
            fwrite(&numero,sizeof(int),1,punteroTemp);
            goles = reg[i].getGoles();
            fwrite(&goles,sizeof(int),1,punteroTemp);
            asistencias = reg[i].getAsistencias();
            fwrite(&asistencias,sizeof(int),1,punteroTemp);
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}

