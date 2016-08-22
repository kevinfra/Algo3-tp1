#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <vector>
#include "ejercicio2.h"
#include "ejercicio1.h"


using namespace std;


int main(int argc, char *argv[]){
  int numeroDeEjercicio = 0;
  if (argc == 1){
    numeroDeEjercicio = atoi(argv[1]);
  }
  cout << "Corriendo ejercicio numero " << numeroDeEjercicio << endl;
  if (numeroDeEjercicio == 1){
  //  cruzarPuente();
  }else if(numeroDeEjercicio == 2){
    long p;
    cout << "Ingresar P para ejercicio 2.  P: ";
    cin >> p;
    arreglarBalanza(p);
  }else if(numeroDeEjercicio == 3){
  //  cargarMochila();
  }else{
    cout << "numero de ejercicio no valido" << endl;
    return -1;
  }
  return 0;
}
