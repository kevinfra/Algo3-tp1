#include <cmath>
#include "estructuras.h"
#include "ejercicio2.h"

using namespace std;

void arreglarBalanza(int p) { //Costo total: O(cbrt p). Estimo que sería esto, pero hay que calcularlo bien.
  tupla res;
  if (esPotencia(p, 3)) {
    res.x = 1;
    res.y = 0;
    //1.- agregar potencia de 3 en el lado derecho de la balanza. fin.
  }else{
    //2.- Chequear primera potencia de 3 > raiz_cubo_peso y agregarla del lado izquierdo.
    //3.- Luego, chequear si es potencia de 3. En tal caso, agregarla al lado derecho. fin
    //4.- Si no, agregar la primera potencia de 3 < |resta_anterior| al lado derecho.
    //5.- Si resta_anterior + primera_potencia_menor es < 0, repetir paso 3 en adelante. Si no, repetir todo.
  }
}

bool esPotencia(int n, int b){ //Costo total: O(log n). Demostrado en clases por euclides.
  if (n > 1) {
    while (n % b == 0) {
      n /= b;
    }
  }
  return n == 1;
}