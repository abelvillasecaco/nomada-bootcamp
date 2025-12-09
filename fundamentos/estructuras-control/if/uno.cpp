#include <iostream>
using namespace std;

int main() {

    int a = 1;
    int b = 2;

    bool condicion = true; // 1

    if (a == b) {
      cout << "la primera condicion es true" << endl;
    } else if (a < b) {
      cout << "la segunda condicion es true" << endl;
    } else {
      cout << "ninguna de las condiciones es true" << endl;
    }

    return 0;
}
