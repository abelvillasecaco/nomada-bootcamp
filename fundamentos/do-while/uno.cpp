// Lee una serie de números hasta ingresar el valor de 0. Luego indica cuántos números positivos,
// negativos, pares e impares fueron ingresados.

#include <iostream>
using namespace std;

int main() {

    int numero;
    int positivos = 0, negativos = 0, pares = 0, impares = 0; // Contadores

    do {
      cout<<"Ingrese un número (0 para finalizar): ";
      cin>>numero;

      if(numero != 0){
        if(numero > 0){
          positivos++;
        }else{
          negativos++;
        }

        if(numero % 2 == 0){
          pares++;
        }else{
          impares++;
        }
      }
    }while(numero != 0);

    cout<<"Positivo: "<<positivos<<endl;
    cout<<"Negativo: "<<negativos<<endl;
    cout<<"Pares: "<<pares<<endl;
    cout<<"Impares: "<<impares<<endl;

    return 0;
}
