/*Shell Sort
Nombre: Erik Villarreal
Fecha: 8 de diciembre 2022
*/
#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>

using namespace std;

double ShellSort(int[], int);
void create(int[], int);
void imprimir(int[], int);
void menu(int);
void create_random(int array[], int);

double time_exe;

long getTime()
{
    struct timeval inicio;
    gettimeofday(&inicio, NULL);
    return inicio.tv_sec * 5000 + inicio.tv_usec;
}

int main()
{
    srand(time(NULL));
    bool salida = false;
    do
    {
        int dim = 100 + rand() % (1001 - 100);
        int V[dim];
        int op;
        bool repetir = false;
        do
        {
            menu(dim);
            cout << "Ingrese una opcion: ";
            cin >> op;
            switch (op)
            {
            case 1:
                cout << "***INGRESO DE DATOS***" << endl;
                create_random(V, dim);
                cout << "Vector cargado..." << endl;
                system("pause");
                break;
            case 2:
                cout << "***ORDENANDO VECTOR***" << endl;
                time_exe = ShellSort(V, dim);
                cout << "Tiempo empleado: " << time_exe << " segundos." << endl;
                system("pause");
                break;
            case 3:
                cout << "***VECTOR***" << endl;
                imprimir(V, dim);
                system("pause");
                break;
            case 4:
                cout << endl << "Saliendo del programa..." << endl;
                repetir = true;
                break;
            case 5:
                cout << endl << "Saliendo del programa..." << endl;
                repetir = true;
                salida = true;
                break;
            default:
                cout << "***OPCION INVALIDA - INGRESE NUEVAMENTE***" << endl;
                system("pause");
                break;
            }
        } while (!repetir);
    } while (!salida);
    return 0;
}

void menu(int dim)
{
    system("cls");
    cout << "\t***Shell Sort en vector de " << dim << " datos***" << endl << endl;
    cout << "1. Ingresar vector" << endl;
    cout << "2. Ordenar vector" << endl;
    cout << "3. Presentar vectores" << endl;
    cout << "4. Repetir" << endl;
    cout << "5. SALIR" << endl;
}

void create(int V[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Elemento [" << i + 1 << "]: ";
        cin >> V[i];
    }
}

void imprimir(int V[], int n)
{
    cout << endl;
    cout << "\t|------------------|" << endl;
    cout << "\t|      VECTOR      |" << endl;
    cout << "\t|------------------|" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i + 1 << "]: " << V[i] << endl;
    }
}

double ShellSort(int V[], int dim)
{
    long inicio = getTime();
    double timeSec;
    long timeMicroSec;
    double exe_time;
    cout << "SE ORDENARAN LOS DATOS..." << endl;
    system("pause");
    int cont = 1;
    for (int i = dim / 2; i > 0; i = i / 2)
    {
        for (int j = i; j < dim; j++)
        {
            for (int k = j - i; k >= 0; k = k - i)
            {
                if (V[k] < V[k + i])
                {
                    break;
                }
                else
                {
                    int temp = V[k + i];
                    V[k + i] = V[k];
                    V[k] = temp;
                    cout << "Cargando..." << i << endl;
                    cont++;
                }
                cout << "\e[A";
            }
        }
    }
    cout << "Vector ordenado con: " << cont++ << " iteraciones..." << endl;
    long final = getTime();
    timeMicroSec = final - inicio;
    timeSec = timeMicroSec * pow(10, -6);
    exe_time = timeSec;
    return exe_time;
}

void create_random(int array[], int dim)
{
    for (int i = 0; i < dim; i++)
    {
        array[i] = 1 + rand() % (10000+1 - 1);
        cout << "[" << i + 1 << "]: " << array[i] << endl;
    }
}