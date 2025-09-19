#include <iostream>
#include <windows.h>
using namespace std;

void intercambio(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void llenarPeorCaso(int a[], int N) {
    for (int i = 0; i < N; i++) {
        a[i] = N - i;
    }
}

void burbuja(int a[], int N) {
    for (int i = N ; i > 0; i--) {
        for (int j = 0; j < i - 1 ; j++) {
            if (a[j] > a[j + 1]) {
                intercambio(a, j, j + 1);
            }
        }
    }
}
int main() {
    int N;
    cout<<"Ingrese la cantidad de datos: ";
    cin>>N;
    int a[N];
    llenarPeorCaso(a,N);
    LARGE_INTEGER start, end, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    burbuja(a,N);
    QueryPerformanceCounter(&end);
    double duration_ms = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart;

    cout << "\n--- Medicion de tiempo ---\n";
    cout << "Se han generado y ordenado " << N << " datos.\n";
    cout << "Tiempo de CPU consumido: " << duration_ms << " ms.\n";
    return 0;
}

