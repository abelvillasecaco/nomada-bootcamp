#include <iostream>
using namespace std;

int main() {

    int opcion;

    cout<<"Menú de opciones: "<<endl;
    cout<<"1. Mostrar saludo "<<endl;
    cout<<"2. Mostrar despedida "<<endl;
    cout<<"3. Salir "<<endl;

    cout<<"Seleccione una opción (1-3): ";
    cin>>opcion;

    switch (opcion) {
      case 1: cout<<"Hola, bienvenido al programa."<<endl;
              break;
      case 2: cout<<"Hasta luego."<<endl;
              break;
      case 3: cout<<"Saliendo del programa..."<<endl;
              break;
      default: cout<<"Opción inválida. Intenta nuevamente."<<endl;
               break;
    }

    return 0;
}
