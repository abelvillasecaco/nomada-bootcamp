// Elabora un menú que permita gestionar una pila de números enteros y que tenga
// las siguientes opciones: apilar elemento, desapilar elemento, ver pila y destruir pila.
// Usa pilas dinámicas. 

// Si apilamos:
// 10 -> 20 -> 30
// tope -> [30 | *] -> [20 | *] -> [10 | NULL]

#include <iostream>
using namespace std;

struct Nodo {
  int dato;
  Nodo *siguiente;
};

void apilar(Nodo *&tope){

    int valor;

    cout<<"Ingresa el número a apilar: ";
    cin>>valor;

    Nodo *nuevo = new Nodo;

    nuevo->dato = valor;
    nuevo->siguiente = tope;

    tope = nuevo;

    cout<<"Elemento apilado correctamente."<<endl;
}

void desapilar(Nodo *&tope){

    if(tope == NULL){
      cout<<"Error: la pila está vacía."<<endl;
      return;
    }

    Nodo *aux = tope;

    cout<<"Elemento eliminado: "<<aux->dato<<endl;

    tope = aux->siguiente;

    delete aux;
}

void verPila(Nodo *tope){

    if(tope == NULL){
      cout<<"Error: la pila está vacía."<<endl;
      return;
    }

    cout<<"Elementos de la pila: "<<endl;

    Nodo *actual = tope;

    while(actual != NULL){
      cout<<actual->dato<<endl;
      actual = actual->siguiente;
    }
}

void destruirPila(Nodo *&tope){

    Nodo *aux;

    while (tope != NULL){
      aux = tope;
      tope = tope->siguiente;
      delete aux;
    }

    cout<<"La pila ha sido destruida."<<endl;
}

int main() {

    Nodo *tope = NULL;
    int opcion;

    do {
      cout<<"\n=== MENÚ DE LA PILA ===\n";
      cout<<"1. Apilar elemento"<<endl;
      cout<<"2. Desapilar elemento"<<endl;
      cout<<"3. Ver pila"<<endl;
      cout<<"4. Destruir pila"<<endl;
      cout<<"5. Salir"<<endl;
      cin>>opcion;

      switch(opcion){
        case 1: apilar(tope);
                break;
        case 2: desapilar(tope);
                break;
        case 3: verPila(tope);
                break;
        case 4: destruirPila(tope);
                break;
        case 5: cout<<"Saliendo del programa..."<<endl;
                break;
        default: cout<<"Opción inválida."<<endl;
      }

    }while(opcion != 5);

    return 0;
}
