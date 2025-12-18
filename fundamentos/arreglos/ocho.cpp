// Usando funciones y arreglos, ordena un conjunto de datos de menor a mayor por el método de la burbuja.
// int arreglo[4] = {2, 6, 1, 9}
// {2, 1, 6, 9}

#include <iostream>
using namespace std;

void metodoBurbuja(int arreglo[], int tam){
  for(int i = 0; i < tam; i++){
    for(int j = 0; j < tam - i - 1; j++){ // arreglo[j+1]
      if(arreglo[j] > arreglo[j + 1]){
        int temp = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = temp;
      }
    }
  }
}

int main() {

    int tam;

    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>tam;

    int arreglo[tam];

    for(int i = 0; i < tam; i++) {
      cout<<"Ingrese el elemento "<<i + 1<<": ";
      cin>>arreglo[i];
    }

    metodoBurbuja(arreglo, tam);

    cout<<"Arreglo ordenado: ";
    for(int i = 0; i < tam; i++){
      cout<<arreglo[i]<<" ";
    }

    cout<<endl;

    return 0;
}

// a = 5,  b =2
