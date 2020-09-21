using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace Analizador_Lexico_Practica_Uno.Clases
{
    class AlfabetoToken
    {
        
        private string cadena;
        private List<string> cadenasToken;
        private List<char> caracteresList;
        private List<string> reservadas;
        private RichTextBox richText;
        private Tabla tabla;
        public AlfabetoToken( RichTextBox richText)
        {
            this.richText = richText;
            this.tabla = new Tabla(richText);

            

            this.cadenasToken = new List<string>();
            caracteresList = new List<char>();
            this.reservadas = new List<string> { "Entero","Decimal","Cadena","Booleano","Chart","SI", "SINO", "SINO_SI","MENTRAS","HACER","DESDE","HASTA","INCREM" };
                 
            
        }

        public void Characterizar(String Linea)
        {
            int pos = 0;
            char caracter ;
            Linea  = Linea.Trim();
            
            ColorText defineColor = new ColorText();

            string[] lineaSplit = Linea.Split(' ');
            
            for(int x = 0; x <Linea.Length; x++)
            {
                Console.WriteLine(lineaSplit.Length);
                
                for (int i = 0; i < lineaSplit.Length-1; i++)
                {
                    Console.WriteLine(lineaSplit[x]);
                    caracter =  lineaSplit[x].ElementAt(i);

                    if ((caracter > 64 && caracter < 91) || (caracter > 96 && caracter < 123))//letras
                    {
                        pos = 1;
                        tabla.GetNodoByToken(1);
                        Console.WriteLine("Letra " + caracter);
                    }
                    else if (caracter > 47 && caracter < 58)//numeros
                    {

                        pos = 0;
                        Console.WriteLine("Numero " + caracter);
                    }

                    else if (caracter == 61)//=
                    {
                        defineColor.addColor(richText, "" + caracter, Color.Pink);
                        pos = 9;
                        Console.WriteLine("Signo Igual " + caracter);
                    }
                    else if (caracter == 43) //signo mas +
                    {
                        pos = 2;
                        defineColor.addColor(richText, "" + caracter, Color.Blue);
                        Console.WriteLine("Signo Mas " + caracter);
                    }
                    else if (caracter == 45) //menos -
                    {
                        pos = 3;
                        defineColor.addColor(richText, "" + caracter, Color.Blue);
                        Console.WriteLine("Signo Menos " + caracter);
                    }
                    else if (caracter == 42) //* multipicacion
                    {
                        pos = 4;
                        Console.WriteLine("Signo Multiplicacion " + caracter);
                    }
                    else if (caracter == 47) //division
                    {

                        pos = 5;
                        Console.WriteLine("Signo Division " + caracter);
                    }
                    else if (caracter == 34) //comillas
                    {
                        pos = 6;
                        Console.WriteLine("Comillas " + caracter);
                    }
                    else if (caracter == 60)//<
                    {
                        pos = 7;
                        Console.WriteLine("Menor " + caracter);
                    }
                    else if (caracter == 62)//>
                    {
                        pos = 8;
                        Console.WriteLine("Mayor " + caracter);
                    }
                    else if (caracter == 33)//!
                    {
                        pos = 10;
                        Console.WriteLine("Signo admiracion" + caracter);
                    }
                    else if (caracter.Equals('|'))//|
                    {
                        pos = 11;
                        Console.WriteLine("pipline creo " + caracter);
                    }
                    else if (caracter.Equals('&'))//&
                    {
                        pos = 12;
                        Console.WriteLine("& cafe" + caracter);
                    }
                    else if (caracter.Equals(';'))//;
                    {
                        pos = 13;
                        Console.WriteLine("coma " + caracter);
                    }
                    else if (caracter.Equals('.'))//.
                    {
                        pos = 14;
                        Console.WriteLine("punto " + caracter);
                    }
                    tabla.GetNodoByToken(pos);


                }
            }
        }
        
    }
}
