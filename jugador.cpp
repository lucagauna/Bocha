#include "jugador.h"
#include <iostream>
#include <cstring>
using namespace std;

Jugador::Jugador(){
    strcpy(nombre, "Undefined");
    strcpy(equipo, "Undefined");
    idJugador = -1;
    edad=-1;
    strcpy(posicion, "Undefined");
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
    cin.getline(nombre,49);
    while(!verificacionJugador){
        fseek(punteroFile,0,0);
        while(fread(&team,sizeof(char),50,punteroFile)==50){
            fread(&plantel,sizeof(int),1,punteroFile);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                if(strcmp(jugador,nombre)==0){
                    verificacionJugador=true;
                }
            }

        }
        if(!verificacionJugador){
            cout<<"Nombre del Jugador no ingresado en el sistema: ";
            cin.getline(nombre,49);
        }
    }

    cout << "Ingrese el ID del Jugador: ";
    cin >> idJugador;

    if(idJugador<=0){
        cout << "ID del Jugador incorrecta, menor a 1 (1-En Adelante): ";
        cin >> idJugador;
    }

    cin.ignore();

    cout<<"Ingrese el equipo del Jugador: ";
    cin.getline(equipo,49);
    while(verificacionEquipo==false){
        fseek(punteroFile,0,0);
        while(fread(&team,sizeof(char),50,punteroFile)==50){
            fread(&plantel,sizeof(int),1,punteroFile);
            for(int i=0; i<plantel; i++){
                fread(&jugador,sizeof(char),50,punteroFile);
                if(strcmp(equipo,team)==0 && strcmp(jugador,nombre)==0){
                    verificacionEquipo=true;
                }
            }

        }
        if(!verificacionEquipo){
            cout<<"Equipo del Jugador incorrecto o inexistente en el sistema: ";
            cin.getline(equipo,49);
        }
    }
    fclose(punteroFile);

    cout<<"Ingrese la edad del Jugador: ";
    cin>>edad;
    cin.ignore();

    while(edad<15||edad>50){
        cout<<"Edad del jugador imposible (15-50): ";
        cin>>edad;
        cin.ignore();
    }

    cout<<"Ingrese la posicion del Jugador: ";
    cin.getline(posicion,49);
    while(strcmp(posicion,"Delantero")!=0&&strcmp(posicion,"Mediocampista")!=0&&strcmp(posicion,"Defensor")!=0&&strcmp(posicion,"Arquero")!=0){
        cout<<"Posicion del Jugador incorrecta (Delantero, Mediocampista, Defensor, Arquero): ";
        cin.getline(posicion,49);
    }

    cout<<"Ingrese la dorsal del jugador: ";
    cin>>numero;
    while(numero<1||numero>99){
        cout<<"Dorsal del jugador incorrecta (1-99): ";
        cin>>numero;
    }

    cout<<"Ingrese los goles anotados por el jugador: ";
    cin>>goles;
    while(goles<0){
        cout<<"Goles anotados por el jugador incorrectos (0-En Adelante): ";
        cin>>goles;
    }

    cout<<"Ingrese las asistencias realizadas por el jugador: ";
    cin>>asistencias;
    while(asistencias<0){
        cout<<"Asistencias anotadas por el jugador incorrectos (0-En Adelante): ";
        cin>>asistencias;

    }


}

int Jugador::getIdJugador(){
    return idJugador;
}

char* Jugador::getNombre(){
    return nombre;
}

char* Jugador::getEquipo(){
    return equipo;
}

int Jugador::getEdad(){
    return edad;
}

char* Jugador::getPosicion(){
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

void Jugador::setIdJugador(int ID){
    idJugador=ID;
}

void Jugador::setNombre(char* nombre) {
    strcpy(this->nombre,nombre);
}

void Jugador::setEquipo(char* equipo) {
    strcpy(this->equipo,equipo);
}

void Jugador::setEdad(int edad) {
    if (edad >= 0 && edad < 100) {
        this->edad = edad;
    } else {
        cout << "Error: Edad Incoherente!!" << endl;
    }
}

void Jugador::setPosicion(char* posicion) {
    if(strcmp(posicion,"Delantero")==0&&strcmp(posicion,"Mediocampista")==0&&strcmp(posicion,"Defensor")==0&&strcmp(posicion,"Arquero")==0){
        strcpy(this->posicion,posicion);
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
    Jugador reg;
    int n;



    punteroFile = fopen("Jugadores.dat", "rb+");
    if (punteroFile == nullptr){
        punteroFile = fopen("Jugadores.dat", "wb+");
        if(punteroFile==nullptr){
            fclose(punteroFile);
            return 0;
        }
    }

    while(fread(&reg,sizeof(jugador),1,punteroFile)==1){
        if(strcmp(reg.getNombre(),jugador.getNombre())==0){
            cout << "Jugador ya ingresado..." <<endl;
            return 0;
        }
        while(reg.getIdJugador() == jugador.getIdJugador() ||  jugador.getIdJugador()<=0){
            cout << "Reingresar el ID del jugador: ";
            cin >> n;
            jugador.setIdJugador(n);
            fseek(punteroFile,0,0);
        }
    }
    fclose(punteroFile);

    punteroFile = fopen("Jugadores.dat", "ab");
    if (punteroFile == nullptr){return false;}

    fwrite(&jugador,sizeof(Jugador),1,punteroFile);

    fclose(punteroFile);
    return true;
    system("pause");
}

bool archivoJugador::eliminarJugador(char* nombreJugador) {
    FILE *punteroFile, *punteroTemp;
    Jugador reg;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return false;}
    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {return false;}

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (strcmp(reg.getNombre(), nombreJugador) != 0) {
            fwrite(&reg,sizeof(Jugador),1,punteroTemp);
        } else {
            encontrado = true;
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
    Jugador reg;
    bool encontrado = false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return false;}
    punteroTemp = fopen("temp.dat", "wb");
    if (punteroTemp == nullptr) {return false;}

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {

        if (strcmp(reg.getNombre(), jugador.getNombre()) == 0) {
            encontrado = true;
            fwrite(&jugador, sizeof(Jugador), 1, punteroTemp);
        } else {
            fwrite(&reg, sizeof(Jugador), 1, punteroTemp);
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

    while(fread(&reg,sizeof(Jugador),1,punteroFile)==1){
        reg.mostrarJugador();
    }
    fclose(punteroFile);
    return true;
}

Jugador archivoJugador::buscarJugador(char* nombreJugador){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (strcmp(reg.getNombre(), nombreJugador) == 0) {
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

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (num == reg.getIdJugador()) {
            fclose(punteroFile);
            return reg;
        }
    }

    cout << "Jugador no encontrado..." << endl;
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarEquipo(char* equipo){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    bool encontrado = false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while(fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (strcmp(reg.getEquipo(), equipo) == 0) {
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Equipo no encontrado..." << endl;
    }
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarEdad(int age){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (reg.getEdad()==age){
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Edad no encontrada..." << endl;
    }
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarPosicion(char* position){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (strcmp(reg.getPosicion(),position)==0) {
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Posicion no encontrada..." << endl;
    }
    fclose(punteroFile);
    return fallo;
}
Jugador archivoJugador::buscarDorsal(int dorsal){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (reg.getNumero()==dorsal) {
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Dorsal no encontrada..." << endl;
    }
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarGoles(int goals){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (reg.getGoles()==goals) {
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Goles no encontrades..." << endl;
    }
    fclose(punteroFile);
    return fallo;
}

Jugador archivoJugador::buscarAsistencias(int asissts){
    FILE *punteroFile;
    Jugador reg;
    Jugador fallo;
    bool encontrado=false;

    punteroFile = fopen("Jugadores.dat", "rb");
    if (punteroFile == nullptr) {return reg;};

    while (fread(&reg, sizeof(Jugador), 1, punteroFile) == 1) {
        if (asissts==reg.getAsistencias()) {
            encontrado=true;
            reg.mostrarJugador();
        }
    }
    if(!encontrado){
        cout << "Asistencias no encontradas..." << endl;
    }
    fclose(punteroFile);
    return fallo;
}

bool archivoJugador::ordenadosNombre(bool valor){
    FILE *punteroFile,*punteroTemp;
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((strcmp(reg[i].getNombre(),reg[y].getNombre())>0 && valor==0) || (strcmp(reg[i].getNombre(),reg[y].getNombre())<0 && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
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
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((reg[i].getIdJugador()>reg[y].getIdJugador() && valor==0) || (reg[i].getIdJugador()<reg[y].getIdJugador() && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
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
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((strcmp(reg[i].getEquipo(),reg[y].getEquipo())>0 && valor==0) || (strcmp(reg[i].getEquipo(),reg[y].getEquipo())<0 && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
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
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((reg[i].getEdad()>reg[y].getEdad() && valor==0) || (reg[i].getEdad()<reg[y].getEdad() && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
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
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((reg[i].getNumero()>reg[y].getNumero() && valor==0) || (reg[i].getNumero()<reg[y].getNumero() && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
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
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((reg[i].getGoles()>reg[y].getGoles() && valor==0) || (reg[i].getGoles()<reg[y].getGoles() && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
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
    Jugador arch;
    Jugador* reg;
    Jugador temp;
    int TAM=0;
    int x=0;

    punteroFile = fopen("Jugadores.dat", "rb");
    if(punteroFile==nullptr){return 0;}

    punteroTemp=fopen("temp.dat", "wb");
    if(punteroTemp==nullptr){return 0;}

    fseek(punteroFile,0,2);
    TAM = ftell(punteroFile) / sizeof(Jugador);
    fseek(punteroFile,0,0);

    reg = new Jugador[TAM];

    while(fread(&arch,sizeof(Jugador),1,punteroFile)==1){
        reg[x] = arch;
        x++;
    }

    for(int i=0; i<TAM-1; i++){
        for(int y=i+1; y<TAM; y++){
            if((reg[i].getAsistencias()>reg[y].getAsistencias() && valor==0) || (reg[i].getAsistencias()<reg[y].getAsistencias() && valor==1)){
                temp = reg[i];
                reg[i] = reg[y];
                reg[y] = temp;
            }
        }
    }
    for(int i=0; i<TAM; i++){
        fwrite(&reg[i],sizeof(Jugador),1,punteroTemp);
    }

    fclose(punteroFile);
    fclose(punteroTemp);

    remove("Jugadores.dat");
    rename("temp.dat","Jugadores.dat");

    delete[] reg;

    return 1;
}
