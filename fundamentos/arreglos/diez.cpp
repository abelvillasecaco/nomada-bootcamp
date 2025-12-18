// Usando funciones y arreglos, encuentra el mayor y menor elemento de un conjunto de datos.
// {3, 6, 1, 7}
// mayor = 3
// menor = 3

#include <iostream>
using namespace std;

void mayorMenor(int arreglo[], int tam, int &mayor, int &menor){
  mayor = menor = arreglo[0];

  for(int i = 1; i < tam; i++){
    if(arreglo[i] > mayor) mayor = arreglo[i];
    if(arreglo[i] < menor) menor = arreglo[i];
  }
}

int main() {

    int tam, mayor, menor;

    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>tam;

    int arreglo[tam];

    for(int i = 0; i < tam; i++) {
      cout<<"Ingrese el elemento "<<i + 1<<": ";
      cin>>arreglo[i];
    }

    mayorMenor(arreglo, tam, mayor, menor);

    cout<<"Elemento mayor: "<<mayor<<endl;
    cout<<"Elemento menor: "<<menor<<endl;

    return 0;
}
