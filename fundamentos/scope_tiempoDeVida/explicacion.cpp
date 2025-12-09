#include <iostream>
using namespace std;

void funcionContador() {
  static int contador = 0;
  contador++; // 4
  cout<<contador<<endl; // 4
}

int main() {

    funcionContador(); // 1
    funcionContador(); // 2
    funcionContador(); // 3
    funcionContador(); // 4

    return 0;
}
