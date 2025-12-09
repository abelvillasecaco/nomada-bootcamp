// Escribe un programa que imprima la suma de los primeros 10 número naturales usando for

#include <iostream>
using namespace std;

int main() {

    int suma = 0;

    for(int i = 1; i <= 10; i++){
      suma += i; // suma = suma + i
      cout<<"Paso "<<i<<": "<<suma<<endl;
    }

    cout<<"La suma de los primeros 10 número naturales es: "<<suma<<endl;

    return 0;
}
