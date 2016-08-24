using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ej1
{
    class Program
    {
        static void Main(string[] args)
        {
            List<int> arquelogos = new List<int>();
            List<int> canibales = new List<int>();

            arquelogos.Add(1);
            arquelogos.Add(2);
            arquelogos.Add(3);

            canibales.Add(3);
            canibales.Add(4);
            canibales.Add(5);

            List<Estado> Historial = new List<Estado>();
            Historial.Add(new Estado() { arqueologosIzq = arquelogos.Count, canibalesIzq = canibales.Count, arqueologosDer = 0, canibalesDer = 0, linternaDer = false });

            Funciones f = new Funciones();
            List<int> Soluciones = new List<int>();

            f.CruzarPuente(canibales, arquelogos, new List<int>(), new List<int>(), false, Historial, 0, Soluciones);
        }
    }
}
