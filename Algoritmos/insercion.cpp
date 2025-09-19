#include <iostream>
using namespace std;

void Insercion(int a[],int N){
    int i,j,v;
    for (i=1;i<N;i++){ 
        j=i;
        v=a[j];
        while(j>0 && a[j-1]>v){
            a[j]=a[j-1];
            j--;
        }
        a[j]=v;
    }
}
int main(){
    int A[10]={5,3,8,6,2,7,4,1,9,0};
    int tamanio=sizeof(A)/sizeof(A[0]);
    Insercion(A,tamanio);
    for(int i=0;i<10;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}