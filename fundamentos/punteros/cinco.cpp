// Escribe un programa que cuente cuántos números pares hay en un arreglo. Usa una función que manipule
// punteros para realizar el conteo.

#include <iostream>
using namespace std;

int contarPares(int *arreglo, int n) {
    int contador = 0;
    for (int i = 0; i < n; i++) {
      if (*(arreglo + i) % 2 == 0) {
        contador++;
      }
    }
    return contador;
}

int main() {

    int n;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    int *arreglo = new int[n];

    for (int i = 0; i < n; i++) {
      cout<<"Ingrese el "<<i+1<<" elemento: ";
      cin >> *(arreglo + i);
    }

    cout<<"El número de pares es: "<<contarPares(arreglo, n)<<endl;

    return 0;
}
