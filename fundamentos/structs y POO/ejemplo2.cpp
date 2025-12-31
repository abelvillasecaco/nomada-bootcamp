#include <iostream>
using namespace std;

struct Persona {
  string nombre; // Miembros, características, campos, atributos, etc...
  int edad;
}
persona1 = {"Abel", 32}, // Instancia
persona2 = {"Roberto", 23};

int main() {

    cout<<"Nombre 1: "<<persona1.nombre<<endl;
    cout<<"Edad 1: "<<persona1.edad<<endl;

    cout<<"Nombre 2: "<<persona2.nombre<<endl;
    cout<<"Edad 2: "<<persona2.edad<<endl;

    return 0;
}
