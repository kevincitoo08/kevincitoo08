#include <iostream>
#include "menu.h"
#include "juegos.h"
using namespace std;

void menu()
{
    int opcion;
    do
    {
        system("cls");
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << "                                                 BIENVENIDO A" <<endl;
        cout << "                                                CIEN O ESCALERA" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "1 - JUGAR           " << endl;
        cout << "2 - PUNTAJES MAXIMOS" << endl;
        cout << "3 - CREDITOS        " << endl;
        cout << "4 - MODO SIMULADO   " << endl;
        cout << "5 - REGLAS DEL JUEGO" << endl;
        cout << "0 - PARA SALIR      " << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------";
        cout << endl;
        cout << "                                                   OPCION: ";
        cin >> opcion;

        switch(opcion)
        {
        case 0:
            return;
            break;
        case 1:
            ElejirJugadores();
            break;
        case 2:

            break;
        case 3:
            Creditos();
            break;
        case 4:
            ModoSimuldado();
            break;
        case 5:
            Reglas();
            break;
        }
    }
    while(true);

}

void ElejirJugadores()
{
    system("cls");
    int jugador;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " " <<endl;
    cout << "Ingrese (1) para un solo jugador                                                         Ingrese (2) para dos jugadores " << endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "                                                   OPCION: ";
    cin >> jugador;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    if (jugador==1)
    {
        ModoUnJugador();
    }
}

void ModoSimuldado()
{
    system("cls");
    int jugador;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << " " <<endl;
    cout << "Ingrese (1) para un solo jugador                                                         Ingrese (2) para dos jugadores " << endl;
    cout << " " <<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------";
    cout << "                                                   OPCION: ";
    cin >> jugador;
    cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

    if (jugador==1)
    {
        ModoUnJugadorSimulado();
    }

}

void Creditos()
{

    system("cls");
    cout << "||====================================================================================||" << endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||                      Fede                                                          ||" << endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||                      Kevin                                                         ||"<< endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||                                                                 GRACIAS POR JUGAR! ||" <<endl;
    cout << "||                                                                                    ||" <<endl;
    cout << "||====================================================================================||" << endl;

    system("pause");
}

void Reglas()
{
    system("cls");
    cout << "                                              REGLAMENTO DEL JUEGO"<<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "El objetivo del juego es obtener al menos 100 puntos en la menor cantidad posible de  rondas, o sacar una escalera"<<endl;
    cout << "en un lanzamiento" << endl;
    cout << "Una ronda esta compuesta por 3 lanzamientos. Un lanzamiento consiste en tirar seis dados y evaluar sus valores para"<<endl;
    cout << "determinar el puntaje."<<endl;
    cout << "El puntaje de un lanzamiento esta determinado por una serie de reglas que figuran en la seccion Combinaciones con"<<endl;
    cout << "puntos."<<endl;
    cout << "El puntaje final de la ronda sera el valor maximo de los puntos obtenidos en los 3 lanzamientos (no la suma de los" <<endl;
    cout << "tres, sino el mas alto), con las siguientes excepciones: "<<endl;
    cout << "Si en un lanzamiento se obtiene escalera el jugador GANA EL PARTIDO en ese momento. "<<endl;
    cout << "Si en un lanzamiento se obtiene una combinacion de 6 dados con valor 6, el puntaje total de la persona se resetea a 0. "<<endl;
    cout << "Para el caso de la opcion para 2 jugadores, cada jugador debe completar una ronda (3 lanzamientos) alternativamente. "<<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    cout << "                                            COMBINACIONES CON PUNTOS"<<endl;
    cout << "                    ________________________________________________________________________"<<endl;
    cout << "                   |Combinación            |Nombre jugada      |    Puntaje otorgado        |"<<endl;
    cout << "                   |_______________________|___________________|____________________________|"<<endl;
    cout << "                   |Menos de 6 dados con   |                   |Suma de los valores de todos|"<<endl;
    cout << "                   | valores iguales       | Suma de dados     |los dados Para el ejemplo   |"<<endl;
    cout << "                   |Ejemplo: 6,5,5,2,2,1   |                   |sería 6+5+5+2+2+1=21        |"<<endl;
    cout << "                   |_______________________|___________________|____________________________|"<<endl;
    cout << "                   |6 dados iguales (menos |Sexteto X (X es    |X*10 puntos                 |"<<endl;
    cout << "                   |para el número 6)      |el número del dado)|                            |"<<endl;
    cout << "                   |_______________________|___________________|____________________________|"<<endl;
    cout << "                   |Escalera. En cualquier |ESCALERA           |Gana la partida en esa ronda|"<<endl;
    cout << "                   |órden(1, 2, 3, 4, 5, 6)|                   |                            |"<<endl;
    cout << "                   |_______________________|___________________|____________________________|"<<endl;
    cout << "                   |Seis 6                 |SEXTETO de 6       |Resetea el puntaje total a 0|"<<endl;
    cout << "                   |                       |                   |                            |"<<endl;
    cout << "                   |_______________________|___________________|____________________________|"<<endl;
    cout << " " <<endl;
    cout << " " <<endl;
    system("pause");
}
