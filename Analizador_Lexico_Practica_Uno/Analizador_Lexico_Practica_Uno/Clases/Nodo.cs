using System;
using System.Collections.Generic;
using System.Drawing;
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
        private Color Color;
        private Boolean aceptacion;

        public Nodo( string Identificador, string Transicion , Color Color)
        {
            this.Identificador = Identificador;
            this.Transicion = Transicion;
            this.Color = Color;
            this.aceptacion = false;
        }
        public void writeInRichText(RichTextBox textArea)
        {
            textArea.Text = "Dessde Nodo";
           
        }
        public String getIdentificador()
        {
            return Identificador;
        }
        public string getTransicion()
        {
            return this.Transicion;
        }
        public Color getColor()
        {
            return this.Color;
        }
        public Boolean isAceptacion()
        {
            return this.aceptacion;
        }
        public void SetAceptacion(Boolean aceptacion)
        {
            this.aceptacion = aceptacion;
        }

    }
}
