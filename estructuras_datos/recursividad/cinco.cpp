// Obtén el producto de dos enteros a y b de manera recursiva.
// a * b = a + a + ... b veces

// Llamada recursivo => multiplicacion(a, b) => a + multiplicacion(a, b - 1)
// Caso base => b = 0

#include <iostream>
using namespace std;

int multiplicacion(int a, int b){
    // if(b == 0)
    //   return 0;

    if(b == 1)
      return a;

    return a + multiplicacion(a, b - 1);
    // multiplicacion(4, 3); => 12
    // return 4 + multiplicacion(4, 2)
    // multiplicacion(4, 2); => 8
    // return 4 + multiplicacion(4, 1)
    // multiplicacion(4, 1); => 4
    // return 4 + multiplicacion(4, 0)
    // multiplicacion(4, 0); => 0
    // return 0;

}

int main() {

    int a, b;

    cout<<"Ingresa a: ";
    cin>>a;
    cout<<"Ingresa b: ";
    cin>>b;

    cout<<"El producto es: "<<multiplicacion(a, b)<<endl;

    return 0;
}
