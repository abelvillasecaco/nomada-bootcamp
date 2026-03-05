// Crea un programa que permita al usuario construir una lista enlazada doble ingresando números
// enteros por teclado. El programa debe incluir una función para eliminar un nodo que contenga
// un valor específico ingresado por el usuario. Luego, muestra la lista actualizada.

// Funcion eliminarNodo(cabeza, cola, valor)
// Si cabeza es NULL
//  return
// actual = cabeza
// Mientras actual != NULL y actual-> != valor
//  actual = actual->siguiente
// Si actual = NULL
//  return
// Si actual == cabeza
//  cabeza = actual->siguiente...

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

void imprimirLista(NodoDoble *cabeza) {
  NodoDoble *actual = cabeza;

  while(actual != NULL) {
    cout<<actual->dato<<" <-> ";
    actual = actual->siguiente;
  }

  cout<<"NULL"<<endl;
}

void eliminarNodo(NodoDoble *&cabeza, NodoDoble *&cola, int valor) {
  // Caso 1: lista vacía
  if(cabeza == NULL) {
    cout<<"La lista está vacía."<<endl;
    return;
  }

  NodoDoble *actual = cabeza;

  while(actual != NULL && actual->dato != valor) {
    actual = actual->siguiente;
  }

  if(actual == NULL) {
    cout<<"Valor no encontrado."<<endl;
    return;
  }

  // Caso 2: si es la cabeza
  if(actual == cabeza) {
    cabeza = actual->siguiente;
  }

  // Caso 3: si es la cola
  if(actual == cola) {
    cola = actual->anterior;
  }

  // Caso 4: reconectar nodos intermedios
  if(actual->anterior != NULL) {
    actual->anterior->siguiente = actual->siguiente;
  }

  if(actual->siguiente != NULL) {
    actual->siguiente->anterior = actual->anterior;
  }

  delete actual;

  cout<<"Nodo eliminado correctamente."<<endl;
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

    cout<<"Lista original: "<<endl;
    imprimirLista(cabeza);

    cout<<"Ingresa el valor a eliminar: ";
    cin>>valor;

    eliminarNodo(cabeza, cola, valor);

    cout<<"Lista final: "<<endl;
    imprimirLista(cabeza);

    return 0;
}
