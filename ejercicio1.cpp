#include "ejercicio1.h"

using namespace std;

int cruzarPuente(vector<int> canibales, vector<int> arqueologos){
  estadosPuente primerEstado;
  primerEstado.arqDerecha = arqueologos;
  primerEstado.canibalesDerecha = canibales;
  primerEstado.linternaALaDerecha = true;
  vector<int> resultados;
  vector<estadosPuente> estados;
  estados.push_back(primerEstado);
  BTCruzarPuente(estados, 0, resultados);
  int resultado = dameMinimoTiempo(resultados);
  return resultado;
}



void BTCruzarPuente(vector<estadosPuente> &estadosAnteriores, int velocidad, vector<int> &velocidadesSoluciones){
  int indexUltimoEstado = estadosAnteriores.size() - 1;
  estadosPuente ultimoEstado = estadosAnteriores[indexUltimoEstado];
  int cantidadCanibalesOrigen = ultimoEstado.canibalesDerecha.size();
  int cantidadArqueologosOrigen = ultimoEstado.arqDerecha.size();
  int cantidadCanibalesDestino = ultimoEstado.canibalesIzquierda.size();
  int cantidadArqueologosDestino = ultimoEstado.arqIzquierda.size();

  if (cantidadCanibalesOrigen + cantidadArqueologosOrigen > 0){

    if (ultimoEstado.linternaALaDerecha){

      for (int i = 0; i < cantidadCanibalesOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int canibalQueSeMueve = ultimoEstado.canibalesDerecha[i];
        nuevoEstado.canibalesIzquierda.push_back(canibalQueSeMueve);
        nuevoEstado.canibalesDerecha.erase(nuevoEstado.canibalesDerecha.begin() + i);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + canibalQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
          estadosAnteriores.pop_back();
        }
      }

      for (int i = 0; i < cantidadArqueologosOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int arqueologoQueSeMueve = ultimoEstado.arqDerecha[i];
        nuevoEstado.arqIzquierda.push_back(arqueologoQueSeMueve);
        nuevoEstado.arqDerecha.erase(nuevoEstado.arqDerecha.begin() + i);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + arqueologoQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
          estadosAnteriores.pop_back();
        }
      }

      for (int i = 0; i < cantidadArqueologosOrigen; ++i){
        for (int k = 0; k < cantidadCanibalesOrigen; ++k){
          estadosPuente nuevoEstado = ultimoEstado;
          int canibalQueSeMueve = ultimoEstado.canibalesDerecha[k];
          int arqueologoQueSeMueve = ultimoEstado.arqDerecha[k];
          nuevoEstado.canibalesIzquierda.push_back(canibalQueSeMueve);
          nuevoEstado.arqIzquierda.push_back(arqueologoQueSeMueve);
          nuevoEstado.canibalesDerecha.erase(nuevoEstado.canibalesDerecha.begin() + k);
          nuevoEstado.arqDerecha.erase(nuevoEstado.arqDerecha.begin() + k);
          nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
          if(estadoValido(nuevoEstado, estadosAnteriores)){
            estadosAnteriores.push_back(nuevoEstado);
            int nuevaVelocidad = velocidad + canibalQueSeMueve + arqueologoQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

      for (int i = 0; i < cantidadCanibalesOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int primerCanibalQueSeMueve = ultimoEstado.canibalesDerecha[i];
        nuevoEstado.canibalesIzquierda.push_back(primerCanibalQueSeMueve);
        nuevoEstado.canibalesDerecha.erase(nuevoEstado.canibalesDerecha.begin() + i);
        int cantidadCanibalesOrigenMenosUno = cantidadCanibalesOrigen - 1;
        for (int k = 0; k < cantidadCanibalesOrigenMenosUno; ++k){
          estadosPuente nuevoEstadoDoble = nuevoEstado;
          int segundoCanibalQueSeMueve = nuevoEstado.canibalesDerecha[k];
          nuevoEstadoDoble.canibalesIzquierda.push_back(segundoCanibalQueSeMueve);
          nuevoEstadoDoble.canibalesDerecha.erase(nuevoEstado.canibalesDerecha.begin() + k);
          nuevoEstadoDoble.linternaALaDerecha = !(nuevoEstado.linternaALaDerecha);
          if(estadoValido(nuevoEstadoDoble, estadosAnteriores)){
            estadosAnteriores.push_back(nuevoEstadoDoble);
            int nuevaVelocidad = velocidad + segundoCanibalQueSeMueve + primerCanibalQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

      for (int i = 0; i < cantidadArqueologosOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int primerArqueologoQueSeMueve = ultimoEstado.arqDerecha[i];
        nuevoEstado.arqIzquierda.push_back(primerArqueologoQueSeMueve);
        nuevoEstado.arqDerecha.erase(nuevoEstado.arqDerecha.begin() + i);
        int cantidadArqueologosOrigenMenosUno = cantidadArqueologosOrigen - 1;
        for (int k = 0; k < cantidadArqueologosOrigenMenosUno; ++k){
          estadosPuente nuevoEstadoDoble = nuevoEstado;
          int segundoArqueologoQueSeMueve = nuevoEstado.arqDerecha[k];
          nuevoEstadoDoble.arqIzquierda.push_back(segundoArqueologoQueSeMueve);
          nuevoEstadoDoble.arqDerecha.erase(nuevoEstado.arqDerecha.begin() + k);
          nuevoEstadoDoble.linternaALaDerecha = !(nuevoEstado.linternaALaDerecha);
          if(estadoValido(nuevoEstadoDoble, estadosAnteriores)){
            estadosAnteriores.push_back(nuevoEstadoDoble);
            int nuevaVelocidad = velocidad + segundoArqueologoQueSeMueve + primerArqueologoQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

    }else{//Tienen que volver con la linterna

      for (int i = 0; i < cantidadCanibalesDestino; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int canibalQueSeMueve = ultimoEstado.canibalesIzquierda[i];
        nuevoEstado.canibalesDerecha.push_back(canibalQueSeMueve);
        nuevoEstado.canibalesIzquierda.erase(nuevoEstado.canibalesIzquierda.begin() + i);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + canibalQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
          estadosAnteriores.pop_back();
        }
      }

      for (int i = 0; i < cantidadArqueologosDestino; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int arqueologoQueSeMueve = ultimoEstado.arqIzquierda[i];
        nuevoEstado.arqDerecha.push_back(arqueologoQueSeMueve);
        nuevoEstado.arqIzquierda.erase(nuevoEstado.arqIzquierda.begin() + i);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + arqueologoQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
          estadosAnteriores.pop_back();
        }
      }

      for (int i = 0; i < cantidadArqueologosDestino; ++i){
        for (int k = 0; k < cantidadCanibalesDestino; ++k){
          estadosPuente nuevoEstado = ultimoEstado;
          int canibalQueSeMueve = ultimoEstado.canibalesIzquierda[k];
          int arqueologoQueSeMueve = ultimoEstado.arqIzquierda[k];
          nuevoEstado.canibalesDerecha.push_back(canibalQueSeMueve);
          nuevoEstado.arqDerecha.push_back(arqueologoQueSeMueve);
          nuevoEstado.canibalesIzquierda.erase(nuevoEstado.canibalesIzquierda.begin() + k);
          nuevoEstado.arqIzquierda.erase(nuevoEstado.arqIzquierda.begin() + k);
          nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
          if(estadoValido(nuevoEstado, estadosAnteriores)){
            estadosAnteriores.push_back(nuevoEstado);
            int nuevaVelocidad = velocidad + canibalQueSeMueve + arqueologoQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

      for (int i = 0; i < cantidadCanibalesDestino; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int primerCanibalQueSeMueve = ultimoEstado.canibalesIzquierda[i];
        nuevoEstado.canibalesDerecha.push_back(primerCanibalQueSeMueve);
        nuevoEstado.canibalesIzquierda.erase(nuevoEstado.canibalesIzquierda.begin() + i);
        int cantidadCanibalesDestinoMenosUno = cantidadCanibalesDestino - 1;
        for (int k = 0; k < cantidadCanibalesDestinoMenosUno; ++k){
          estadosPuente nuevoEstadoDoble = nuevoEstado;
          int segundoCanibalQueSeMueve = nuevoEstado.canibalesIzquierda[k];
          nuevoEstadoDoble.canibalesDerecha.push_back(segundoCanibalQueSeMueve);
          nuevoEstadoDoble.canibalesIzquierda.erase(nuevoEstado.canibalesIzquierda.begin() + k);
          nuevoEstadoDoble.linternaALaDerecha = !(nuevoEstado.linternaALaDerecha);
          if(estadoValido(nuevoEstadoDoble, estadosAnteriores)){
            estadosAnteriores.push_back(nuevoEstadoDoble);
            int nuevaVelocidad = velocidad + segundoCanibalQueSeMueve + primerCanibalQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

      for (int i = 0; i < cantidadArqueologosOrigen; ++i){
        estadosPuente nuevoEstado = ultimoEstado;
        int primerArqueologoQueSeMueve = ultimoEstado.arqIzquierda[i];
        nuevoEstado.arqDerecha.push_back(primerArqueologoQueSeMueve);
        nuevoEstado.arqIzquierda.erase(nuevoEstado.arqIzquierda.begin() + i);
        int cantidadArqueologosOrigenMenosUno = cantidadArqueologosOrigen - 1;
        for (int k = 0; k < cantidadArqueologosOrigenMenosUno; ++k){
          estadosPuente nuevoEstadoDoble = nuevoEstado;
          int segundoArqueologoQueSeMueve = nuevoEstado.arqIzquierda[k];
          nuevoEstadoDoble.arqDerecha.push_back(segundoArqueologoQueSeMueve);
          nuevoEstadoDoble.arqIzquierda.erase(nuevoEstado.arqIzquierda.begin() + k);
          nuevoEstadoDoble.linternaALaDerecha = !(nuevoEstado.linternaALaDerecha);
          if(estadoValido(nuevoEstadoDoble, estadosAnteriores)){
            estadosAnteriores.push_back(nuevoEstadoDoble);
            int nuevaVelocidad = velocidad + segundoArqueologoQueSeMueve + primerArqueologoQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }
    }
  }else{
    velocidadesSoluciones.push_back(velocidad);
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

int dameMinimoTiempo(vector<int> tiempos){
  int cantidadTiempos = tiempos.size();
  int res = -1;
  if (cantidadTiempos > 0){
    res = tiempos[0];
  }
  for (int i = 1; i < cantidadTiempos; ++i){
    if(res > tiempos[i]){
      res = tiempos[i];
    }
  }
  return res;
}