// Diseña un programa que genere un tablero de números aleatorios de tamaño 
// N x N (ingresado por el usuario) y encuentre la suma de los valores en la diagonal principal.

#include <iostream>
using namespace std;

void sumaDiagonal(){
  int n;
  cout<<"Ingresa N: ";
  cin>>n;

  int matriz[n][n];
  int suma = 0;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      matriz[i][j] = rand() % 10;
      cout<<matriz[i][j]<<" ";
      if(i == j){
        suma += matriz[i][j];
      }
    }
    cout<<endl;
  }
  cout<<"Suma diagonal principal: "<<suma<<endl;
}

int main() {

    srand(time(0));
    sumaDiagonal();

    return 0;
}
