#include <iostream>
using namespace std;

class Animal {
  public:
    virtual void hacerSonido(){
      cout<<"El animal hace un sonido."<<endl;
    }
};

class Gato : public Animal {
  public:
    void hacerSonido() override {
      cout<<"Miau"<<endl;
    }
};

class Perro : public Animal {
  public:
    void hacerSonido() override {
      cout<<"Guau"<<endl;
    }
};

int main() {

    Animal* animal1 = new Gato();
    Animal* animal2 = new Perro();

    animal1->hacerSonido();
    animal2->hacerSonido();

    return 0;
}
