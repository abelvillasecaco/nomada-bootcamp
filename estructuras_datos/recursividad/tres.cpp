// Calcula el enésimo número Fibonacci mediante una función recursiva.
// 0, 1, 1, 2, 3, 5, 8, 13...

// fibonacci(n) = fibonacci(n - 1) + fibonacci(n - 2)

// Caso base 1: n == 0
// Caso base 2: n == 1

#include <iostream>
using namespace std;

int fibonacci(int n){
    if(n == 0)
      return 0;
    if(n == 1)
      return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
    // fibonacci(5) => 5
    // fibanacci(4) + fibonacci(3)
    // fibonacci(4) => 3
    // fibanacci(3) + fibonacci(2)
    // fibonacci(3) => 2
    // fibanacci(2) + fibonacci(1)
    // fibonacci(2) => 1
    // fibanacci(1) + fibonacci(0)
}

int main() {

    int n; // n = 5

    cout<<"Ingresa la posición Fibonacci: ";
    cin>>n;

    cout<<"El valor es: "<<fibonacci(n)<<endl;

    cout<<"Serie Fibonacci: "<<endl;
    for(int i = 0; i <= n; i++){
      cout<<fibonacci(i)<<" ";
    }

    return 0;
}
