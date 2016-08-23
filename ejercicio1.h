#include <vector>
#include "estructuras.h"
using namespace std;

int cruzarPuente(vector<int> canibales, vector<int> arqueologos);
void BTCruzarPuente(vector<estadosPuente> &estadosAnteriores, int velocidad, vector<int> &velocidadesSoluciones);
bool estadoValido(estadosPuente &nuevoEstado, vector<estadosPuente> &estadosAnteriores);
int dameMinimoTiempo(vector<int> tiempos);