using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;

namespace Analizador_Lexico.Models
{
    public class LoadFile
    {
        public String Confirmacion { get; set; }
        public Exception error { get; set; }

        public void FileLoad(String path, HttpPostedFileBase file) 
        {
            try
            {
                file.SaveAs(path);
                this.Confirmacion = "Fichero Almacenado";
            }
            catch (Exception ex)
            {
                this.error = ex;
            }

        }
        public void ReadFile(String path)
        {
            String line;
            try
            {
                //Pass the file path and file name to the StreamReader constructor
                StreamReader sr = new StreamReader(path);
                //Read the first line of text
                line = sr.ReadLine();
                //Continue to read until you reach end of file
                while (line != null)
                {
                    //write the lie to console window
                    Console.WriteLine(line);
                    //Read the next line
                    line = sr.ReadLine();
                }
                //close the file
                sr.Close();
                Console.ReadLine();
            }
            catch (Exception e)
            {
                Console.WriteLine("Exception: " + e.Message);
            }
            finally
            {
                Console.WriteLine("Executing finally block.");
            }
        }
    }
}