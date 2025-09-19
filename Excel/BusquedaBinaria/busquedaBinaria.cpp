#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

int busquedaBinaria(const vector<int>& arr, int x) {
    int izquierda = 0;
    int derecha = arr.size() - 1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;
        if (arr[medio] == x)
            return medio;
        else if (arr[medio] > x)
            derecha = medio - 1;
        else
            izquierda = medio + 1;
    }
    return -1;
}

int main() {
    int N;
    cout << "Ingresa el valor de N: ";
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) arr[i] = i;

    int objetivo = -1; // fuerza peor caso (no está en el array)

    LARGE_INTEGER frecuencia, inicio, fin;
    QueryPerformanceFrequency(&frecuencia);

    QueryPerformanceCounter(&inicio);
    busquedaBinaria(arr, objetivo);
    QueryPerformanceCounter(&fin);

    double tiempo = static_cast<double>(fin.QuadPart - inicio.QuadPart) / frecuencia.QuadPart;

    cout << "Tiempo de ejecucion con N=" << N << ": " 
        << tiempo << " segundos" << endl;

    return 0;
}
