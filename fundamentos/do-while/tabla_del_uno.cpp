// Elabora la tabla del uno usando do-while

#include <iostream>
using namespace std;

int main() {

    int numero = 1, resultado;

    do {
      resultado = numero * 1;
      cout<<"1 * "<<numero<<" = "<<resultado<<endl;
      numero++;
    }while(numero <= 12);

    return 0;
}
