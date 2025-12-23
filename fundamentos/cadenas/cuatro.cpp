// Escribe un programa que tome una cadena ingresada por el usuario y  muestre la misma cadena invertida.
#include <iostream>
#include <string>
using namespace std;

int main() {

    string cadena; // Hola mundo

    cout<<"Introduce una cadena: ";
    getline(cin, cadena);

    cout<<"La cadena invertida es: "<<endl;
    for(int i = cadena.length() - 1; i >= 0; i--){ // i = 10
      cout<<cadena[i];
    }

    cout<<endl;

    return 0;
}
