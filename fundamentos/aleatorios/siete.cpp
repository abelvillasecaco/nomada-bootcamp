// Crea un programa que genere una lista de números aleatorios en un rango definido por el usuario
// y separe los números en pares e impares.

// 10 - 30
// 7 (3, 6, 1, 7, 2, 11, 9)

#include <iostream>
using namespace std;

void paresImpares(){
  int cantidad, min, max;
  cout<<"Ingresa la cantidad, el mínimo y el máximo: ";
  cin>>cantidad>>min>>max;

  int numeros[cantidad];

  cout<<"Números generados: ";
  for(int i = 0; i < cantidad; i++){
    numeros[i] = min + rand() % (max - min + 1);
    cout<<numeros[i]<< " ";
  }

  cout<<endl;

  cout<<"Pares: ";
  for(int i = 0; i < cantidad; i++){
    if(numeros[i] % 2 == 0){
      cout<<numeros[i]<<" ";
    }
  }

  cout<<endl;

  cout<<"Impares: ";
  for(int i = 0; i < cantidad; i++){
    if(numeros[i] % 2 != 0){
      cout<<numeros[i]<<" ";
    }
  }
}

int main() {

    srand(time(0));
    paresImpares();

    return 0;
}
