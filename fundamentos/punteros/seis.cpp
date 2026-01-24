// Escribe un programa que calcule la longitud de una cadena de caracteres (tipo char)
// sin usar la función strlen. Utiliza punteros para recorrer la cadena.

// Clave recorrer hasta encontrar '\0'
// texto = "HOLA"
// Dirección     Contenido
// 0x600.        'H'
// 0x601.        'O'
// 0x602.        'L'
// 0x603.        'A'
// 0x604.        '\0'

#include <iostream>
using namespace std;

int longitudCadena(char *texto) { // &texto[0]
    int contador = 0;
    while(*texto != '\0') { // texto (dirección) != *texto (caracter)
      contador++;
      texto++;
    }
    return contador;
}

int main() {

    char texto[100];
    cout << "Ingrese una cadena: ";
    cin >> texto; // Hola

    cout << "La longitud de la cadena es: " << longitudCadena(texto) << endl;

    return 0;
}
