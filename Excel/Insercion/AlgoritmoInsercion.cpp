#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

void Insercion(int a[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        j = i;
        v = a[j];
        while (j > 0 && a[j-1] > v) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

int main() {
    LARGE_INTEGER frecuencia, inicio, fin;
    QueryPerformanceFrequency(&frecuencia);

    int repeticiones = 100;
    int N = 10;

    double total_ms = 0.0;

    for (int r = 0; r < repeticiones; r++) {
        int* A = new int[N];
        for (int i = 0; i < N; i++) {
            A[i] = N - i;
        }

        QueryPerformanceCounter(&inicio);
        Insercion(A, N);
        QueryPerformanceCounter(&fin);

        double tiempo_ms = double(fin.QuadPart - inicio.QuadPart) * 1000.0 / double(frecuencia.QuadPart);
        total_ms += tiempo_ms;

        delete[] A;
    }

    double promedio = total_ms / repeticiones;

    cout << "N,Tiempo(ms)" << endl;
    cout << N << "," << fixed << setprecision(6) << promedio << endl;

    return 0;
}
