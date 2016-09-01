#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <utility>
#include <vector>
#include <list>
#include <string>
#include <chrono>
#include "ejercicio1.h"
#include "ejercicio2.h"

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
  bool experimentos = false;
  if (argc == 2){
    numeroDeEjercicio = atoi(argv[1]);
  }else if (argc == 3){
    numeroDeEjercicio = atoi(argv[1]);
    string exp = argv[2];
    if(exp == "-exp"){
      experimentos = true;
    }
  }else{
    cout << "Modo de uso: \n tp1 numeroDeEjercicio \n Opcional luego del numero de ejercicio: " << endl;
    cout << "   -exp para experimentos" << endl;
    return -1;
  }


  if (!experimentos) cout << "Corriendo ejercicio numero " << numeroDeEjercicio << endl;

  if (numeroDeEjercicio == 1){
    if(!experimentos){
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
        velocidadesCanibales.push_back(velocidad);
        cantidadCanibales--;
      }

      start_timer();
      int tiempo = cruzarPuente(velocidadesCanibales, velocidadesArq);
      cout << tiempo << endl;
      cout << "tiempo que tarda en nanosegundos: " << stop_timer() << endl;

    }else{
      vector<int> canibales;
      vector<int> arqueologos;
      for (int q = 0; q < 4; ++q){
        for (int k = 0; k < 4; ++k){
          arqueologos.push_back(k);
          for (int times = 0; times < 30; ++times){
            start_timer();
            cruzarPuente(canibales, arqueologos);
            cout << stop_timer() << "    " << canibales.size() + arqueologos.size() << endl;
          }
        }
        arqueologos.clear();
        canibales.push_back(q);
      }
    }


  }else if(numeroDeEjercicio == 2){
    if(!experimentos){
      long p;
      cout << "Ingresar P para ejercicio 2.  P: ";
      cin >> p;
      pair<list< long >, list< long > > balanza(arreglarBalanza(p));
      list<long> izquierdas = balanza.first;
      list<long> derechas = balanza.second;
      // Mostrar en pantalla los resultados
      cout << izquierdas.size() << " " << derechas.size() << endl;
      for (list<long>::iterator itIzq = izquierdas.begin(); itIzq != izquierdas.end(); itIzq++) {
        cout << *itIzq << " ";
      }
      cout << endl;
      for (list<long>::iterator itDer = derechas.begin(); itDer != derechas.end(); itDer++) {
        cout << *itDer << " ";
      }
      cout << endl;
    }else{
      int p = 1;
      for (int q = 0; q < 500; ++q){
        for (int i = 0; i < 50; ++i){
          start_timer();
          arreglarBalanza(p);
          cout << stop_timer() << "    " << p << endl;
        }
        p += 111;
      }
    }


  }else if(numeroDeEjercicio == 3){
  //  cargarMochila();
  }else{
    cout << "numero de ejercicio no valido" << endl;
    return -1;
  }
  return 0;
}



