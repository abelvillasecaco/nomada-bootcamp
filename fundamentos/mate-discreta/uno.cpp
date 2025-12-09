#include <iostream>
using namespace std;

// puedeEntrar = (edad >= 18) OR acompañado

int main() {

    int edad;
    bool acompanado;

    cout<<"Ingresa tu edad: ";
    cin>>edad;

    cout<<"¿Estás acompañado? (1 = sí, 0 = no): ";
    cin>>acompanado;

    bool puedeEntrar = (edad >= 18) || acompanado; // 12 >= 18 = false ||

    if(puedeEntrar){
      cout<<"Puedes ingresar al cine."<<endl;
    }else{
      cout<<"No puedes ingresar al cine."<<endl;
    }

    return 0;
}

