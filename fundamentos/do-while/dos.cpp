// Calcula el área máxima de un terreno si las longitudes son X y (20-X).

// A = X(20-X) => 0 a 20
// El cálculo se hará hasta que el usuario ingrese un negativo

#include <iostream>
using namespace std;

int main() {

    float x;
    float area, areaMax = 0;

    do {

      cout<<"Ingresa el valor de X (negativo para terminar): ";
      cin>>x;

      if(x >= 0 && x <= 20){ // rango de 0 - 20
        area = x * (20 - x);

        if(area > areaMax) areaMax = area;
      }

    }while(x >= 0);

    cout<<"El área máxima encontrada es: "<<areaMax<<endl;

    return 0;
}

