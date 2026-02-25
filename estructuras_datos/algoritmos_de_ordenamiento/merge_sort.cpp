// Dado un arreglo de enteros desordenado, implementa el algoritmo Merge Sort 
// para ordenar el arreglo de menor a mayor.

// {6, 3, 9, 5, 2, 8}
// {6, 3, 9} {5, 2, 8}

// medio = (inicio + fin) / 2

#include <iostream>
using namespace std;

void merge(int arr[], int inicio, int medio, int fin){
    int n1 = medio - inicio + 1; // 3
    int n2 = fin - medio; // 3

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++){
      L[i] = arr[inicio + i];
    }

    for(int j = 0; j < n2; j++){
      R[j] = arr[medio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;

    while(i < n1 && j < n2){
      if(L[i] <= R[j]){
        arr[k] = L[i];
        i++;
      }else{
        arr[k] = R[j];
        j++;
      }
      k++;
    }

    while(i < n1){
      arr[k] = L[i];
      i++;
      k++;
    }

    while(j < n2){
      arr[k] = R[j];
      j++;
      k++;
    }
}

void mergeSort(int arr[], int inicio, int fin){
    if(inicio < fin){
      int medio = (inicio + fin) / 2;
      mergeSort(arr, inicio, medio);
      mergeSort(arr, medio + 1, fin);
      merge(arr, inicio, medio, fin);
    }
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout<<"Arreglo ordenado: "<<endl;
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    }

    return 0;
}
