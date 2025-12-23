// Muestre la tabla de códigos ASCII
#include <iostream>
using namespace std;

int main() {

    for(int i = 32; i < 126; i++) {
      cout<<"Código: "<<i<<" -> Caracter: "<<(char)i<<endl;
    }

    return 0;
}
