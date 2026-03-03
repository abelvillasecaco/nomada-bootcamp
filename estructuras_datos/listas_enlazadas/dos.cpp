// Escribe un programa que permita al usuario ingresar una lista de números en una lista enlazada simple.
// El programa debe incluir una opción para insertar un nuevo número en una posición específica.
// Finalmente, imprime los elementos de la lista actualizada.

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

void insertarEnPosicion(Nodo *&cabeza, int valor, int posicion) {
    if(posicion <= 0){
      cout<<"Posición inválida."<<endl;
      return;
    }

    Nodo *nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if(posicion == 1){
      nuevo->siguiente = cabeza;
      cabeza = nuevo;
      return;
    }

    Nodo *actual = cabeza;
    int contador = 1;

    while(actual != NULL && contador < posicion - 1){
      actual = actual->siguiente;
      contador++;
    }

    if(actual == NULL){
      cout<<"Posición fuera de rango."<<endl;
      delete nuevo; // Liberar memoria
      return;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
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

    int n, valor, nuevoValor, posicion;

    cout<<"¿Cuántos números deseas ingresar?: ";
    cin>>n;

    for(int i = 0; i < n; i++){
      cout<<"Ingresa el valor "<<i + 1<<": ";
      cin>>valor;
      insertarFinal(cabeza, valor);
    }

    cout<<"Lista original: "<<endl;
    imprimirLista(cabeza);

    cout<<"\nIngresa el nuevo valor a insertar: ";
    cin>>nuevoValor;
    cout<<"Ingresa la posición donde deseas insertarlo: ";
    cin>>posicion;

    insertarEnPosicion(cabeza, nuevoValor, posicion);

    cout<<"Lista actualizada: "<<endl;
    imprimirLista(cabeza);

    return 0;
}
