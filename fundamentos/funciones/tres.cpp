#include <iostream>
using namespace std;

void duplicarValor(int &num){
  num = num * 2;
  cout<<"Valor duplicado: "<<num<<endl;
}

int main() {

    int valor = 10; // Mando la copia del 10
    duplicarValor(valor); // Pase por Valor
    cout<<"Valor original: "<<valor<<endl;

    return 0;
}
