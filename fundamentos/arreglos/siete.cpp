// Usando funciones y arreglos, elimina los elementos repetidos de un conjunto de datos.
// 1. Detectar los valores duplicados
// 2. Mantener un solo elemento (ocurrencia)
// 3. Reducir el tamaño del arreglo

// int arreglo[4] = {1, 1, 2, 6}
// int arreglo[4] = {1, 2, 6}


#include <iostream>
using namespace std;

int eliminarRepetidos(int arreglo[], int tam){
  for(int i = 0; i < tam; i++){
    for(int j = i + 1; j < tam; j++){
      if(arreglo[i] == arreglo[j]){
        for(int k = j; k < tam - 1; k++){
          arreglo[k] = arreglo[k + 1];
        }
        tam--;
        j--;
      }
    }
  }
  return tam;
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

    tam = eliminarRepetidos(arreglo, tam);

    cout<<"Arreglo sin elementos repetidos: ";
    for(int i = 0; i < tam; i++){
      cout<<arreglo[i]<<" ";
    }

    return 0;
}
