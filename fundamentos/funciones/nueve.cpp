// Escribe una función que reciba dos números enteros por referencia y los intercambie.
// Muestra los valores antes y después de llamar a la función.

// a (int&)
// b (int&)

#include <iostream>
using namespace std;

void intercambiarValores(int &a, int &b);

int main() {

    int num1, num2;

    cout<<"Ingresa el primer y segundo número: ";
    cin>>num1>>num2; // 2 5

    cout<<"\nValores antes del intercambio: "<<endl;
    cout<<"Primer Valor: "<<num1<<endl;
    cout<<"Segundo Valor: "<<num2<<endl;

    intercambiarValores(num1, num2);

    cout<<"\nValores después del intercambio: "<<endl;
    cout<<"Primer Valor: "<<num1<<endl;
    cout<<"Segundo Valor: "<<num2<<endl;

    return 0;
}

void intercambiarValores(int &a, int &b){

  int temp;

  temp = a; // temp = 2
  a = b; // a = 5
  b = temp; // b = 2

}
