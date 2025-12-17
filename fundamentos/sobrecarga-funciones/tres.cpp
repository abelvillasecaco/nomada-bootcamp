// Define una función esMayor sobrecargada para comparar dos números y retornar
// si el primero es mayor. Crea sobrecargas para int y double.

#include <iostream>
using namespace std;

bool esMayor(int a, int b){
  return a > b;
}

bool esMayor(double a, double b){
  return a > b;
}

int main() {

    int aInt, bInt;
    double aDouble, bDouble;

    cout<<"Ingresa dos enteros: ";
    cin>>aInt>>bInt;

    cout<<"Ingresa dos decimales: ";
    cin>>aDouble>>bDouble;

    cout<<"El primer entero es mayor?: "<<esMayor(aInt, bInt)<<endl;
    cout<<"El primer decimal es mayor?: "<<esMayor(aDouble, bDouble)<<endl;

    return 0;
}
