#include <iostream>
#include "funciones.h"

using namespace std;

int tirarDado()
{
    return rand()% 6 + 1;
}

void generarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        v[i] = tirarDado();
    }
}
void escribirTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        cout << "Dado #" << i+1 << ": ";
        cin >> v[i];

    }
}
void mostrarTirada(int v[], int tam)
{
    for (int i= 0; i < tam; i++)
    {
        cout << "Dado #" << i+1 << ":" << v[i] << endl;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------";
}



int SumaDeDados (int v[], int tam)
{
    int contador=0;
    for (int i = 0; i < tam; i++)
    {
        contador += v[i];
    }

    return contador;
}

void ordenarVector(int vec[], int tam)
{
    int aux;
    for(int i = 0; i < tam-1; i++)
    {
        for(int j = i+1; j < tam; j++)
        {
            if(vec[j]<vec[i])
            {
                aux = vec[j];
                vec[j]=vec[i];
                vec[i]=aux;
            }
        }
    }
}

bool Escalera (int v[], int tam)
{
    int cont = 0;
    for(int i = 0; i < tam-1 ; i++)
    {
        if (v[i] < v[i+1])
        {
            cont++;
        }
        if (cont == tam-1)
        {
            return true;
        }

    }
    return false;
}
bool Sexteto (int v[], int tam)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] == tam)
        {
            cont++;
        }
    }
    if (cont == tam)
    {
        return true;
    }
    return false;

}
bool SextetodeX (int v[], int tam)
{
    int cont = 0;
    for (int i = 0; i < tam; i++)
    {
        if (v[i] == v[0] && v[0] != tam)
        {
            cont++;
        }
    }

    if (cont == tam)
    {
        return true;
    }
    return false;
}
void PressEnter()
{

    system("pause");
    cout << "------------------------------------------------------------------------------------------------------------------------";
}
