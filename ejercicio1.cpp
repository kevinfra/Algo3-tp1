#include "estructuras.h"

void cruzarPuente(vector<int> canibales, vector<int> arqueologos){
  if()
}



void BTCruzarPuente(vector<estadosPuente> &estadosAnteriores, int &velocidad, vector<int> &velocidadesSoluciones){
  int indexUltimoEstado = estadosAnteriores.size() - 1;
  int ultimoEstado = estadosAnteriores[indexUltimoEstado];
  int cantidadCanibalesOrigen;
  int cantidadArqueologosOrigen;
  int cantidadCanibalesDestino;
  int cantidadArqueologosDestino;
  if (ultimoEstado.linternaALaDerecha){
    cantidadCanibalesOrigen = ultimoEstado[indexUltimoEstado].canibalesDerecha.size();
    cantidadArqueologosOrigen = ultimoEstado[indexUltimoEstado].arqDerecha.size();
    cantidadCanibalesDestino = ultimoEstado[indexUltimoEstado].canibalesIzquierda.size();
    cantidadArqueologosDestino = ultimoEstado[indexUltimoEstado].arqIzquierda.size();
  }else{
    cantidadCanibalesOrigen = ultimoEstado[indexUltimoEstado].canibalesIzquierda.size();
    cantidadArqueologosOrigen = ultimoEstado[indexUltimoEstado].arqIzquierda.size();
    cantidadCanibalesDestino = ultimoEstado[indexUltimoEstado].canibalesDerecha.size();
    cantidadArqueologosDestino = ultimoEstado[indexUltimoEstado].arqDerecha.size();
  }

  //TODO: falta ver el tema del alias en personasOrigen y personasDestino
  if (cantidadCanibalesOrigen + cantidadArqueologosOrigen > 0){

    for (int i = 0; i < cantidadCanibalesOrigen; ++i){
      estadosPuente nuevoEstado = ultimoEstado;
      int canibalQueSeMueve = ultimoEstado.canibalesDerecha[i]
      nuevoEstado.canibalesIzquierda.push(canibalQueSeMueve);
      nuevoEstado.canibalesDerecha.erase(i);
      nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
      if(estadoValido(nuevoEstado, estadosAnteriores)){
        estadosAnteriores.push(nuevoEstado);
        int nuevaVelocidad = velocidad + canibalQueSeMueve;
        BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
      }
    }

    for (int i = 0; i < ultimoEstado[]; ++i){
      /* code */ AWANTIA
    }

  }else{
    velocidadesSoluciones.push(velocidad);
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