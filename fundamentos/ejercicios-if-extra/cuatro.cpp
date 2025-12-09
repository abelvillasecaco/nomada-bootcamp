// Dadas 3 longitudes, comprueba si pueden formar un triángulo. Luego, clasifica el tipo
// de triángulo es según sus lados.

// Equilatero => 3 lados iguales
// Isósceles => 2 lados iguales
// Escaleno => 3 lados diferentes

#include <iostream>
using namespace std;

int main() {

    double lado1, lado2, lado3;
    cout<<"Ingrese los 3 lados: ";
    cin>>lado1>>lado2>>lado3;

    if (lado1 <= 0 || lado2 <= 0 || lado3<= 0) {
      cout<<"Longitudes inválidas."<<endl;
      return 0;
    }

    if (lado1 + lado2 > lado3 && lado1 + lado3 > lado2 && lado2 + lado3 > lado1) {
      if (lado1 == lado2 && lado2 == lado3) {
        cout<<"El triángulo es equilátero."<<endl;
      } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
        cout<<"El triángulo es isósceles."<<endl;
      } else {
        cout<<"El triángulo es escaleno."<<endl;
      }
    } else {
      cout<<"Los lados no forman un triángulo."<<endl;
    }

    return 0;
}
