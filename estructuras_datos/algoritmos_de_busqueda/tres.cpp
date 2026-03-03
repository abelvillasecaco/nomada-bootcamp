// Escribe un programa que permita al usuario ingresar un arreglo, lo ordene y
// busque un número usando una función de búsqueda binaria.

#include <iostream>
using namespace std;

void ordenarConBurbuja(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
      for(int j = 0; j < n - i - 1; j++){
        if(arr[j] > arr[j + 1]){
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
}

int busquedaBinaria(int arr[], int n, int valor){
    int inicio = 0, fin = n - 1; // inicio = 3 fin = 4

    while(inicio <= fin){
      int medio = (inicio + fin) / 2; // medio = 3

      if(arr[medio] == valor){ // arr[2] = 7
        return medio;
      }

      if(valor < arr[medio]){
        fin = medio - 1;
      }else{
        inicio = medio + 1;
      }
    }

    return -1;
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    ordenarConBurbuja(arr, n);

    int valor;
    cout<<"Ingresa el valor a buscar: ";
    cin>>valor;

    int pos = busquedaBinaria(arr, n, valor); // 3

    if(pos != -1){
      cout<<"Encontrado en la posición: "<<pos<<endl;
    }else{
      cout<<"No encontrado."<<endl;
    }

    return 0;
}

// 1 2 5 7 9
