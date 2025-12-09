// 1. Declara una variable de tipo int llamada edad y asígnale tu edad.
// 2. Declara una variable de tipo float llamada precio y asígnale el valor 17.99.
// 3. Declara una variable de tipo char llamada genero y asígnale la letra ‘F’.
// 4. Declara una variable de tipo double llamada distancia y asígnale el valor 12345.6789
// 5. Declara una variable de tipo bool llamada esGraduado y asígnale false.
// 6. Crea un programa que multiplique una variable float por una variable double y muestra el resultado.
// 7. Crea un programa que cambien el valor de una variable bool y muestra el nuevo valor.
// 8. Crea un programa que concatene dos variables char y muestre el resultado.
// 9. Crea un programa que compare dos variables int y muestre cuál es la mayor.
// 10. Intenta asignar un valor fuera del rango permitido para una variable int y observa qué sucede.

#include <iostream>
using namespace std;

int main() {

    // Ejercicio 1
    int edad = 32;
    cout<<"1. Edad: "<<edad<<endl;

    // Ejercicio 2
    float precio = 17.99;
    cout<<"2. Precio: "<<precio<<endl;

    // Ejercicio 3
    char genero = 'M'; // caracter
    cout<<"3. Género: "<<genero<<endl;

    // Ejercicio 4
    double distancia = 12345.6789;
    cout<<"4. Distancia: "<<distancia<<endl;

    // Ejercicio 5
    bool esGraduado = false; // 0
    cout<<"5. Es Graduado: "<<esGraduado<<endl;

    // Ejercicio 6
    float factor1 = 5.5f;
    double factor2 = 2.3, resultado = 0.00;
    resultado = factor1 * factor2;
    cout<<"6. Resultado de multiplicación: "<<resultado<<endl;

    // Ejercicio 7
    bool interruptor = true;
    cout<<"7. Valor inicial del interruptor: "<<interruptor<<endl;
    interruptor = !interruptor;
    cout<<"7. Valor final del interruptor: "<<interruptor<<endl;

    // Ejercicio 8
    char letra1 = 'H', letra2 = 'i'; // Hi
    string palabra = "";
    palabra = palabra + letra1;
    // palabra = "H"
    palabra = palabra + letra2;
    // palabra = "Hi"; => string
    cout<<"8. Concatenación de char's: "<<palabra<<endl;

    return 0;
}

// Tipos de datos
// 1. int => enteros
// 2. float => decimales => 3.14
// 3. char => caracteres => 'a', '1', '#'
// 4. double => decimales con decimales => 3.14159265358979323846
// 5. bool => booleanos => true, false
// 6. string => cadenas de caracteres => "hola mundo"

// precision(20) => cast

// camelCase (la más usada)
// snake_case
// kebab-case
