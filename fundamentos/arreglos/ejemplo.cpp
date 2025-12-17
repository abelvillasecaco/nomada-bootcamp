#include <iostream>
using namespace std;

int main() {

    int numeros[5] = {10, 20, 30, 40, 50}; // 150
    int suma = 0;

    for(int i = 0; i < 5; i++){
      suma += numeros[i]; // suma = 150
    }

    cout<<"La suma de todos los elementos es: "<<suma<<endl;

    return 0;
}
