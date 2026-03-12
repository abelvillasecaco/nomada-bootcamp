// Escribe un menú que permita gestionar una cola de números enteros y que
// tenga las siguientes opciones:

// 	- Encolar elemento
// 	- Desencolar elemento
// 	- Ver cola
// 	- Destruir cola

// Queue => Cola
// FIFO

// cola[MAX]
// frente
// final

// frente = -1
// final = -1

#include <iostream>
using namespace std;

const int MAX = 10;
int cola[MAX];
int frente = -1, final = -1;

void encolar(){
  int dato;

  if(final == MAX - 1){
    cout<<"La cola está llena, no se pueden añadir elementos."<<endl;
    return;
  }

  cout<<"Ingresa el elemento a insertar: ";
  cin>>dato; // 30

  if(frente == -1){
    frente = 0;
  }

  final++; // final = 2

  cola[final] = dato; // 10 20 30

  cout<<"Elemento encolado correctamente."<<endl;
}

void desencolar(){

    if(frente == -1 || frente > final){
      cout<<"La cola está vacía."<<endl;
      return;
    }

    cout<<"Elemento eliminado: "<<cola[frente]<<endl;

    frente++;

    if(frente > final){
      frente = -1;
      final = -1;
    }
}

void verCola(){

    if(frente == -1){
      cout<<"La cola está vacía."<<endl;
      return;
    }

    cout<<"Elementos de la cola: "<<endl;

    for(int i = frente; i <= final; i++){
      cout<<cola[i]<<" ";
    }
    cout<<endl;
}

void destruirCola(){
    frente = -1;
    final = -1;

    cout<<"La cola ha sido destruida."<<endl;
}

int main() {

    int opcion;

    do{

      cout<<endl;
      cout<<"=== MENÚ DE COLA ==="<<endl;
      cout<<"1. Encolar elemento"<<endl;
      cout<<"2. Desencolar elemento"<<endl;
      cout<<"3. Ver cola"<<endl;
      cout<<"4. Destruir cola"<<endl;
      cout<<"5. Salir"<<endl;
      cout<<"Seleccione una opción: ";
      cin>>opcion;

      switch(opcion){
        case 1: encolar();
                break;
        case 2: desencolar();
                break;
        case 3: verCola();
                break;
        case 4: destruirCola();
                break;
        case 5: cout<<"Saliendo del programa..."<<endl;
                break;
        default: cout<<"Opción inválida."<<endl;
      }

    }while(opcion != 5);

    return 0;
}
