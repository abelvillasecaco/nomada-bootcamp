// Desarrolla un programa que permita encontrar el menor elemento de un arreglo.

#include <iostream>
using namespace std;

// [2, 6, 1, 8, 3]
// n = 5

int encontrarMenor(int arr[], int n){
    int menor = arr[0]; // menor = 2

    for(int i = 1; i < n; i++){ // arr[2] = 1
      if(arr[i] < menor){ // 6 < 2
        menor = arr[i]; // menor = 1
      }
    }

    return menor;
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    int menor = encontrarMenor(arr, n);

    cout<<"El menor elemento es: "<<menor<<endl;

    return 0;
}
