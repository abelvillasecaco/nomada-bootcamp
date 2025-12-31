#include <iostream>
using namespace std;

class Animal {
  public:
    void comer(){
      cout<<"El animal está comiendo."<<endl;
    }
};

class Perro : public Animal {
  public:
    void ladrar(){
      cout<<"Guau"<<endl;
    }
};

int main() {

    Perro perro;
    perro.comer();
    perro.ladrar();

    return 0;
}
