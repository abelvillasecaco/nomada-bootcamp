// Escribe un programa que lea números enteros de un archivo y genere otro archivo que contenga
// solo los números positivos

#include <iostream>
#include <fstream>

using namespace std;

void filtrarPositivos(){
  string origen, destino;
  int numero;

  cout<<"Archivo de origen: ";
  cin>>origen;

  cout<<"Archivo de destino: ";
  cin>>destino;

  ifstream archivoOrigen(origen);
  ofstream archivoDestino(destino);

  if(!archivoOrigen || !archivoDestino){
    cout<<"Error al abrir los archivos."<<endl;
    return;
  }

  while(archivoOrigen >> numero){
    if(numero >= 0){
      archivoDestino<<numero<<endl;
    }
  }

  archivoOrigen.close();
  archivoDestino.close();

  cout<<"Archivo filtrado correctamente."<<endl;
}

int main() {

    filtrarPositivos();

    return 0;
}
