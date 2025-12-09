// Factorizar un número ingresado por teclado.
// 12 = 2 x 2 x 3

#include <iostream>
using namespace std;

int main() {

    int numero, divisor = 2;

    cout<<"Ingresa el número a factorizar: ";
    cin>>numero;

    cout<<"Factores primos: ";

    while (numero > 1) {
      while (numero % divisor == 0) {
        cout<<divisor<<" ";
        numero = numero / divisor;
      }
      divisor++;
    }

    return 0;
}
