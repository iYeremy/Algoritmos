#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

__declspec(noinline) int busquedaBinaria(int a[], int N, int x) {
    int l = 0, r = N - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int main() {
    const int WARMUP = 1000;
    const int REPS = 20000; // ajustar si quieres más/menos precisión
    DWORD_PTR mask = 1; // cpu 0
    SetProcessAffinityMask(GetCurrentProcess(), mask);
    SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);

    LARGE_INTEGER freq;
    QueryPerformanceFrequency(&freq);

    volatile long long sink = 0; // evita optimizaciones: guarda resultados

    for (int N = 10; N <= 1000; N += 10) {
        int* a = new int[N];
        for (int i = 0; i < N; ++i) a[i] = i + 1;
        int x = N + 1;

        // Warm-up
        for (int i = 0; i < WARMUP; ++i) {
            sink += busquedaBinaria(a, N, x);
        }

        // Medición en batch
        LARGE_INTEGER t1, t2;
        QueryPerformanceCounter(&t1);
        for (int i = 0; i < REPS; ++i) {
            sink += busquedaBinaria(a, N, x);
        }
        QueryPerformanceCounter(&t2);

        double total_sec = double(t2.QuadPart - t1.QuadPart) / double(freq.QuadPart);
        double per_call = total_sec / double(REPS);
        cout.setf(ios::fixed);
        cout.precision(9);
        cout << N << "," << per_call << endl;

        delete[] a;
    }

    // usar sink para evitar que el compilador descarte la variable (se imprime al final)
    if (sink == 123456789) cout << "sink\n";
    return 0;
}
