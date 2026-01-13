// Crea un programa que permita a un usuario elegir el tamaño de una pizza usando un enum.
// Los tamaños disponibles son Pequeña, Mediana, y Grande. Crea una función que reciba el
// tamaño seleccionado y muestre el precio correspondiente.

#include <iostream>
using namespace std;

enum TamanoPizza {
  PEQUENA = 1,
  MEDIANA,
  GRANDE
};

void mostrarPrecio(TamanoPizza t) {
  if(t == PEQUENA) {
    cout<<"Pizza Pequeña - Precio: S/. 15.00"<<endl;
  }else if(t == MEDIANA
  ) {
    cout<<"Pizza Mediana - Precio: S/. 25.00"<<endl;
  }else if(t == GRANDE) {
    cout<<"Pizza Grande - Precio: S/. 35.00"<<endl;
  }else {
    cout<<"Tamaño inválido."<<endl;
  }
}

int main() {

    int opcion;

    cout<<"Seleccione el tamaño de pizza: "<<endl;
    cout<<"1. Pequeña"<<endl;
    cout<<"2. Mediana"<<endl;
    cout<<"3. Grande"<<endl;
    cout<<"Opción: ";
    cin>>opcion;

    mostrarPrecio(static_cast<TamanoPizza>(opcion));

    return 0;
}
