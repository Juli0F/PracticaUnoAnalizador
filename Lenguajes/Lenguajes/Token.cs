using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lenguajes
{
    public class Token
    {
        public enum Tipo
        {
            NUM_ENTERO,//NUMERO ENTERO
            NUM_DECIMAL,//NUMERO DECIMAL
            TEXTO,//TEXTO ENTRE COMILLAS
            CARCTER_VALUE,//CARACTER EJEMPLO 'A' 'B' 'C' ... PERO SIN COMILLAS
            KW_ENTERO,//PALABRA RESERVADA PARA DECLARAR UN ENTERO
            KW_CADENA,//PALABRA RESERVADA PARA DECLARAR UNA CADENA
            KW_BOOLEAN,//PALABRA RESERVADA PARA DECLARAR UN BOOLEAN
            KW_CHART,//PALABRA RESERVADA PARA DECLARAR UN CHAR
            KW_DECIMAL,//PALABRA RESERVADA PARA declarar un numero decimal
            FALSO,
            VERDADERO,
            PRINCIPAL,
            MAS,//SIGNO MAS +
            MENOS,//SIGNO MENOS -
            MULTIPLICACION,//SIGNO POR *
            DIVISION,// SIGNO DE DIVISION /
            INCREMENTO, //DOBLE SIGNO MAS '++'
            DECREMENTO,//DOBLE SIGNO MENOS '--'
            MAYOR,// SIGNO MAYOR QUE '>'
            MENOR,//SIGNO MENOR QUE '<'
            MAYOR_IGUAL,//SIGNOS  >=
            MENOR_IGUAL,//SIGNOS  <=
            IGUAL_COMPARACION,//SIGNOS ==
            DIFERENTE,////SIGNOS  !=
            O_LOGICO,//SIGNOS  ||
            Y_LOGICO,//SIGNOS  &&
            ADMIRACION,//SIGNO  !
            PARENTESIS_ABIERTO,//SIGNO  (
            PARENTESIS_CERRADO,//SIGNO  )
            LLAVE_ABIERTA,//SIGNO  {
            LLAVE_CERRADA,//SIGNO  }
            IGUAL,// SIGNO IGUAL =
            PUNTO_Y_COMA,// FIN DE LINEA ;
           // PALABRA_RESERVADA,// SI SINO SINO_SI MIENTRAS HACER HASTA
           COMA,
           SI,
           SINO,
           SINO_SI,
           MIENTRAS,
           HACER,
           HASTA,
           DESDE,
           KW_INCREMENTO,
           COMENTARIO_LINEA,
           COMENTARIO_MULTILINEA,
           SPACE,
           ERROR,
           ESCRIBIR,
           LEER,
           IDENTIFICADOR,
           IMPRIMIR,
           

        }

        public Token(Tipo typeToken, String value, int linea, int columna)
        {
            this.typeToken = typeToken;
            AsignarTipo();
            Console.WriteLine("TypeToken "+this.typeToken);
            this.value = value;
            this.linea = linea;
            this.columna = columna;

        }
        public String GetValue()
        {
            return this.value;
        }
        public string GetClasificacion() {
            return this.clasificacion;
        }
        public void SetClasificacion(string clasificacion)
        {
            this.clasificacion = clasificacion;
        }

        public int GetLinea()
        {
            return this.linea;
        }
        public int getColumna()
        {
            return this.columna;
        }
        public void AsignarTipo()
        {
            switch (typeToken)
            {
                case Tipo.NUM_ENTERO:
                    clasificacion = "numero"; break;
                case Tipo.NUM_DECIMAL:
                    clasificacion = "numero"; break;
                case Tipo.TEXTO:
                    clasificacion = "text"; break;
                case Tipo.KW_ENTERO:
                    clasificacion = "entero"; break;
                case Tipo.KW_DECIMAL:
                    clasificacion = "decimal"; break;
                case Tipo.KW_BOOLEAN:
                    clasificacion = "boolean"; break;
                case Tipo.KW_CHART:
                    clasificacion = "caracter"; break;
                case Tipo.KW_CADENA:
                    clasificacion = "cadena"; break;
                case Tipo.FALSO:
                    clasificacion = "booleano"; break;
                case Tipo.LLAVE_ABIERTA:
                    clasificacion = "llave_abierta"; break;
                case Tipo.LLAVE_CERRADA:
                    clasificacion = "llave_cerrada"; break;
                case Tipo.VERDADERO:
                    clasificacion = "booleano"; break;
                case Tipo.PRINCIPAL:
                    clasificacion = "principal"; break;
                case Tipo.MAS:
                    clasificacion = "mas"; break;
                case Tipo.MENOS:
                    clasificacion = "menos"; break;
                case Tipo.MULTIPLICACION:
                    clasificacion = "por"; break;
                case Tipo.DIVISION:
                    clasificacion = "division"; break;
                case Tipo.INCREMENTO:
                    clasificacion = "incremento"; break;
                case Tipo.DECREMENTO:
                    clasificacion = "decremento"; break;
                case Tipo.MAYOR:
                    clasificacion = "op_relacional"; break;
                case Tipo.MENOR:
                    clasificacion = "op_relacional"; break;
                case Tipo.MAYOR_IGUAL:
                    clasificacion = "op_relacional"; break;
                case Tipo.MENOR_IGUAL:
                    clasificacion = "op_relacional"; break;
                case Tipo.IGUAL_COMPARACION:
                    clasificacion = "op_relacional"; break;
                case Tipo.DIFERENTE:
                    clasificacion = "op_relacional"; break;
                case Tipo.O_LOGICO:
                    clasificacion = "op_logico"; break;
                case Tipo.Y_LOGICO:
                    clasificacion = "op_logico"; break;
                case Tipo.ADMIRACION:
                    clasificacion = "op_logico"; break;
                case Tipo.PARENTESIS_ABIERTO:
                    clasificacion = "par_abierto"; break;
                case Tipo.PARENTESIS_CERRADO:
                    clasificacion = "par_cerrado"; break;
                case Tipo.IGUAL:
                    clasificacion = "igual"; break;
                case Tipo.PUNTO_Y_COMA:
                    clasificacion = "punto_coma"; break;
                case Tipo.COMA:
                    clasificacion = "coma"; break;
                //case Tipo.PALABRA_RESERVADA:
                //    clasificacion =  "PALABRA_RESERRVADA"; break;
                case Tipo.COMENTARIO_LINEA:
                    clasificacion = "COMENTARIO_LINEA"; break;
                case Tipo.COMENTARIO_MULTILINEA:
                    clasificacion = "COMENTARIO_MULTILINEA"; break;
                case Tipo.ERROR:
                    clasificacion = "error"; break;
                case Tipo.SPACE:
                    clasificacion = "espacio"; break;
                case Tipo.CARCTER_VALUE:
                    clasificacion = "caracter"; break;
                case Tipo.SI:
                    clasificacion = "si"; break;
                case Tipo.SINO:
                    clasificacion = "sino"; break;
                case Tipo.SINO_SI:
                    clasificacion = "sino_si"; break;
                case Tipo.MIENTRAS:
                    clasificacion = "mientras"; break;
                case Tipo.HACER:
                    clasificacion = "hacer"; break;
                case Tipo.HASTA:
                    clasificacion = "hasta"; break;
                case Tipo.DESDE:
                    clasificacion = "desde"; break;
                case Tipo.KW_INCREMENTO:
                    clasificacion = "kw_incremento"; break;
                case Tipo.IDENTIFICADOR:
                    clasificacion = "id"; break;

            }
        }
            public void GetTypeToken()
                {
            switch (typeToken)
            {
                case Tipo.NUM_ENTERO:
                    clasificacion =  "NUM_ENTERO"; break;
                case Tipo.NUM_DECIMAL:
                    clasificacion =  "NUM_Decimal"; break;
                case Tipo.TEXTO:
                    clasificacion =  "TEXTO"; break;
                case Tipo.KW_ENTERO:
                    clasificacion =  "KW_ENTERO"; break;
                case Tipo.KW_DECIMAL:
                    clasificacion =  "KW_DECIMAL"; break;
                case Tipo.KW_BOOLEAN:
                    clasificacion =  "KW_BOOLEAN"; break;
                case Tipo.KW_CHART:
                    clasificacion =  "KW_CARACTER"; break;
                case Tipo.KW_CADENA:
                    clasificacion =  "KW_CADENA"; break;
                case Tipo.FALSO:
                    clasificacion =  "FALSO"; break;
                case Tipo.VERDADERO:
                    clasificacion =  "VERDADERO"; break;
                case Tipo.PRINCIPAL:
                    clasificacion =  "PRINCIPAL"; break;
                case Tipo.MAS:
                    clasificacion =  "SIGNO_MAS"; break;
                case Tipo.MENOS:
                    clasificacion =  "SIGNO_MENOS"; break;
                case Tipo.MULTIPLICACION:
                    clasificacion =  "SIGNO_POR"; break;
                case Tipo.DIVISION:
                    clasificacion =  "DIVISION"; break;
                case Tipo.INCREMENTO:
                    clasificacion =  "INCREMENTO"; break;
                case Tipo.DECREMENTO:
                    clasificacion =  "DECREMENTO"; break;
                case Tipo.MAYOR:
                    clasificacion =  "MAYOR_QUE"; break;
                case Tipo.MENOR:
                    clasificacion =  "MENOR_QUE"; break;
                case Tipo.MAYOR_IGUAL:
                    clasificacion =  "MAYOR_IGUAL"; break;
                case Tipo.MENOR_IGUAL:
                    clasificacion =  "MENOR_IGUAL"; break;
                case Tipo.IGUAL_COMPARACION:
                    clasificacion =  "IGUAL_IGUAL =="; break;
                case Tipo.DIFERENTE:
                    clasificacion =  "DIFERENTE"; break;
                case Tipo.O_LOGICO:
                    clasificacion =  " 'O' "; break;
                case Tipo.Y_LOGICO:
                    clasificacion =  "&"; break;
                case Tipo.ADMIRACION:
                    clasificacion =  "!"; break;
                case Tipo.PARENTESIS_ABIERTO:
                    clasificacion =  "PARENTESIS ABIERTO"; break;
                case Tipo.PARENTESIS_CERRADO:
                    clasificacion =  "PARENTESIS_CERRADO"; break;
                case Tipo.IGUAL:
                    clasificacion =  "SIGNO_IGUAL"; break;
                case Tipo.PUNTO_Y_COMA:
                    clasificacion =  "punto_coma"; break;
                //case Tipo.PALABRA_RESERVADA:
                //    clasificacion =  "PALABRA_RESERRVADA"; break;
                case Tipo.COMENTARIO_LINEA:
                    clasificacion =  "COMENTARIO_LINEA"; break;
                case Tipo.COMENTARIO_MULTILINEA:
                    clasificacion =  "COMENTARIO_MULTILINEA"; break;
                case Tipo.ERROR:
                    clasificacion =  "ERROR"; break;
                case Tipo.SPACE:
                    clasificacion =  "ESPACIO"; break;
                case Tipo.CARCTER_VALUE:
                    clasificacion =  "CARACTER"; break;
                case Tipo.SI:
                    clasificacion =  "SI"; break;
                case Tipo.SINO:
                    clasificacion =  "SINO"; break;
                case Tipo.SINO_SI:
                    clasificacion =  "SINO_SI"; break;
                case Tipo.MIENTRAS:
                    clasificacion =  "MIENTRAS"; break;
                case Tipo.HACER:
                    clasificacion =  "HACER"; break;
                case Tipo.HASTA:
                    clasificacion =  "HASTA"; break;
                case Tipo.DESDE:
                    clasificacion =  "DESDE"; break;
                case Tipo.KW_INCREMENTO:
                    clasificacion =  "KW_INCREMENTO"; break;
                
            }
        }
        private string clasificacion ;
        private int linea;
        private int columna;
        private Tipo typeToken;
        private String value;
    }
}
