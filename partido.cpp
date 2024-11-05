#include "partido.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "partido.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


Partido::Partido() {
    goles = new int[2]{0, 0};
}


void Partido::asignarCompetencia(Competencia& comp) {
    cout << "Competencia seleccionada: " << comp.getCompetencia() << endl;
    cout << "Equipos disponibles: " << endl;
    for (int i = 0; i < comp.getNumEquipo(); ++i) {
        cout << i + 1 << ". " << comp.getEquipo(i) << endl;
    }


    cout<<"Seleccione el Primer Equipo: "<<endl;
    getline(cin, equipo1);
    cout<<"Seleccione el Segundo Equipo: "<<endl;
    getline(cin, equipo2);

     bool equipo1Valido = false;
    bool equipo2Valido = false;


 for (int i = 0; i < comp.getNumEquipo(); ++i) {
        if (comp.getEquipo(i) == equipo1) {
            equipo1Valido = true;
        }
        if (comp.getEquipo(i) == equipo2) {
            equipo2Valido = true;
        }
    }

    if (equipo1Valido && equipo2Valido) {
        cout << "Equipos seleccionados: " << equipo1 << " vs " << equipo2 << endl;
    } else {
        cout << "Equipo inexistente.." << endl;
        return;
    }

    cout << "Fecha: ";
    cin >> fecha;
    cin.ignore();


    srand(time(nullptr));
    goles[0] = rand() % 5;
    goles[1] = rand() % 5;

}

string Partido::getEquipo1()
{
    return equipo1;
}
string Partido::getEquipo2()
{
    return equipo2;
}
int Partido::getGoles(int i)
{
    if (i >= 0 && i < 2)
    {
        return goles[i];
    }
    return -1;
}
int Partido::getFecha() const
{
    return fecha;
}

void Partido::setEquipo1(string& valor)
{
    equipo1 = valor;
}
void Partido::setEquipo2(string& valor)
{
    equipo2 = valor;
}
void Partido::setGoles(int valor, int i)
{
    if (i >= 0 && i < 2)
    {
        goles[i] = valor;
    }
}
void Partido::setFecha(int valor)
{
    fecha = valor;
}

void Partido::mostrarPartido() const
{
    system("cls");
    cout << "Fecha: " << fecha << endl;
    cout << "Equipo 1: " << equipo1 << " | Goles: " << goles[0] << endl;
    cout << "Equipo 2: " << equipo2 << " | Goles: " << goles[1] << endl;

    if (goles[0] > goles[1])
    {
        cout << "Ganador: " << equipo1 << endl;
    }
    else if (goles[0] < goles[1])
    {
        cout << "Ganador: " << equipo2 << endl;
    }
    else
    {
        cout << "Resultado: Empate" << endl;
    }
}
