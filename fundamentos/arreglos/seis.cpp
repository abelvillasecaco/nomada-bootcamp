// Usando funciones y arreglos, diga si un elemento se encuentra en un conjunto de datos.
// Utiliza la búsqueda secuencial.

// Ejemplo: int arreglo[] = {1, 2, 3, 4, 5, 6};
// int elemento = 3;

#include <iostream>
using namespace std;

bool buquedaSecuencial(int arreglo[], int tam, int valor){
  for(int i = 0; i < tam; i++){
    if(arreglo[i] == valor){
      return true;
    }
  }
  return false;
}

int main() {

    int tam, valor;

    cout<<"Ingrese el tamaño del arreglo: ";
    cin>>tam;

    int arreglo[tam];

    for(int i = 0; i < tam; i++) {
      cout<<"Ingrese el elemento "<<i + 1<<": ";
      cin>>arreglo[i]; // {1, 2, 3, 4, 5, 6};
    }

    cout<<"Ingrese el valor a buscar: ";
    cin>>valor; // 3

    if(buquedaSecuencial(arreglo, tam, valor)){
      cout<<"El elemento "<<valor<<" se encuentra en el arreglo."<<endl;
    }else{
      cout<<"El elemento "<<valor<<" no se encuentra en el arreglo."<<endl;
    }

    return 0;
}
