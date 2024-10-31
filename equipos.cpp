#include "equipos.h"
#include <iostream>
#include <cstring>
using namespace std;

// Constructor
Equipo::Equipo(){
    nombre="Undefined";
    ///directorTecnico = "Undefinded"
    plantel=-1;
}

void Equipo::cargar(){
    cout << "Ingrese nombre del Equipo: ";
    getline(cin,nombre);
   /* cout << "Ingrese el director tecnico: ";
    cin >> directorTecnico; */
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
///string Equipo::getDirectorTecnico(){return directorTecnico;}
int  Equipo::getPlantel(){return plantel;}
void  Equipo::setNombre(string nombre){this->nombre=nombre;}
///void Equipo::setDirectorTecnico(string directorTecnico){this->directorTecnico=directorTecnico;}
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
///    cout << "Director Tecnico: " <<directorTecnico <<endl;
    cout << "Plantel: " << plantel <<endl;
    for(int i=0; i<plantel; i++){
        cout << "Jugador numero #" << i+1 << ": " << jugadores[i] <<endl;
    }
}

archivoEquipo::archivoEquipo(const char* nombre="Equipos.dat"){
    strcpy(this->nombre, nombre);
}

bool archivoEquipo::agregarRegistro(Equipo reg){
    FILE *punteroFile;
    Equipo lista;
    int escribio;
    int plantel;
    char jugador[50]={0};
    char name[50]={0};


    punteroFile = fopen(nombre, "rb+");
    if (punteroFile == nullptr){
        punteroFile = fopen(nombre, "wb+");
        if(punteroFile==nullptr){
            fclose(punteroFile);
            return 0;
        }
    }

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        if(name==reg.getNombre()){
            cout << "Equipo ya ingresado..." <<endl;
            return 0;
        }
        fread(&plantel,sizeof(int),1,punteroFile);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
        }
    }
    fclose(punteroFile);

    punteroFile = fopen(nombre, "ab");
    if (punteroFile == nullptr){return false;}


    strncpy(name, reg.getNombre().c_str(), 49);
    name[49]='\0';
    escribio=fwrite(name,sizeof(char),50,punteroFile);
    plantel= reg.getPlantel();
    escribio=fwrite(&plantel,sizeof(int),1,punteroFile);
    for(int i=0; i<reg.getPlantel(); i++){
        strncpy(jugador, reg.getJugador(i).c_str(), 49);
        jugador[49]='\0';
        escribio=fwrite(jugador,sizeof(char),50,punteroFile);
    }
    fclose(punteroFile);
    return escribio;
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
            for(int i=0; i<plantel; i++){
                fread(&jugador, sizeof(char),50,punteroFile);
            }
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
Equipo archivoEquipo::buscarEquipo(const char* team){
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
            }
        }

    }

    if(!encontrado){
        cout << "Equipo no encontrado..." <<endl;
    }

    fclose(punteroFile);
    return reg;
}

Equipo archivoEquipo::buscarJugador(const char* player){
    FILE* punteroFile;
    Equipo reg;
    char name[50]={0};
    char jugador[50]={0};
    int plantel;
    bool encontrado = false;
    punteroFile=fopen(nombre, "rb");
    if(punteroFile==nullptr){return reg;}
    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg.setNombre(name);
        fread(&plantel,sizeof(int),1,punteroFile);
        reg.setPlantel(plantel);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
            reg.setJugador(i,jugador);
            if(strcmp(player, jugador)==0){
                encontrado = true;
            }
        }
        if(encontrado){
            fclose(punteroFile);
            return reg;
        }
    }

    if(!encontrado){
        cout << "Jugador no encontrado..." <<endl;
    }

    fclose(punteroFile);
    reg.setNombre(" ");
    reg.setPlantel(0);
    return reg;
}

Equipo archivoEquipo::buscarPlantel(int quantity){
    FILE* punteroFile;
    Equipo reg;
    char name[50]={0};
    char jugador[50]={0};
    int plantel;
    bool encontrado = false;
    punteroFile=fopen(nombre, "rb");
    if(punteroFile==nullptr){return reg;}
    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg.setNombre(name);
        fread(&plantel,sizeof(int),1,punteroFile);
        reg.setPlantel(plantel);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
            reg.setJugador(i,jugador);
        }
        if(quantity==plantel){
            encontrado = true;
            reg.mostrarEquipo();
        }

    }

    if(!encontrado){
        cout << "Plantel no encontrado..." <<endl;
    }

    fclose(punteroFile);
    return reg;
}


bool archivoEquipo::ordenadosEquipo(bool valor){
    FILE *punteroFile,*punteroTemp;
    Equipo *reg;
    Equipo temp;
    int iteraciones=0;
    int x=0;
    char name[50]={0};
    char jugador[50]={0};
    int plantel=0;

    punteroFile = fopen(nombre, "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&plantel,sizeof(int),1,punteroFile);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
        }
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Equipo[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&plantel,sizeof(int),1,punteroFile);
        reg[x].setPlantel(plantel);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
            reg[x].setJugador(i,jugador);
        }
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
            strncpy(name, reg[i].getNombre().c_str(), 49 );
            fwrite(&name,sizeof(char),50,punteroTemp);
            plantel = reg[i].getPlantel();
            fwrite(&plantel,sizeof(int),1,punteroTemp);
            for(int z=0; z <plantel; z++){
                strncpy(jugador, reg[i].getJugador(z).c_str(), 49);
                fwrite(&jugador,sizeof(char),50,punteroTemp);
                //cout << jugador;
                //cout << "sas";
            }
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
            strncpy(name, reg[i].getNombre().c_str(), 49 );
            fwrite(&name,sizeof(char),50,punteroTemp);
            plantel = reg[i].getPlantel();
            fwrite(&plantel,sizeof(int),1,punteroTemp);
            for(int z=0; z <plantel; z++){
                strncpy(jugador, reg[i].getJugador(z).c_str(), 49);
                fwrite(&jugador,sizeof(char),50,punteroTemp);
                //cout << jugador;
                //cout << "sas";
            }
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove(nombre);
    rename("temp.dat",nombre);

    delete[] reg;

    return 1;
}
bool archivoEquipo::ordenadosPlantel(bool valor){
    FILE *punteroFile,*punteroTemp;
    Equipo *reg;
    Equipo temp;
    int iteraciones=0;
    int x=0;
    char name[50]={0};
    char jugador[50]={0};
    int plantel=0;

    punteroFile = fopen(nombre, "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        fread(&plantel,sizeof(int),1,punteroFile);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
        }
        iteraciones++;
    }

    fseek(punteroFile,0,0);

    reg = new Equipo[iteraciones];

    while(fread(&name,sizeof(char),50,punteroFile)==50){
        reg[x].setNombre(name);
        fread(&plantel,sizeof(int),1,punteroFile);
        reg[x].setPlantel(plantel);
        for(int i=0; i<plantel; i++){
            fread(&jugador,sizeof(char),50,punteroFile);
            reg[x].setJugador(i,jugador);
        }
        x++;
    }

    if(valor==0){

        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getPlantel()>reg[y].getPlantel()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(), 49 );
            fwrite(&name,sizeof(char),50,punteroTemp);
            plantel = reg[i].getPlantel();
            fwrite(&plantel,sizeof(int),1,punteroTemp);
            for(int z=0; z <plantel; z++){
                strncpy(jugador, reg[i].getJugador(z).c_str(), 49);
                fwrite(&jugador,sizeof(char),50,punteroTemp);
                //cout << jugador;
                //cout << "sas";
            }
        }
    } else if (valor==1){
        for(int i=0; i<iteraciones-1; i++){
            for(int y=i+1; y<iteraciones; y++){
                if(reg[i].getPlantel()<reg[y].getPlantel()){
                    temp = reg[i];
                    reg[i] = reg[y];
                    reg[y] = temp;
                }
            }
        }
        for(int i=0; i<iteraciones; i++){
            strncpy(name, reg[i].getNombre().c_str(), 49 );
            fwrite(&name,sizeof(char),50,punteroTemp);
            plantel = reg[i].getPlantel();
            fwrite(&plantel,sizeof(int),1,punteroTemp);
            for(int z=0; z <plantel; z++){
                strncpy(jugador, reg[i].getJugador(z).c_str(), 49);
                fwrite(&jugador,sizeof(char),50,punteroTemp);
                //cout << jugador;
                //cout << "sas";
            }
        }
    }


    fclose(punteroFile);
    fclose(punteroTemp);

    remove(nombre);
    rename("temp.dat",nombre);

    delete[] reg;

    return 1;
}
