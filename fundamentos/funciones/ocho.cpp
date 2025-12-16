// Escribe una función que reciba dos números enteros: una base y un exponente, y devuelva la base
// elevada a la potencia del exponente.

// pow
// resultado *= base

#include <iostream>
using namespace std;

int calcularPotencia(int base, int exponente); // Declarando la función

int main() {

    int base, exponente;

    cout<<"Ingresa la base: ";
    cin>>base; // 2

    cout<<"Ingresa el exponente: ";
    cin>>exponente; // 2

    cout<<"Resultado: "<<calcularPotencia(base, exponente)<<endl;

    return 0;
}

int calcularPotencia(int base, int exponente) {
  int resultado = 1;

  for(int i = 1; i <= exponente; i++){
    resultado *= base; // resultado = 4
  }

  return resultado;
}
