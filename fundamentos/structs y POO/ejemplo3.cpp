#include <iostream>
using namespace std;

class CuentaBancaria {

  private:
    double saldo;

  public:
    void setSaldo(double cantidad){ // setter
      if(cantidad >= 0){
        saldo = cantidad; // saldo = 1000.50
      }
    }

    double getSaldo(){ // getter
      return saldo;
    }
};

int main() {

    CuentaBancaria cuenta;
    cuenta.setSaldo(1000.50);
    cout<<"Saldo: "<<cuenta.getSaldo()<<endl;

    return 0;
}
