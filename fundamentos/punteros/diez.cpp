// Escribe un programa que cree un arreglo dinámico, lo llene con valores ingresados por el usuario
// y luego cree una copia exacta del arreglo en otra ubicación de memoria dinámica usando punteros.
// Muestra ambos arreglos al final.

#include <iostream>
using namespace std;

int *crearArreglo(int n) {
   return new int[n];
}

void ingresarDatos(int *arreglo, int n) {
    for(int i = 0; i < n; i++) {
      cout<<"Ingrese el elemento ["<<i<<"]: "; // [5][8][2][9]
      cin>>*(arreglo + i); // arreglo[i]
    }
}

void copiarArreglo(int *original, int *copia, int n) {
  cout<<"Copiando el arreglo..."<<endl;
  for(int i = 0; i < n; i++) {
    *(copia + i) = *(original + i);
  }
}

void mostrarArreglo(const char *mensaje, int *arreglo, int n) {
    cout<<mensaje<<endl;
    for(int i = 0; i < n; i++) {
        cout<<arreglo[i]<<"\t";
    }
    cout<<endl;
}

void liberarMemoria(int *arreglo) {
    delete[] arreglo;
}

int main() {

    int n;
    cout<<"Ingrese el tamaño del arreglo: ";
    cin>>n;

    int *original = crearArreglo(n);
    int *copia = crearArreglo(n);

    ingresarDatos(original, n);
    copiarArreglo(original, copia, n);
    mostrarArreglo("Arreglo original: ", original, n);
    mostrarArreglo("Arreglo copiado: ", copia, n);

    liberarMemoria(original);
    liberarMemoria(copia);

    return 0;
}
