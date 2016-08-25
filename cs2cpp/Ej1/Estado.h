#include <vector>

class Estado{
    public:
        int arqueologosIzq();
        int canibalesIzq();
        int arqueologosDer();
        int canibalesDer();
        bool linternaDer();
        Estado();
        Estado(int arqIzq, int caniIzq, int arqDer, int caniDer, bool linternaDerecha);


    private:
        int arqueologosIzq;
        int canibalesIzq;
        int arqueologosDer;
        int canibalesDer;
        bool linternaDer;
}