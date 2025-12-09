// Escribe un programa que pida un número N y muestre todos los números pares desde 2 hasta N,
// usando for.

#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Ingrese un número: ";
    cin>>n; // 4

    for(int i = 2; i <= n; i+=2){
      cout<<i<<" "; // 2 4
    }

    cout<<endl;

    return 0;
}
