// Dada una matriz (arreglo bidimensional), ordena cada fila de manera ascendente utilizando el método burbuja o selección.

// 1 3 5 7
// 0 6 2 1
// 1 8 3 2

#include <iostream>
using namespace std;

void leerMatriz(int m[][100], int f, int c){
    for(int i = 0; i < f; i++){
      for(int j = 0; j < c; j++){
        cout<<"Ingresa m["<<i<<"]["<<j<<"]: ";
        cin>>m[i][j];
      }
    }
}

void mostrarMatriz(int m[][100], int f, int c){
    for(int i = 0; i < f; i++){
      for(int j = 0; j < c; j++){
        cout<<m[i][j]<<"\t";
      }
      cout<<endl;
    }
}

void burbujaFilas(int fila[], int c){
    for(int i = 0; i < c - 1; i++){
      for(int j = 0; j < c - 1 - i; j++){
        if(fila[j] > fila[j + 1]){
          int aux = fila[j];
          fila[j] = fila[j + 1];
          fila[j + 1] = aux;
        }
      }
    }
}

void ordenarFilas(int m[][100], int f, int c){
  for(int i = 0; i < f; i++){
    burbujaFilas(m[i], c); //m[i][0] => Dirección del primer elemento de esa fila
  }
}

int main() {

    int f, c;

    cout<<"Ingrese las filas: ";
    cin>>f;

    cout<<"Ingrese las columnas: ";
    cin>>c;

    int m[100][100];

    leerMatriz(m, f, c);

    cout<<"Matriz original: "<<endl;
    mostrarMatriz(m, f, c);

    ordenarFilas(m, f, c);

    cout<<"Matriz ordenada: "<<endl;
    mostrarMatriz(m, f, c);

    return 0;
}
