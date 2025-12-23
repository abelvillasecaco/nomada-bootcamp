// Lee una palabra en mayúsculas y mediante una función conviértela a minúsculas.
#include <iostream>
using namespace std;

void convertirMinusculas(char palabra[]) { // ABEL => abel
  int i = 0;

  while(palabra[i] != '\0') {
    if(palabra[i] >= 'A' && palabra[i] <= 'Z') {
      palabra[i] = palabra[i] + 32;
    }
    i++;
  }
}

int main() {

    char palabra[50];

    cout<<"Introduce una palabra: ";
    cin>>palabra; // ABEL

    convertirMinusculas(palabra);

    cout<<"La palabra convertida es: "<<palabra<<endl;

    return 0;
}
