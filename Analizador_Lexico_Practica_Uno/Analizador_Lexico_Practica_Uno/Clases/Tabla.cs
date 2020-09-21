using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.IsolatedStorage;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Analizador_Lexico_Practica_Uno.Clases
{
    class Tabla
    {
        private List<String> Alfabeto;
        private List<Nodo> Nodos;

        private Nodo actual;
        private int position;
        private Nodo[,] tabla;
        private RichTextBox log;

        //Constructor que recibe la lista caracteres del alfabeto y lista de nodos
        //en la lista de nodos el nodo en la primera posicion debe ser el Nodo Inicial
        public Tabla(RichTextBox log )
        {
            

            this.Alfabeto = new List<string> { "D","L","+","-","*","/","\"","<",">","=","!","|","&",";","."};
           
            crearNodos();
            CrearTabla();

            position = 0;
            actual = Nodos.ElementAt<Nodo>(0);

            this.log = log;

        }

        public List<String> getAlfabeto()
        {
            return Alfabeto;
        }

        public void setAlfabeto(List<String> Alfabeto)
        {
            this.Alfabeto = Alfabeto;
        }

        public List<Nodo> getNodos()
        {
            return Nodos;
        }

        public void setNodos(List<Nodo> nodos)
        {
            this.Nodos = nodos;
        }
        public void GetNodoByToken(int alfPosition) 
        {
            int posTemp = 0;
            Nodo temp = tabla[alfPosition, position];

            if (!temp.getIdentificador().Equals("Error"))
            {
                Nodos.ForEach(nodo => {

                    if (temp.getIdentificador().Equals(nodo.getIdentificador()))
                    {
                        position = posTemp;
                    }
                    posTemp++;

                });
            }
            else
            {
                ColorText addText = new ColorText();
                addText.addColor(log,"Error, se esperaba algo diferente",Color.Red);

            }
            
            actual = Nodos.ElementAt<Nodo>(position);

        }
        public Nodo GetNodoByPosition(int posX, int posY)
        {

            return this.tabla[posX, posY];

        }

        public void CrearTabla()
        {
            this.tabla = new Nodo[Alfabeto.Count, Nodos.Count];
            fillTablWithError();
            
            //estado inicial
            tabla[2, 0] = Nodos.ElementAt<Nodo>(1);
            tabla[3, 0] = Nodos.ElementAt<Nodo>(1);
            tabla[5, 0] = Nodos.ElementAt<Nodo>(2);
            tabla[6, 0] = Nodos.ElementAt<Nodo>(3);
            tabla[9, 0] = Nodos.ElementAt<Nodo>(4);
            tabla[10, 0] = Nodos.ElementAt<Nodo>(5);
            tabla[11, 0] = Nodos.ElementAt<Nodo>(6);
            tabla[12, 0] = Nodos.ElementAt<Nodo>(7);
            tabla[13, 0] = Nodos.ElementAt<Nodo>(13);


            //estado A
            tabla[0, 1] = Nodos.ElementAt<Nodo>(8);

            //estado B
            tabla[4, 2] = Nodos.ElementAt<Nodo>(13);
            tabla[9, 2] = Nodos.ElementAt<Nodo>(23);

            //estdo C
            tabla[1, 3] = Nodos.ElementAt<Nodo>(3);
            tabla[6, 3] = Nodos.ElementAt<Nodo>(16);

            //estado D
            tabla[9, 4] = Nodos.ElementAt<Nodo>(30);

            //estado E
            tabla[9, 5] = Nodos.ElementAt<Nodo>(30);

            //estado F
            tabla[11, 6] = Nodos.ElementAt<Nodo>(30);

            //estado G
            tabla[12, 7] = Nodos.ElementAt<Nodo>(30);

            //estado H
            tabla[0, 8] = Nodos.ElementAt<Nodo>(9);
            tabla[2, 8] = Nodos.ElementAt<Nodo>(10);
            tabla[3, 8] = Nodos.ElementAt<Nodo>(11);
            tabla[14, 8] = Nodos.ElementAt<Nodo>(12);

            //estado I
            tabla[0, 9] = Nodos.ElementAt<Nodo>(20);
            tabla[2, 9] = Nodos.ElementAt<Nodo>(10);
            tabla[3, 9] = Nodos.ElementAt<Nodo>(21);
            tabla[14, 9] = Nodos.ElementAt<Nodo>(12);
            
            //estado J
            tabla[0, 10] = Nodos.ElementAt<Nodo>(18);
            tabla[4, 10] = Nodos.ElementAt<Nodo>(22);
            tabla[5, 10] = Nodos.ElementAt<Nodo>(22);
            tabla[6, 10] = Nodos.ElementAt<Nodo>(19);

            //estado k
            tabla[0, 11] = Nodos.ElementAt<Nodo>(18);
            tabla[4, 11] = Nodos.ElementAt<Nodo>(22);
            tabla[5, 11] = Nodos.ElementAt<Nodo>(22);

            //estado L
            tabla[0, 12] = Nodos.ElementAt<Nodo>(24);

            //estado M
            tabla[1, 13] = Nodos.ElementAt<Nodo>(13);
            tabla[4, 13] = Nodos.ElementAt<Nodo>(14);

            //estado N
            tabla[4, 14] = Nodos.ElementAt<Nodo>(15);

            //estado O
            tabla[5, 15] = Nodos.ElementAt<Nodo>(30);

            //estado p
            tabla[2, 16] = Nodos.ElementAt<Nodo>(17);

            //estado Q
            tabla[0, 17] = Nodos.ElementAt<Nodo>(18);

            //estado R
            tabla[0, 18] = Nodos.ElementAt<Nodo>(18);

            //estado S
            tabla[1, 19] = Nodos.ElementAt<Nodo>(19);

            //estado T
            tabla[0, 20] = Nodos.ElementAt<Nodo>(20);
            tabla[2, 20] = Nodos.ElementAt<Nodo>(25);
            tabla[3, 20] = Nodos.ElementAt<Nodo>(20);
            tabla[14, 20] = Nodos.ElementAt<Nodo>(12);

            //estado U
            tabla[0, 21] = Nodos.ElementAt<Nodo>(26);


            //estado V
            tabla[0, 22] = Nodos.ElementAt<Nodo>(27);

            //estado W
            tabla[1, 23] = Nodos.ElementAt<Nodo>(28);

            //estado X
            tabla[0, 24] = Nodos.ElementAt<Nodo>(29);

            //estado Y
            tabla[4, 25] = Nodos.ElementAt<Nodo>(22);
            tabla[5, 25] = Nodos.ElementAt<Nodo>(22);

            //Z
            tabla[0, 26] = Nodos.ElementAt<Nodo>(26);

            //A1
            tabla[0, 27] = Nodos.ElementAt<Nodo>(27);


            //B1
            tabla[1, 28] = Nodos.ElementAt<Nodo>(28);

            //C1
            tabla[0, 29] = Nodos.ElementAt<Nodo>(27);

            //D1
            tabla[0, 30] = null;


            Console.WriteLine(tabla[5, 5]);


        }


        //Metodo que ubicara los nodos Destino dentro de la tabla
        //
        public void destinoDeTransicion(int x, int y, Nodo nodo)
        {
            this.tabla[x,y] = nodo;
        }

        public void crearNodos()
        {
            

            Nodo inicial = new Nodo("Q0","",Color.Red);

            Nodo A = new Nodo("A", "", Color.Black);
            Nodo B = new Nodo("B", "", Color.Black);
            Nodo C = new Nodo("C", "", Color.Black);
            Nodo D = new Nodo("D", "", Color.Black);
            Nodo E = new Nodo("E", "", Color.Black);
            Nodo F = new Nodo("F", "", Color.Black);
            Nodo G = new Nodo("G", "", Color.Black);
            Nodo H = new Nodo("H", "", Color.Black);
            Nodo I = new Nodo("I", "", Color.Black);
            Nodo J = new Nodo("J", "", Color.Black);
            Nodo K = new Nodo("K", "", Color.Black);
            Nodo L = new Nodo("L", "", Color.Black);
            Nodo M = new Nodo("M", "", Color.Black);
            Nodo N = new Nodo("N", "", Color.Black);
            Nodo O = new Nodo("O", "", Color.Black);
            Nodo P = new Nodo("P", "", Color.Black);
            Nodo Q = new Nodo("Q", "", Color.Black);
            Nodo R = new Nodo("R", "", Color.Black);
            Nodo S = new Nodo("S", "", Color.Black);
            Nodo T = new Nodo("T", "", Color.Black);
            Nodo U = new Nodo("U", "", Color.Black);
            Nodo V = new Nodo("V", "", Color.Black);
            Nodo W = new Nodo("W", "", Color.Black);
            Nodo X = new Nodo("X", "", Color.Black);
            Nodo Y = new Nodo("Y", "", Color.Black);
            Nodo Z = new Nodo("Z", "", Color.Black);


            Nodo A1 = new Nodo("A1", "", Color.Black);
            Nodo B1 = new Nodo("B1", "", Color.Black);
            Nodo C1 = new Nodo("C1", "", Color.Black);
            Nodo D1 = new Nodo("D1", "", Color.Black);

            D.SetAceptacion(true);
            E.SetAceptacion(true);
            H.SetAceptacion(true);
            P.SetAceptacion(true);
            D1.SetAceptacion(true);
            L.SetAceptacion(true);
            I.SetAceptacion(true);
            T.SetAceptacion(true);
            R.SetAceptacion(true);
            Z.SetAceptacion(true);
            A1.SetAceptacion(true);
            B1.SetAceptacion(true);

            Nodos = new List<Nodo>();
            Nodos.Add(inicial);
            Nodos.Add(A);
            Nodos.Add(B);
            Nodos.Add(C);
            Nodos.Add(D);
            Nodos.Add(E);
            Nodos.Add(F);
            Nodos.Add(G);
            Nodos.Add(H);
            Nodos.Add(I);
            Nodos.Add(J);
            Nodos.Add(K);
            Nodos.Add(L);
            Nodos.Add(M);
            Nodos.Add(N);
            Nodos.Add(O);
            Nodos.Add(P);
            Nodos.Add(Q);
            Nodos.Add(R);
            Nodos.Add(S);
            Nodos.Add(T);
            Nodos.Add(U);
            Nodos.Add(V);
            Nodos.Add(W);
            Nodos.Add(X);
            Nodos.Add(Y);
            Nodos.Add(Z);

            Nodos.Add(A1);
            Nodos.Add(B1);
            Nodos.Add(C1);
            Nodos.Add(D1);

        }
        public void fillTablWithError()
        {
            for(int i = 0; i<Alfabeto.Count; i++)
            {
                for(int j = 0; j<Nodos.Count; j++)
                {
                    tabla[i, j] = new Nodo("Error", "", Color.Red);
                    Console.Write(tabla[i, j].getIdentificador());
                }
                Console.WriteLine("");
            }
        }
    }
}
