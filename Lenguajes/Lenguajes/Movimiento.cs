using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lenguajes
{
    public class Movimiento
    {
        private int indexCola = 0;
        private int iteracion = 0;
        
        private int columna_actua;
        private int fila_actual;

        private Stack<string> pila;
        private Stack<Nodo> error;

        public void buscarToken(Nodo nodo)
        {
            
            string entrada = nodo.getToken().GetClasificacion();
            

            Console.WriteLine("Ingresando $ a la Pila");
            Console.WriteLine("Ingresando Produccion Inicial");

            pila.Clear();
            pila.Push("$");
            pila.Push("INICIO");

            do
            {
                if (columna_actua == -1)
                {

                }
                else
                {

                }
                

            } while (!pila.Peek().Equals("$") && (entrada.Equals("$")));
        }
        public string delFirst(LinkedList<Token> colaDeTokens, int indexActual)
        {
            string entrada = "$";

            if (colaDeTokens.Count > 0)
            {
                entrada = colaDeTokens.First<Token>().GetClasificacion();
                colaDeTokens.RemoveFirst();
            }
            return entrada;
        }
    }
}
