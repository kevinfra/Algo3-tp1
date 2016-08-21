#include <vector>
#include <utility>
#include <iostream>


using namespace std;


void damePesos(int p){
	int[] base = decAter(p);

	int tam = sqrt(p);
	vector<escaque> izq (tam, 0);
	vector<escaque> der (tam, 0);
	int indIzq = 0;
	int indDer = 0;

	bool sumo = false;
	int t;
	for (int i = 0; i < tamano(base) || sumo; i++)
	{
		t = i < n ? base[i] : 0;
		if (sumo)
		{
			t++;
			if (t == 3)
			{
				t = 0;
			}
			else
			{
				sumo = false;
			}
		}
		if (t == 1) {
			izq[indIzq] = 3^i;
			indIzq++;
		} else if (t == 2) {
			der[indDer] = 3^i;
			indDer++;
			sumo = true;
		}
	}
}
