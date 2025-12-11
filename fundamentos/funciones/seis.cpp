// Escribe una función que reciba tres números enteros como parámetros y devuelva el mayor de ellos.

#include <iostream>
using namespace std;

int mayorDeTres(int a, int b, int c);

int main() {

    int num1, num2, num3;

    cout<<"Ingresa los tres números: ";
    cin>>num1>>num2>>num3; // 5, 2, 9

    cout<<"El número mayor es: "<<mayorDeTres(num1, num2, num3)<<endl;

    return 0;
}

int mayorDeTres(int a, int b, int c){
  int mayor = a; // mayor = 5

  if(b > mayor) mayor = b;
  if(c > mayor) mayor = c;

  return mayor;
}
