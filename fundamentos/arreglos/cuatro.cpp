// Escribe una función que invierta los elementos de un arreglo de enteros.

// {1, 6, 2, 8}
// {8, 6, 2, 1}
// {8, 2, 6, 1}

#include <iostream>
using namespace std;

void invertirArreglo(int arreglo[], int tam){

  int i = 0;
  int j = tam - 1;

  while(i < j){
    int temp = arreglo[i]; // temp = 1
    arreglo[i] = arreglo[j]; // arreglo[i] = 8
    arreglo[j] = temp; // arreglo[j] = 1

    i++;
    j--;
  }
}

int main() {

    int tam;

    cout<<"Ingresa la cantidad de elementos del arreglo: ";
    cin>>tam;

    int arreglo[tam];

    for(int i = 0; i < tam; i++){
      cout<<"Ingresa el elemento "<<i + 1<<": ";
      cin>>arreglo[i];
    }

    invertirArreglo(arreglo, tam);

    cout<<"Arreglo invertido: ";
    for(int i = 0; i < tam; i++){
      cout<<arreglo[i]<<" ";
    }
    cout<<endl;

    return 0;
}
