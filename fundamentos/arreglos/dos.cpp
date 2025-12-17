// Escribe una función que encuentre el número mayor en un arreglo de enteros.



// Crea una función que calcule el promedio de los elementos en un arreglo de enteros.

// {1, 6, 45, 2}
// int arreglo[4]

#include <iostream>
using namespace std;

int encontrarMayor(int arreglo[], int tam){
    int mayor = arreglo[0];

    for(int i = 1; i < tam; i++){
      if(arreglo[i] > mayor){
        mayor = arreglo[i];
      }
    }

    return mayor;
}

int main() {

    int tam;

    cout<<"Ingresa la cantidad de elementos del arreglo: ";
    cin>>tam; // 4

    int arreglo[tam];

    for(int i = 0; i < tam; i++){
      cout<<"Ingresa el elemento "<<i + 1<<": ";
      cin>>arreglo[i];
    }

    int mayor = encontrarMayor(arreglo, tam);

    cout<<"El número mayor del arreglo es: "<<mayor<<endl;

    return 0;
}
