// Lee dos matrices y obtén el producto.

#include <iostream>
using namespace std;

void leerMatriz(int m[100][100], int f, int c){ //
  for(int i = 0; i < f; i++){ // recorre las filas
    for(int j = 0; j < c; j++){ // recorre las columnas
      cout<<"Ingresa el elemento ["<<i<<"]["<<j<<"]: ";
      cin>>m[i][j]; // m[2][2] = 4
    }
  }
}

void multiplicarMatriz(int a[100][100], int b[100][100], int r[100][100], int fA, int cA, int cB){
  for(int i = 0; i < fA; i++){
    for(int j = 0; j < cB; j++){
      r[i][j] = 0;
      for(int k = 0; k < cA; k++){
        r[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}

// A = [1 2]
//     [3 4]

// B = [5 6]
//     [7 8]

// R[0][0] = 19

void imprimirMatriz(int m[100][100], int f, int c){
  for(int i = 0; i < f; i++){ // recorre las filas
    for(int j = 0; j < c; j++){ // recorre las columnas
      cout<<m[i][j]<<"\t";
    }
    cout<<endl;
  }
}

int main() {

    int matrizA[100][100], matrizB[100][100], matrizR[100][100];
    int filasA, columnasA, filasB, columnasB;

    cout<<"Filas y columnas de A: ";
    cin>>filasA>>columnasA;
    cout<<"Filas y columnas de B: ";
    cin>>filasB>>columnasB;

    if (columnasA != filasB){
      cout<<"No se pueden multiplicar."<<endl;
      return 0;
    }

    cout<<"Ingresa la matriz A: "<<endl;
    leerMatriz(matrizA, filasA, columnasA);
    cout<<"Ingresa la matriz B: "<<endl;
    leerMatriz(matrizB, filasB, columnasB);

    multiplicarMatriz(matrizA, matrizB, matrizR, filasA, columnasA, columnasB);

    imprimirMatriz(matrizR, filasA, columnasB);

    return 0;
}
