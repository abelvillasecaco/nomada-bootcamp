// Encuentra el promedio de N números.

// 1, 4, 2, 2

#include <iostream>
using namespace std;

int main() {

    int n;

    cout<<"Ingresa la cantidad de números que necesitas: ";
    cin>>n; // 4

    if(n <= 0){
      cout<<"La cantidad de número debe ser mayor a 0."<<endl;
      return 0;
    }

    double suma = 0.0, numero;

    for(int i = 1; i <= n; i++){
      cout<<"Ingresa el número "<<i<<": ";
      cin>>numero; // 3
      suma += numero; // suma = 10
    }

    double promedio = suma / n;

    cout<<"El promedio de los "<<n<<" números es: "<<promedio<<endl;

    return 0;
}
