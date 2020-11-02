using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lenguajes
{
    public class Token_Fase_2
    {
        public enum Token_Sintactico
        {
            PRINCIPAL,
            WHILE,
            FOR,
            SI,
            SINO_SI,
            LEER,
            ESCRIBIR,
            TEXTO,
            BOOLEANO
               

        }
        private int linea;
        private int columna;
        private Token_Sintactico typeToken;
        private String value;
    }
}
