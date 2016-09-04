#include "ejercicio3.h"

void Mochilero(int cantMochilas, int cantTesoros, vector<int> capacidades, vector<tesoro> tesoros) {
	//capacidades.size() == cantMochilas
	//tesoro = cantidad, peso, valor
	//0 < cantMochilas <= 3
	/*
		SALIDA:
		valorTotal con el valor total de los tesoros guardados

		Y para la mochila i:
		mochila_i con mochila_i[0] indicando la cantidad de tesoros que tiene, mochila_i[1..N] indicando los tipos
	*/

	int valorTesoro;
	int pesoTesoro;
	int cantidadPorTipoTesoro;
	int tipoTesoro;
	int valorMochila1;
	int valorMochila2;
	int valorNingunaMochila;
	int iMochila1;
	int iMochila2;
	bool metoEnMochila1;
	bool metoEnMochila2;

	int valorTotal = 0;
	vector<int> mochila1;
	vector<int> mochila2;
	int cantTesorosMochila1 = 0;
	int cantTesorosMochila2 = 0;

	vector<vector<vector<int>>>> cuboMagico;

	//Dimensiono el cubo e inicializo cada valor en 0
	cuboMagico.resize(cantTesoros + 1);
	for (int i = 0; i <= cantTesoros; ++i) {
		cuboMagico[i].resize(capacidades[0] + 1);
		for (int j = 0; j <= capacidades[0]; ++j) {
			cuboMagico[i][j].resize(capacidades[1] + 1, 0);
		}
	}

	int iTesoro = 0;
	for (int iTesoroPorTipo = 0; iTesoroPorTipo < tesoros.size(); ++iTesoroPorTipo) {
		valorTesoro = get<2>(tesoros[iTesoroPorTipo]);
		pesoTesoro = get<1>(tesoros[iTesoroPorTipo]);
		cantidadPorTipoTesoro = get<0>(tesoros[iTesoroPorTipo]);

		for (int iTipoTesoro = 0; iTipoTesoro < cantidadPorTipoTesoro; ++iTipoTesoro) {

			for (iMochila1 = 0; iMochila1 <= capacidades[0]; ++iMochila1) {

				for (iMochila2 = 0; iMochila2 <= capacidades[1]; ++iMochila2) {

					valorMochila1 = 0;
					valorMochila2 = 0;
					valorNingunaMochila = 0;

					if (pesoTesoro <= iMochila1 || pesoTesoro <= iMochila2) {

						valorNingunaMochila = cuboMagico[iTesoro][iMochila1][iMochila2];
						if (pesoTesoro <= iMochila1) {
							valorMochila1 = valorTesoro + cuboMagico[iTesoro][iMochila1 - pesoTesoro][iMochila2];
						}

						if (pesoTesoro <= iMochila2) {
							valorMochila2 = valorTesoro + cuboMagico[iTesoro][iMochila1][iMochila2 - pesoTesoro];
						}
					}

					cuboMagico[iTesoro + 1][iMochila1][iMochila2] = max(max(valorNingunaMochila, valorMochila1), valorMochila2);
				}
			}
			iTesoro++;
		}
	}

	valorTotal = cuboMagico[cantTesoros - 1][capacidades[0]][capacidades[1]];

	/*
	vector<int> mochila1;
	vector<int> mochila2;
	int cantTesorosMochila1 = 0;
	int cantTesorosMochila2 = 0;

		SALIDA:
		valorTotal con el valor total de los tesoros guardados

		Y para la mochila i:
		mochila_i con mochila_i[0] indicando la cantidad de tesoros que tiene, mochila_i[1..N] indicando los tipos
	*/

	iMochila1 = capacidades[0];
	iMochila2 = capacidades[1];

	iTesoro = cantTesoros - 1;
	for (int iTesoroPorTipo = tesoros.size(); iTesoroPorTipo > 0; --iTesoroPorTipo) {
		valorTesoro = get<2>(tesoros[iTesoroPorTipo - 1]);
		pesoTesoro = get<1>(tesoros[iTesoroPorTipo - 1]);
		cantidadPorTipoTesoro = get<0>(tesoros[iTesoroPorTipo - 1]);

		for (int iTipoTesoro = 0; iTipoTesoro < cantidadPorTipoTesoro; ++iTipoTesoro) {
			
			metoEnMochila1 = false;
			metoEnMochila2 = false;

			if (cuboMagico[iTesoro + 1][iMochila1][iMochila2] != cuboMagico[iTesoro][iMochila1][iMochila2]) {

				if (pesoTesoro <= iMochila1 && pesoTesoro <= iMochila2) {

					if (cuboMagico[iTesoro][iMochila1 - pesoTesoro][iMochila2] => cuboMagico[iTesoro][iMochila1][iMochila2 - pesoTesoro]) {
						metoEnMochila1 = true;
					}
					else {
						metoEnMochila2 = true;
					}
				}

				if (metoEnMochila1 || pesoTesoro <= iMochila1) {
					//Meto el objeto (pesoTesoro, valor) en la mochila 1

					mochila1.push_back(iTesoroPorTipo)

					cantTesorosMochila1++;
					
					iMochila1 -= pesoTesoro;
				}
				else if (metoEnMochila2 || pesoTesoro <= iMochila2) {
					//Meto el objeto (pesoTesoro, valor) en la mochila 2
					mochila2.push_back(iTesoroPorTipo)

					cantTesorosMochila2++;
					
					iMochila2 -= pesoTesoro;
				}
			}
			iTesoro--;
		}
	}

	mochila1.insert(mochila1.begin(), cantTesorosMochila1);
	mochila2.insert(mochila2.begin(), cantTesorosMochila2);
}