// Dado un arreglo de enteros desordenado, se debe implementar el algoritmo de ordenamiento 
// Insertion Sort para organizar los elementos de menor a mayor.

// [5, 3, 4, 1]

#include <iostream>
using namespace std;

void mostrarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
      int elementoInsertar = arr[i];
      int j = i - 1;

      while(j >= 0 && arr[j] > elementoInsertar){
        arr[j + 1] = arr[j];
        j--;
        cout<<"Paso Víctor"<<i<<": ";
        mostrarArreglo(arr, n);
      }

      arr[j + 1] = elementoInsertar;

      cout<<"Paso "<<i<<": ";
      mostrarArreglo(arr, n);

    }
}


int main() {

    int n;
    cout<<"Ingresa la cantidad de elementos: ";
    cin>>n;

    int arr[n];

    cout<<"Ingresa los elementos: "<<endl;
    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    insertionSort(arr, n);

    cout<<"Arreglo ordenado: "<<endl;
    mostrarArreglo(arr, n);

    return 0;
}
