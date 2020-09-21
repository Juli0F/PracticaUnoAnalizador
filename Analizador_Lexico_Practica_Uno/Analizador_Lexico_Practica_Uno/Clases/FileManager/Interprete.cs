using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Analizador_Lexico_Practica_Uno.Clases
{
    class Interprete
    {
        private string cadena;
        private Tabla tabla;
        public Interprete(RichTextBox edit, RichTextBox logs )
        {
            this.edit = edit;
            this.log = logs;
            tabla = new Tabla(logs);
            
            //this.constructor

        }

        public void Interpretar(char caracter)
        {
            
            lineas.ForEach(x=>{ 

            });
        }

        
        private List<String> tokens;
        private List<string> lineas;
        private String path;
        private RichTextBox edit;
        private RichTextBox log;
    }
}
