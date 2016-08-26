#include "ejercicio1.h"

using namespace std;

int cruzarPuente(vector<int> canibales, vector<int> arqueologos){
  vector<int> arqDer;
  vector<int> caniDer;
  Estado primerEstado(arqueologos, canibales, arqDer, caniDer, false);
  vector<int> resultados;
  vector<Estado> estados;
  estados.push_back(primerEstado);
  int resultado = -1;
  if(canibales.size() <= arqueologos.size()){
    BTCruzarPuente(canibales, arqueologos, estados, 0, resultados);
    resultado = minimo(resultados);
  }
  return resultado;
}

void BTCruzarPuente(vector<int> canibalesOrigen, vector<int> arqueologosOrigen, vector<int> canibalesDestino, vector<int> arqueologosDestino, bool linternaDer, vector<Estado> &estadosAnteriores, int tiempo, vector<int> &soluciones){
  vector<int> canibalesDer = linternaDer ? canibalesOrigen : canibalesDestino;
  vector<int> canibalesIzq = linternaDer ? canibalesDestino : canibalesOrigen;
  vector<int> arqueologosDer = linternaDer ? arqueologosOrigen : arqueologosDestino;
  vector<int> arqueologosIzq = linternaDer ? arqueologosDestino : arqueologosOrigen;

  canibalesOrigen = canibalesOrigen.sort().reverse();
  arqueologosOrigen = arqueologosOrigen.sort().reverse();
  canibalesDestino = canibalesDestino.sort().reverse();
  arqueologosDestino = arqueologosDestino.sort().reverse();

  bool esSolucion = canibalesIzq.size() + arqueologosIzq.size() == 0;

  if (esSolucion){
    soluciones.push_back(tiempo);
    cout << "Encontre una solución: " << tiempo << endl;

  }else{

    Estado nuevoEstado();
    vector<int> nuevoCanibalesOrigen;
    vector<int> nuevoArqueologosOrigen;
    vector<int> nuevoCanibalesDestino;
    vector<int> nuevoArqueologosDestino;

    int cantCanibalesOrigen = canibalesOrigen.size();
    int cantArqueologosOrigen = arqueologosOrigen.size();
    int cantCanibalesDestino = canibalesDestino.size();
    int cantArqueologosDestino = arqueologosDestino.size();
    bool nuevaLinternaDer = !linternaDer;

    //Mando 0 canibales y 1 arqueologo, o
    //0 canibales y 2 arqueologos, o
    //1 canibal y 1 arqueologo o
    //2 canibales o 0 arqueologos
    for (int mandarCanibales = 0; mandarCanibales <= 2; mandarCanibales++){
      for (int mandarArqueologos = mandarCanibales == 0 ? 1 : 0; mandarArqueologos <= 2 - mandarCanibales; mandarArqueologos++){
        cout << "Intento mandar " << mandarCanibales << " canibales y " << mandarArqueologos << " arqueologos hacia la " << (linternaDer ? "izquierda" : "derecha")) << endl;
        if (estadoValido(cantCanibalesOrigen - mandarCanibales, cantArqueologosOrigen - mandarArqueologos, cantCanibalesDestino + mandarCanibales, cantArqueologosDestino + mandarArqueologos, linternaDer, estadosAnteriores)){
          cout << "Mando" << endl;
          if (!linternaDer){
            cout << (linternaDer ? "Derecha" : "Izquierda") << " | A = " << (cantArqueologosOrigen - mandarArqueologos) << " | C = " << (cantCanibalesOrigen - mandarCanibales));
            cout << (linternaDer ? "Izquierda" : "Derecha") << " | A = " << (cantArqueologosDestino + mandarArqueologos) << " | C = " << (cantCanibalesDestino + mandarCanibales));
          }else{
            cout << (linternaDer ? "Izquierda" : "Derecha") << " | A = " << (cantArqueologosDestino + mandarArqueologos) << " | C = " << (cantCanibalesDestino + mandarCanibales));
            cout << (linternaDer ? "Derecha" : "Izquierda") << " | A = " << (cantArqueologosOrigen - mandarArqueologos) << " | C = " << (cantCanibalesOrigen - mandarCanibales));
          }

          //Hago una copia de las listas (para no modificar otras listas)
          nuevoCanibalesOrigen = canibalesOrigen;
          nuevoArqueologosOrigen = arqueologosOrigen;
          nuevoCanibalesDestino = canibalesDestino;
          nuevoArqueologosDestino = arqueologosDestino;

          vector<int> canibalesMasRapidos;
          if (mandarCanibales > 0){
            for (int q = 0; q < mandarCanibales; ++q){
              canibalesMasRapidos.push_back(nuevoCanibalesOrigen[q]);
            }

            for (int i = 0; i < mandarCanibales; i++){
              int index = indexOf(canibalesMasRapidos[i], nuevoCanibalesOrigen);
              nuevoCanibalesOrigen.erase(nuevoCanibalesOrigen.begin() + index);
              nuevoCanibalesDestino.push_back(canibalesMasRapidos[i]);
            }
          }

          vector<int> arqueologosMasRapidos;
          if (mandarArqueologos > 0){
            for (int q = 0; q < mandarArqueologos; ++q){
              arqueologosMasRapidos.push_back(nuevoArqueologosOrigen[q]);
            }

            for (int i = 0; i < mandarArqueologos; i++){
              int index = indexOf(arqueologosMasRapidos[i], arqueologosMasRapidos)
              nuevoArqueologosOrigen.erase(arqueologosMasRapidos.begin() + index);
              nuevoArqueologosDestino.push_back(arqueologosMasRapidos[i]);
            }
          }

          arqueologosDer = arqueologosDer.size() + (linternaDer ? -1 : 1) * mandarArqueologos;
          arqueologosIzq = arqueologosIzq.size() + (linternaDer ? 1 : -1) * mandarArqueologos;
          canibalesDer = canibalesDer.size() + (linternaDer ? -1 : 1) * mandarCanibales;
          canibalesIzq = canibalesIzq.size() + (linternaDer ? 1 : -1) * mandarCanibales;
          linternaDer = nuevaLinternaDer;

          nuevoEstado.set_estado(arqueologosIzq, canibalesIzq, arqueologosDer, canibalesDer, linternaDer);

          estadosAnteriores.push_back(nuevoEstado);
          int nuevoTiempo = tiempo + max(mandarArqueologos > 0 ? maximo(arqueologosMasRapidos) : 0, mandarCanibales > 0 ? maximo(canibalesMasRapidos) : 0);
          BTCruzarPuente(nuevoCanibalesDestino, nuevoArqueologosDestino, nuevoCanibalesOrigen, nuevoArqueologosOrigen, nuevaLinternaDer, estadosAnteriores, nuevoTiempo, soluciones);
          estadosAnteriores.pop_back();

        }else{
          cout << "No mando" << endl;
        }
      }
    }
  }
}

  bool estadoValido(int cantCanibalesOrigen, int cantArqueologosOrigen, int cantCanibalesDestino, int cantArqueologosDestino, bool linternaDer, vector<Estado> estadosAnteriores){
    if (cantCanibalesOrigen < 0 || cantArqueologosOrigen < 0)
      return false;

    int canibalesDer = linternaDer ? cantCanibalesOrigen : cantCanibalesDestino;
    int canibalesIzq = linternaDer ? cantCanibalesDestino : cantCanibalesOrigen;
    int arqueologosDer = linternaDer ? cantArqueologosOrigen : cantArqueologosDestino;
    int arqueologosIzq = linternaDer ? cantArqueologosDestino : cantArqueologosOrigen;

    if ((0 < arqueologosDer && arqueologosDer < canibalesDer) ||
      (0 < arqueologosIzq && arqueologosIzq < canibalesIzq))
      return false;

    for (int i = 0; i < estadosAnteriores.size(); i++)
    {
      Estado estadoAnterior = estadosAnteriores[i];
      if (estadoAnterior.arqueologosDer == arqueologosDer &&
        estadoAnterior.canibalesDer == canibalesDer &&
        estadoAnterior.linternaDer == !linternaDer)
        return false;
    }

    return true;
  }
}

int indexOf(int valor, vector<int> lista){
  int largo = lista.size();
  for (int k = 0; k < largo; ++k){
    if(lista[k] == valor){
      return k;
    }
  }
  return -1;
}

int maximo(vector<int> lista){
  int largo = lista.size();
  if (largo > 0) int res = lista[0];
  for (int k = 0; k < largo; ++k){
    if (res < lista[k]) res = lista[k];
  }
}

int minimo(vector<int> lista){
  int largo = lista.size();
  if (largo > 0) int res = lista[0];
  for (int k = 0; k < largo; ++k){
    if (res > lista[k]) res = lista[k];
  }
}