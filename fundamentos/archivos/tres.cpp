// Escribe un programa que lea un archivo y lo copie hacia otro

#include <iostream>
#include <fstream>

using namespace std;

void copiarArchivo(){

    string origen, destino, linea;

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

    while(getline(archivoOrigen, linea)){
      archivoDestino<<linea<<endl;
    }

    archivoOrigen.close();
    archivoDestino.close();

    cout<<"Archivo copiado exitosamente."<<endl;
}

int main() {

    copiarArchivo();

    return 0;
}
