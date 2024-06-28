#include <iostream>
#include "juegos.h"
#include "funciones.h"
#include "menu.h"
#include "rlutil.h"

using namespace std;



void ModoUnJugador()
{
    const int TAM = 6;
    int tirada[TAM];
    int ronda = 1;
    int PuntosAct = 0;
    int puntos = 0;
    int lanzamiento = 1;
    string nombre;

    cout << "Ingrese su nombre de jugador: ";
    cin.ignore();

    getline(cin, nombre);
    cout << " " <<endl;

    system("cls");

    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "                                               COMIENZA LA RONDA # " << ronda <<endl;

    while (PuntosAct <= 100)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre << "     |     LANZAMIENTO # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << PuntosAct << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";

            generarTirada(tirada, TAM);
            mostrarTirada(tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
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
            if (Sexteto(tirada, TAM) == true)
            {
                puntos = 0;
                PuntosAct = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                puntos = tirada[0] * 10;
                PuntosAct += puntos;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                puntos = SumaDeDados (tirada, TAM);
                PuntosAct += puntos;
                cout << "LA TIRADA SUMA: " << puntos << " PUNTOS" <<endl;
                system("pause");
            }
            if (PuntosAct > 100)
            {
                rlutil::anykey();
            }
            lanzamiento++;
        }
        lanzamiento = 1;
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
    cout << "                           FELICIDADES " << nombre <<  " GANASTE!!! =)" <<endl;
    cout << "                           SU PUNTUACION ES: " << PuntosAct <<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    system("pause");
}

void ModoDosJugadores()
{

    const int TAM = 6;
    int tirada[TAM];
    int ronda = 1;
    int PuntosAct1 = 0;
    int puntos1 = 0;
    int PuntosAct2 = 0;
    int puntos2 = 0;
    int lanzamiento = 1;
    string nombre1;
    string nombre2;

    cout << "Ingrese nombre del jugador #1 : ";
    cin.ignore();
    getline(cin, nombre1);
    cout << " " <<endl;
    cout << "Ingrese nombre del jugador #2 : ";
    getline(cin, nombre2);
    cout << "" <<endl;
    system("pause");
    system("cls");

    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "      COMIENZA LA RONDA #" << ronda << ", " << nombre1 << " COMIENZA CON EL JUEGO!" << endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    system("pause");
    system("cls");
    while ( PuntosAct1 < 100 || PuntosAct2 < 100)
    {
        for (int i = 0; i < 3; i++)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << "TURNO DE " << nombre1 << "     |    LANZAMIENTO # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << PuntosAct1 << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            generarTirada(tirada, TAM);
            mostrarTirada(tirada, TAM);
            ordenarVector(tirada, TAM);
            Escalera (tirada, TAM);
            SumaDeDados (tirada,TAM);
            Sexteto(tirada, TAM);
            SextetodeX(tirada, TAM);
            if (Escalera(tirada, TAM) == true)
            {
                system("pause");
                system("cls");
                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "" <<endl;
                cout << "                                                    ESCALERA GANASTE!" << endl;
                cout << "                                                       FELICIDAES " << nombre1 <<endl;
                cout << "" <<endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                system("pause");
                menu();
            }
            if (SextetodeX(tirada, TAM) == true)
            {
                puntos1 = tirada[0] * 10;
                PuntosAct1 += puntos1;
                cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                cout << "LA TIRADA SUMA: " << puntos1 << " PUNTOS" <<endl;
                system("pause");
            }
            if (Sexteto(tirada, TAM) == true)
            {
                puntos1 = 0;
                PuntosAct1 = 0;
                cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                system("pause");
            }
            if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
            {
                puntos1 = SumaDeDados (tirada, TAM);
                PuntosAct1 += puntos1;
                cout << "SUMA DE DADOS!" <<endl;
                cout << "LA TIRADA SUMA: " << puntos1 << " PUNTOS" <<endl;
                system("pause");
            }
          if (PuntosAct1 > 100 )
            {
                system("cls");
                cout << " PUNTAJE DE " << nombre1 << "es: " << PuntosAct1 << "EN EL LANZAMIENTO # " << lanzamiento << endl;
                system("pause");
                break;
            }
            lanzamiento++;
        }
        lanzamiento = 1;
        system("cls");
        if (PuntosAct1 < 100)
        {
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << "                                                   RONDA # " << ronda <<endl;
            cout << "                                              PROXIMO TURNO: " << nombre2 <<endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                             PUNTAJE " << nombre1 << ": " << PuntosAct1 << " PUNTOS" <<endl;
            cout << "                                             PUNTAJE " << nombre2 << ": " << PuntosAct2 << " PUNTOS" <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("pause");
            system("cls");
        }

            for (int i = 0; i < 3; i++)
            {


                cout << "------------------------------------------------------------------------------------------------------------------------";
                cout << "TURNO DE " << nombre2 << "     |    LANZAMIENTO # " << lanzamiento << "    |     PUNTAJE ACTUAL: " << PuntosAct2 << endl;
                cout << "------------------------------------------------------------------------------------------------------------------------";
                generarTirada(tirada, TAM);
                mostrarTirada(tirada, TAM);
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
                    cout << "                                                       FELICIDAES" << nombre2 <<endl;
                    cout << "" <<endl;
                    cout << "------------------------------------------------------------------------------------------------------------------------";
                    system("pause");
                    menu();
                }
                if (SextetodeX(tirada, TAM) == true)
                {
                    puntos2 = tirada[0] * 10;
                    PuntosAct2 += puntos2;
                    cout << "SEXTETO DE " << tirada[0] << " =D!!!" <<endl;
                    cout << "LA TIRADA SUMA: " << puntos2 << " PUNTOS" <<endl;
                    system("pause");
                }
                if (Sexteto(tirada, TAM) == true)
                {
                    puntos2 = 0;
                    PuntosAct2 = 0;
                    cout << "SEXTETO DE SEIS! SE REINICIA EL PUNTAJE!"<<endl;
                    system("pause");
                }
                if (SextetodeX(tirada, TAM) == false && Sexteto(tirada, TAM) == false)
                {
                    puntos2 = SumaDeDados (tirada, TAM);
                    PuntosAct2 += puntos2;
                    cout << "SUMA DE DADOS!";
                    cout << "LA TIRADA SUMA: " << puntos2 << " PUNTOS" <<endl;
                    system("pause");
                }
               if (PuntosAct2 > 100 )
                {

                    system("cls");
                    cout << " PUNTAJE DE " << nombre2 << "es: " << PuntosAct2 << "EN EL LANZAMIENTO # " << lanzamiento << endl;
                    system("pause");
                    break;
                }
                lanzamiento++;
            }
            lanzamiento = 1;
            system("cls");
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << "                                                   RONDA # " << ronda <<endl;
            cout << "                                              PROXIMO TURNO: " << nombre1 <<endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                             PUNTAJE " << nombre1 << ": " << PuntosAct1 << " PUNTOS" <<endl;
            cout << "                                             PUNTAJE " << nombre2 << ": " << PuntosAct2 << " PUNTOS" <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("pause");
            system("cls");
            ronda++;
            if (PuntosAct2 < 100){
            cout << "------------------------------------------------------------------------------------------------------------------------";
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "                                             COMIENZA LA RONDA # " << ronda << endl;
            cout << " " <<endl;
            cout << " " <<endl;
            cout << "------------------------------------------------------------------------------------------------------------------------";
            system("pause");
            system("cls");

    }
    }
    if (PuntosAct1 > PuntosAct2)
    {
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "                           FELICIDADES " <<  nombre1 << " GANASTE"<<endl;
        cout << "                           SU PUNTUACION ES: " << PuntosAct1 <<endl;
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        system("pause");
    }
    else
    {
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "                           FELICIDADES " <<  nombre2 << " GANASTE"<<endl;
        cout << "                           SU PUNTUACION ES: " << PuntosAct2 <<endl;
        cout << " " <<endl;
        cout << " " <<endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        system("pause");
    }
}
