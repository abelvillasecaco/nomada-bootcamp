// Un vehículo recorre N distancias en N tiempos diferentes.
// Cuál será su velocidad promedio para toda la trayectoria?

// Vprom = distanciaTotal / tiempoTotal

// 1 => 10 km => 1h
// 2 => 20 km => 2h

// DistanciaTotal = 30km
// TiempoTotal = 3h
// Vprom = 30 / 3 = 10 km/h

#include <iostream>
using namespace std;

int main() {

    int N;
    double distancia, tiempo;
    double sumDist = 0.0;
    double sumTiempo = 0.0;

    cout<<"Ingresa la cantidad de segmentos: ";
    cin>>N;

    for(int i = 1; i <= N; i++){
      cout<<"Segmento "<<i<<" - ingresa la distancia: ";
      cin>>distancia;

      cout<<"Segmento "<<i<<" - ingresa el tiempo: ";
      cin>>tiempo;

      sumDist += distancia;
      sumTiempo += tiempo;
    }

    if(sumTiempo > 0.0){
      double vProm = sumDist / sumTiempo;

      cout<<"Distancia Total: "<<sumDist<<endl;
      cout<<"Tiempo Total: "<<sumTiempo<<"h"<<endl;
      cout<<"Velocidad Promedio: "<<vProm<<"km/h"<<endl;
    }else{
      cout<<"Tiempo = 0, no se puede calcular la velocidad promedio."<<endl;
    }

    return 0;
}
