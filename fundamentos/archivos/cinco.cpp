// Escribe un programa que lea un archivo de texto y cuente el número de líneas y palabras
// stringstream

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void contarLineasPalabras(){
  string nombreArchivo, linea;
  int lineas = 0, palabras = 0;

  cout<<"Ingresa el nombre del archivo: ";
  cin>>nombreArchivo;

  ifstream archivo(nombreArchivo);

  if(!archivo){
    cout<<"No se pudo abrir el archivo."<<endl;
    return;
  }

  while(getline(archivo, linea)){
      lineas++;
      stringstream ss(linea); // cin >>
      string palabra;
      while(ss >> palabra){ // ss >> palabra
        palabras++;
      }
  }

  archivo.close();

  cout<<"Líneas: "<<lineas<<endl;
  cout<<"Palabras: "<<palabras<<endl;

}

int main() {

    contarLineasPalabras();

    return 0;
}


// "Hola mundo desde C++"
// stringstream ss(linea);
// cin>>palabra;

// Hola
// mundo
// desde
// C++

// palabras = 4
