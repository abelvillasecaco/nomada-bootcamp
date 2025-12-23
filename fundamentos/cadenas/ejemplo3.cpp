// Comparación de cadenas
#include <iostream>
#include <string>
using namespace std;

int main() {

    string palabra1 = "casa";
    string palabra2 = "Casa";

    if(palabra1 == palabra2) {
      cout<<"Las palabras son iguales"<<endl;
    }else{
      cout<<"Las palabras son distintas"<<endl;
    }

    return 0;
}

// Case sensitive
