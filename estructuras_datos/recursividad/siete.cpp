// Calcula la suma de los elementos de un arreglo. Usa funciones recursivas.

// {5, 2, 7, 1}
// sumaArreglo(arr, n) = arr[n - 1] + sumaArreglo (arr, n - 1)
// Caso base => n = 0

#include <iostream>
using namespace std;

int sumaArreglo(int arr[], int n){
    if(n == 0)
      return 0;

    return arr[n - 1] + sumaArreglo(arr, n - 1);
    // Primera llamada:
    // sumaArreglo(arr, 4)
    // return arr[3] + sumaArreglo(arr, 3)
    // => 1 + sumaArreglo(arr, 3)

    // Segunda llamada:
    // sumaArreglo(arr, 3)
    // return arr[2] + sumaArreglo(arr, 2)
    // => 7 + sumaArreglo(arr, 2)
}

int main() {

    int n;
    cout<<"Cantidad de elementos: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cout<<"Elemento "<<i + 1<<": ";
      cin>>arr[i];
    }

    cout<<"La suma: "<<sumaArreglo(arr, n)<<endl; // sumaArreglo(arr, 4)
    return 0;
}
