// Muestra una figura de asteriscos con validación (triángulo)

// El usuario ingresa un número N entre 1 y 10

// N = 5

// *
// **
// ***
// ****
// *****

#include <iostream>
using namespace std;

int main() {
    int N;

    cout << "Ingrese un numero entre 1 y 10: ";
    cin >> N;

    if (N < 1 || N > 10) {
        cout << "ERROR: Debe ingresar un numero entre 1 y 10." << endl;
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
