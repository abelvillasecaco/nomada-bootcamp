// Escribe un programa que permita al usuario construir una lista enlazada doble ingresando
// números enteros por teclado. Luego, recorre e imprime los elementos en ambos sentidos:
// - Desde el inicio al final.
// - Desde el final al inicio.

// dato - puntero
// puntero - dato - puntero
// NULL <- 10 <-> 20 <-> 30 -> NULL

// Función insertar(cabeza, cola, valor)
//  Crear nuevo nodo
//  nuevo->dato = valor
//  nuevo->siguiente = NULL
//  nuevo->anterior = NULL

//  Si cabeza es NULL
//     cabeza = nuevo
//     cola = nuevo
//  Sino
//     cola->siguiente = nuevo
//     nuevo->anterior = cola
//     cola = nuevo
//  Fin de Función

// Imprimir desde el inicio:
// Función imprimirAdelante(cabeza)
//  actual = cabeza
//  Mientras actual != NULL
//    Imprimir actual->dato
//    actual = actual->siguiente
// Fin de función

#include <iostream>
using namespace std;

struct NodoDoble {
  int dato;
  NodoDoble *siguiente;
  NodoDoble *anterior;
};

void insertarNodoDoble(NodoDoble *&cabeza, NodoDoble *&cola, int valor){
  NodoDoble *nuevo = new NodoDoble();
  nuevo->dato = valor;
  nuevo->siguiente = NULL;
  nuevo->anterior = NULL;

  if (cabeza == NULL){
    cabeza = nuevo;
    cola = nuevo;
  }else{
    cola->siguiente = nuevo;
    nuevo->anterior = cola;
    cola = nuevo;
  }
}

void imprimirAdelante(NodoDoble *cabeza) {
  NodoDoble *actual = cabeza;

  cout<<"Recorrido desde inicio al final: "<<endl;

  while(actual != NULL) {
    cout<<actual->dato<<" <-> ";
    actual = actual->siguiente;
  }
  cout<<"NULL"<<endl;
}

void imprimirAtras(NodoDoble *cola) {
  NodoDoble *actual = cola;

  cout<<"Recorrido desde final al inicio: "<<endl;

  while(actual != NULL) {
    cout<<actual->dato<<" <-> ";
    actual = actual->anterior;
  }
  cout<<"NULL"<<endl;
}

int main() {

    NodoDoble *cabeza = NULL;
    NodoDoble *cola = NULL;

    int n, valor;

    cout<<"¿Cuántos números deseas ingresar?: ";
    cin>>n;

    for(int i = 0; i < n; i++){
      cout<<"Ingresa el número "<<i + 1<<": ";
      cin>>valor;
      insertarNodoDoble(cabeza, cola, valor);
    }

    cout<<endl;

    imprimirAdelante(cabeza);

    cout<<endl;

    imprimirAtras(cola);

    return 0;
}
