// Escribe un programa que permita al usuario ingresar un arreglo y buscar un número específico.
// Implementa la búsqueda secuencial como una función.

#include <iostream>
using namespace std;

int busquedaSecuencial(int arr[], int n, int valor){
    for(int i = 0; i < n; i++){
      if(arr[i] == valor){
        return i;
      }
    }
    return -1;
}

int main() {

    int n;

    cout<<"Ingrese el tamaño del arreglo: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cout<<"Ingrese el elemento ["<<i<<"]: ";
      cin>>arr[i];
    }

    int valor;
    cout<<"Ingresa el elemento a buscar: ";
    cin>>valor;

    int posicion = busquedaSecuencial(arr, n, valor);

    if(posicion != -1){
      cout<<"Elemento encontrado en la posición: "<<posicion<<endl;
    }else{
      cout<<"Elemento no encontrado"<<endl;
    }

    return 0;
}
