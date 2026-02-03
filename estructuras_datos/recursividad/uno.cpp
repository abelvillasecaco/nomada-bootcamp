// Calcula el factorial de un número mediante una función recursiva.

// n! = n * (n-1)x(n-2)...x1!
// 3! = 3 x 2 x 1 = 6.

// 0! = 1

#include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0)
      return 1; // 0! = 1

    return n * factorial(n - 1);
    // factorial(3) => 3 * 2 = 6
    // factorial(2) => 2 * 1 = 2
    // factorial(1) => 1 * 1 = 1
    // factorial(0) => 1
}

int main() {

    int numero;
    cout<<"Ingrese el número: ";
    cin>>numero; // 3

    cout<<"El factorial es: "<<factorial(numero)<<endl; // 3

    return 0;
}
