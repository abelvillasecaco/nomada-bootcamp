// Crear una estructura Producto para almacenar el nombre, precio y cantidad en
// stock de un producto en una tienda. El programa permitirá al usuario ingresar
// los datos de varios productos, luego buscará el producto con el mayor precio
// y el que tenga la mayor cantidad en stock, y mostrará sus detalles.


#include <iostream>
using namespace std;

struct Producto {
  string nombre;
  double precio;
  int stock;
};

int main() {

    Producto productos[10];
    int n;

    cout<<"Cantidad de productos: ";
    cin>>n; // 3

    for(int i = 0; i < n; i++){
      cout<<"\nProducto "<<i + 1<<endl;
      cout<<"Nombre: "<<endl;
      cin>>productos[i].nombre; // Leche // Aceite // Pan
      cout<<"Precio: "<<endl;
      cin>>productos[i].precio; // 4.5 // 11 // 4
      cout<<"Stock: "<<endl;
      cin>>productos[i].stock; // 5 // 12 // 11
    }

    int idxPrecio = 0;
    int idxStock = 0;

    for(int i = 1; i < n; i++){
      if(productos[i].precio > productos[idxPrecio].precio){
        idxPrecio = i;
      }
      if(productos[i].stock > productos[idxStock].stock){
        idxStock = i;
      }
    }

    cout<<"\nProducto con mayor precio:\n";
    cout<<productos[idxPrecio].nombre<<" - "<<productos[idxPrecio].precio<<endl;

    cout<<"\nProducto con mayor stock:\n";
    cout<<productos[idxStock].nombre<<" - "<<productos[idxStock].stock<<endl;

    return 0;
}
