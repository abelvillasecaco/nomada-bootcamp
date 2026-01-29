// Diseña un programa que permita al usuario ingresar un número de línea y muestre el contenido de
// esa línea en un archivo de texto.

#include <iostream>
#include <fstream>
using namespace std;

void mostrarLinea(){
  string nombreArchivo, linea;
  int lineaBuscada, contador = 0;

  cout<<"Ingrese el nombre del archivo: ";
  cin>>nombreArchivo;

  cout<<"Ingrese el número de línea a buscar: ";
  cin>>lineaBuscada;

  ifstream archivo(nombreArchivo);

  if(!archivo){
    cout<<"No se pudo abrir el archivo."<<endl;
    return;
  }

  while(getline(archivo, linea)){
    contador++;
    if(contador == lineaBuscada){
      cout<<"Línea "<<lineaBuscada<<": "<<linea<<endl;
      archivo.close();
      return;
    }
  }

  archivo.close();
  cout<<"La línea no existe."<<endl;
}

int main() {

    mostrarLinea();

    return 0;
}
