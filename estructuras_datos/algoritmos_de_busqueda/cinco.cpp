// Escribe un programa que permita al usuario ingresar un arreglo.
// Luego, busca un número dado y muestra la posición de su primera y 
// última aparición en el arreglo usando una función de búsqueda secuencial.

// [4, 7, 2, 7, 9, 7]
// Elemento a buscar: 7

#include <iostream>
using namespace std;

void buscar(int arr[], int n, int valor){
    int primera = -1;
    int ultima = -1;

    for(int i = 0; i < n; i++){
      if(arr[i] == valor){ // arr[5] = 7
          if(primera == -1){
                  primera = i; // primera = 1
          }
          ultima = i; // ultima = 5
      }
    }

    if(primera == -1){
      cout<<"No se encontró en el arreglo."<<endl;
    }else{
      cout<<"Primera aparición en la posición: "<<primera<<endl; // 1
      cout<<"Última aparición en la posición: "<<ultima<<endl; // 5
    }
}

int main() {

    int n;
    cout<<"Ingresa el tamaño del arreglo: ";
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++){
      cin>>arr[i];
    }

    int valor;
    cout<<"Número a buscar: ";
    cin>>valor;

    buscar(arr, n, valor);

    return 0;
}
