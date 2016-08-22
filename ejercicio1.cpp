#include "ejercicio1.h"

using namespace std;

int cruzarPuente(std::vector<int> canibales, std::vector<int> arqueologos){
  return 0;
}



void BTCruzarPuente(vector<estadosPuente> &estadosAnteriores, int &velocidad, vector<int> &velocidadesSoluciones){
  int indexUltimoEstado = estadosAnteriores.size() - 1;
  estadosPuente ultimoEstado = estadosAnteriores[indexUltimoEstado];
  int cantidadCanibalesOrigen;
  int cantidadArqueologosOrigen;
  int cantidadCanibalesDestino;
  int cantidadArqueologosDestino;
  //TODO: falta ver el tema del alias en personasOrigen y personasDestino
  if (ultimoEstado.linternaALaDerecha){
    cantidadCanibalesOrigen = ultimoEstado.canibalesDerecha.size();
    cantidadArqueologosOrigen = ultimoEstado.arqDerecha.size();
    cantidadCanibalesDestino = ultimoEstado.canibalesIzquierda.size();
    cantidadArqueologosDestino = ultimoEstado.arqIzquierda.size();
    if (cantidadCanibalesOrigen + cantidadArqueologosOrigen > 0){

      for (int i = 0; i < cantidadCanibalesOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int canibalQueSeMueve = ultimoEstado.canibalesDerecha[i];
        nuevoEstado.canibalesIzquierda.push_back(canibalQueSeMueve);
        nuevoEstado.canibalesDerecha.erase(i);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + canibalQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
        }
      }

      for (int i = 0; i < cantidadArqueologosOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int arqueologoQueSeMueve = ultimoEstado.arqDerecha[i]
        nuevoEstado.arqIzquierda.push_back(arqueologoQueSeMueve);
        nuevoEstado.arqDerecha.erase(i);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + arqeologoQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
        }
      }

    }else{
      velocidadesSoluciones.push_back(velocidad);
    }
  }else{
    cantidadCanibalesOrigen = ultimoEstado[indexUltimoEstado].canibalesIzquierda.size();
    cantidadArqueologosOrigen = ultimoEstado[indexUltimoEstado].arqIzquierda.size();
    cantidadCanibalesDestino = ultimoEstado[indexUltimoEstado].canibalesDerecha.size();
    cantidadArqueologosDestino = ultimoEstado[indexUltimoEstado].arqDerecha.size();
  }

}


bool estadoValido(estadosPuente &nuevoEstado, vector<estadosPuente> &estadosAnteriores){
  int cantidadArqDerecha = nuevoEstado.arqDerecha.size();
  int cantidadArqIzquierda = nuevoEstado.arqIzquierda.size();
  int cantidadCanibalesDerecha = nuevoEstado.canibalesDerecha.size();
  int cantidadCanibalesIzquierda = nuevoEstado.canibalesIzquierda.size();
  bool linternaEnLaDerecha = nuevoEstado.linternaALaDerecha;

  for (int i = 0; i < estadosAnteriores.size(); ++i){
    if ((cantidadArqDerecha == estadosAnteriores[i].arqDerecha.size() &&
      cantidadCanibalesDerecha == estadosAnteriores[i].canibalesDerecha.size() &&
      linternaEnLaDerecha == estadosAnteriores[i].linternaALaDerecha) ||
      ((cantidadArqDerecha > 0 && cantidadArqDerecha < cantidadCanibalesDerecha) || (cantidadArqIzquierda > 0 && cantidadArqIzquierda < cantidadCanibalesIzquierda))){
      return false;
    }
  }
  return true;
}