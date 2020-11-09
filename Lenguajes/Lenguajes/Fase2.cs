using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lenguajes
{
   
    class Fase2
    {
        private LinkedList<Token_Fase_2> salida;
        private int estado;
        private String auxlex;
        private int linea;
        private int columna;
        private Token Token;

        public Fase2(Token token)
        {
            this.Token = token;

        }
    }
}
