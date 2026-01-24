// Crea un programa que permita realizar operaciones básicas (suma, resta, multiplicación y división)
// entre dos números. Usa una función que reciba punteros para devolver los resultados.

#include <iostream>
using namespace std;

void operaciones(float numero1, float numero2, float *suma, float *resta, float *multiplicacion, float *division) {
    *suma = numero1 + numero2; // *suma
    *resta = numero1 - numero2;
    *multiplicacion = numero1 * numero2;
    *division = (numero2 != 0) ? numero1 / numero2 : 0;
}

int main() {

    float numero1, numero2, suma, resta, multiplicacion, division;
    cout << "Ingrese el primer número: ";
    cin >> numero1;
    cout << "Ingrese el segundo número: ";
    cin >> numero2;

    operaciones(numero1, numero2, &suma, &resta, &multiplicacion, &division);

    cout << "El resultado de la suma es: " << suma << endl; // desreferenciar
    cout << "El resultado de la resta es: " << resta << endl;
    cout << "El resultado de la multiplicación es: " << multiplicacion << endl;
    cout << "El resultado de la división es: " << division << endl;

    return 0;
}
