#include <iostream>
using namespace std;

int main() {

    char opcion;

    cout<<"Menú de opciones: "<<endl;
    cout<<"a. Mostrar saludo "<<endl;
    cout<<"b. Mostrar despedida "<<endl;
    cout<<"c. Salir "<<endl;

    cout<<"Seleccione una opción (a, b o c): ";
    cin>>opcion; // B

    switch (opcion) {
      case 'a':
      case 'A': cout<<"Hola"<<endl;
                break;
      case 'b':
      case 'B': cout<<"Adiós"<<endl;
                break;
      case 'c':
      case 'C': cout<<"Saliendo del programa..."<<endl;
                break;
      default: cout<<"Opción inválida."<<endl;
               break;
    }

    return 0;
}
