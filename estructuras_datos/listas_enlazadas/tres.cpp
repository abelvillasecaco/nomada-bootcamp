// Crea un programa que permita al usuario ingresar una lista de números enteros.
// El programa debe incluir una función para eliminar un nodo de la lista en función de su valor.
// Finalmente, muestra los elementos restantes de la lista actualizada.

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

      while(actual->siguiente != NULL){
        actual = actual->siguiente;
      }
      actual->siguiente = nuevo;
    }
}

void eliminarPorValor(Nodo *&cabeza, int valor) {
    if(cabeza == NULL){
      cout<<"La lista está vacía."<<endl;
      return;
    }

    if(cabeza->dato == valor){
      Nodo *temp = cabeza;
      cabeza = cabeza->siguiente;
      delete temp;
      cout<<"Nodo eliminado correctamente."<<endl;
      return;
    }

    Nodo *anterior = cabeza;
    Nodo *actual = cabeza->siguiente;

    while(actual != NULL && actual->dato != valor){
      anterior = actual;
      actual = actual->siguiente;
    }

    if(actual == NULL){
      cout<<"Valor no encontrado en la lista."<<endl;
      return;
    }

    anterior->siguiente = actual->siguiente;
    delete actual;

    cout<<"Nodo eliminado correctamente."<<endl;
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
    int n, valor, eliminar;

    cout<<"¿Cuántos números deseas ingresar?: ";
    cin>>n;

    for(int i = 0; i < n; i++){
      cout<<"Ingresa el número "<<i + 1<<": ";
      cin>>valor;
      insertarFinal(cabeza, valor);
    }

    cout<<"Lista original: "<<endl;
    imprimirLista(cabeza);

    cout<<"\nIngresa el valor a eliminar: ";
    cin>>eliminar;

    eliminarPorValor(cabeza, eliminar);

    cout<<"Lista actualizada: "<<endl;
    imprimirLista(cabeza);

    return 0;
}
