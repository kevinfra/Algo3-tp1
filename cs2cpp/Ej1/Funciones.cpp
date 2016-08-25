#include <iostream>
#include <vector>
#include <algorithm> //Sort esta en O(n*Log n) y reverse en O(n)
#include "Estado.h"

using namespace std;

void cruzarPuente(vector<int> canibalesOrigen, vector<int> arqueologosOrigen, vector<int> canibalesDestino, vector<int> arqueologosDestino, bool linternaDer, vector<Estado> estadosAnteriores, int tiempo, vector<int> soluciones){
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

    Estado nuevoEstado;
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
          if (mandarCanibales > 0)
          {
            for (int q = 0; q < mandarCanibales; ++q)
            {
              canibalesMasRapidos.push_back(nuevoCanibalesOrigen[q]);
            }

            for (int i = 0; i < mandarCanibales; i++)
            {
              int index = indexOf(canibalesMasRapidos[i], nuevoCanibalesOrigen);
              nuevoCanibalesOrigen.erase(nuevoCanibalesOrigen.begin() + index);
              nuevoCanibalesDestino.push_back(canibalesMasRapidos[i]);
            }
          }

          vector<int> arqueologosMasRapidos = new vector<int>();
          if (mandarArqueologos > 0)
          {
            arqueologosMasRapidos = nuevoArqueologosOrigen.Take(mandarArqueologos).Tovector();
            for (int i = 0; i < mandarArqueologos; i++)
            {
              nuevoArqueologosOrigen.Remove(arqueologosMasRapidos[i]);
              nuevoArqueologosDestino.Add(arqueologosMasRapidos[i]);
            }
          }

          nuevoEstado = new Estado()
          {
            arqueologosDer = arqueologosDer.size() + (linternaDer ? -1 : 1) * mandarArqueologos,
            arqueologosIzq = arqueologosIzq.size() + (linternaDer ? 1 : -1) * mandarArqueologos,
            canibalesDer = canibalesDer.size() + (linternaDer ? -1 : 1) * mandarCanibales,
            canibalesIzq = canibalesIzq.size() + (linternaDer ? 1 : -1) * mandarCanibales,
            linternaDer = nuevaLinternaDer
          };

          estadosAnteriores.Add(nuevoEstado);
          int nuevoTiempo = Tiempo + Math.Max(mandarArqueologos > 0 ? arqueologosMasRapidos.Max() : 0, mandarCanibales > 0 ? canibalesMasRapidos.Max() : 0);
          CruzarPuente(nuevoCanibalesDestino, nuevoArqueologosDestino, nuevoCanibalesOrigen, nuevoArqueologosOrigen, nuevaLinternaDer, estadosAnteriores, nuevoTiempo, Soluciones);
          estadosAnteriores.Remove(nuevoEstado);
        }
        else
        {
          Console.WriteLine("No mando");
        }
      }
    }
  }

  public bool estadoValido(int cantCanibalesOrigen, int cantArqueologosOrigen, int cantCanibalesDestino, int cantArqueologosDestino, bool linternaDer, vector<Estado> estadosAnteriores)
  {
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
