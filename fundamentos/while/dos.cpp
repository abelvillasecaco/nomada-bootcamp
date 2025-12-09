// Indicar si un número es primo.
// - Solo tiene 2 divisores: 1 y él mismo
// - Es mayor o igual 2

#include <iostream>
using namespace std;

int main() {

    int numero;
    bool esPrimo = true; // bandera => flag

    cout<<"Ingresa un número: ";
    cin>>numero;

    if (numero < 2) {
      esPrimo = false;
    } else {
      int i = 2;
      while (i < numero) {
        if (numero % i == 0) {
          esPrimo = false;
          break;
        }
        i++;
      }
    }

    if (esPrimo) {
      cout<<numero<<" es primo."<<endl;
    } else {
      cout<<numero<<" no es primo."<<endl;
    }

    return 0;
}
