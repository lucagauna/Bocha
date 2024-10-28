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
        cout << "Reingrese cantidad de jugadores: ";
        cin >> plantel;
    }
    cin.ignore();
    jugadores = new string[plantel];
    if(jugadores==nullptr){return;}
    for(int i=0; i<plantel; i++){
        cout << "Ingrese jugador numero #" << i+1 << ": ";
        getline(cin,jugadores[i]);
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

archivoEquipo::archivoEquipo(const char* nombre="Equipos.dat"){
    strcpy(this->nombre, nombre);
}

bool archivoEquipo::agregarRegistro(Equipo reg){
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

bool archivoEquipo::eliminarRegistro(char* club){
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

bool archivoEquipo::modificarRegistro(Equipo club){
    FILE *punteroFile,*punteroTemp;
    char name[50]={0};
    char jugador[50]={0};
    int plantel=0;
    bool encontrado=false;

    punteroFile = fopen(nombre, "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        if(strcmp(name,club.getNombre().c_str())!=0){
            fwrite(&name,sizeof(char),50,punteroTemp);
            fread(&plantel,sizeof(int),1,punteroFile);
            fwrite(&plantel,sizeof(int),1,punteroTemp);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                fwrite(&jugador,sizeof(char),50,punteroTemp);
            }

        } else{
            encontrado=true;
            strncpy(name, club.getNombre().c_str(),49);
            name[49]='\0';
            fwrite(&name,sizeof(char),50,punteroTemp);
            plantel = club.getPlantel();
            fwrite(&plantel,sizeof(int),1,punteroTemp);
            for(int i=0; i<plantel; i++){
                strncpy(jugador, club.getJugador(i).c_str(),49);
                jugador[49]='\0';
                fwrite(&jugador,sizeof(char),50,punteroTemp);

            }
            fread(&plantel, sizeof(int), 1, punteroFile);
            fseek(punteroFile, plantel * sizeof(char) * 50, SEEK_CUR);
        }


    }

    fclose(punteroFile);
    fclose(punteroTemp);
    if(encontrado){
        remove(nombre);
        rename("temp.dat",nombre);
    } else{
        cout<< "Club no encontrado..." <<endl;
        remove("temp.dat");
        return 0;
    }

    return 1;
}

bool archivoEquipo::mostrarRegistro(){
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
Equipo archivoEquipo::listarRegistro(const char* team){
    FILE* punteroFile;
    Equipo reg;
    char name[50]={0};
    char jugador[50]={0};
    int plantel;
    bool encontrado = false;
    punteroFile=fopen(nombre, "rb");
    if(punteroFile==nullptr){return reg;}
    while(fread(&name,sizeof(char),50,punteroFile)==50){
        if(strcmp(team, name)==0){
            encontrado = true;
            reg.setNombre(name);
            fread(&plantel,sizeof(int),1,punteroFile);
            reg.setPlantel(plantel);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                reg.setJugador(i,jugador);
            }
            fclose(punteroFile);
            return reg;
        } else {
           fread(&plantel,sizeof(int),1,punteroFile);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                reg.setJugador(i,jugador);
            }
        }

    }

    if(!encontrado){
        cout << "Equipo no encontrado..." <<endl;
    }

    fclose(punteroFile);
    return reg;
}

/*bool  archivoEquipo::buscarRegistro(){
    FILE* punteroFile;
    Equipo reg;
    char nombreEquipo[50] = {0};
    char jugador[50] = {0};
    int plantel;
    char nombreBuscado[50];

    cout << "Ingrese el nombre del equipo a buscar: ";
    cin.getline(nombreBuscado, 50);

    punteroFile = fopen(nombre,"rb");
    if (punteroFile == nullptr){return 0;}
    while(fread(&nombreEquipo,sizeof(char),50, punteroFile)== 50){
        if(strcmp(nombreEquipo, nombreBuscado)== 0){
            fread(&plantel, sizeof(int),1,punteroFile);
            reg.setNombre(nombreEquipo);
            reg.setPlantel(plantel);

            for(int i = 0; i < plantel; i++){
                fread(&jugador,sizeof(char), 50,punteroFile);
                reg.setJugador(i, jugador);
            }
                reg.mostrarEquipo();
                fclose(punteroFile);
                return true;
        } else {
        fread(&plantel,sizeof(int),1,punteroFile );
        for(int i = 0; i < plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
        }
    }


    }

    cout<<"EQUIPO NO ENCONTRADO..."<<endl;
    fclose(punteroFile);
    return false;

}
*/
