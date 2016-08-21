#include <iostream>
#include "ejercicio2.h"
#include "ejercicio1.h"

using namespace std;

int main(int numeroDeEjercicio){
  cout << "Corriendo ejercicio numero " << numeroDeEjercicio << endl;
  if (numeroDeEjercicio == 1){
    cruzarPuente();
  }else if(numeroDeEjercicio == 2){
    int p;
    cout << "Ingresar P para ejercicio 2.  P: ";
    cin >> p;
    arreglarBalanza(p);
  }else if(numeroDeEjercicio == 3){
    cargarMochila();
  }else{
    cout << "numero de ejercicio no valido" << endl;
    return -1
  }
  return 0;
}
