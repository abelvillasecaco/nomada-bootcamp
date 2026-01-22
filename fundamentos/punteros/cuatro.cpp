// Escribe un programa que invierta los elementos de un arreglo utilizando una función con punteros.
// El programa debe imprimir el arreglo antes y después de invertirlo.

// {8, 6, 10, 4, 2}
// {2, 4, 10, 6, 8}
// {2, 4, 10, 6, 8}

#include <iostream>
using namespace std;

void invertirArreglo(int *arr, int n){
    for(int i = 0; i < n / 2; i++){
      int temp = *(arr + i);
      *(arr + i) = *(arr + n - 1 - i);
      *(arr + n - 1 - i) = temp;
    }
}

void mostrarArreglo(int *arr, int n){
    for(int i = 0; i < n; i++){
      cout<<*(arr + i)<<" ";
    }
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int *arreglo = new int[n];

    for(int i = 0; i < n; i++){
      cout<<"Elemento ["<<i + 1<<"]: ";
      cin>>*(arreglo + i); // arreglo[0] => {8, 6, 10, 4}
    }

    cout<<"\nArreglo original"<<endl;
    mostrarArreglo(arreglo, n);

    invertirArreglo(arreglo, n);

    cout<<"\nArreglo invertido"<<endl;
    mostrarArreglo(arreglo, n);

    delete[] arreglo;

    return 0;
}
