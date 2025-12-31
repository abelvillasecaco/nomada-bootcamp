// Dada una matriz encuentre el mayor elemento de cada fila.

#include <iostream>
using namespace std;

void leerMatriz(int m[100][100], int f, int c){ //
  for(int i = 0; i < f; i++){ // recorre las filas
    for(int j = 0; j < c; j++){ // recorre las columnas
      cout<<"Ingresa el elemento ["<<i<<"]["<<j<<"]: ";
      cin>>m[i][j];
    }
  }
}

void mayorPorFila(int m[100][100], int f, int c){
  for(int i = 0; i < f; i++){
    int mayor = m[i][0];
    for(int j = 1; j < c; j++){
      if(m[i][j] > mayor){
        mayor = m[i][j];
      }
    }
    cout<<"El mayor elemento de la fila "<<i<<" es: "<<mayor<<endl;
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
    mayorPorFila(matriz, filas, columnas);

    return 0;
}
