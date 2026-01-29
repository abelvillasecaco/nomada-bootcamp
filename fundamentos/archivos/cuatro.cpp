// Diseña un programa que lea un archivo de texto y genere una copia con todas las letras convertidas a mayúsculas.

// toupper(); => convierte a mayúsculas
// texto

// Escribe un programa que lea un archivo y lo copie hacia otro

#include <iostream>
#include <fstream>
#include <cctype>

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
      for(char &c : linea){ // palabra
        c = toupper(c); // P
      }
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

