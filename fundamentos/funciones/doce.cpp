// Escribe una función que calcule el promedio de n números solo cuando son positivos
// 1, 5, -2, 7, -40
#include <iostream>
using namespace std;

double calcularPromedio(int n){
  double numero, suma = 0;
  int contador = 0;

  for(int i = 1; i <= n; i++){
    cout<<"Ingresa el número "<<i<<": ";
    cin>>numero;

    if(numero > 0){
      suma += numero; // suma = suma + numero
      contador++;
    }
  }

  if(contador == 0){
    return 0;
  }

  return suma / n;
}

int main() {

    int n;

    cout<<"Ingresa la cantidad de números a promediar: ";
    cin>>n;

    if(n > 0){

      double resultado = calcularPromedio(n);

      if(resultado == 0){
        cout<<"No se ingresaron números positivos."<<endl;
      }else{
        cout<<"Promedio de los positivos: "<<resultado<<endl;
      }

    }

    return 0;
}
