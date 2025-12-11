// Escribe una función que reciba un número entero y devuelva true si el número es
// par y false si es impar. Luego, muestra el resultado desde main.

#include <iostream>
using namespace std;

bool esPar(int numero);

int main() {

    int valor;

    cout<<"Ingresa el número a evaluar: ";
    cin>>valor;

    bool resultado = esPar(valor);
    // cout<<"Resultado: "<<resultado<<endl;
    cout<<(esPar(valor) ? "Es par" : "Es impar")<<endl;

    // if(esPar(valor)){
    //   cout<<"Es par"<<endl;
    // }else{
    //   cout<<"Es impar"<<endl;
    // }

    return 0;
}

bool esPar(int numero){
  return (numero % 2 == 0); // True o false
}
