#include "Estado.h"

Estado(){
  this->arqueologosIzq = 0;
  this->canibalesIzq = 0;
  this->arqueologosDer = 0;
  this->canibalesDer = 0;
  this->linternaDer = true;
}

Estado(int arqIzq, int caniIzq, int arqDer, int caniDer, bool linternaDerecha){
  this->arqueologosIzq = arqueologosIzq;
  this->canibalesIzq = canibalesIzq;
  this->arqueologosDer = arqueologosDer;
  this->canibalesDer = canibalesDer;
  this->linternaDer = linternaDerecha;
}

int arqueologosIzq(){
  return this->arqueologosIzq;
}

int canibalesIzq(){
  return this->canibalesIzq;
}

int arqueologosDer(){
  return this->arqueologosDer;
}

int canibalesDer(){
  return this->canibalesDer;
}

bool linternaDer(){
  return this->linternaDer
}