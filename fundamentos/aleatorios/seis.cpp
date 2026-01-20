// Crea un programa que genere una contraseña aleatoria de una longitud específica ingresada por el usuario.
// La contraseña debe contener letras (mayúsculas y minúsculas), números y caracteres especiales.

#include <iostream>
using namespace std;

void generarPassword(int longitud){

  if(longitud < 9){
    cout<<"La longitud debe ser al menos de 8 caracteres."<<endl;
    return;
  }

  string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string minusculas = "abcdefghijklmnopqrstuvwxyz";
  string numeros = "0123456789";
  string especiales = "!@#$%&";

  string password = "";

  password += mayusculas[rand() % mayusculas.length()];
  password += minusculas[rand() % minusculas.length()];
  password += numeros[rand() % numeros.length()];
  password += especiales[rand() % especiales.length()];

  string todos = mayusculas + minusculas + numeros + especiales;

  for(int i = 4; i < longitud; i++){
    password += todos[rand() % todos.length()];
  }

  for(int i = 0; i < longitud; i++){
    int j = rand() % longitud;
    swap(password[i], password[j]);
  }

  cout<<"Contraseña generada: "<<password<<endl;
}

int main() {

    srand(time(0));
    int longitud;
    cout<<"Ingresa la longitud de la contraseña: ";
    cin>>longitud;

    generarPassword(longitud);

    return 0;
}

// INTERCAMBIAR
// char temp = password[i];
// password[i] = password[j];
// password[j] = temp;
