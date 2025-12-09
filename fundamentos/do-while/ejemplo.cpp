#include <iostream>
using namespace std;
// Imprimer los números del 1 al 5

int main() {

    int contador = 1;

    do {
      cout<<"Contador: "<<contador<<endl; // Contador: 5
      contador++; // Contador: 6
    }while(contador <= 5);

    return 0;
}
