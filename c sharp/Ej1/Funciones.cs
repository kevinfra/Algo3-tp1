using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ej1
{
    public class Funciones
    {
        public void CruzarPuente(List<int> canibalesOrigen, List<int> arqueologosOrigen, List<int> canibalesDestino, List<int> arqueologosDestino, bool linternaDer, List<Estado> estadosAnteriores, int Tiempo, List<int> Soluciones, string Testing)
        {
            List<int> canibalesDer = linternaDer ? canibalesOrigen : canibalesDestino;
            List<int> canibalesIzq = linternaDer ? canibalesDestino : canibalesOrigen;
            List<int> arqueologosDer = linternaDer ? arqueologosOrigen : arqueologosDestino;
            List<int> arqueologosIzq = linternaDer ? arqueologosDestino : arqueologosOrigen;

            //Hago una copia de las listas para no modificar las listas de las recursiones padres
            canibalesOrigen = canibalesOrigen.OrderBy(x => x).ToList();
            arqueologosOrigen = arqueologosOrigen.OrderBy(x => x).ToList();
            canibalesDestino = canibalesDestino.OrderBy(x => x).ToList();
            arqueologosDestino = arqueologosDestino.OrderBy(x => x).ToList();

            bool esSolucion = canibalesIzq.Count + arqueologosIzq.Count == 0;

            if (esSolucion)
            {
                Soluciones.Add(Tiempo);
                Console.WriteLine(Testing + "Encontre una solución: Tiempo total " + Tiempo);
            }
            else
            {
                Estado nuevoEstado;
                List<int> nuevoCanibalesOrigen;
                List<int> nuevoArqueologosOrigen;
                List<int> nuevoCanibalesDestino;
                List<int> nuevoArqueologosDestino;

                int cantCanibalesOrigen = canibalesOrigen.Count;
                int cantArqueologosOrigen = arqueologosOrigen.Count;
                int cantCanibalesDestino = canibalesDestino.Count;
                int cantArqueologosDestino = arqueologosDestino.Count;
                bool nuevaLinternaDer = !linternaDer;

                //Mando 0 canibales y 1 arqueologo, o
                //0 canibales y 2 arqueologos, o 
                //1 canibal y 1 arqueologo o 
                //2 canibales o 0 arqueologos
                for (int mandarCanibales = 0; mandarCanibales <= 2; mandarCanibales++)
                {
                    for (int mandarArqueologos = mandarCanibales == 0 ? 1 : 0; mandarArqueologos <= 2 - mandarCanibales; mandarArqueologos++)
                    {
                        
                        Console.WriteLine("");
                        Console.WriteLine(Testing + "Intento mandar " + mandarCanibales + " canibales y " + mandarArqueologos + " arqueologos hacia la " + (linternaDer ? "IZQUIERDA" : "DERECHA"));
                        if (estadoValido(cantCanibalesOrigen - mandarCanibales, cantArqueologosOrigen - mandarArqueologos, cantCanibalesDestino + mandarCanibales, cantArqueologosDestino + mandarArqueologos, linternaDer, estadosAnteriores))
                        {
                            Console.WriteLine(Testing + "Mando");
                            if (!linternaDer)
                            {
                                Console.WriteLine(Testing + "IZQ " + (cantArqueologosOrigen - mandarArqueologos) + "A " + (cantCanibalesOrigen - mandarCanibales) + "C | DER " + (cantArqueologosDestino + mandarArqueologos) + "A " + (cantCanibalesDestino + mandarCanibales) + "C");
                            }
                            else
                            {
                                Console.WriteLine(Testing + "IZQ " + (cantArqueologosDestino + mandarArqueologos) + "A " + (cantCanibalesDestino + mandarCanibales) + "C | DER " + (cantArqueologosOrigen - mandarArqueologos) + "A " + (cantCanibalesOrigen - mandarCanibales) + "C");
                            }

                            //Hago una copia de las listas (para no modificar otras listas)
                            nuevoCanibalesOrigen = canibalesOrigen.ToList();
                            nuevoArqueologosOrigen = arqueologosOrigen.ToList();
                            nuevoCanibalesDestino = canibalesDestino.ToList();
                            nuevoArqueologosDestino = arqueologosDestino.ToList();

                            List<int> canibalesMasRapidos = new List<int>();
                            if (mandarCanibales > 0)
                            {
                                canibalesMasRapidos = nuevoCanibalesOrigen.Take(mandarCanibales).ToList();
                                for (int i = 0; i < mandarCanibales; i++)
                                {
                                    nuevoCanibalesOrigen.Remove(canibalesMasRapidos[i]);
                                    nuevoCanibalesDestino.Add(canibalesMasRapidos[i]);
                                }
                            }

                            List<int> arqueologosMasRapidos = new List<int>();
                            if (mandarArqueologos > 0)
                            {
                                arqueologosMasRapidos = nuevoArqueologosOrigen.Take(mandarArqueologos).ToList();
                                for (int i = 0; i < mandarArqueologos; i++)
                                {
                                    nuevoArqueologosOrigen.Remove(arqueologosMasRapidos[i]);
                                    nuevoArqueologosDestino.Add(arqueologosMasRapidos[i]);
                                }
                            }

                            nuevoEstado = new Estado()
                            {
                                arqueologosDer = arqueologosDer.Count + (linternaDer ? -1 : 1) * mandarArqueologos,
                                arqueologosIzq = arqueologosIzq.Count + (linternaDer ? 1 : -1) * mandarArqueologos,
                                canibalesDer = canibalesDer.Count + (linternaDer ? -1 : 1) * mandarCanibales,
                                canibalesIzq = canibalesIzq.Count + (linternaDer ? 1 : -1) * mandarCanibales,
                                linternaDer = nuevaLinternaDer
                            };

                            estadosAnteriores.Add(nuevoEstado);
                            int nuevoTiempo = Tiempo + Math.Max(mandarArqueologos > 0 ? arqueologosMasRapidos.Max() : 0, mandarCanibales > 0 ? canibalesMasRapidos.Max() : 0);
                            CruzarPuente(nuevoCanibalesDestino, nuevoArqueologosDestino, nuevoCanibalesOrigen, nuevoArqueologosOrigen, nuevaLinternaDer, estadosAnteriores, nuevoTiempo, Soluciones, "-" + Testing);
                            estadosAnteriores.Remove(nuevoEstado);
                        }
                        else
                        {
                            Console.WriteLine(Testing + "No mando");
                        }
                    }
                }
            }
        }

        public bool estadoValido(int cantCanibalesOrigen, int cantArqueologosOrigen, int cantCanibalesDestino, int cantArqueologosDestino, bool linternaDer, List<Estado> estadosAnteriores)
        {
            if (cantCanibalesOrigen < 0 || cantArqueologosOrigen < 0)
                return false;

            int canibalesDer = linternaDer ? cantCanibalesOrigen : cantCanibalesDestino;
            int canibalesIzq = linternaDer ? cantCanibalesDestino : cantCanibalesOrigen;
            int arqueologosDer = linternaDer ? cantArqueologosOrigen : cantArqueologosDestino;
            int arqueologosIzq = linternaDer ? cantArqueologosDestino : cantArqueologosOrigen;

            if ((0 < arqueologosDer && arqueologosDer < canibalesDer) ||
                (0 < arqueologosIzq && arqueologosIzq < canibalesIzq))
                return false;

            for (int i = 0; i < estadosAnteriores.Count; i++)
            {
                Estado estadoAnterior = estadosAnteriores[i];
                if (estadoAnterior.arqueologosDer == arqueologosDer &&
                    estadoAnterior.canibalesDer == canibalesDer &&
                    estadoAnterior.linternaDer == !linternaDer)
                    return false;
            }

            return true;
        }
    }
}
