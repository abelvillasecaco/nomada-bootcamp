// Dado un arreglo de enteros desordenado, implementa el algoritmo de ordenamiento Quick Sort 
// para ordenar el arreglo de menor a mayor.

// { 10, 7, 8, 9, 1 }
// inicio = 0
// fin = 4

#include <iostream>
using namespace std;

void imprimirArreglo(int arr[], int n){
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int particionPivote(int arr[], int inicio, int fin){
    int pivote = arr[fin]; // arr[4] = 1
    int i = inicio - 1; // i = -1

    for(int j = inicio; j < fin; j++){
      if(arr[j] < pivote){
        i++;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i + 1], arr[fin]);

    return i + 1; // La posición final del pivote
}

void quickSort(int arr[], int inicio, int fin){
    if(inicio < fin){

      int ip = particionPivote(arr, inicio, fin);

      quickSort(arr, inicio, ip - 1);
      quickSort(arr, ip + 1, fin);
    }
}

int main() {

    int n;
    cout<<"Ingresa la cantidad de elementos: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout<<"Arreglo ordenado: "<<endl;
    imprimirArreglo(arr, n);

    return 0;
}
