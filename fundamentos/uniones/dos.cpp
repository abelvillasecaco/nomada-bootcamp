// Utiliza una unión para representar un punto en un plano, permitiendo almacenar
// las coordenadas en formato cartesiano (X e Y) o en formato polar (radio y ángulo).

#include <iostream>
using namespace std;

struct Cartesiano {
  float x;
  float y;
};

struct Polar {
  float radio;
  float angulo;
};

union Punto {
  Cartesiano c;
  Polar p;
};

void ingresarCartesiano(Punto &pt) {
  cout<<"Ingresa coordenada X: ";
  cin>>pt.c.x;
  cout<<"Ingresa coordenada Y: ";
  cin>>pt.c.y;
}

void ingresarPolar(Punto &pt) {
  cout<<"Ingresa el radio: ";
  cin>>pt.p.radio;
  cout<<"Ingresa el ángulo (en grados): ";
  cin>>pt.p.angulo;
}

void mostrarCartesiano(Punto pt) {
  cout<<"X = "<<pt.c.x<<endl;
  cout<<"Y = "<<pt.c.y<<endl;
}

void mostrarPolar(Punto pt) {
  cout<<"Radio = "<<pt.p.radio<<endl;
  cout<<"Ángulo = "<<pt.p.angulo<<" grados"<<endl;
}

int main() {

    Punto pt;
    int opcion;

    cout<<"Selecciona el tipo de coordenadas: "<<endl;
    cout<<"1. Cartesianas"<<endl;
    cout<<"2. Polares"<<endl;
    cout<<"Opción: ";
    cin>>opcion;

    if(opcion == 1){
      ingresarCartesiano(pt);
      cout<<"\nCoordenadas cartesianas almacenadas: "<<endl;
      mostrarCartesiano(pt);
    } else if(opcion == 2) {
      ingresarPolar(pt);
      cout<<"\nCoordenadas polares almacenadas: "<<endl;
      mostrarPolar(pt);
    }else {
      cout<<"Opción inválida. "<<endl;
    }

    return 0;
}
