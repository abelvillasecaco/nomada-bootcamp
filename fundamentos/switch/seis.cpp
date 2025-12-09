// Lee tres números que representen el día, el mes y el año, y di si forman una fecha correcta.
// Considera años bisiestos.

#include <iostream>
using namespace std;

int main() {

    int dia, mes, anio;
    cout<<"Ingresa el día: ";
    cin>>dia;
    cout<<"Ingrese el mes (1-12): ";
    cin>>mes;
    cout<<"Ingrese el año: ";
    cin>>anio;

    if (mes < 1 || mes > 12) {
      cout<<"Mes inválido."<<endl;
      return 0;
    }

    if (anio < 1) {
      cout<<"El año debe ser positivo."<<endl;
      return 0;
    }

    bool bisiesto = (anio % 400 == 0) || (anio % 4 == 0 && anio % 100 != 0);
    int diasMes = 0;

    switch (mes) {
      case 1:
      case 3:
      case 5:
      case 7:
      case 8:
      case 10:
      case 12: diasMes = 31;
               break;
      case 4:
      case 6:
      case 9:
      case 11: diasMes = 30;
               break;
      case 2: diasMes = bisiesto ? 29 : 28; // Operador ternario
              break;
      default: diasMes = 0;
               break;
    }

    if (dia >= 1 && dia <= diasMes) {
      cout<<"La fecha "<<dia<<"/"<<mes<<"/"<<anio<<" es válida."<<endl;
    } else {
      cout<<"La fecha "<<dia<<"/"<<mes<<"/"<<anio<<" es inválida."<<endl;
    }

    return 0;
}
