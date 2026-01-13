#include <iostream>
using namespace std;

union Datos {
  int entero;
  float decimal;
};

int main() {

    Datos dato;

    dato.entero = 10;
    cout<<"Entero: "<<dato.entero<<endl;

    dato.decimal = 5.5;
    cout<<"Decimal: "<<dato.decimal<<endl;

    cout<<"Entero después de asignar decimal: "<<dato.entero<<endl;

    return 0;
}
