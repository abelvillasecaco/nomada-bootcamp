// Declaración e inicialización de una matriz. Lee una matriz con f filas y c columnas y luego imprímela.

#include <iostream>
using namespace std;

// Hardcodear
// const int FIL = 100;
// const int COL = 100;

void leerMatriz(int m[100][100], int f, int c){ //
  for(int i = 0; i < f; i++){ // recorre las filas
    for(int j = 0; j < c; j++){ // recorre las columnas
      cout<<"Ingresa el elemento ["<<i<<"]["<<j<<"]: ";
      cin>>m[i][j]; // m[2][2] = 4
    }
  }
}

void imprimirMatriz(int m[100][100], int f, int c){
  for(int i = 0; i < f; i++){ // recorre las filas
    for(int j = 0; j < c; j++){ // recorre las columnas
      cout<<m[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int main() {

    int matriz[100][100]; // Límite
    int filas, columnas;

    cout<<"Ingresa el número de filas: ";
    cin>>filas; // 3
    cout<<"Ingresa el número de columnas: ";
    cin>>columnas; // 3

    leerMatriz(matriz, filas, columnas); // pase por referencia

    cout<<"\nMatriz ingresada:\n";
    imprimirMatriz(matriz, filas, columnas);

    return 0;
}
