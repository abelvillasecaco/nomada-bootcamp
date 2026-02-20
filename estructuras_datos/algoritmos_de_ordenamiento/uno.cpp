// Dado un arreglo de números enteros, ordénalo de menor a mayor utilizando el método burbuja o selección.

// int arreglo = {5, 1, 4, 2, 8}
// = {1, 5, 4, 2, 8}
// = {1, 4, 5, 2, 8}

// Leer n
// para i desde 0 hasta n - 2
//  para j desde 0 hasta n - 2 - i
//     si arr[j] > a[j + 1]:
//        intercambiar arr[j] y arr[j + 1]
// mostrar arr ordenado

#include <iostream>
using namespace std;

void leerArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++){
      cout<<"Ingresa a["<<i<<"]: ";
      cin>>arr[i];
    }
}

void burbuja(int arr[], int n) {

    for(int i = 0; i < n - 1; i++){ // 4
        for(int j = 0; j < n - 1 - i; j++){ // 4
          if(arr[j] > arr[j + 1]){ // 5 > 4
            int aux = arr[j]; // 5
            arr[j] = arr[j + 1]; // 4
            arr[j + 1] = aux; // 5
          }
        }
    }
}

void mostrarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {

    int n;
    cout<<"Ingresa la cantidad de elementos: ";
    cin>>n; // 5

    int arr[n];

    leerArreglo(arr, n);

    burbuja(arr, n);

    cout<<"Arreglo ordenado: ";
    mostrarArreglo(arr, n);

    return 0;
}
