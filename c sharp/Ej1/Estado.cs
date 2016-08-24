using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ej1
{
    public class Estado
    {
        public Estado()
        {
            arqueologosIzq = 0;
            canibalesIzq = 0;
            arqueologosDer = 0;
            canibalesDer = 0;
            linternaDer = false;
        }

        public int arqueologosIzq { get; set; }
        public int canibalesIzq { get; set; }
        public int arqueologosDer { get; set; }
        public int canibalesDer { get; set; }
        public bool linternaDer { get; set; }
    }
}
