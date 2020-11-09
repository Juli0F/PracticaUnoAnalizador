using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lenguajes
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            txtEntrada.Text = "principal()";
            //xtEntrada.Text = "123 234.23\n  \" Texto \" entero decimal booleano caracter, verdadero, falso, principal, + - * / ++ -- > < <= >= == != || && ! ( ) + ; SI SINO SINO_SI MIENTRAS HACER DESDE HASTA INCREMENTO //MI COMENTARIO UNA LINEA 34224   \n /* MI COMENTARIO MULTILINEA * \n segunda linea */ " +
          //      "leer escribir";
         //   txtEntrada.Text += "leer escribir";
        }

        private void runToolStripMenuItem_Click(object sender, EventArgs e)
        {
            

        }

        private void button1_Click(object sender, EventArgs e)
        {
            log.Text = "";
            Console.WriteLine("Iniciando");
            String entrada = txtEntrada.Text;
            Analizador lexico = new Analizador();
            LinkedList<Token> tokens = lexico.cadenaEntrante(entrada);
            Console.WriteLine("conteo: "+ tokens.Count);
            lexico.printList(tokens);






            //(List<String> alfabeto, List<string> lstProducciones)
            List<string> alfabeto = new List<string>();
            Dictionary<String,int> producciones = new Dictionary<String,int>();

            //entero	decimal	caracter	cadena 	booleano	id	;	,	=	numero	texto	booleano

            /*
            producciones.Add( "DEF_VAR",0);
            producciones.Add("KW_TIPO",1);
            producciones.Add("ID_VALUE",2);
            producciones.Add("ID_FACTOR",3);
            producciones.Add("ID_FACT_IGUAL",4);
            producciones.Add("VALOR",5);
            */

            producciones.Add("INICIO", 0);
            producciones.Add("BLOQUE", 1);
            producciones.Add("SENTENCIA", 2);
            producciones.Add("SEN", 3);
            producciones.Add("SEN_FACT",4);
            producciones.Add("DEF_VAR", 5);
            producciones.Add("KW_TIPO", 6);
            producciones.Add("ID_VALUE", 7);
            producciones.Add("ID_FACT", 8);
            producciones.Add("ID_FACT_IGUAL", 9);
            producciones.Add("VALOR", 10);
            producciones.Add("CONDICIONAL", 11);
            producciones.Add("WHILE", 12);
            producciones.Add("DO", 13);
            producciones.Add("FOR", 14);
            producciones.Add("IF", 15);
            producciones.Add("SI_CONTINUA", 16);
            producciones.Add("CONDICION_TIPO", 17);
            producciones.Add("OPERADOR", 18);
            producciones.Add("CONDICION_LOGICA", 19);
            producciones.Add("SUMA_RESTA", 20);
            producciones.Add("SR", 21);
            producciones.Add("MD", 22);
            producciones.Add("MDP", 23);
            producciones.Add("P", 24);
            producciones.Add("PP", 25);
            producciones.Add("U", 26);
            producciones.Add("E", 27);
            producciones.Add("LEER", 28);
            producciones.Add("IMPRIMIR", 29);
            producciones.Add("IM_TIPOS", 30);
            producciones.Add("IM_TIPOS_ID", 31);
            producciones.Add("IM_TIPOS_TEXTO", 32);



            alfabeto.Add("principal");
            alfabeto.Add("par_abierto");
            alfabeto.Add("par_cerrado");
            alfabeto.Add("llave_abierta");
            alfabeto.Add("llave_cerrada");
            alfabeto.Add("punto_coma");
            alfabeto.Add("coma");
            alfabeto.Add("entero");
            alfabeto.Add("decimal");
            alfabeto.Add("caracter");
            alfabeto.Add("cadena");
            alfabeto.Add("kw_booleano");
            alfabeto.Add("id");
            alfabeto.Add("igual");
            alfabeto.Add("texto");
            alfabeto.Add("booleano");
            alfabeto.Add("numero");
            alfabeto.Add("while");
            alfabeto.Add("hacer");
            alfabeto.Add("desde");
            alfabeto.Add("op_relacional");
            alfabeto.Add("incremento");
            alfabeto.Add("si");
            alfabeto.Add("sino_si");
            alfabeto.Add("sino");
            alfabeto.Add("op_logico");
            alfabeto.Add("mas");
            alfabeto.Add("menos");
            alfabeto.Add("division");
            alfabeto.Add("por");
            alfabeto.Add("potencia");
            alfabeto.Add("leer");
            alfabeto.Add("imprimir");
            alfabeto.Add("$");









            Matriz matriz = new Matriz(alfabeto,producciones, log) ;
            Queue<Token> oldList = new Queue<Token>(tokens);

            for (int i = 0; i < tokens.Count; i++)
            {
                Console.WriteLine("Token 1: TypeToken: " + " clasificacion: "+ tokens.ElementAt<Token>(i).GetClasificacion());
            }
            matriz.IntroducirErroes();
            matriz.setProduccionesDentro();
            matriz.ImprimirMatriz();
            matriz.imprimirPila();
            matriz.cola(tokens);
       
        }

        private void toolStripMenuItem1_Click(object sender, EventArgs e)
        {

        }

        private void fIleToolStripMenuItem_Click(object sender, EventArgs e)
        {
            txtEntrada.Text = "";
        }

        private void runToolStripMenuItem_Click_1(object sender, EventArgs e)
        {

        }

        private void abrirToolStripMenuItem_Click(object sender, EventArgs e)
        {


            txtEntrada.Text = "";
            OpenFileDialog save = new OpenFileDialog();
            save.Filter = "File Tokenizer |*.gtE";
            save.Title = "Abrir Archivo";

            var option = save.ShowDialog();

            if (option == DialogResult.OK)
            {
                // StreamReader write = new StreamReader(save.FileName);
                //richTextBox1.Text = File.ReadAllLines(save.FileName);

                StreamReader read = new StreamReader(save.FileName);
                txtEntrada.Text = read.ReadToEnd();



            }

        }

        private void guardarToolStripMenuItem_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "File Tokenizer |*.gtE";
            save.Title = "Guardar Archivo";

            var option = save.ShowDialog();

            if (option == DialogResult.OK)
            {
                StreamWriter write = new StreamWriter(save.FileName);
                foreach (Object line in txtEntrada.Lines)
                {
                    write.WriteLine();
                }
                write.Close();
                txtEntrada.Text = "";
            }
        }


       
    }
}
