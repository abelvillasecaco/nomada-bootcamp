// Escribe un programa que utilice una función para intercambiar el valor de dos variables utilizando punteros.
// Muestra los valores de las variables antes y después del intercambio.

#include <iostream>
using namespace std;

void intercambiar(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int x, y;

    cout<<"Ingresa el primer valor: ";
    cin>>x; // 3
    cout<<"Ingresa el segundo valor: ";
    cin>>y; // 2

    cout<<"\nAntes del intercambio: "<<endl;
    cout<<"x = "<<x<<", y = "<<y<<endl;

    intercambiar(&x, &y);

    cout<<"\nDespués del intercambio: "<<endl;
    cout<<"x = "<<x<<", y = "<<y<<endl; // x = 2, y = 3

    return 0;
}
