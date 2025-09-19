#include <iostream>

using namespace std;

const int N = 1000;
main()
{
    int i, j, a[N+1];

    // Inicialización del arreglo
    for (a[1] = 0, i = 2; i <= N; i++) 
        a[i] = 1;

    // Marcamos los múltiplos como no primos
    for (i = 2; i <= N/2; i++)
        for (j = 2; j <= N/i; j++)
            a[i*j] = 0;

    // Imprimimos los primos
    for (i = 1; i <= N; i++)
        if (a[i]) cout << i << ' ';

    cout << '\n';
}
