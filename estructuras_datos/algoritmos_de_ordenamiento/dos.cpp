// Dado un arreglo de cadenas que representan nombres de estudiantes,
// ordénalos alfabéticamente (de A a Z) utilizando el método de selección.

#include <iostream>
using namespace std;

void leerNombres(string nombres[], int n) {
    cin.ignore(); // Limpiar el buffer para getline
    for(int i = 0; i < n; i++){
      cout<<"Ingresa el nombre ["<<i<<"]: ";
      getline(cin, nombres[i]);
    }
}

void mostrarNombres(string nombres[], int n) {
    for(int i = 0; i < n; i++){
      cout<<nombres[i]<<endl;
    }
}

void seleccion(string nombres[], int n) {
    for(int i = 0; i < n - 1; i++){
      int minIndex = i;

      for(int j = i + 1; j < n; j++){
        if(nombres[j] < nombres[minIndex]){ // "Ana" < "Luis"
          minIndex = j;
        }
      }

      string aux = nombres[i];
      nombres[i] = nombres[minIndex];
      nombres[minIndex] = aux;

    }
}

int main() {

    int n;
    cout<<"Ingresa la cantidad de estudiantes: ";
    cin>>n;

    string nombres[n];

    leerNombres(nombres, n);

    cout<<"\nLista original de nombres: "<<endl;
    mostrarNombres(nombres, n);

    seleccion(nombres, n);

    cout<<"\nLista ordenada: "<<endl;
    mostrarNombres(nombres, n);

    return 0;
}
