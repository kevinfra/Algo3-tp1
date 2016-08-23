#include <iostream>
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atol */
#include <vector>
#include <string>
#include "ejercicio2.h"
#include "ejercicio1.h"

using namespace std;


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
    int cantidadArq, cantidadCavernicolas;

    cout << "Ingrese la cantidad de Arqueologos y luego la de Cavernicolas: " << endl;
    cin >> cantidadArq >> cantidadCavernicolas;
    if(debug){
      cout << "Nro arq: " << cantidadArq << " y nro caver: " << cantidadCavernicolas << endl;
    }

    cout << "Ingrese las velocidades de los Arqueologos: " << endl;
    int velocidad;
    vector<int> velocidadesArq;
    while(cantidadArq > 0 && (cin >> velocidad)){
      velocidadesArq.push_back(velocidad);
      cantidadArq--;
    }

    if(debug){
      cout << "velocidades arq: ";
      for (int i = 0; i < velocidadesArq.size(); ++i){
        cout << velocidadesArq[i] << ", ";
      }
      cout << endl;
    }

    cout << "Ingrese las velocidades de los Cavernicolas" << endl;
    vector<int> velocidadesCavernicolas;
    while((cin >> velocidad) && cantidadCavernicolas > 0){
      velocidadesCavernicolas.push_back(velocidad);
      cantidadCavernicolas--;
    }

    int tiempo = cruzarPuente(velocidadesCavernicolas, velocidadesArq);
    if(tiempo > -1){
      cout << "El tiempo minimo para cruzar es de " << tiempo << endl;
    }else{
      cout << "No es posible cruzar el puente y que todos los arqueologos se salven!" << endl;
    }

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

