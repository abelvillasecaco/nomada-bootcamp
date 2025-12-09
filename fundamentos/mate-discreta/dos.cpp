// (p -> q) === (-p V q)
// Escribe un programa que genere la tabla de verdad para p, q y muestre las columnas:
// p
// q
// p -> q
// !p || q

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    cout<<setw(3)<<"p"<<setw(4)<<"q"<<setw(8)<<"p -> q"
        <<setw(11)<<"!p || q"<<setw(12)<<"¿Coincide?"<<endl;
    cout<<string(38, '-')<<endl;

    bool all_equal = true;

    for(int i = 0; i <= 1; i++){
      for(int j = 0; j <= 1; j++){
        bool p = (i == 1);
        bool q = (j == 1);

        bool impl = (!p) || q;
        bool alt = (!p) || q;

        cout<<setw(3)<<(p ? 'V' : 'F')
            <<setw(4)<<(q ? 'V' : 'F')
            <<setw(8)<<(impl ? 'V' : 'F')
            <<setw(11)<<(alt ? 'V' : 'F')
            <<setw(12)<<((impl == alt) ? "Sí" : "No")<<endl;

        if(impl != alt) all_equal = false;
      }
    }

    cout<<string(38, '-')<<endl;
    if(all_equal){
      cout<<"Conclusión: Las columnas son idénticas en todas las filas -> Son equivalentes."<<endl;
    }else{
      cout<<"Conclusión: No son equivalentes."<<endl;
    }

    return 0;
}
