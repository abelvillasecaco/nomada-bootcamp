// Crea una union que permita almacenar un char o un int, que permita evidenciar cómo cambiar el
// valor almacenado afecta al contenido de la union.

#include <iostream>
using namespace std;

union Dato {
  char caracter; // 1 byte
  int numero; // 4 bytes
};

void ingresarChar(Dato &d) {
  cout<<"Ingresa un caracter: ";
  cin>>d.caracter;
}

void ingresarInt(Dato &d) {
  cout<<"Ingresa un número entero: ";
  cin>>d.numero;
}

void mostrarDatos(Dato d) {
  cout<<"Contenido interpretado como char: "<<d.caracter<<endl;
  cout<<"Contenido interpretado como int: "<<d.numero<<endl;
}

int main() {

    Dato d;

    ingresarChar(d);
    cout<<"\nLuego de ingresar un char: "<<endl;
    mostrarDatos(d);

    ingresarInt(d);
    cout<<"\nLuego de ingresar un int: "<<endl;
    mostrarDatos(d);

    return 0;
}
