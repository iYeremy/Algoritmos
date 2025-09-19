#include <iostream>
#include <windows.h>
using namespace std;

int busquedaBinaria(int a[], int N, int x) {
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
    LARGE_INTEGER freq, start, end;
    QueryPerformanceFrequency(&freq);

    for (int N = 10; N <= 1000; N += 10) {
        int* a = new int[N];
        for (int i = 0; i < N; i++) a[i] = i + 1;
        int x = N + 1;

        QueryPerformanceCounter(&start);
        busquedaBinaria(a, N, x);
        QueryPerformanceCounter(&end);

        double tiempo = (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
        cout << N << "," << tiempo << endl;

        delete[] a;
    }

    return 0;
}
