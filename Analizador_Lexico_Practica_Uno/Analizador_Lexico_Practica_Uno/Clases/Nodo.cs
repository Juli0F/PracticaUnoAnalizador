using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Analizador_Lexico_Practica_Uno.Clases
{
    class Nodo
    {
        private string Identificador;
        private string Transicion;
        private string Color;

        public Nodo( string Identificador, string Transicion , string Color)
        {
            this.Identificador = Identificador;
            this.Transicion = Transicion;
            this.Color = Color;
        }
        public void writeInRichText(RichTextBox textArea)
        {
            textArea.Text = "Dessde Nodo";
           
        }
    }
}
