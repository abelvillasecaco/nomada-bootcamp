// Escribe una función que reciba una temperatura en grados Celsius y la convierta a Fahrenheit.
// F = (C * 9/5) + 32
#include <iostream>
using namespace std;

float celsiusAFahrenheit(float celsius){
  return (celsius * 9.0 / 5.0) + 32;
}

int main() {
    float temperatura;
    cout<<"Ingresa la temperatura en Celsius: ";
    cin>>temperatura;

    cout<<"La temperatura en Fahrenheit es: "<<celsiusAFahrenheit(temperatura)<<endl;

    return 0;
}
