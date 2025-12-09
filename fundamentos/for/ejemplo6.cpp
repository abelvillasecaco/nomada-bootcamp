// Ingresar N números y contar cuántos están en el rango [10, 50], es decir, entre 10 y 50 inclusive.
// Validar que N sea mayor o igual a 1.
#include <iostream>
using namespace std;

int main() {

    int n, x, contador = 0;

    cout<<"Ingrese la cantidad de números (N): ";
    cin>>n;

    if (n < 1) {
      cout<<"Error: N debe ser al menos 1."<<endl;
      return 0;
    }

    for(int i = 1; i <= n; i++){
      cout<<"Ingresa el número "<<i<<": ";
      cin>>x;

      if(x >= 10 && x <= 50){
        contador++;
      }
    }

    cout<<"La cantidad de números entre 10 y 50 es: "<<contador<<endl;

    return 0;
}
