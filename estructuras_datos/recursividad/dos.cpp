// Usando métodos recursivos, obtén la suma de los n primeros números naturales positivos.

// n = 4 => 1 + 2 + 3 + 4 = 10
// n + (n - 1)
// suma(0) = 0

#include <iostream>
using namespace std;

int sumaNaturales(int n){
    if (n == 0)
      return 0;

    return n + sumaNaturales(n - 1);
    // return 4 + 6; => 10
    // return 3 + 3; => 6
    // return 2 + 1; => 3
    // return 1 + 0; => 1
    // return 0 => 0
}

int main() {

    int n;
    cout<<"Ingresa n: ";
    cin>>n;

    cout<<"La suma es: "<<sumaNaturales(n)<<endl; // 4

    return 0;
}
