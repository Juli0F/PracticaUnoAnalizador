using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
using System.IO;
using Analizador_Lexico_Practica_Uno.Clases;

namespace Analizador_Lexico_Practica_Uno
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            panelContenedor.Visible = true;
        }

        private void menuStrip2_ItemClicked(object sender, ToolStripItemClickedEventArgs e)
        {
                   }

        private void nuevoToolStripMenuItem_Click(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            Nodo n = new Nodo("Prueba","A","Rojo");
            n.writeInRichText(richTextBox1);
           
            Console.WriteLine("Nuevo");

            for (int i = 0; i < 10; i++)
            {

                for (int j = 0; j < 10; j++)
                {

                    Console.Write("[" + i + "}" + "[" + j + "}, ");

                }
                Console.WriteLine("");
            }
        }

        private void cargarToolStripMenuItem_Click_1(object sender, EventArgs e)
        {
            richTextBox1.Text = "";
            OpenFileDialog save = new OpenFileDialog();
            save.Filter = "File Tokenizer |*.txt";
            save.Title = "Abrir Archivo";

            var option = save.ShowDialog();

            if (option == DialogResult.OK)
            {
                // StreamReader write = new StreamReader(save.FileName);
                //richTextBox1.Text = File.ReadAllLines(save.FileName);

                StreamReader read = new StreamReader(save.FileName);
                richTextBox1.Text = read.ReadToEnd();



            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SaveFileDialog save = new SaveFileDialog();
            save.Filter = "File Tokenizer |*.gtE";
            save.Title = "Guardar Archivo";

            var option = save.ShowDialog();

            if(option == DialogResult.OK) 
            {
                StreamWriter write = new StreamWriter(save.FileName);
                foreach (Object line in richTextBox1.Lines)
                {
                    write.WriteLine();
                }
                write.Close();
                richTextBox1.Text = "";
            }

        }

        private void runToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Pintar();
            richTextBox1.Invoke. = "Hola";
            richTextBox1.SelectionColor = Color.Red;
            richTextBox1.Text = "Hola d";
        }
        private void Pintar()
        {
            List<string> texto = richTextBox1.Lines.ToList<String>();
            texto.ForEach(x => { Console.WriteLine(x);


            });
        }
    }
}
