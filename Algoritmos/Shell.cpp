#include <iostream>
#include <windows.h>
using namespace std;

void ordenarPeorCaso(int a[], int N) {
    for (int i = 0; i < N; i++) {
        a[i] = N - i;
    }

}
void ordenShell(int a[], int N) {
    int i, j, h;
    int v;

    // Se calcula lo que podemos llamar el "salto" inicial
    for (h = 1; h <= N / 9; h = 3 * h + 1)
        ;


    for (; h > 0; h /= 3) {
        // Recorrer el arreglo desde h hasta N-1
        for (i = h; i < N; i++) {
            v = a[i];
            j = i;

            // Desplazar elementos mayores que v en el subgrupo
            while (j >= h && a[j - h] > v) {
                a[j] = a[j - h];
                j -= h;
            }
            // Insertar v
            a[j] = v;
        }
    }
}

int main() {
    int N;
    cout << "Introduzca el numero de datos a ordenar: ";
    cin >> N;
    int a[N]; // Creacion matriz de N elementos
    ordenarPeorCaso(a, N); //Llenamos la matriz de manera descendente
    // Aquí utilizamos el tipo de dato LARGE_INTEGER, utilizado para almacenar los valores del contador de rendimiento
    LARGE_INTEGER start, end, frequency;
    /* Esta función obtiene la frecuencia del contador de rendimiento del sistema y la almacena en la variable frequency.
     * Este valor representa el número de "ticks" por segundo y es necesario para convertir el resultado del contador a una unidad de tiempo legible, como segundos o milisegundos.
     */
    QueryPerformanceFrequency(&frequency); //Función que obtiene la frecuencia del contador de rendimiento del sistema (número de ticks por segundo)
    QueryPerformanceCounter(&start); //Guardado de marca de tiempo inicial
    //FUNCION PARA EL ORDENAMIENTO SHELL
    ordenShell(a, N);
    // Función que termina la marca de tiempo iniciada
    QueryPerformanceCounter(&end);

    // El número total de ticks que el algoritmo consumió se calcula con la resta de (end.QuadPart - start.QuadPart)
    double duration_ms = static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / frequency.QuadPart; // multiplicamos por 1000 para tener el resultado en milisegundos

    // Muestra de resultados en milisegundos
    cout << "\n--- Medicion de tiempo ---\n";
    cout << "Se han generado y ordenado " << N << " datos.\n";
    cout << "Tiempo de CPU consumido: " << duration_ms << " ms.\n";

    return 0;

}
