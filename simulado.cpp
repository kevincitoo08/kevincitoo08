#include <iostream>
#include "juegos.h"
#include "funciones.h"
#include "menu.h"
using namespace std;

void ModoUnJugadorSimulado()
{
    const int TAM = 6;
    int tirada[TAM];
    int ronda = 1;
    int PuntosAct = 0;
    int puntos = 0;
    string nombre;

    cout << "Ingrese su nombre de jugador: ";
    cin.ignore();

    getline(cin, nombre);
    cout << " " <<endl;

    system("cls");

    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "                                               COMIENZA LA RONDA #" << ronda <<endl;

    while (PuntosAct <= 100)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre << "     |    RONDA #" << ronda << "    |     PUNTAJE ACTUAL: " << PuntosAct << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";

            escribirTirada (tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            puntos = SumaDeDados (tirada, TAM);
            Sexteto6(tirada, TAM);
            PuntosAct += puntos;
            if (Escalera(tirada, TAM) == true)
            {
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (Sexteto6(tirada, TAM) == true)
            {
                puntos = 0;
                PuntosAct = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
            }
            else
            {
                cout << "LA TIRADA SUMA: " << puntos << " PUNTOS" <<endl;
                system("pause");
            }
            if (PuntosAct > 100 )
            {
                break;
            }
        }
        system("cls");
        if (PuntosAct < 100)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                           LA PUNTUACION DE LA RONDA # " << ronda << " es: " << PuntosAct<< endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            ronda++;
            system("pause");
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "                                               COMIENZA LA RONDA #" << ronda <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
        }
    }
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "                           FELICIDADES HA GANADO!!! =)" <<endl;
    cout << "                           SU PUNTUACION ES: " << PuntosAct <<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    system("pause");
}


