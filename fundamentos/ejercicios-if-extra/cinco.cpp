// Escribe un algoritmo que lea el promedio de un alumno y diga cuál es su rendimiento, considera:
// datos erróneos, rendimiento pésimo, rendimiento deficiente, rendimiento regular, rendimiento bueno.

// Datos erróneos si fuera < 0 ó > 20
// pésimo: 0 - 5
// deficiente: 5 - 10
// regular: 10 - 14
// bueno: 14 - 20

#include <iostream>
using namespace std;

int main() {

    double promedio;
    cout<<"Ingresa el promedio del alumno: ";
    cin>>promedio; // indeterminado => failbit => 0

    if (cin.fail()) {
      cout<<"Error: Debes ingresar un número"<<endl;
      return 0;
    }

    if (promedio < 0 || promedio > 20) {
      cout<<"Datos erróneos."<<endl;
    } else {
      if (promedio <= 5) {
        cout<<"Rendimiento pésimo"<<endl;
      } else if (promedio <= 10) {
        cout<<"Rendimiento deficiente"<<endl;
      } else if (promedio <= 14) {
        cout<<"Rendimiento regular"<<endl;
      } else {
        cout<<"Rendimiento bueno"<<endl;
      }
    }

    return 0;
}
