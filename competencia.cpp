#include "competencia.h"
#include <iostream>
#include <cstring>
using namespace std;

void Competencia::cargar(){

    cout<<"Ingrese el nombre de la competencia: ";
    getline(cin, nameCompetencia);


    cout<<"Ingrese la cantidad de equipos: ";
    cin >> numEquipo;
    cin.ignore();


        equipo = new string[numEquipo];
    for (int i = 0;i < numEquipo ; i++ ){
        cout << "Ingrese el nombre de cada equipo " << (i+1) <<": ";
        getline(cin, equipo[i]);
    }

}
    string Competencia::getCompetencia(){return nameCompetencia;}
    string Competencia::getEquipo(int i) {
    if (i >= 0 && i < numEquipo) {
        return equipo[i];
    } else {
        return "sas";
    }
}

    int Competencia::getNumEquipo(){return numEquipo;}


    void Competencia::setNumEquipo(int valor){
        numEquipo = valor;
        equipo = new string[numEquipo];
    }
    void Competencia::setCompetencia(const string& valor){nameCompetencia = valor;}
    void Competencia::setEquipo(int i,char* valor) {
    if (i >= 0 && i < numEquipo) {
        equipo[i] = valor;
    } else {
        cout << "sos" << endl;
    }
}
    void Competencia::agregarEquipo(string& nombreEquipo){
        string* nuevoEquipo = new string[numEquipo + 1];
        for(int i = 0; i < numEquipo; i++){
            nuevoEquipo[i] = equipo[i];
        }
        nuevoEquipo[numEquipo] = nombreEquipo;
        delete[] equipo;
        equipo = nuevoEquipo;
        numEquipo++;

    }

    void Competencia::mostrarCompetencia()  {
    cout << "Competencia: " << nameCompetencia << endl;
    cout << "Cantidad de equipos: " << numEquipo <<endl;
    cout << "Equipos: " << endl;
    for (int i = 0; i < numEquipo; ++i) {
        cout << "- " << equipo[i] << endl;
    }
}

archivoCompetencia::archivoCompetencia(const char* nombreCompetencia = "Competencias.dat" ) {
    strcpy(this->nombre, nombreCompetencia);
}


bool archivoCompetencia::agregarCompetencia(Competencia reg) {
    FILE *punteroFile;
    punteroFile = fopen(this->nombre, "rb+");
    if (punteroFile == nullptr) {
        punteroFile = fopen(this->nombre, "wb+");
        if (punteroFile == nullptr) {
            return false;
        }
    }

    char nombre[50] = {0};

    while (fread(nombre, sizeof(char), 50, punteroFile) == 50) {
        if (strcmp(nombre, reg.getCompetencia().c_str()) == 0) {
            cout << "Competencia ya ingresada..." << endl;
            fclose(punteroFile);
            return false;
        }
    }
    fclose(punteroFile);

    punteroFile = fopen(this->nombre, "ab");
    if (punteroFile == nullptr) {
        return false;
    }

    strncpy(nombre, reg.getCompetencia().c_str(), sizeof(nombre) - 1);
    nombre[sizeof(nombre) - 1] = '\0';
    fwrite(&nombre, sizeof(char), 50, punteroFile);

    int numEquipo = reg.getNumEquipo();
    fwrite(&numEquipo, sizeof(int), 1, punteroFile);

    for (int i = 0; i < numEquipo; ++i) {
        char nombreEquipo[50] = {0};
        strncpy(nombreEquipo, reg.getEquipo(i).c_str(), sizeof(nombreEquipo) - 1);
        nombreEquipo[sizeof(nombreEquipo) - 1] = '\0';
        fwrite(nombreEquipo, sizeof(char), 50, punteroFile);
    }

    fclose(punteroFile);
    return true;
}

bool archivoCompetencia::eliminarCompetencia(char* nombreCompetencia){
    char nombre[50]={0};
    char equipos[50]={0};
    int cantidad;
    bool encontrado=false;
    Competencia reg;
    FILE *punteroFile = fopen("Competencias.dat", "rb");
    FILE *punteroTemp = fopen("Temp.dat", "wb");
    if(punteroFile==nullptr){return false;}
    if(punteroTemp==nullptr){
        fclose(punteroFile);
        return false;
    }

    while(fread(&nombre, sizeof(char),50,punteroFile)==50){
        fread(&cantidad,sizeof(int),1,punteroFile);
        if(strcmp(nombreCompetencia,nombre)!=0){
            fwrite(&nombre, sizeof(char),50,punteroTemp);
            fwrite(&cantidad, sizeof(int),1,punteroTemp);
            for(int i=0; i<cantidad; i++){
                fread(&equipos,sizeof(char),50,punteroFile);
                fwrite(&equipos,sizeof(char),50,punteroTemp);
            }
        } else {
            encontrado = true;
            for(int i=0; i<cantidad; i++){
                fread(&equipos,sizeof(char),50,punteroFile);
            }
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if(!encontrado){
        cout << "Competencia no encontrada..." <<endl;
    }

    remove("Competencias.dat");
    rename ("Temp.dat", "Competencias.dat");
    return true;
}

bool archivoCompetencia::modificarCompetencia(Competencia reg){
    char nombre[50]={0};
    char equipos[50]={0};
    int cantidad;
    bool encontrado=false;
    FILE *punteroFile = fopen("Competencias.dat", "rb");
    FILE *punteroTemp = fopen("Temp.dat", "wb");
    if(punteroFile==nullptr){return false;}
    if(punteroTemp==nullptr){
        fclose(punteroFile);
        return false;
    }

    while(fread(&nombre, sizeof(char),50,punteroFile)==50){
        if(strcmp(nombre,reg.getCompetencia().c_str())!=0){
            fwrite(&nombre, sizeof(char),50,punteroTemp);
            fread(&cantidad,sizeof(int),1,punteroFile);
            fwrite(&cantidad, sizeof(int),1,punteroTemp);
            for(int i=0; i<cantidad; i++){
                fread(&equipos,sizeof(char),50,punteroFile);
                fwrite(&equipos, sizeof(char),50,punteroTemp);
            }
        } else {
            encontrado = true;
            strncpy(nombre, reg.getCompetencia().c_str(), 49);
            fwrite(&nombre, sizeof(char),50,punteroTemp);
            cantidad = reg.getNumEquipo();
            fwrite(&cantidad, sizeof(int),1,punteroTemp);
            for(int i=0; i<cantidad; i++){
                strncpy(equipos, reg.getEquipo(i).c_str(), 49);
                fwrite(&equipos, sizeof(char),50,punteroTemp);
            }
            fread(&cantidad,sizeof(int),1,punteroFile);
            for(int i=0; i<cantidad; i++){
                fread(&equipos,sizeof(char),50,punteroFile);
            }
        }
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    if(!encontrado){
        cout << "Competencia no encontrada..."<<endl;
        remove("Temp.dat");
        return false;
    }

    remove("Competencias.dat");
    rename ("Temp.dat", "Competencias.dat");
    return true;
}

bool archivoCompetencia::listarCompetencia(){
    char nombre[50]={0};
    char equipos[50]={0};
    int cantidad;
    Competencia reg;
    FILE *punteroFile = fopen("Competencias.dat", "rb");
    if(punteroFile==nullptr){return false;}

    while(fread(&nombre, sizeof(char), 50, punteroFile)==50){
        reg.setCompetencia(nombre);
        fread(&cantidad, sizeof(int), 1, punteroFile);
        reg.setNumEquipo(cantidad);
        for(int i=0; i<cantidad; i++){
            fread(&equipos, sizeof(char), 50, punteroFile);
            reg.setEquipo(i,equipos);
        }
        reg.mostrarCompetencia();
    }
    fclose(punteroFile);
    return true;
}
