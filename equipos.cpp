#include "equipos.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
void Equipo::cargar(){
    cout << "Ingrese nombre del Equipo: ";
    getline(cin,nombre);
    cout << "Ingrese cantidad de jugadores: ";
    cin >> plantel;
    while(plantel<=0){
        cout << "Ingrese cantidad de jugadores: ";
        cin >> plantel;
    }
    cin.ignore();
    jugadores = new string[plantel];
    if(jugadores==nullptr){return;}
    for(int i=0; i<plantel; i++){
        cout << "Ingrese jugador numero #" << i+1 << ": ";
        getline(cin,jugadores[i]);
        cout << endl;
    }

}

string Equipo::getNombre(){return nombre;}
string  Equipo::getJugador(int i){return jugadores[i];}
int  Equipo::getPlantel(){return plantel;}
void  Equipo::setNombre(string nombre){this->nombre=nombre;}
void  Equipo::setJugador(int pos, string jugador){
    jugadores[pos]=jugador;
    }
void  Equipo::setPlantel(int plantel){
    this->plantel=plantel;
    jugadores = new string[plantel];
    if(jugadores==nullptr){return;}
}

void Equipo::mostrarEquipo() const {
    cout << "Equipo: " << nombre << endl;
    cout << "Plantel: " << plantel <<endl;
    for(int i=0; i<plantel; i++){
        cout << "Jugador numero #" << i+1 << ": " << jugadores[i] <<endl;
    }
}

/*Equipo::~Equipo(){
    delete[] jugadores;
}*/

ArchivoEquipo::ArchivoEquipo(const char* nombre="Equipos.dat"){
    strcpy(this->nombre, nombre);
}

bool ArchivoEquipo::agregarRegistro(Equipo reg){
    FILE *punteroFile;
    Equipo lista;
    int escribio;
    char jugador[50]={0};
    char name[50]={0};
    punteroFile=fopen(nombre,"ab");
    if(punteroFile==nullptr){return 0;}
    while(fread(&lista,sizeof(Equipo),1,punteroFile)==1){ /// ARREGLAR >:V
        if(lista.getNombre()==reg.getNombre()){
            cout<< "Equipo ya ingresado..."  <<endl;
            return 0;
        }
    }
    strncpy(name, reg.getNombre().c_str(), 49);
    name[49]='\0';
    escribio=fwrite(name,sizeof(char),50,punteroFile);
    int plantel= reg.getPlantel();
    escribio=fwrite(&plantel,sizeof(int),1,punteroFile);
    for(int i=0; i<reg.getPlantel(); i++){
        strncpy(jugador, reg.getJugador(i).c_str(), 49);
        jugador[49]='\0';
        escribio=fwrite(jugador,sizeof(char),50,punteroFile);
    }
    fclose(punteroFile);
    return escribio; // ELIMINAR VECTOR DINAMICO!!
}

bool ArchivoEquipo::eliminarRegistro(char* club){
    FILE *punteroFile, *punteroTemp;
    Equipo reg;
    char name[50]={0};
    char player[50]={0};
    int quantity;
    bool encontrado=false;
    punteroFile=fopen(nombre, "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        if(strcmp(name,club)!=0){
            fwrite(&name,sizeof(char),50,punteroTemp);
            fread(&quantity,sizeof(int),1,punteroFile);
            fwrite(&quantity,sizeof(int),1,punteroTemp);
            for(int i=0; i<quantity; i++){
                fread(&player,sizeof(char),50,punteroFile);
                fwrite(&player,sizeof(char),50,punteroTemp);
            }
        } else {
            encontrado=true;
            fread(&quantity,sizeof(int),1,punteroFile);
            for(int i=0; i<quantity; i++){
                fread(&player, sizeof(char),50,punteroFile);
            }
        }
    }
    fclose(punteroFile);
    fclose(punteroTemp);

    if(encontrado){
        remove(nombre);
        rename("temp.dat",nombre);
        return 1;
    } else{
        remove("temp.dat");
        cout << "CLUB NO ENCONTRADO..." <<endl;
        return 0;
    }

    return 1;
}

bool ArchivoEquipo::modificarRegistro(Equipo club){
    FILE *punteroFile, *punteroTemp;
    Equipo reg;
    char name[50]={0};
    char player[50]={0};
    int quantity=0;

    punteroFile=fopen(nombre, "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        if(strcmp(name,club.getNombre().c_str())==0){
            strncpy(name,club.getNombre().c_str(),49);
            name[49]='\0';
            fwrite(&name,sizeof(char),50,punteroTemp);
            quantity=club.getPlantel();
            fwrite(&quantity,sizeof(int),1,punteroTemp);
            for(int i=0; i<quantity; i++){
                strncpy(player,club.getJugador(i).c_str(),49);
                player[49]='\0';
                fwrite(&player,sizeof(char),50,punteroTemp);
            }
            fread(&quantity,sizeof(int),1,punteroFile);
            for(int i=0; i<quantity; i++){
                fread(&player, sizeof(char),50,punteroFile);
            }
            fseek(punteroFile,-50,1);
        } else{
            fread(&name,sizeof(char),50,punteroFile);
            fwrite(&name,sizeof(char),50,punteroTemp);
            fread(&quantity,sizeof(int),1,punteroFile);
            fwrite(&quantity,sizeof(int),1,punteroTemp);
            for(int i=0; i<quantity; i++){
                fread(&player,sizeof(char),50,punteroFile);
                fwrite(&player,sizeof(char),50,punteroTemp);
            }

        }

    }
    fclose(punteroFile);
    fclose(punteroTemp);

    remove(nombre);
    rename("temp.dat",nombre);

    return 1;
}

bool ArchivoEquipo::mostrarRegistro(){
    FILE *punteroFile;
    Equipo reg;
    char name[50]={0};
    char player[50]={0};
    int quantity;
    punteroFile = fopen(nombre,"rb");
    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg.setNombre(name);
        fread(&quantity,sizeof(int),1,punteroFile);
        reg.setPlantel(quantity);
        for(int i=0; i<quantity; i++){
            fread(&player,sizeof(char),50,punteroFile);
            reg.setJugador(i,player);
        }
        reg.mostrarEquipo();
    }
    fclose(punteroFile);
    return true;
}

Equipo ArchivoEquipo::listarRegistro(int pos){
    FILE* punteroFile;
    Equipo reg;
    char name[50]={0};
    char player[50]={0};
    int quantity;
    punteroFile=fopen(nombre, "rb");
    if(punteroFile==nullptr){return reg;}
    fseek(punteroFile, (pos-1) * sizeof(Equipo),0);
    if(fread(&name,sizeof(char),50,punteroFile)!=50){
        reg.setNombre(name);
        fread(&quantity,sizeof(int),1,punteroFile);
        reg.setPlantel(quantity);
        for(int i=0; i<quantity; i++){
            fread(&player,sizeof(char),50,punteroFile);
            reg.setJugador(i,player);
        }
    } else {
        cout << "EQUIPO NO ENCONTRADO..." <<endl;
        return reg;
    }
    fclose(punteroFile);
    return reg;
}

Equipo archivoEquipo::buscarRegistro(char* nombreBuscado){
    FILE* punteroFile;
    Equipo reg;
    char nombreEquipo[50] = {0};
    char jugador[50] = {0};
    int plantel;

    punteroFile = fopen(nombre,"rb");
    if (punteroFile == nullptr){return 0;}



}
