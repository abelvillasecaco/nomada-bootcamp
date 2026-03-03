// Escribe un programa que realice una búsqueda secuencial recursiva en un arreglo.

#include <iostream>
using namespace std;

int busquedaRecursiva(int arr[], int n, int valor, int indice){
    if(indice >= n)
      return -1;

    if(arr[indice] == valor)
      return indice;

    return busquedaRecursiva(arr, n, valor, indice + 1);
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    int valor;
    cout<<"Ingresa el valor a buscar:";
    cin>>valor;

    int resultado = busquedaRecursiva(arr, n, valor, 0);

    if(resultado != -1){
      cout<<"Encontrado en la posición: "<<resultado<<endl;
    }else{
      cout<<"No encontrado."<<endl;
    }

    return 0;
}
