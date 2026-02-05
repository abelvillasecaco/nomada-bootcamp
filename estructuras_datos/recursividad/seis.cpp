// Lee un número en base 10 y muestre su equivalente en base 2 por métodos recursivos.
// 10 (decimal) = 1010
// 13 (decimal) = 1101

// 1. Dividir entre 2
// 2. Guardas el residuo (%2)
// 3. Repetir con el cociente (/2)
// 4. Lees los residuos de atrás hacia adelante

// 13     6     1
// 6      3     0
// 3      1     1
// 1      0     1

// 1101 => 13

#include <iostream>
using namespace std;

void transformaBinario(int n){
    if(n == 0)
      return;

    transformaBinario(n / 2);
    cout<<n % 2;
}

int main() {

    int numero;

    cout<<"Ingresa un número en base 10: ";
    cin>>numero;

    cout<<"El número "<<numero<<" en binario es: ";
    transformaBinario(numero);
    cout<<endl;

    return 0;
}
