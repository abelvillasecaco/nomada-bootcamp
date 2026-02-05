// Usando recursividad, determina si un número es par o impar.
// CASOS BASES:
// 0 -> Par
// 1 -> Impar

#include <iostream>
using namespace std;

bool esPar(int n){
    if(n == 0)
      return true;
    if(n == 1)
      return false;

    return esPar(n - 2); // 8 => 6 => 4 => 2 => 0
}

int main() {

    int numero;
    cout<<"Ingresa el número: ";
    cin>>numero;

    if(esPar(numero)){
      cout<<"Es par"<<endl;
    }else{
      cout<<"Es impar"<<endl;
    }

    return 0;
}
