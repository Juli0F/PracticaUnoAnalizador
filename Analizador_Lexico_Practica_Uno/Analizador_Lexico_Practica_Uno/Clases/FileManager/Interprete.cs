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
        public Interprete(RichTextBox edit, RichTextBox logs, String path , Boolean exist)
        {
            this.edit = edit;
            this.log = logs;
            //this.constructor

        }
        public void LeerArchivo()
        {
            lineas = File.ReadLines(path).ToList<string>();
        }
        public void Interpretar()
        {
            lineas.ForEach(x=>{ 

            });
        }

        private string cadena;
        private List<String> tokens;
        private List<string> lineas;
        private String path;
        private RichTextBox edit;
        private RichTextBox log;
    }
}
