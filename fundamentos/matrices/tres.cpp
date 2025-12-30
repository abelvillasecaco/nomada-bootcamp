// Lee dos matrices y obtén la suma.

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

void sumarMatriz(int a[100][100], int b[100][100], int r[100][100], int f, int c){
  for(int i = 0; i < f; i++){
    for(int j = 0; j < c; j++){
      r[i][j] = a[i][j] + b[i][j];
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

    int matrizA[100][100], matrizB[100][100], matrizR[100][100]; // Límite
    int filas, columnas;

    cout<<"Ingresa el número de filas: ";
    cin>>filas; // 3
    cout<<"Ingresa el número de columnas: ";
    cin>>columnas; // 3

    cout<<"Datos para la matriz A: "<<endl;
    leerMatriz(matrizA, filas, columnas);

    cout<<"Datos para la matriz B: "<<endl;
    leerMatriz(matrizB, filas, columnas);

    sumarMatriz(matrizA, matrizB, matrizR, filas, columnas);

    cout<<"Resultado: "<<endl;
    imprimirMatriz(matrizR, filas, columnas);

    return 0;
}
