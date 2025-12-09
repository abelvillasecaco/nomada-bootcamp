// Costo de una llamada telefónica. Una llamada telefónica cuesta S/. 0,5 por los primeros tres minutos o menos.
// Cada minuto adicional es un paso de contador y cuesta S/. 0,1. Calcula el monto de una llamada cualquiera.
// ceil 1.2 (2) 5.7 (6)

#include <iostream>
#include <cmath>
using namespace std;

int main() {

    double duracion; // 3.3
    cout<<"Ingrese la duración de la llamada en minutos: ";
    cin>>duracion;

    if (duracion <= 0) {
      cout<<"Duración de la llamada inválida."<<endl;
      return 0;
    }

    double costo = 0.0;

    if (duracion <= 3.0) {
      costo = 0.5;
    } else {
      double extra = duracion - 3.0;
      int minutosExtra = (int) ceil(extra);
      costo = 0.5 + minutosExtra * 0.1;
    }

    cout<<"Costo de la llamada: S/. "<<costo<<endl;

    return 0;
}
