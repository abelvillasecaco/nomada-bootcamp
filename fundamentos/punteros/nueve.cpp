// Escribe un programa que cree una matriz dinámica de tamaño m x n, permita al usuario llenarla
// y luego la imprima en forma de tabla. Usa punteros para manejar la memoria dinámica.

#include <iostream>
using namespace std;

int **crearMatriz(int m, int n) {
    int **matriz = new int*[m]; // Reserva las filas
    for (int i = 0; i < m; i++) {
      matriz[i] = new int[n]; // Reserva las columnas para cada fila
    }
    return matriz;
}

void llenarMatriz(int **matriz, int m, int n) {
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        cout<<"Ingrese el elemento ["<<i<<"]["<<j<<"]: ";
        cin>>matriz[i][j]; // *(*(matriz + i) + j)
      }
    }
}

void mostrarMatriz(int **matriz, int m, int n) {
    for(int i = 0; i < m; i++) {
      for(int j = 0; j < n; j++) {
        cout<<matriz[i][j]<<"\t";
      }
      cout<<endl;
    }
}

void liberarMatriz(int **matriz, int m) {
    for(int i = 0; i < m; i++) {
      delete [] matriz[i];
    }
    delete [] matriz;
}

int main() {

    int m, n;
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> m >> n;

    int **matriz = crearMatriz(m, n); // matriz[i] es un int* matriz[i][j] es un int

    llenarMatriz(matriz, m, n);
    mostrarMatriz(matriz, m, n);
    liberarMatriz(matriz, m);

    return 0;
}
