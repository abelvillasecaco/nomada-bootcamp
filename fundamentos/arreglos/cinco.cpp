// Crea una función que calcule el promedio de los elementos en un arreglo de enteros.

// Ejemplo: int arreglo[] = {1, 2, 3, 4};
#include <iostream>
using namespace std;

double calcularPromedio(int arreglo[], int tam) {
  int suma = 0;

  for(int i = 0; i < tam; i++) {
    suma += arreglo[i];
  }

  // return (double)suma / tam;
  return static_cast<double>(suma) / tam; // Conversión implícita
  // 7 / 2 = 3.5
}

int main() {

    int tam;

    cout<<"Ingrese el tamaño del arreglo: ";
    cin>>tam;

    int arreglo[tam];

    for(int i = 0; i < tam; i++) {
      cout<<"Ingrese el elemento "<<i + 1<<": ";
      cin>>arreglo[i];
    }

    double promedio = calcularPromedio(arreglo, tam);
    cout<<"El promedio del arreglo es: "<<promedio<<endl;

    return 0;
}
