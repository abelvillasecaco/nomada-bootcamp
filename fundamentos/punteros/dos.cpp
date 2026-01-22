// Escribe un programa que pida al usuario el tamaño de un arreglo y luego sus elementos.
// Usa punteros para calcular el promedio de los números almacenados en el arreglo.

// int *arreglo = new int[n];

#include <iostream>
using namespace std;

float calcularPromedio(int *arr, int n){
    int suma = 0;

    for(int i = 0; i < n; i++){
      suma += *(arr + i);
    }

    return (float)suma / n;
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int *arreglo = new int[n]; // Memoria dinámica

    for(int i = 0; i < n; i++){
      cout<<"Elemento ["<<i + 1<<"]: ";
      cin>>*(arreglo + i); // arreglo[0] => {8, 6, 10, 4}
    }

    cout<<"Promedio: "<<calcularPromedio(arreglo, n)<<endl;

    delete[] arreglo;

    return 0;
}
