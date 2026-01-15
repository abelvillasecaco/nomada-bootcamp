// Crea un programa que simule un sorteo de lotería en el que el usuario puede
// elegir 5 números diferentes entre 1 y 50. El programa debe generar 5 números
// aleatorios entre 1 y 50 como el resultado del sorteo y luego comparar los números
// elegidos por el usuario con los generados. El programa debe mostrar cuántos números acertó.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sorteoLoteria(){

  int usuario[5], sorteo[5];
  int aciertos = 0;

  cout<<"Ingresa los 5 números entre 1 y 50: "<<endl;
  for(int i = 0; i < 5; i++){
    cout<<"Ingresa el número "<<i + 1<<": ";
    cin>>usuario[i];
  }

  for(int i = 0; i < 5; i++){
    sorteo[i] = 1 + rand() % 50;
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 5; j++){
      if(usuario[i] == sorteo[j]){
        aciertos++;
      }
    }
  }

  cout<<"\nNúmeros del sorteo: "<<endl;
  for(int i = 0; i < 5; i++){
    cout<<"Número "<<i + 1<<": "<<sorteo[i]<<" "<<endl;
  }

  cout<<"\nAciertos: "<<aciertos<<endl;

}

int main() {

    srand(time(0));
    sorteoLoteria();

    return 0;
}
