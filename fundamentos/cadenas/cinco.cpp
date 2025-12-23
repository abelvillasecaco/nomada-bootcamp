// Escribe un programa que verifique si una cadena es un palíndromo. Ignora espacios y diferencias
// entre mayúsculas y minúsculas.

// HolA
// <cctype>
// isalpha
// A - Z / a - z

#include <iostream>
#include <string>
#include <cctype> // isalpha, toupper, tolower
using namespace std;

string limpiarCadena(string texto){
  string resultado = "";

  for(int i = 0; i < texto.length(); i++){ // ABEL
    if(isalpha(texto[i])){
      resultado += tolower(texto[i]);
    }
  }
  return resultado;
}

bool esPalindromo(string texto){
  int inicio = 0;
  int fin = texto.length() - 1;

  while(inicio < fin){
    if(texto[inicio] != texto[fin]){
      return false;
    }
    inicio++;
    fin--;
  }
  return true;
}

int main() {

    string cadena;
    cout<<"Introduce una cadena: ";
    getline(cin, cadena);

    string limpia = limpiarCadena(cadena);

    if(esPalindromo(limpia)){
      cout<<"Es un palindromo"<<endl;
    }else{
      cout<<"No es un palindromo"<<endl;
    }

    return 0;
}
