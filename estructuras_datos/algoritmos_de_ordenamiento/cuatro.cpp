// Dado un arreglo de números y un entero k, utiliza el método de selección
// para encontrar los k menores elementos del arreglo.

// [2, 5, 1, 6]

// para i desde 0 hasta k - 1
// minIndex = i

#include <iostream>
using namespace std;

void leerArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++){
      cout<<"Ingresa a["<<i<<"]: ";
      cin>>arr[i];
    }
}

void mostrarArreglo(int arr[], int n) {
    for(int i = 0; i < n; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void seleccionKMenores(int arr[], int n, int k) {
    for(int i = 0; i < k; i++){
      int minIndex = i;

      for(int j = i + 1; j < n; j++){
        if(arr[j] < arr[minIndex]){
          minIndex = j;
        }
      }

      int aux = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = aux;
    }
}


int main() {

    int n;
    cout<<"Ingresa n: ";
    cin>>n;

    int arr[n];

    leerArreglo(arr, n);

    int k;
    cout<<"Ingresa k: ";
    cin>>k;

    cout<<"Arreglo original: "<<endl;
    mostrarArreglo(arr, n);

    seleccionKMenores(arr, n, k);

    mostrarArreglo(arr, n);

    cout<<"Los "<<k<<" menores elementos son: ";
    for(int i = 0; i < k; i++){
      cout<<arr[i]<<" ";
    }
    cout<<endl;


    return 0;
}
