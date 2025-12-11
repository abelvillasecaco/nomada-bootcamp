#include <iostream>
using namespace std;

// 1. Declaracion de una funcion
int suma(int a, int b);

int main() {

  // 3. Llamada a una funcion
    int a, b;
    cout << "Ingrese dos numeros: ";
    cin >> a >> b; // 5 3

    cout<<"El resultado es: "<<suma(a, b)<<endl;

    return 0;
}

// 2. Definicion de una funcion
int suma(int a, int b){
  return a + b;
}
