// Elabora un algoritmo que resuelva una ecuación de primer grado.
// a * x + b = 0
// Si a != 0 => x = -b / a
// Si b == 0 y a == 0 => infinitas soluciones
// Si a == 0 y b != 0 => no hay solución

#include <iostream>
using namespace std;

int main() {

    double a, b;
    cout<<"Ingresa a: ";
    cin>>a;
    cout<<"Ingresa b: ";
    cin>>b;

    if (a == 0) {
      if (b == 0) {
        cout<<"Existen infinitas soluciones."<<endl;
      } else {
        cout<<"No tiene solución."<<endl;
      }
    } else {
      double x = -b / a;
      cout<<"Solución única: x = "<<x<<endl;
    }

    return 0;
}
