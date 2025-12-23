#include <iostream>
#include <string>
using namespace std;

int main() {

    string texto = "Programación en C++";
    cout<<"Longitud de la cadena: "<<texto.length()<<endl;

    string subcadena = texto.substr(0, 13);
    cout<<"La subcadena es: "<<subcadena<<endl;

    size_t pos = texto.find("C++");
    if(pos != string::npos) { // no position
      cout<<"La palabra C++ se encuentra en la cadena en la posición: "<<pos<<endl;
    }else{
      cout<<"La palabra C++ no se encuentra en la cadena"<<endl;
    }

    return 0;
}

// Operador de resolución de ámbito
