// Define una función valorAbsoluto sobrecargada para recibir números enteros y
// double para que funcione con ambos tipos de datos.

// -4 => 4


#include <iostream>
using namespace std;

int valorAbsoluto(int numero);
double valorAbsoluto(double numero);

int main() {

    int entero;
    double decimal;

    cout<<"Ingresa un número entero: ";
    cin>>entero;

    cout<<"Ingresa un número decimal: ";
    cin>>decimal;

    cout<<"Valor absoluto del entero: "<<valorAbsoluto(entero)<<endl;
    cout<<"Valor absoluto del decimal: "<<valorAbsoluto(decimal)<<endl;

    return 0;
}

int valorAbsoluto(int numero){
  if(numero < 0){
    return -numero;
  }
  return numero;
}

double valorAbsoluto(double numero){
  if(numero < 0){
    return -numero;
  }
  return numero;
}
