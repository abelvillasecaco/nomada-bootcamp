// Ingreso de notas con validaciones múltiples

// El usuario debe ingresar la cantidad de N notas
// Validar que N sea mayor o igual que 0 usando while
// Luego, por cada nota:
// - Validar que cada nota esté entre 0 y 20 usando do-while
// - Acumularlas (usado for). Al final usar un if para indicar si el
// promedio final es aprobado (>=13) o desaprobado (<13)

#include <iostream>
using namespace std;

int main() {

    int n;
    double suma = 0.0, nota;

    cout<<"Ingresa la cantidad de notas: ";
    cin>>n;

    while(n <= 0){
      cout<<"N debe ser mayor que 0.";
      cin>>n;
    }

    for(int i = 1; i <= n; i++){

      do{

        cout<<"Ingresa la nota "<<i<<" (0 - 20): ";
        cin>>nota;

        if(nota < 0 || nota > 20){
          cout<<"Nota inválida."<<endl;
        }

      }while(nota < 0 || nota > 20);

      suma += nota;
    }

    double promedio = suma / n;

    cout<<"Promedio final: "<<promedio<<endl;

    if(promedio >= 13){
      cout<<"Alumno aprobado."<<endl;
    }else{
      cout<<"Alumno desaprobado."<<endl;
    }

    return 0;
}
