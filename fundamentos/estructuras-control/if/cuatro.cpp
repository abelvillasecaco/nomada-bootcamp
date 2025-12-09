// Encuentra el mayor valor de tres números dados.
// 6 9 1

#include <iostream>
using namespace std;

int main() {

    int numero1, numero2, numero3;

    cout<<"Ingresa los tres números a comparar: ";
    cin>>numero1>>numero2>>numero3;

    int mayor = numero1;

    if (numero2 > mayor) {
        mayor = numero2;
    }
    if (numero3 > mayor) {
        mayor = numero3;
    }

    cout<<"El mayor número es: "<<mayor<<endl;

    return 0;
}

// Código spagetti => mala práctica
