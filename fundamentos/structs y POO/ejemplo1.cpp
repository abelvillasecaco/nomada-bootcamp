#include <iostream>
using namespace std;

struct Persona {
  string nombre;
  int edad;
  float altura;
};

int main() {

    Persona persona1; // Instancia

    persona1.nombre = "Hugo";
    persona1.edad = 18;
    persona1.altura = 1.75f;

    cout<<"Nombre: "<<persona1.nombre<<endl;
    cout<<"Edad: "<<persona1.edad<<endl;
    cout<<"Altura: "<<persona1.altura<<endl;

    return 0;
}
