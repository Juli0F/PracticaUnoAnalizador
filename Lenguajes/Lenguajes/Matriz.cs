using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Forms.VisualStyles;

namespace Lenguajes
{
    public class Matriz
    {
        private int columna_actua;
        private int fila_actual;
        private int indice;
        private Boolean conError;

        private string[,] matrizProducciones;

        private Dictionary<String, int> producciones;

        private List<string> alfabeto;
        private Stack<String> pila;
        private Stack<String> pilaError;
        private Stack<Nodo> nodo;


        private RichTextBox rich;





        public Matriz(List<String> alfabeto, Dictionary<string, int> produccionesDic, RichTextBox rich)
        {
            this.fila_actual = 0;
            this.columna_actua = -1; //-1 para indicar que aun no a ingresado ningun toqen para que se pueda mover en las columnas
            this.indice = 0;
            conError = false;

            this.pila = new Stack<string>();
            this.nodo = new Stack<Nodo>();
            this.pilaError = new Stack<string>();
            this.alfabeto = alfabeto;
            this.matrizProducciones = new string[produccionesDic.Count, alfabeto.Count];
            this.producciones = produccionesDic;

            this.rich = rich;


        }
        public void IntroducirErroes()
        {
            for (int i = 0; i < matrizProducciones.GetLength(0); i++)
            {
                for (int j = 0; j < matrizProducciones.GetLength(1); j++)
                    matrizProducciones[i, j] = "ERROR";
            }
        }

        public void setProduccionesDentro()
        {
            //tabla de analis LL1
            matrizProducciones[0, 0] = "principal par_abierto par_cerrado BLOQUE";
            matrizProducciones[0, 33] = "$";

            matrizProducciones[1, 3] = "llave_abierta SENTENCIA llave_cerrada";
            matrizProducciones[1, 33] = "$";

            matrizProducciones[2, 1] = "SEN";
            matrizProducciones[2, 4] = "ε";
            matrizProducciones[2, 5] = "SEN";
            matrizProducciones[2, 6] = "SEN";
            matrizProducciones[2, 7] = "SEN";
            matrizProducciones[2, 8] = "SEN";
            matrizProducciones[2, 9] = "SEN";
            matrizProducciones[2, 10] = "SEN";
            matrizProducciones[2, 11] = "SEN";
            matrizProducciones[2, 12] = "SEN";
            matrizProducciones[2, 16] = "SEN";
            matrizProducciones[2, 17] = "SEN";
            matrizProducciones[2, 18] = "SEN";
            matrizProducciones[2, 19] = "SEN";
            matrizProducciones[2, 22] = "SEN";
            matrizProducciones[2, 27] = "SEN";
            matrizProducciones[2, 31] = "SEN";
            matrizProducciones[2, 32] = "SEN";


            matrizProducciones[3, 1] = "SEN_FACT SEN";
            matrizProducciones[3, 4] = "ε";
            matrizProducciones[3, 5] = "SEN_FACT SEN";
            matrizProducciones[3, 6] = "SEN_FACT SEN";
            matrizProducciones[3, 7] = "SEN_FACT SEN";
            matrizProducciones[3, 8] = "SEN_FACT SEN";
            matrizProducciones[3, 9] = "SEN_FACT SEN";
            matrizProducciones[3, 10] = "SEN_FACT SEN";
            matrizProducciones[3, 11] = "SEN_FACT SEN";
            matrizProducciones[3, 12] = "SEN_FACT SEN";
            matrizProducciones[3, 16] = "SEN_FACT SEN";
            matrizProducciones[3, 17] = "SEN_FACT SEN";
            matrizProducciones[3, 18] = "SEN_FACT SEN";
            matrizProducciones[3, 19] = "SEN_FACT SEN";
            matrizProducciones[3, 5] = "SEN_FACT SEN";
            matrizProducciones[3, 22] = "SEN_FACT SEN";
            matrizProducciones[3, 23] = "SEN_FACT SEN";
            matrizProducciones[3, 31] = "SEN_FACT SEN";
            matrizProducciones[3, 32] = "SEN_FACT SEN";

            matrizProducciones[4, 1] = "SUMA_RESTA";
            matrizProducciones[4, 7] = "DEF_VAR";
            matrizProducciones[4, 8] = "DEF_VAR";
            matrizProducciones[4, 9] = "DEF_VAR";
            matrizProducciones[4, 10] = "DEF_VAR";
            matrizProducciones[4, 11] = "DEF_VAR";
            matrizProducciones[4, 12] = "SUMA_RESTA";
            matrizProducciones[4, 16] = "SUMA_RESTA";
            matrizProducciones[4, 17] = "CONDICIONAL";
            matrizProducciones[4, 18] = "CONDICIONAL";
            matrizProducciones[4, 19] = "CONDICIONAL";
            matrizProducciones[4, 22] = "CONDICIONAL";
            matrizProducciones[4, 27] = "SUMA_RESTA";
            matrizProducciones[4, 31] = "leer par_abierto id par_cerrado punto_coma";
            matrizProducciones[4, 32] = "imprimir par_abierto IM_TIPOS par_cerrado punto_coma";
            //KW_TIPO ID_VALUE

            matrizProducciones[5, 7] = "KW_TIPO ID_VALUE";
            matrizProducciones[5, 8] = "KW_TIPO ID_VALUE";
            matrizProducciones[5, 9] = "KW_TIPO ID_VALUE";
            matrizProducciones[5, 10] = "KW_TIPO ID_VALUE";
            matrizProducciones[5, 11] = "KW_TIPO ID_VALUE";

            matrizProducciones[6, 7] = "entero";
            matrizProducciones[6, 8] = "decimal";
            matrizProducciones[6, 9] = "caracter";
            matrizProducciones[6, 10] = "cadena";
            matrizProducciones[6, 11] = "kw_booleano";

            matrizProducciones[7, 12] = "id ID_FACT";

            matrizProducciones[8, 5] = "punto_coma";
            matrizProducciones[8, 6] = "coma ID_VALUE";
            matrizProducciones[8, 7] = "ε";
            matrizProducciones[8, 8] = "ε";
            matrizProducciones[8, 9] = "ε";
            matrizProducciones[8, 10] = "ε";
            matrizProducciones[8, 11] = "ε";
            matrizProducciones[8, 12] = "ε";
            matrizProducciones[8, 13] = "igual VALOR ID_FACT_IGUAL";
            matrizProducciones[8, 16] = "ε";
            matrizProducciones[8, 17] = "ε";
            matrizProducciones[8, 18] = "ε";
            matrizProducciones[8, 22] = "ε";
            matrizProducciones[8, 27] = "ε";
            matrizProducciones[8, 31] = "ε";
            matrizProducciones[8, 32] = "ε";


            matrizProducciones[9, 5] = "punto_coma";
            matrizProducciones[9, 6] = "coma ID_VALUE";

            matrizProducciones[10, 1] = "SUMA_RESTA";
            matrizProducciones[10, 11] = "SUMA_RESTA";
            matrizProducciones[10, 14] = "texto";
            matrizProducciones[10, 15] = "booleano";
            matrizProducciones[10, 16] = "SUMA_RESTA";
            matrizProducciones[10, 27] = "SUMA_RESTA";

            matrizProducciones[11, 17] = "WHILE";
            matrizProducciones[11, 18] = "DO";
            matrizProducciones[11, 19] = "FOR";
            matrizProducciones[11, 22] = "IF";

            //matrizProducciones[11, 18] = "WHILE";

            matrizProducciones[12, 17] = "mientras par_abierto CONDICION_TIPO par_cerrado BLOQUE";

            matrizProducciones[13, 18] = "hacer BLOQUE mientras par_abierto CONDICION_TIPO par_cerrado punto_coma";

            matrizProducciones[14, 19] = "desde id op_relacional numero hasta id op_relacional kw_incremento numero BLOQUE";

            matrizProducciones[15, 22] = "si par_abierto CONDICION_TIPO par_cerrado BLOQUE SI_CONTINUA";

            matrizProducciones[16, 4] = "ε";
            matrizProducciones[16, 5] = "ε";
            matrizProducciones[16, 7] = "ε";
            matrizProducciones[16, 8] = "ε";
            matrizProducciones[16, 9] = "ε";
            matrizProducciones[16, 10] = "ε";
            matrizProducciones[16, 11] = "ε";
            matrizProducciones[16, 12] = "ε";
            matrizProducciones[16, 16] = "ε";
            matrizProducciones[16, 18] = "ε";
            matrizProducciones[16, 19] = "ε";
            matrizProducciones[16, 22] = "ε";
            matrizProducciones[16, 23] = "sino_si par_abierto CONDICION_TIPO par_cerrado BLOQUE SI_CONTINUA";
            matrizProducciones[16, 24] = "sino BLOQUE";
            matrizProducciones[16, 27] = "ε";


            matrizProducciones[17, 12] = "CONDICION_LOGICA";
            matrizProducciones[17, 15] = "booleano OPERADOR";
            matrizProducciones[17, 16] = "CONDICION_LOGICA";
            matrizProducciones[17, 27] = "CONDICION_LOGICA";

            matrizProducciones[18, 2] = "ε";
            matrizProducciones[18, 25] = "op_logico";

            matrizProducciones[19, 1] = "SUMA_RESTA op_relacional SUMA_RESTA";
            matrizProducciones[19, 12] = "SUMA_RESTA op_relacional SUMA_RESTA";
            matrizProducciones[19, 16] = "SUMA_RESTA op_relacional SUMA_RESTA";
            matrizProducciones[19, 27] = "SUMA_RESTA op_relacional SUMA_RESTA";

            matrizProducciones[20, 1] = "MD SR";
            matrizProducciones[20, 12] = "MD SR";
            matrizProducciones[20, 16] = "MD SR";
            matrizProducciones[20, 27] = "MD SR";

            matrizProducciones[21, 4] = "ε";
            matrizProducciones[21, 5] = "ε";
            matrizProducciones[21, 7] = "ε";
            matrizProducciones[21, 8] = "ε";
            matrizProducciones[21, 9] = "ε";
            matrizProducciones[21, 10] = "ε";
            matrizProducciones[21, 11] = "ε";
            matrizProducciones[21, 12] = "ε";
            matrizProducciones[21, 16] = "ε";
            matrizProducciones[21, 17] = "ε";
            matrizProducciones[21, 18] = "ε";
            matrizProducciones[21, 19] = "ε";
            matrizProducciones[21, 20] = "ε";
            matrizProducciones[21, 22] = "ε";
            matrizProducciones[21, 32] = "ε";
            matrizProducciones[21, 26] = "mas MD SR";
            matrizProducciones[21, 27] = "menos MD SR";

            matrizProducciones[22, 1] = "P MDP";
            matrizProducciones[22, 4] = "ε";
            //matrizProducciones[22, 5] = "ε";
            matrizProducciones[22, 7] = "ε";
            matrizProducciones[22, 8] = "ε";
            matrizProducciones[22, 9] = "ε";
            matrizProducciones[22, 10] = "ε";
            matrizProducciones[22, 11] = "ε";
            matrizProducciones[22, 12] = "P MDP";
            matrizProducciones[22, 16] = "P MDP";
            matrizProducciones[22, 17] = "ε";
            matrizProducciones[22, 18] = "ε";
            matrizProducciones[22, 19] = "ε";
            matrizProducciones[22, 20] = "ε";
            matrizProducciones[22, 22] = "ε";
            matrizProducciones[22, 26] = "ε";
            matrizProducciones[22, 28] = "ε";
            matrizProducciones[22, 29] = "ε";

            matrizProducciones[23, 4] = "ε";
            matrizProducciones[23, 5] = "ε";
            matrizProducciones[23, 7] = "ε";
            matrizProducciones[23, 8] = "ε";
            matrizProducciones[23, 9] = "ε";
            matrizProducciones[23, 10] = "ε";
            matrizProducciones[23, 11] = "ε";
            matrizProducciones[23, 12] = "ε";
            matrizProducciones[23, 16] = "ε";
            matrizProducciones[23, 17] = "ε";
            matrizProducciones[23, 18] = "ε";
            matrizProducciones[23, 19] = "ε";
            matrizProducciones[23, 20] = "ε";
            matrizProducciones[23, 22] = "ε";
            matrizProducciones[23, 28] = "division P MDP";
            matrizProducciones[23, 29] = "por P MDP";
            matrizProducciones[23, 32] = "ε";

            matrizProducciones[24, 1] = "U PP";
            matrizProducciones[24, 12] = "U PP";
            matrizProducciones[24, 16] = "U PP";
            matrizProducciones[24, 17] = "ε";
            matrizProducciones[24, 18] = "ε";
            matrizProducciones[24, 19] = "ε";
            matrizProducciones[24, 20] = "ε";
            matrizProducciones[24, 22] = "ε";
            matrizProducciones[24, 27] = "U PP";
            matrizProducciones[24, 29] = "ε";
            matrizProducciones[24, 32] = "ε";

            matrizProducciones[25, 4] = "ε";
            matrizProducciones[25, 5] = "ε";
            matrizProducciones[25, 7] = "ε";
            matrizProducciones[25, 8] = "ε";
            matrizProducciones[25, 9] = "ε";
            matrizProducciones[25, 10] = "ε";
            matrizProducciones[25, 11] = "ε";

            matrizProducciones[25, 16] = "ε";
            matrizProducciones[25, 17] = "ε";
            matrizProducciones[25, 18] = "ε";
            matrizProducciones[25, 19] = "ε";
            matrizProducciones[25, 20] = "ε";
            matrizProducciones[25, 22] = "ε";
            matrizProducciones[25, 30] = "potencia P PP";
            matrizProducciones[25, 32] = "ε";

            matrizProducciones[26, 1] = "E";
            matrizProducciones[26, 12] = "E";
            matrizProducciones[26, 16] = "E";
            matrizProducciones[26, 27] = "E";

            matrizProducciones[27, 1] = "par_abierto E par_cerrado";
            matrizProducciones[27, 27] = "id";
            matrizProducciones[27, 16] = "numero";

            matrizProducciones[28, 31] = "leer par_abierto id par_cerrrado punto_coma";

            matrizProducciones[29, 32] = "imprimir par_abierto IM_TIPOS par_cerrado punto_coma"; ;

            matrizProducciones[30, 12] = "id IM_TIPOS_ID";
            matrizProducciones[30, 14] = "texto IM_TIPOS_TEXTO";

            matrizProducciones[31, 26] = "mas IM_TIPOS";
            matrizProducciones[32, 26] = "mas IM_TIPOS";








        }
        public void ImprimirMatriz()
        {
            for (int i = 0; i < matrizProducciones.GetLength(0); i++)
            {
                for (int j = 0; j < matrizProducciones.GetLength(1); j++)
                    Console.Write(matrizProducciones[i, j] + "? ");

                //this.rich.Text = rich.Text + "\n" + (" ");
            }
        }

        public void imprimirPila()
        {
            this.rich.Text = rich.Text + "\n" + (pila.Count);
            for (int i = 0; i <= pila.Count; i++)
            {
                // this.rich.Text = rich.Text + "\n" + (pila.Peek());
            }
        }
        public void pruebaToken()
        {

        }

        public void cola(LinkedList<Token> txtEntrada)
        {

            int indexCola = 0;
            int iteracion = 0;


            //token.AsignarTipo();
            String entrada = txtEntrada.ElementAt<Token>(indexCola).GetClasificacion();
            txtEntrada.RemoveFirst();

            this.rich.Text = rich.Text + "\n" + ("Ingresando $ a la Pila");
            this.rich.Text = rich.Text + "\n" + ("Ingresando Produccion Inicial");

            pila.Clear();
            pila.Push("$");
            pila.Push("INICIO");

            nodo.Push(new Nodo(new Token(Token.Tipo.PRINCIPAL, "INICIO", 1, 1), 0, "INICIO", 1));

            do
            {

                iteracion++;
                //this.rich.Text = rich.Text + "\n" + ("Valor Columna Actual " + columna_actua);
                this.rich.Text = rich.Text + "\n" + ("Token que Entra: " + entrada);

                if (columna_actua == -1)
                {


                    if (entrada.Contains("Error"))
                    {

                        pilaError.Push(entrada);
                    }
                    else
                    {
                        //inicio 
                        //observo que tengo en el tope de la pila
                        string topePila = pila.Peek();
                        this.rich.Text = rich.Text + "\n" + ("Ultimo Elemento en la Pila: " + topePila);
                        //pregunto si lo que tengo en el tope de la pila es una produccion
                        //si lo es entonces obtengo el indice de la fila
                        //sino es una producciones entonces es un terminal
                        if (producciones.ContainsKey(topePila))
                        {
                            columna_actua = alfabeto.FindIndex(x => x.Equals(entrada));
                            fila_actual = producciones[topePila];




                            string valueCelda = matrizProducciones[fila_actual, columna_actua];

                            //verifico que contenga mas de una produccion
                            if (valueCelda.Contains(" "))
                            {
                                string[] produccionesIn = valueCelda.Split(' ');

                                this.rich.Text = rich.Text + "\n" + ("Tope pila: " + topePila + ", se remplazara por " + produccionesIn.Length + " produciones");

                                pila.Pop();

                                this.rich.Text = rich.Text + "\n" + ("Inicia Remplazo (shift)");

                                for (int i = produccionesIn.Length - 1; i > -1; i--)
                                {
                                    this.rich.Text = rich.Text + "\n" + ("Introduciendo la Produccion: " + produccionesIn[i]);

                                    pila.Push(produccionesIn[i]);

                                }

                                this.rich.Text = rich.Text + "\n" + ("Ultimo elemento Ingresado en la Pila: " + pila.Peek());
                                bool terminal = false;
                                do
                                {
                                    string topePila2 = pila.Peek();


                                    if (topePila2.Equals(entrada))
                                    {
                                        this.rich.Text = rich.Text + "\n" + ("Reduce: " + topePila2);

                                        pila.Pop();
                                        columna_actua = -1;

                                        entrada = delFirst(txtEntrada, indexCola);

                                        this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                                        this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);
                                        terminal = true;
                                    }
                                    else { terminal = false; }

                                } while (terminal);
                            }
                            else
                            {
                                if (valueCelda.Equals(entrada))
                                {
                                    pila.Pop();
                                    columna_actua = -1;

                                    entrada = delFirst(txtEntrada, indexCola);

                                    this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                                    this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);
                                }
                                else if (valueCelda.Equals("ε"))
                                {
                                    pila.Pop();
                                    columna_actua = -1;

                                    entrada = delFirst(txtEntrada, indexCola);

                                    this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                                    this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);
                                }
                                else
                                {
                                    this.rich.Text = rich.Text + "\n" + ("Remplazar Ultimo con" + valueCelda);

                                    pila.Pop();
                                    pila.Push(valueCelda);

                                }

                            }




                        }
                        else
                        {

                            //string valueCelda = matrizProducciones[fila_actual, columna_actua];

                            string value = pila.Peek();
                            if (entrada.Equals(value))
                            {
                                this.rich.Text = rich.Text + "\n" + ("Reduce " + entrada);

                                pila.Pop();

                                this.rich.Text = rich.Text + "\n" + ("Valor en la pila" + value + " Token entrante: " + entrada);

                                entrada = delFirst(txtEntrada, indexCola);

                                this.rich.Text = rich.Text + "\n" + ("siguiente Token -->" + entrada);
                            }
                            else
                            {
                                string valueCelda = matrizProducciones[fila_actual, columna_actua];
                                if (entrada.Equals(valueCelda))
                                {
                                    this.rich.Text = rich.Text + "\n" + ("Reduce " + entrada);

                                    pila.Pop();

                                    this.rich.Text = rich.Text + "\n" + ("Valor de la celda" + valueCelda + " Token entrante: " + entrada);

                                    entrada = delFirst(txtEntrada, indexCola);

                                    this.rich.Text = rich.Text + "\n" + ("siguiente Token -->" + entrada);
                                }
                                else
                                {
                                    this.rich.Text = rich.Text + "\n" + ("Error de sintaxis en la linea: " + txtEntrada.First<Token>().GetLinea());
                                    pilaError.Push("Error" + entrada);
                                    conError = true;
                                }

                            }

                        }



                        //fin else

                    }
                }
                else
                {
                    //observo que tengo en el tope de la pila
                    string topePila = pila.Peek();
                    this.rich.Text = rich.Text + "\n" + ("Tope pila: : " + topePila);
                    //pregunto si lo que tengo en el tope de la pila es una produccion
                    //si lo es entonces obtengo el indice de la fila
                    //sino es una producciones entonces es un terminal
                    if (producciones.ContainsKey(topePila))
                    {
                        fila_actual = producciones[topePila];




                        string valueCelda = matrizProducciones[fila_actual, columna_actua];
                        this.rich.Text = rich.Text + "\n" + ("Valor de la Celda: " + valueCelda + " Fila " + fila_actual + " Columna " + columna_actua + " entraa: " + entrada);
                        //verifico que contenga mas de una produccion
                        if (valueCelda.Contains(" "))
                        {
                            string[] produccionesIn = valueCelda.Split(' ');

                            this.rich.Text = rich.Text + "\n" + ("Tope pila: " + topePila + ", se remplazara por " + produccionesIn.Length + " produciones");
                            pila.Pop(); //----------------------------agregado a ultima hora borrar si deja de funcionar
                            this.rich.Text = rich.Text + "\n" + ("Inicia Remplazo (shift)");

                            for (int i = produccionesIn.Length - 1; i > -1; i--)
                            {
                                this.rich.Text = rich.Text + "\n" + ("Introduciendo la Produccion: " + produccionesIn[i]);

                                pila.Push(produccionesIn[i]);

                            }

                            string topePila2 = pila.Peek();
                            this.rich.Text = rich.Text + "\n" + ("Ultimo Elemento ingresado: " + topePila2);

                            if (topePila2.Equals(entrada))
                            {
                                this.rich.Text = rich.Text + "\n" + ("Reduce: " + entrada);

                                pila.Pop();
                                columna_actua = -1;

                                entrada = delFirst(txtEntrada, indexCola);

                                this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                                this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);


                            }
                        }
                        else
                        {
                            if (valueCelda.Equals(entrada))
                            {
                                this.rich.Text = rich.Text + "\n" + ("Reduce: " + entrada);

                                pila.Pop();
                                columna_actua = -1;

                                entrada = delFirst(txtEntrada, indexCola);

                                this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                                this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);

                            }
                            else
                            {
                                this.rich.Text = rich.Text + "\n" + ("Remplazar Ultimo por: " + valueCelda);
                                pila.Pop();

                                pila.Push(valueCelda);

                            }

                        }




                    }
                    else
                    {
                        string value = pila.Peek();
                        if (entrada.Equals(value))
                        {
                            this.rich.Text = rich.Text + "\n" + ("Reduce: " + entrada);
                            pila.Pop();

                            entrada = delFirst(txtEntrada, indexCola);

                            this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                            this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);

                        }
                        else
                        {
                            string valueCelda = matrizProducciones[fila_actual, columna_actua];
                            if (entrada.Equals(valueCelda))
                            {
                                this.rich.Text = rich.Text + "\n" + ("Reduce: " + entrada);
                                pila.Pop();

                                entrada = delFirst(txtEntrada, indexCola);

                                this.rich.Text = rich.Text + "\n" + ("Pedir Sigueinte Token");
                                this.rich.Text = rich.Text + "\n" + ("\nsiguiente Token -->" + entrada);

                            }
                            else
                            {
                                // + txtEntrada.First<Token>().GetLinea()
                                this.rich.Text = rich.Text + "\n" + ("Error de sintaxis en la linea: ");
                                conError = true;
                            }

                        }

                    }


                }
                this.rich.Text = rich.Text + "\n" + ("Fin Iteracion");

            } while (!pila.Peek().Equals("$") && !(entrada.Equals("$")) && !conError);
            
            this.rich.Text = rich.Text + "\n" + ("Cadena aceptada");
            


        }
        public string delFirst(LinkedList<Token> colaDeTokens, int indexActual)
        {
            string entrada = "$";

            if (colaDeTokens.Count > 0)
            {
                
                entrada = colaDeTokens.First<Token>().GetClasificacion();

                while (entrada.Equals("espacio"))
                {
                    colaDeTokens.RemoveFirst();
                    entrada = colaDeTokens.First<Token>().GetClasificacion();
                }

                colaDeTokens.RemoveFirst();
            }

            return entrada;

        }

    }
}
