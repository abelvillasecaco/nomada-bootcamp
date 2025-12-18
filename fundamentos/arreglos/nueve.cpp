// Usando funciones y arreglos, ordena un conjunto de datos de menor a mayor por el método de inserción.
// int arreglo[4] = {5, 3, 8, 2}
// {3, 5, 8, 2}
// {2, 3, 5, 8}

#include <iostream>
using namespace std;

void metodoInsercion(int arreglo[], int tam){
  for(int i = 1; i < tam; i++){
    int actual = arreglo[i]; // actual = 3
    int j = i - 1;

    while(j >= 0 && arreglo[j] > actual){
      arreglo[j + 1] = arreglo[j];
      j--;
    }
    arreglo[j + 1] = actual;
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

    metodoInsercion(arreglo, tam);

    cout<<"Arreglo ordenado: ";
    for(int i = 0; i < tam; i++){
      cout<<arreglo[i]<<" ";
    }

    cout<<endl;

    return 0;
}
