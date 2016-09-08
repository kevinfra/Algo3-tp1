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
#include "ejercicio3.h"

using namespace std;

static chrono::time_point<chrono::high_resolution_clock> start_time;

void start_timer() {
	start_time = chrono::high_resolution_clock::now();
}

double stop_timer() {
	chrono::time_point<chrono::high_resolution_clock> end_time = chrono::high_resolution_clock::now();
	return double(chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count());
}


int main(int argc, char *argv[]) {
	int numeroDeEjercicio = 0;
	bool experimentos = false;
	if (argc == 2) {
		numeroDeEjercicio = atoi(argv[1]);
	}
	else if (argc == 3) {
		numeroDeEjercicio = atoi(argv[1]);
		string exp = argv[2];
		if (exp == "-exp") {
			experimentos = true;
		}
	}
	else {
		cout << "Modo de uso: \n tp1 numeroDeEjercicio \n Opcional luego del numero de ejercicio: " << endl;
		cout << "   -exp para experimentos" << endl;
		return -1;
	}


	if (!experimentos) 
		cout << "Corriendo ejercicio numero " << numeroDeEjercicio << endl;

	if (numeroDeEjercicio == 1) {
		if (!experimentos) {
			int cantidadArq, cantidadCanibales;

			cout << "Ingrese la cantidad de Arqueologos y luego la de Canibales: " << endl;
			cin >> cantidadArq >> cantidadCanibales;

			cout << "Ingrese las velocidades de los Arqueologos: " << endl;
			int velocidad;
			vector<int> velocidadesArq;
			while(cantidadArq > 0 && (cin >> velocidad)) {
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

		}
		else {
			vector<int> canibales;
			vector<int> arqueologos;
			for (int i = 0; i < 200; ++i)
			{
				canibales.push_back(i);
				for (int veces = 0; veces < 50; ++veces)
				{
					start_timer();
					cruzarPuente(canibales, arqueologos);
					cout << stop_timer() << "    " << canibales.size() << endl;
				}
			}
			canibales.clear()
			for (int q = 0; q <= 7; ++q){
				for (int k = 4; k <= q; ++k){
					canibales.push_back(k);
					for (int times = 0; times < 15; ++times){
						start_timer();
						cruzarPuente(canibales, arqueologos);
						cout << stop_timer() << "    " << arqueologos.size() << "    " << canibales.size() << "    " << canibales.size() + arqueologos.size() << endl;

					}
				}
				canibales.clear();
				arqueologos.push_back(q);
			}
		}
	}
	else if (numeroDeEjercicio == 2) {
		if (!experimentos) {
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
		}
		else {
			for (int q = 0; q < 5000; ++q) {
				int p[q];
				for(int j= 0;j<q;j++){
				   p[q] = 1;
				}
				for (int i = 0; i < 1000; ++i){
					start_timer();
					arreglarBalanzaParaTest(p,q);
					cout << stop_timer() << "    " << q << endl;
				}
			}
		}
	}
	else if (numeroDeEjercicio == 3) {

		int cantMochilas;
		int tiposDeTesoros;
		vector<int> capacidades;
		vector<int> tesoroCant;
		vector<int> tesoroPeso;
		vector<int> tesoroValor;


		cout << "Cantidad de mochilas y de tipos de tesoros:" << endl;
		cin >> cantMochilas >> tiposDeTesoros;
		int tamanoMochila;
		
		cout << "capacidades de las " << cantMochilas << " mochilas" << endl;
		while(cantMochilas > 0 && (cin >> tamanoMochila)) {
				capacidades.push_back(tamanoMochila);
				cantMochilas--;
	  }

	  int totalInfoTesoros = tiposDeTesoros*3;
	  int unaInfoTesoro;
	  cout << "ingresar C P V de cada tipo de tesoro" << endl;
	  while(totalInfoTesoros > 0 && (cin >> unaInfoTesoro)) {
				if (totalInfoTesoros % 3 == 0){
					tesoroCant.push_back(unaInfoTesoro);
				}
				else if (totalInfoTesoros % 3 == 1){
					tesoroPeso.push_back(unaInfoTesoro);
				}
				else if (totalInfoTesoros % 3 == 2){
					tesoroValor.push_back(unaInfoTesoro);
				}
				totalInfoTesoros--;
	  }

		int cantTesoros = 0;
		for (uint i = 0; i < tesoroCant.size(); ++i)
		{
			cantTesoros += tesoroCant[i];
		}

		salida ej3 = Mochilero(cantMochilas, cantTesoros, capacidades, tesoroCant, tesoroValor, tesoroPeso);
		cout << "valorTotal = " << ej3.first << endl;
		for (unsigned int i = 0; i < ej3.second.size(); ++i)
		{	
			cout << endl;
			cout << "mochila" << (i+1) << " capacidad = " << capacidades[i] << endl;
			cout << "cantTesoros = " << ej3.second[i][0] << " | ";
			for (unsigned int j = 1; j < ej3.second[i].size(); ++j)
			{
				cout << "tesoro nro " << ej3.second[i][j] << " (v,p) = (" << tesoroValor[ej3.second[i][j]-1] << "," << tesoroPeso[ej3.second[i][j]-1] << ")" << " | ";
			}
			cout << endl;
		}
	}
	else {
		cout << "numero de ejercicio no valido" << endl;
		return -1;
	}
	return 0;
}



