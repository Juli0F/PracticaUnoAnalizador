using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lenguajes
{
    public class Nodo
    {
        private Token token;
        private int padre;
        private string label;
        private int id;

        
        public Nodo(Token token, int padre, string label, int id)
        {
            this.token = token;
            this.padre = padre;
            this.label = label;
            this.id = id;

        }

        public Token getToken()
        {
            return this.token;
        }
        public int getId()
        {
            return this.id;
        }
        public string getLabel()
        {
            return this.label;
        }
        public int getPadre()
        {
            return this.padre;
        }
            



    }
}
