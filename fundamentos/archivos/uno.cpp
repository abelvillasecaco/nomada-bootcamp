// Escribe un algoritmo que permita escribir un archivo.

#include <iostream>
#include <fstream>
using namespace std;

void escribirArchivo(){

  string nombreArchivo, texto;

  cout<<"Ingresa el nombre del archivo: ";
  cin>>nombreArchivo;
  cin.ignore();

  cout<<"Ingresa el texto a guardar: ";
  getline(cin, texto);

  ofstream archivo(nombreArchivo);

  if(!archivo){
    cout<<"Error al cargar el archivo."<<endl;
    return;
  }

  archivo<<texto;

  archivo.close();

  cout<<"Archivo creado y escrito exitosamente."<<endl;

}

int main() {

    escribirArchivo();

    return 0;
}
