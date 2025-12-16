// Desarrolla una función que te permita calcular el promedio de n números.
//

#include <iostream>
using namespace std;

double calcularPromedio(int n){
  double numero, suma = 0;

  for(int i = 1; i <= n; i++){
    cout<<"Ingresa el número "<<i<<": ";
    cin>>numero;

    suma += numero; // suma = suma + numero
  }

  return suma / n;
}

int main() {

    int n;

    cout<<"Ingresa la cantidad de números a promediar: ";
    cin>>n;

    if(n > 0){
      cout<<calcularPromedio(n)<<endl;
    }else{
      cout<<"Error: la cantidad debe ser mayor que cero."<<endl;
    }

    return 0;
}
