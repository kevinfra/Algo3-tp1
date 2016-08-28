#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <vector>
#include <string>
#include <chrono>
#include "ejercicio2.h"
#include "ejercicio1.h"

using namespace std;

static chrono::time_point<chrono::high_resolution_clock> start_time;

void start_timer() {
    start_time = chrono::high_resolution_clock::now();
}

double stop_timer() {
    chrono::time_point<chrono::high_resolution_clock> end_time = chrono::high_resolution_clock::now();
    return double(chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count());
}


int main(int argc, char *argv[]){
  int numeroDeEjercicio = 0;
  bool debug = false;
  if (argc == 2){
    numeroDeEjercicio = atoi(argv[1]);
  }else if (argc == 3){
    numeroDeEjercicio = atoi(argv[1]);
    if(atoi(argv[2]) == -100){
      debug = true;
    }
  }else{
    cout << "Debe ingresar el numero de ejercicio como parametro" << endl;
    return -1;
  }


  cout << "Corriendo ejercicio numero " << numeroDeEjercicio << endl;

  if (numeroDeEjercicio == 1){
    int cantidadArq, cantidadCanibales;

    cout << "Ingrese la cantidad de Arqueologos y luego la de Canibales: " << endl;
    cin >> cantidadArq >> cantidadCanibales;

    cout << "Ingrese las velocidades de los Arqueologos: " << endl;
    int velocidad;
    vector<int> velocidadesArq;
    while(cantidadArq > 0 && (cin >> velocidad)){
      velocidadesArq.push_back(velocidad);
      cantidadArq--;
    }

    cout << "Ingrese las velocidades de los Canibales" << endl;
    vector<int> velocidadesCanibales;
    while(cantidadCanibales > 0 && (cin >> velocidad)){
      cout << velocidad << endl;
      velocidadesCanibales.push_back(velocidad);
      cantidadCanibales--;
    }

    start_timer();
    int tiempo = cruzarPuente(velocidadesCanibales, velocidadesArq);
    cout << tiempo << endl;
    cout << "tiempo que tarda en ns: " << stop_timer() << endl;


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



