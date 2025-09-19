//Encuentra el mcd de dos nmeros usando el algoritmo de Euclides
#include <iostream>
using namespace std;
int mcd(int u, int v){
    int t; //variable t
    while (u>0){ // mientras u sea mayor a 0 
        if (u < v) { //si u es menor a v
            t=u; u=v; v=t; // intercambia u por v
        }
        u=u-v; //resta u-v

    }
    return v; //regresa v
}
main(){
    int x,y;
    while (cin>>x && cin>>y){ //mientras se puedan leer dos nmeros
        int b=x%y; //calcula el valor de x%y
        int a=y%mcd(x,y); //calcula el valor de y%mcd(x,y)
        if (x>0 && y>0) cout << x << " " << y << " " << "El MCD es: "<< mcd(x,y) <<" ,El valor de (u%v) es: "<< b << " ,Este mismo valor es:"<<a <<endl; //si ambos son positivos imprime el mcd
        else cout<<"Error: Ambos nmeros deben ser positivos"<<endl; //si alguno es negativo imprime error
    }
}   