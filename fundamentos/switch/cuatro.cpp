#include <iostream>
using namespace std;

// Lee un día y mes cualquiera y determina la estación a la que pertenece.
// Verano 21 dic - 20 mar
// Otoño 21 mar - 20 jun
// Invierno 21 jun - 20 sep
// Primavera 21 sep - 20 dic

int main() {

    int dia, mes;
    cout<<"Ingresa el día (1-31): ";
    cin>>dia;
    cout<<"Ingresa el mes (1-12): ";
    cin>>mes;

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12) {
      cout<<"Fecha inválida (día o mes fuera de rango).\n";
      return 0;
    }

    switch (mes) {
      case 1:
      case 2: cout<<"Verano\n";
              break;
      case 3: if (dia <= 20) cout<<"Verano\n";
              else cout<<"Otoño\n";
              break;
      case 4:
      case 5: cout<<"Otoño\n";
              break;
      case 6: if (dia <= 20) cout<<"Otoño\n";
              else cout<<"Invierno\n";
              break;
      case 7:
      case 8: cout<<"Invierno\n";
              break;
      case 9: if (dia <= 20) cout<<"Invierno\n";
              else cout<<"Primavera\n";
              break;
      case 10:
      case 11: cout<<"Primavera\n";
               break;
      case 12: if (dia <= 20) cout<<"Primavera\n";
               else cout<<"Verano\n";
               break;
      default: cout<<"Mes inválido.\n";
               break;
    }

    return 0;
}

