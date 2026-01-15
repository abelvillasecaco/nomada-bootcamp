// Crea un programa que simule el lanzamiento de un dado de 6 caras.
// El usuario debe ingresar la cantidad de veces que desea lanzar el dado.
// El programa debe mostrar el resultado de cada lanzamiento y, al final,
// la cantidad de veces que apareció cada número (1 a 6).

// int num = min + rand() % (max - min + 1) => un aleatorio en un rango de números

#include <iostream>
#include <cstdlib>
#include <ctime>
// Desde C++ 11
using namespace std;

void lanzarDado(int lanzamientos){
  int conteo[6] = {0}; // {0, 0, 0, 0, 0, 0}

  for(int i = 1; i <= lanzamientos; i++){
    int dado = 1 + rand() % 6;
    cout<<"Lanzamiento "<<i<<": "<<dado<<endl;
    conteo[dado - 1]++;
  }

  cout<<"\nResultados finales\n";
  for(int i = 0; i < 6; i++){
    cout<<"Número "<<(i + 1)<<": "<<conteo[i]<<" veces"<<endl;
  }
}

int main() {

    srand(time(0));

    int lanzamientos;
    cout<<"Ingresa la cantidad de lanzamientos: ";
    cin>>lanzamientos;

    lanzarDado(lanzamientos);

    return 0;
}
