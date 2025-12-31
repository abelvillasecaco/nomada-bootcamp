// Crea una estructura Estudiante que contenga un array de 5 calificaciones.
// Luego, crea una función para calcular el promedio de las calificaciones y
// otra para mostrar los datos del estudiante.

#include <iostream>
using namespace std;

struct Estudiante {
  string nombre;
  int edad;
  float notas[5];
};

float calcularPromedio(Estudiante e){
  float suma = 0;

  for(int i = 0; i < 5; i++){
    suma += e.notas[i];
  }

  return suma / 5;
}

void mostrarEstudiante(Estudiante e){
  cout<<"Nombre: "<<e.nombre<<endl;
  cout<<"Edad: "<<e.edad<<endl;
  cout<<"Notas: ";
  for(int i = 0; i < 5; i++){
    cout<<e.notas[i]<<" ";
  }
  cout<<endl;

  cout<<"Promedio: "<<calcularPromedio(e)<<endl;
}

int main() {

    Estudiante est;

    cout<<"Ingresa el nombre del estudiante: ";
    cin>>est.nombre;

    cout<<"Ingresa la edad del estudiante: ";
    cin>>est.edad;

    for(int i = 0; i < 5; i++){
      cout<<"Ingresa la nota "<<i + 1<<": ";
      cin>>est.notas[i]; // {10, 20, 12, 15, 16}
    }

    mostrarEstudiante(est);

    return 0;
}
