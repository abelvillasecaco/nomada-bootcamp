// Reeplazar parte de una cadena
#include <iostream>
#include <string>
using namespace std;

int main() {

    string frase = "Aprender es divertido";
    frase.replace(0, 8, "Enseñar");
    cout<<"La frase con el cambio es: "<<frase<<endl;

    return 0;
}
