// Escribe un programa que utilice un enum class para representar los días de la semana.
// El usuario deberá ingresar un número del 1 al 7 para seleccionar un día.
// El programa deberá mostrar el nombre del día correspondiente y si es un día laboral o un día de fin de semana.
// Usa funciones para manejar la lógica.

#include <iostream>
using namespace std;

enum class DiaSemana {
  Lunes = 1,
  Martes,
  Miercoles,
  Jueves,
  Viernes,
  Sabado,
  Domingo
};

void mostrarDia(DiaSemana dia) {
  switch(dia){
    case DiaSemana::Lunes: cout<<"Lunes"<<endl; break;
    case DiaSemana::Martes: cout<<"Martes"<<endl; break;
    case DiaSemana::Miercoles: cout<<"Miércoles"<<endl; break;
    case DiaSemana::Jueves: cout<<"Jueves"<<endl; break;
    case DiaSemana::Viernes: cout<<"Viernes"<<endl; break;
    case DiaSemana::Sabado: cout<<"Sábado"<<endl; break;
    case DiaSemana::Domingo: cout<<"Domingo"<<endl; break;
    default: cout<<"Día inválido."; break;
  }
}

void tipoDia(DiaSemana dia) {
  if(dia == DiaSemana::Sabado || dia == DiaSemana::Domingo){
    cout<<"Es fin de semana."<<endl;
  }else{
    cout<<"Es día laboral."<<endl;
  }
}

int main() {

    int numero;

    cout<<"Ingresa un número del 1 al 7: ";
    cin>>numero;

    DiaSemana dia = static_cast<DiaSemana>(numero);

    mostrarDia(dia);
    tipoDia(dia);

    return 0;
}
