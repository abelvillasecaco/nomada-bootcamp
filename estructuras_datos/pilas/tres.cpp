// Elabora un menú que permita gestionar una pila de números enteros y
// que tenga las siguientes opciones: apilar elemento, desapilar elemento,
// ver pila y destruir pila.
// Usa pilas estáticas y las funciones predefinidas de stack (de la Standard Template Library de C++).

#include <iostream>
#include <stack>
using namespace std;

void apilar(stack<int> &pila){

    int valor;

    cout<<"Ingresa el número a apilar: ";
    cin>>valor;

    pila.push(valor);

    cout<<"Elemento apilado correctamente."<<endl;
}

void desapilar(stack<int> &pila){

    if(pila.empty()){
      cout<<"Error: la pila está vacía."<<endl;
      return;
    }

    cout<<"Elemento eliminado: "<<pila.top()<<endl;

    pila.pop();
}

void verPila(stack<int> pila){

    if(pila.empty()){
      cout<<"Error: la pila está vacía."<<endl;
      return;
    }

    cout<<"Elementos de la pila (de arriba hacia abajo)."<<endl;

    while(!pila.empty()){
      cout<<pila.top()<<endl;

      pila.pop();
    }
}

void destruirPila(stack<int> &pila){

    while(!pila.empty()){
      pila.pop();
    }

    cout<<"La pila ha sido destruida."<<endl;
}

int main() {

    stack<int> pila;
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
        case 1: apilar(pila);
                break;
        case 2: desapilar(pila);
                break;
        case 3: verPila(pila);
                break;
        case 4: destruirPila(pila);
                break;
        case 5: cout<<"Saliendo del programa..."<<endl;
                break;
        default: cout<<"Opción inválida."<<endl;
      }

    }while(opcion != 5);

    return 0;
}
