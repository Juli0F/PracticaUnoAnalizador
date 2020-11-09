using System;
using System.Collections.Generic;
using System.Linq;

namespace Lenguajes
{
    class Analizador
    {
        private LinkedList<Token> salida;
        private int estado;
        private String auxlex;
        private int linea;
        private int columna;

        public LinkedList<Token> cadenaEntrante(String entrada)
        {
            entrada = entrada + "#";
            salida = new LinkedList<Token>();
            estado = 0;
            columna = 1;
            linea = 1;
            auxlex = "";

            Char c;
            for(int i = 0; i <= entrada.Length - 1; i++)
            {

                c = entrada.ElementAt(i);


                switch (estado)
                {
                    case 0:/*estado inicial*/

                        if (char.IsDigit(c))
                        {
                            estado = 1;
                            auxlex += c;
                            columna++;
                            //siguiente estado , reconoce digitos

                        }
                        else if (c.CompareTo('\"') == 0)
                        {//reconoce las comillas
                            estado = 4;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('e') == 0)
                        {//loo manda al automta de 'entero'
                            estado = 7;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('d') == 0)
                        {//inicia la palabra decimal
                            estado = 13;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('c') == 0)
                        {//palabras reserverdas con c : cadena o caracter
                            estado = 20;
                            columna++;
                            auxlex += c;
                        }
                        else if (c.CompareTo('b') == 0)
                        {//palabra reservada booleano
                            estado = 30;
                            columna++;
                            auxlex += c;
                        }
                        else if (c.CompareTo('f') == 0)
                        {//falso
                            estado = 38;
                            columna++;
                            auxlex += c;
                        }
                        else if (c.CompareTo('v') == 0)
                        {//falso
                            estado = 42;
                            columna++;
                            auxlex += c;
                        }
                        
                        else if (c.CompareTo('p') == 0)
                        {//palabra reservada principal
                            estado = 50;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('+') == 0)
                        {//caracter signo mas

                            estado = 59;
                            auxlex += c;
                            columna++;
                        }
                        ///inicia la parde despues del signo mas segunda parte segunda parte segunda parte segunda parte
                        else if (c.CompareTo('-') == 0)
                        {//caracter signo MENOS
                            estado = 61;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('*') == 0)
                        {//caracter signo por
                            estado = 59;
                            columna++;
                            auxlex += c;    ///agregar tokwn agregar token agregar token agregar token agregar token 
                        }
                        else if (c.CompareTo('/') == 0)
                        {//caracter signo mas

                            estado = 64;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('=') == 0)
                        {//caracter signo mas
                            estado = 78;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('>') == 0)
                        {//caracter mayor
                            estado = 72;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('<') == 0)
                        {//caracter mayor 
                            estado = 72;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('!') == 0)
                        {//caracter signo mas
                            estado = 74;
                            auxlex += c;
                            columna++;
                        }

                        else if (c.CompareTo('|') == 0)
                        {//caracter signo mas
                            estado = 75;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('&') == 0)
                        {//caracter signo mas
                            estado = 77;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('S') == 0)
                        {//caracter signo mas
                            estado = 80;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('M') == 0)
                        {//MIENTRAS
                            estado = 90;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('H') == 0)
                        {//HACER
                            estado = 97;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('I') == 0)
                        {//caracter signo mas
                            estado = 103;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('D') == 0)
                        {//caracter signo mas
                            estado = 112;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('\n') == 0)
                        {
                            linea++;
                            columna = 1;
                        } else if (c.CompareTo('l') == 0)
                        {
                            estado = 122;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('_')==0)
                        {
                            estado = 125;
                            auxlex += c;
                            columna++;
                        }
                        else if ((c.CompareTo('(') == 0) || (c.CompareTo(')') == 0) || (c.CompareTo(';') == 0) || char.IsWhiteSpace(c) || char.IsLetter(c) || (c.CompareTo(',') == 0) || (c.CompareTo('{') == 0) || (c.CompareTo('}') == 0))
                        {//caracter signo mas

                            auxlex += c;
                            columna++;
                            if (c.CompareTo('(') == 0)
                            {
                                addTokenToList(Token.Tipo.PARENTESIS_ABIERTO);
                            }else if (c.CompareTo(',') == 0)
                            {
                                addTokenToList(Token.Tipo.COMA);
                            } 
                            else if (c.CompareTo(')') == 0)
                            {
                                addTokenToList(Token.Tipo.PARENTESIS_CERRADO);
                            }
                            else if (c.CompareTo('{') == 0)
                            {
                                addTokenToList(Token.Tipo.LLAVE_ABIERTA);
                            }
                            else if (c.CompareTo('}') == 0)
                            {
                                addTokenToList(Token.Tipo.LLAVE_CERRADA);
                            }
                            else if (c.CompareTo(';') == 0)
                            {
                                addTokenToList(Token.Tipo.PUNTO_Y_COMA);
                            } else if (char.IsWhiteSpace(c))
                            {
                                addTokenToList(Token.Tipo.SPACE);
                            } else if (char.IsLetter(c))
                            {
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            //estado = 80;


                        }

                        else
                        {
                            if ((c.CompareTo('#') == 0) && (entrada.Length - 1 == i))
                            {

                            }
                            else
                            {
                                auxlex += c;
                                addTokenToList(Token.Tipo.ERROR);
                                estado = 0;
                            }

                        }
                        break;





                    //---------------------------------------------------IDENTIFICADOR DE NUMEROS ENTEROS Y DECIMALES---------------------------------------------------

                    case 1://estado 1
                        if (char.IsDigit(c))//sigue aceptado numeros
                        {
                            auxlex += c;
                            columna++;

                        } else if (c.CompareTo('.') == 0)//pasa a  la opcion de decimales
                        {

                            estado = 2;
                            auxlex += c;
                            columna++;

                        } else if (c.CompareTo('\n') == 0)//acepta numeros con saltos de linea
                        {
                            linea++;
                            columna = 1;
                        }
                        else//aparece un caracter diferente de digito y punto decimal, se acepta lo que ya se tiene almacenado en la 
                        //variable y se retroce un espacio
                        {
                            i -= 1;
                            addTokenToList(Token.Tipo.NUM_ENTERO);
                        }



                        break;



                    case 2:

                        if (char.IsDigit(c))//sigue aceptado numeros
                        {
                            estado = 3;
                            auxlex += c;
                            columna++;

                        }
                        else
                        {
                            //se esperaba un numero
                            i = i - 1;
                            columna++;
                            auxlex += c + " se esperaban Digitos";
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;

                    case 3:
                        if (char.IsDigit(c))//sigue aceptado numeros
                        {
                            estado = 3;
                            auxlex += c;
                            columna++;

                        }
                        else
                        {

                            i = i - 1;
                            columna++;
                            //auxlex += c;
                            addTokenToList(Token.Tipo.NUM_DECIMAL);

                        }
                        break;
                    //-----------------------------------------FIN----------IDENTIFICADOR DE NUMEROS ENTEROS Y DECIMALES---------------------------------------------------


                    //---------------------------------------------------INICIA IDENTIFICADOR DE CADENAS DE TEXTO DEL TIPO "(L|D)*"---------------------------------------------------
                    case 4:

                        if (!(c.CompareTo('\"') == 0))
                        {
                            estado = 4;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('\"') == 0)
                        {
                            auxlex += c;
                            addTokenToList(Token.Tipo.TEXTO);
                            columna++;
                        }
                        else
                        {

                            auxlex += "se esperaba letras o digitos o \",  se desconoce: " + c;
                            addTokenToList(Token.Tipo.ERROR);
                            columna++;
                        }
                        break;
                    //---------------------------------------------------TERMINA IDENTIFICADOR DE CADENAS DE TEXTO DEL TIPO "(L|D)*"---------------------------------------------------

                    //---------------------------------------------------INICIA IDENTIFICADOR DE PALABRA RESERVADA 'entero'---------------------------------------------------

                    case 7:
                        if (c.CompareTo('n') == 0)
                        {
                            estado = 8;
                            auxlex += c;
                            columna++;
                        }
                        else if (c.CompareTo('s') == 0)
                        {
                            estado = 116;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            
                           if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 8:
                        if (c.CompareTo('t') == 0)
                        {
                            estado = 9;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba t, se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 9:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 10;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'entero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 10:
                        if (c.CompareTo('r') == 0)
                        {
                            estado = 11;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'entero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 11:
                        if (c.CompareTo('o') == 0)
                        {
                            auxlex += c;
                            addTokenToList(Token.Tipo.KW_ENTERO);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'entero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    //---------------------------------------------------Termina IDENTIFICADOR DE PALABRA RESERVADA 'entero'---------------------------------------------------

                    //---------------------------------------------------Inicia IDENTIFICADOR DE PALABRA RESERVADA 'decimal'---------------------------------------------------
                    case 13:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 14;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 14:
                        if (c.CompareTo('c') == 0)
                        {
                            estado = 15;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'decimal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;


                    case 15:
                        if (c.CompareTo('i') == 0)
                        {
                            estado = 16;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'decimal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    case 16:
                        if (c.CompareTo('m') == 0)
                        {
                            estado = 17;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'decimal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 17:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 18;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'decimal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    case 18:
                        if (c.CompareTo('l') == 0)
                        {
                            auxlex += c;
                            addTokenToList(Token.Tipo.KW_DECIMAL);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'entero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;




                    //---------------------------------------------------Termina IDENTIFICADOR DE PALABRA RESERVADA 'decimal'---------------------------------------------------




                    //---------------------------------------------------Inicia IDENTIFICADOR DE PALABRA RESERVADA 'cadena y bifurcacion a caracter'---------------------------------------------------

                    case 20:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 21;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 21:
                        if (c.CompareTo('d') == 0)
                        {
                            estado = 22;
                            auxlex += c;
                            columna++;
                        }
                        else if ((c.CompareTo('r') == 0))
                        {
                            estado = 25;
                            auxlex += c;
                            columna++;

                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'cadena/caracter', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 22:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 23;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'cadena', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 23:
                        if (c.CompareTo('n') == 0)
                        {
                            estado = 24;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'cadena', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 24:
                        if (c.CompareTo('a') == 0)
                        {

                            auxlex += c;
                            addTokenToList(Token.Tipo.KW_CADENA);

                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'cadena', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        //---------------------------------------------------Termina IDENTIFICADOR DE PALABRA RESERVADA 'cadena'---------------------------------------------------




                        //---------------------------------------------------Inicia IDENTIFICADOR DE PALABRA RESERVADA 'caracter '---------------------------------------------------


                        break;
                    case 25:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 26;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'caracter', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 26:
                        if (c.CompareTo('c') == 0)
                        {
                            estado = 27;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'caracter', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 27:
                        if (c.CompareTo('t') == 0)
                        {
                            estado = 28;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'caracter', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 28:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 29;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'caracter', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 29:
                        if (c.CompareTo('r') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.KW_CHART);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'caracter', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    //---------------------------------------------------Termina IDENTIFICADOR DE PALABRA RESERVADA 'caracter'---------------------------------------------------




                    //---------------------------------------------------Inicia IDENTIFICADOR DE PALABRA RESERVADA 'booleano '---------------------------------------------------

                    case 30:
                        if (c.CompareTo('o') == 0)
                        {
                            estado = 31;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 31:
                        if (c.CompareTo('o') == 0)
                        {
                            estado = 32;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'booleano', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 32:
                        if (c.CompareTo('l') == 0)
                        {
                            estado = 33;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'booleano', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 33:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 34;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'booleano', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 34:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 35;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'booleano', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 35:
                        if (c.CompareTo('n') == 0)
                        {
                            estado = 36;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'booleano', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 36:
                        if (c.CompareTo('o') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.KW_BOOLEAN);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'booleano', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    //---------------------------------------------------Termina IDENTIFICADOR DE PALABRA RESERVADA 'booleano'---------------------------------------------------




                    //---------------------------------------------------Inicia IDENTIFICADOR DE PALABRA RESERVADA 'falso'---------------------------------------------------

                    case 38:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 39;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 39:
                        if (c.CompareTo('l') == 0)
                        {
                            estado = 40;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'falso', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 40:
                        if (c.CompareTo('s') == 0)
                        {
                            estado = 41;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'falso', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 41:
                        if (c.CompareTo('o') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.FALSO);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'falso', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    //---------------------------------------------------FIN IDENTIFICADOR DE PALABRA RESERVADA 'falso'---------------------------------------------------

                    //---------------------------------------------------Inicia IDENTIFICADOR DE PALABRA RESERVADA 'VERDADERO'---------------------------------------------------

                    case 42:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 43;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 43:
                        if (c.CompareTo('r') == 0)
                        {
                            estado = 44;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdadero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 44:
                        if (c.CompareTo('d') == 0)
                        {
                            estado = 45;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdadero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 45:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 46;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdadero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 46:
                        if (c.CompareTo('d') == 0)
                        {
                            estado = 47;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdadero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 47:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 48;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdadero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 48:
                        if (c.CompareTo('r') == 0)
                        {
                            estado = 49;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdadero', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 49:
                        if (c.CompareTo('o') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.VERDADERO);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'verdader', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    //---------------------------------------------------FIN IDENTIFICADOR DE PALABRA RESERVADA 'verdadero'---------------------------------------------------

                    //---------------------------------------------------inicio IDENTIFICADOR DE PALABRA RESERVADA 'principal'---------------------------------------------------

                    case 50:
                        if (c.CompareTo('r') == 0)
                        {
                            estado = 51;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 51:
                        if (c.CompareTo('i') == 0)
                        {
                            estado = 52;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 52:
                        if (c.CompareTo('n') == 0)
                        {
                            estado = 53;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 53:
                        if (c.CompareTo('c') == 0)
                        {
                            estado = 54;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 54:
                        if (c.CompareTo('i') == 0)
                        {
                            estado = 55;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 55:
                        if (c.CompareTo('p') == 0)
                        {
                            estado = 56;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 56:
                        if (c.CompareTo('a') == 0)
                        {
                            estado = 57;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 57:
                        if (c.CompareTo('l') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.PRINCIPAL);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'principal', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    //---------------------------------------------------FIN IDENTIFICADOR DE PALABRA RESERVADA 'principal'---------------------------------------------------

                    case 59:
                        if (c.CompareTo('+') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.INCREMENTO);
                        }
                        else
                        {

                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.MAS);
                            }
                            else
                            {

                                addTokenToList(Token.Tipo.MAS);
                            }

                            i = i - 1;
                            columna++;

                        }
                        break;
                    //---------------------------------------------------FIN DE INCREMENTO'++' ---------------------------------------------------
                    //---------------------------------------------------DECREMENTO '--'   ---------------------------------------------------

                    case 61:
                        if (c.CompareTo('-') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.DECREMENTO);
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.MENOS);
                            }
                            else
                            {

                                addTokenToList(Token.Tipo.MENOS);
                            }


                            columna++;
                            i = i - 1;
                        }
                        break;
                    case 64:
                        if (c.CompareTo('/') == 0)
                        {
                            estado = 67;
                            auxlex += c;
                            columna++;

                            //addTokenToList(Token.Tipo.COMENTARIO_LINEA);
                        } else if (c.CompareTo('*') == 0)
                        {
                            estado = 65;
                            auxlex += c;
                            columna++;

                        } else
                        {
                            i = i - 1;
                            addTokenToList(Token.Tipo.DIVISION);
                        }

                        break;

                    case 65:
                        if (!(c.CompareTo('*') == 0))
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                            }
                            estado = 65;
                            columna++;
                            auxlex += c;
                        }
                        else
                        {
                            estado = 66;
                            auxlex += c;
                            columna++;
                        }
                        break;
                    case 66:
                        if (c.CompareTo('/') == 0)
                        {
                            columna++;
                            auxlex += c;
                            addTokenToList(Token.Tipo.COMENTARIO_MULTILINEA);
                        }
                        else
                        {
                            estado = 65;
                            columna++;
                            auxlex += c;
                        }
                        break;
                    case 67:
                        if (!(c.CompareTo('\n') == 0))
                        {
                            estado = 67;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {

                            columna++;
                            auxlex += c;
                            addTokenToList(Token.Tipo.COMENTARIO_LINEA);

                        }
                        break;


                    //Fin division o cualquier otra cosa con el inicio de la diagonal

                    case 70:
                        if (c.CompareTo('=') == 0)
                        {
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.MAYOR_IGUAL);
                        }
                        else
                        {
                            columna++;
                            i = i - 1;
                            addTokenToList(Token.Tipo.MAYOR);
                        }
                        break;
                    case 72:
                        if (c.CompareTo('=') == 0)
                        {
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.MENOR_IGUAL);
                        }
                        else
                        {
                            columna++;
                            i = i - 1;
                            addTokenToList(Token.Tipo.MENOR);
                        }
                        break;
                    case 74:
                        if (c.CompareTo('=') == 0)
                        {
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.DIFERENTE);
                        }
                        else
                        {
                            columna++;
                            i = i - 1;
                            addTokenToList(Token.Tipo.ADMIRACION);
                        }
                        break;
                    case 75:
                        if (c.CompareTo('|') == 0)
                        {
                            columna++;
                            auxlex += c;
                            addTokenToList(Token.Tipo.O_LOGICO);
                        }
                        else
                        {
                            i = i - 1;
                            auxlex = "se esperaba |, se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;
                    case 77:
                        if (c.CompareTo('&') == 0)
                        {
                            columna++;
                            auxlex += c;
                            addTokenToList(Token.Tipo.Y_LOGICO);
                        }
                        else
                        {
                            i = i - 1;
                            auxlex = "se esperaba &, se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;


                    case 78:
                        if (c.CompareTo('=') == 0)
                        {

                            columna++;
                            auxlex += c;
                            addTokenToList(Token.Tipo.IGUAL_COMPARACION);

                        }
                        else
                        {
                            i = i - 1;
                            columna++;
                            addTokenToList(Token.Tipo.IGUAL);
                        }
                        break;


                    case 80:
                        if (c.CompareTo('I') == 0)
                        {
                            estado = 81;
                            columna++;
                            auxlex += c;

                        }
                        else
                        {
                            i = i - 1;
                            columna++;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 81:
                        if (c.CompareTo('N') == 0)
                        {
                            estado = 82;
                            columna++;
                            auxlex += c;

                        }
                        else
                        {
                            i = i - 1;
                            auxlex += c;
                            addTokenToList(Token.Tipo.SI);
                        }
                        break;
                    case 82:
                        if (c.CompareTo('O') == 0)
                        {
                            estado = 83;
                            columna++;
                            auxlex += c;

                        }
                        else
                        {
                            i = i - 1;
                            auxlex += "Se esperaba algo diferente a: " + c;
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;
                    case 83:
                        if (c.CompareTo('_') == 0)
                        {
                            estado = 84;
                            columna++;
                            auxlex += c;

                        }
                        else
                        {
                            i = i - 1;

                            addTokenToList(Token.Tipo.SINO);
                        }
                        break;
                    case 84:
                        if (c.CompareTo('S') == 0)
                        {
                            estado = 85;
                            columna++;
                            auxlex += c;

                        }
                        else
                        {
                            i = i - 1;
                            auxlex = "se esperaba a S, se desconoce: " + c;
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;
                    case 85:
                        if (c.CompareTo('I') == 0)
                        {

                            columna++;
                            auxlex += c;
                            addTokenToList(Token.Tipo.SINO_SI);

                        }
                        else
                        {
                            i = i - 1;
                            auxlex += " : se esperaba I, se desconoce: " + c;
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;
                    //___________________________________Inica PALABRA RESERVADA Mientras________________________________
                    case 90:
                        if (c.CompareTo('I') == 0)
                        {
                            estado = 91;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else if (char.IsWhiteSpace(c))
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 91:
                        if (c.CompareTo('E') == 0)
                        {
                            estado = 92;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'MIENTRAS', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 92:
                        if (c.CompareTo('N') == 0)
                        {
                            estado = 93;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'MIENTRAS', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 93:
                        if (c.CompareTo('T') == 0)
                        {
                            estado = 94;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'MIENTRAS', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 94:
                        if (c.CompareTo('R') == 0)
                        {
                            estado = 95;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'MIENTRAS', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 95:
                        if (c.CompareTo('A') == 0)
                        {

                            estado = 96;
                            auxlex += c;

                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'MIENTRAS', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    case 96:
                        if (c.CompareTo('S') == 0)
                        {

                            auxlex += c;
                            columna++;

                            addTokenToList(Token.Tipo.MIENTRAS);
                        }
                        else
                        {

                            columna++;

                            auxlex = "se esperaba completar 'MIENTRAS', se desconoce " + c;

                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    //___________________________________Inica PALABRA RESERVADA HACER ________________________________

                    case 97:
                        if (c.CompareTo('A') == 0)
                        {
                            estado = 98;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }



                            columna++;
                            i = -1;
                        }
                        break;
                    case 98:
                        if (c.CompareTo('C') == 0)
                        {
                            estado = 99;
                            auxlex += c;
                            columna++;
                        } else if (c.CompareTo('S') == 0)
                        {
                            estado = 101;
                            auxlex += c;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'HACER'/ HASTA, se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 99:
                        if (c.CompareTo('E') == 0)
                        {
                            estado = 100;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'HACER', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 100:
                        if (c.CompareTo('R') == 0)
                        {
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.HACER);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'HACER', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    //_____________________________________HASTA _____________________________________________________________


                    case 101:
                        if (c.CompareTo('T') == 0)
                        {
                            estado = 102;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'HASTA', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 102:
                        if (c.CompareTo('A') == 0)
                        {
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.HASTA);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'HASTA', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    //------------------------------------------------INCREMENTO---------------------------------------------

                    case 103:
                        if (c.CompareTo('N') == 0)
                        {
                            estado = 104;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 104:
                        if (c.CompareTo('C') == 0)
                        {
                            estado = 105;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 105:
                        if (c.CompareTo('R') == 0)
                        {
                            estado = 106;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 106:
                        if (c.CompareTo('E') == 0)
                        {
                            estado = 107;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 107:
                        if (c.CompareTo('M') == 0)
                        {
                            estado = 108;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 108:
                        if (c.CompareTo('E') == 0)
                        {
                            estado = 109;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 109:
                        if (c.CompareTo('N') == 0)
                        {
                            estado = 110;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 110:
                        if (c.CompareTo('T') == 0)
                        {
                            estado = 111;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;


                    case 111:
                        if (c.CompareTo('O') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.INCREMENTO);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'INCREMENTO', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    //------------------------------------------------------------------------------------------------------------
                    //------------------------------------DESDE------------------------------------------------------------------------


                    case 112:
                        if (c.CompareTo('E') == 0)
                        {
                            estado = 113;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 113:
                        if (c.CompareTo('S') == 0)
                        {
                            estado = 114;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'DESDE', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 114:
                        if (c.CompareTo('D') == 0)
                        {
                            estado = 115;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'DESDE', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;


                    case 115:
                        if (c.CompareTo('E') == 0)
                        {

                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.DESDE);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'DESDE', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    //escribir
                    case 116:
                        if (c.CompareTo('c') == 0)
                        {
                            estado = 117;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'escribir', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        } 
                

                        break;
                    case 117:
                        if (c.CompareTo('r') == 0)
                        {
                            estado = 118;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'escribir', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 118:
                        if (c.CompareTo('i') == 0)
                        {
                            estado = 119;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'escribir', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 119:
                        if (c.CompareTo('b') == 0)
                        {
                            estado = 120;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'escribir', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 120:
                        if (c.CompareTo('i') == 0)
                        {
                            estado = 121;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'escribir', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 121:
                        if (c.CompareTo('r') == 0)
                        {
                            
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.ESCRIBIR);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'escribir', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;

                    //----------------------------------------------leer-----------------
                    case 122:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 123;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            if (c.CompareTo('\n') == 0)
                            {
                                linea++;
                                columna = 0;
                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }
                            else
                            {

                                addTokenToList(Token.Tipo.CARCTER_VALUE);
                            }


                            columna++;
                            i = -1;
                        }
                        break;
                    case 123:
                        if (c.CompareTo('e') == 0)
                        {
                            estado = 124;
                            auxlex += c;
                            columna++;
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'leer', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 124:
                        if (c.CompareTo('r') == 0)
                        {
                            estado = 115;
                            auxlex += c;
                            columna++;
                            addTokenToList(Token.Tipo.LEER);
                        }
                        else
                        {
                            columna++;
                            auxlex = "se esperaba completar 'leer', se desconoce " + c;
                            addTokenToList(Token.Tipo.ERROR);

                        }
                        break;
                    case 125:
                        if (char.IsLetter(c))
                        {
                            estado = 126;
                            auxlex += c;
                            columna++;

                        }
                        else
                        {
                            auxlex += ", no se reconoce: " + c;
                            addTokenToList(Token.Tipo.ERROR);
                        }
                        break;
                    case 126:

                        if (char.IsLetterOrDigit(c) && !char.IsWhiteSpace(c) )
                        {
                            auxlex += c;
                            columna++;
                            estado = 126;
                        }
                        else
                        {
                            addTokenToList(Token.Tipo.IDENTIFICADOR);
                        }
                        break;


                }

            }
            
            return salida;
        }
        public void addTokenToList(Token.Tipo tipo)
        {
            salida.AddLast(new Token(tipo, auxlex, linea, columna));
            //Console.WriteLine("add.conteo:" + salida.Count);
            estado = 0;
            auxlex = "";
        }

        public void printList(LinkedList<Token> lista)
        {
            foreach (Token item in lista)
            {
                item.AsignarTipo();
                Console.WriteLine(" Columna"  + item.getColumna() +" Linea: "+item.GetLinea()+ ",  Tipo: " + item.GetClasificacion() + ", valor: " + item.GetValue());
            }

        }
    }
    
}
