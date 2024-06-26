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
    int jugada = 1;
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
            cout << "TURNO DE " << nombre << "     |    TIRADA #" << jugada << "    |     PUNTAJE ACTUAL: " << PuntosAct << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";

            escribirTirada(tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            SumaDeDados (tirada,TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
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
            if (SextetodeX(tirada, TAM) == true){
                puntos = tirada[0] * 10;
                PuntosAct += puntos;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                system("pause");
            }
            if (Sexteto(tirada, TAM) == true)
            {
                puntos = 0;
                PuntosAct = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false){
                puntos = SumaDeDados (tirada, TAM);
                PuntosAct += puntos;
                cout << "LA TIRADA SUMA: " << puntos << " PUNTOS" <<endl;
                system("pause");
            }
            if (PuntosAct > 100 )
            {
                break;
            }
            jugada++;
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
