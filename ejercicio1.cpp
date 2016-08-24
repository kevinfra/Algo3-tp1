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
  cout << estadosAnteriores.size() << endl;
  int indexUltimoEstado = estadosAnteriores.size() - 1;
  estadosPuente ultimoEstado = estadosAnteriores[indexUltimoEstado];
  int cantidadCanibalesOrigen = ultimoEstado.canibalesDerecha.size();
  int cantidadArqueologosOrigen = ultimoEstado.arqDerecha.size();
  int cantidadCanibalesDestino = ultimoEstado.canibalesIzquierda.size();
  int cantidadArqueologosDestino = ultimoEstado.arqIzquierda.size();

  if (cantidadCanibalesOrigen + cantidadArqueologosOrigen > 0){

    if (ultimoEstado.linternaALaDerecha){

      cout << "cruza desde la derecha" << endl;

      if (0 < cantidadCanibalesOrigen){
        cout << "cruza un canibal solo" << endl;
        estadosPuente nuevoEstado = ultimoEstado;
        int indexCanibal = indiceDelMasRapido(ultimoEstado.canibalesDerecha);
        int canibalQueSeMueve = ultimoEstado.canibalesDerecha[indexCanibal];
        nuevoEstado.canibalesIzquierda.push_back(canibalQueSeMueve);
        nuevoEstado.canibalesDerecha.erase(nuevoEstado.canibalesDerecha.begin() + indexCanibal);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + canibalQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
          estadosAnteriores.pop_back();
        }
      }

      if (0 < cantidadArqueologosOrigen){
        cout << "cruza un arqueologo solo" << endl;
        estadosPuente nuevoEstado = ultimoEstado;
        int indexArq = indiceDelMasRapido(ultimoEstado.arqDerecha);
        int arqueologoQueSeMueve = ultimoEstado.arqDerecha[indexArq];
        nuevoEstado.arqIzquierda.push_back(arqueologoQueSeMueve);
        nuevoEstado.arqDerecha.erase(nuevoEstado.arqDerecha.begin() + indexArq);
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
          cout << "cruzan un canibal y un arqueologo" << endl;
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
        cout << "cruzan dos canibales: ";
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
            cout << primerCanibalQueSeMueve << " ," << segundoCanibalQueSeMueve << endl;
            estadosAnteriores.push_back(nuevoEstadoDoble);
            int nuevaVelocidad = velocidad + segundoCanibalQueSeMueve + primerCanibalQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

      for (int i = 0; i < cantidadArqueologosOrigen; ++i){
        cout << "cruzan dos arqueologos: ";
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
            cout << primerArqueologoQueSeMueve << " ," << segundoArqueologoQueSeMueve << endl;
            estadosAnteriores.push_back(nuevoEstadoDoble);
            int nuevaVelocidad = velocidad + segundoArqueologoQueSeMueve + primerArqueologoQueSeMueve;
            BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
            estadosAnteriores.pop_back();
          }
        }
      }

    }else{//Tienen que volver con la linterna

      cout << "cruza desde la izquierda" << endl;

      if (0 < cantidadCanibalesDestino){
        cout << "cruza un canibal solo" << endl;
        cout << cantidadCanibalesDestino << endl;
        estadosPuente nuevoEstado = ultimoEstado;
        int indexCanibal = indiceDelMasRapido(ultimoEstado.canibalesIzquierda);
        int canibalQueSeMueve = ultimoEstado.canibalesIzquierda[indexCanibal];
        nuevoEstado.canibalesDerecha.push_back(canibalQueSeMueve);
        nuevoEstado.canibalesIzquierda.erase(nuevoEstado.canibalesIzquierda.begin() + indexCanibal);
        nuevoEstado.linternaALaDerecha = !(ultimoEstado.linternaALaDerecha);
        if(estadoValido(nuevoEstado, estadosAnteriores)){
          estadosAnteriores.push_back(nuevoEstado);
          int nuevaVelocidad = velocidad + canibalQueSeMueve;
          BTCruzarPuente(estadosAnteriores, nuevaVelocidad, velocidadesSoluciones);
          estadosAnteriores.pop_back();
        }
      }

      if (0 < cantidadArqueologosDestino){
        estadosPuente nuevoEstado = ultimoEstado;
        int indexArq = indiceDelMasRapido(ultimoEstado.arqIzquierda);
        cout << "cruza un arquelogo solo" << endl;
        int arqueologoQueSeMueve = ultimoEstado.arqIzquierda[indexArq];
        nuevoEstado.arqDerecha.push_back(arqueologoQueSeMueve);
        nuevoEstado.arqIzquierda.erase(nuevoEstado.arqIzquierda.begin() + indexArq);
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
    cout << "guardo " << velocidad << endl;
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

int indiceDelMasRapido(vector<int> velocidades){
  int size = velocidades.size();
  int res = 0;
  for (int i = 0; i < size; ++i){
    if(velocidades[res] > velocidades[i]){
      res = i;
    }
  }
  return res;
}