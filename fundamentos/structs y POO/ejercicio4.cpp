// Escribe un programa que mediante un menú, gestione los datos de un conjunto de
// alumnos en un curso determinado. Deberá tener las opciones de ingreso, consulta,
// modificación, eliminación y listado.

// CRUD => Create, Read, Update, Delete

#include <iostream>
using namespace std;

struct Alumno{
  string nombre;
  int edad;
  bool activo;
};

void listar(Alumno a[], int n){
  for(int i = 0; i < n; i++){
    if(a[i].activo){
      cout<<i<<" - "<<a[i].nombre<<" ("<<a[i].edad<<") "<<endl;
    }
  }
}

void consultar(Alumno a[], int n){
  int idx;
  cout<<"Ingresa la posición a consultar: ";
  cin>>idx;

  if(idx >= 0 && idx < n && a[idx].activo){
    cout<<"Nombre: "<<a[idx].nombre<<endl;
    cout<<"Edad: "<<a[idx].edad<<endl;
  }else{
    cout<<"Alumno no existe o está eliminado. "<<endl;
  }
}

void modificar(Alumno a[], int n){
  int idx;
  cout<<"Ingresa la posición a modificar: ";
  cin>>idx;

  if(idx >= 0 && idx < n && a[idx].activo){
    cout<<"Nuevo nombre: ";
    cin>>a[idx].nombre;

    cout<<"Nueva edad: ";
    cin>>a[idx].edad;

    cout<<"Alumno modificado correctamente."<<endl;
  }else{
    cout<<"Alumno no existe o está eliminado. "<<endl;
  }
}

int main() {

    Alumno alumnos[20];
    int i = 0, opc;

    do {

      cout<<"\n1. Ingresar\n2. Consultar\n3. Modificar\n4. Eliminar\n5. Listar\n0. Salir"<<endl;
      cin>>opc;

      if(opc == 1){
        cout<<"Nombre: ";
        cin>>alumnos[i].nombre;
        cout<<"Edad: ";
        cin>>alumnos[i].edad;
        alumnos[i].activo = true;
        i++;
      }else if (opc == 2){
        consultar(alumnos, i);
      }else if (opc == 3){
        modificar(alumnos, i);
      }else if(opc == 4){

        int idx;
        cout<<"Ingresa la posición a eliminar: ";
        cin>>idx;

        if(idx >= 0 && idx < i && alumnos[idx].activo){
          alumnos[idx].activo = false;

          cout<<"Alumno eliminado correctamente."<<endl;
        }else{
          cout<<"Alumno no existe o ya está eliminado. "<<endl;
        }
      }else if(opc == 5){
        listar(alumnos, i);
      }

    }while(opc != 0);

    return 0;
}
