// Crea un programa que permita al usuario ingresar una lista de números enteros,
// los cuales serán almacenados en una lista enlazada simple. Luego, el programa debe
// imprimir todos los números almacenados en la lista.

#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *siguiente;
};

void insertarFinal(Nodo *&cabeza, int valor) {
    Nodo *nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(cabeza == NULL){
      cabeza = nuevo;
    }else{
      Nodo *actual = cabeza;
      while(actual->siguiente != NULL) {
        actual = actual->siguiente;
      }
      actual->siguiente = nuevo;
    }
}

void imprimirLista(Nodo *cabeza) {
    Nodo *actual = cabeza;

    while(actual != NULL) {
      cout<<actual->dato<<" -> ";
      actual = actual->siguiente;
    }
    cout<<"NULL"<<endl;
}

int main() {

    Nodo *cabeza = NULL;

    int n, valor;

    cout<<"¿Cuántos números deseas ingresar?: ";
    cin>>n;

    for(int i = 0; i < n; i++){
      cout<<"Ingresa el valor "<<i + 1<<": ";
      cin>>valor;
      insertarFinal(cabeza, valor);
    }

    cout<<"Lista almacenada: "<<endl;
    imprimirLista(cabeza);

    return 0;
}
