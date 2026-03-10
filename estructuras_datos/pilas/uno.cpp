// Elabora un menú que permita gestionar una pila de números enteros y que tenga las siguientes
// opciones: apilar elemento, desapilar elemento, ver pila y destruir pila. Usa pilas estáticas.

// 10 -> 20 -> 30

// pila => int[]
// tope => int
// MAX => const int

// Pila vacía: tope == -1
// Pila llena: tope == MAX - 1

// Necesito 4 funciones

#include <iostream>
using namespace std;

const int MAX = 5;

void apilar(int pila[], int &tope){

    if(tope == MAX - 1){
      cout<<"Error: La pila está llena."<<endl;
      return;
    }

    int dato;

    cout<<"Ingresa el número a apilar: ";
    cin>>dato;

    tope++;

    pila[tope] = dato;

    cout<<"Elemento apilado correctamente."<<endl;
}

void desapilar(int pila[], int &tope){

    if(tope == -1){
      cout<<"Error: La pila está vacía."<<endl;
      return;
    }

    cout<<"Elemento eliminado: "<<pila[tope]<<endl;
    tope--;
}

void verPila(int pila[], int tope){

    if(tope == -1){
      cout<<"Error: La pila está vacía."<<endl;
      return;
    }

    cout<<"\nElementos de la pila (de arriba hacia abajo): "<<endl;

    for(int i = tope; i >= 0; i--){
      cout<<pila[i]<<endl;
    }
}

void destruirPila(int &tope){

    tope = -1;

    cout<<"La pila se ha destuido."<<endl;
}

int main() {

    int pila[MAX]; // Arreglo que representa la pila
    int tope = -1;
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
        case 1: apilar(pila, tope);
                break;
        case 2: desapilar(pila, tope);
                break;
        case 3: verPila(pila, tope);
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
