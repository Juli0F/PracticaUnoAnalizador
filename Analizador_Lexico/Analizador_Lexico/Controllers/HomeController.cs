using Analizador_Lexico.Models;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Web;
using System.Web.ModelBinding;
using System.Web.Mvc;



namespace Analizador_Lexico.Controllers
{
    public class HomeController : Controller
    {
        
        public ActionResult Nuevo(String nombre)
        {
            ViewBag.Title = "Archivo: "+nombre;
            
            return View();
        }
        
        [HttpPost]
        public ActionResult LF(HttpPostedFileBase file)
        {
            LoadFile model = new LoadFile();
            if (file != null)
            {
                String path = Server.MapPath("~/Temp/");
                path += file.FileName;
                model.FileLoad(path, file);
                model.ReadFile(path);
                ViewBag.error = model.error;
                ViewBag.Confirmar = model.Confirmacion;
            }
            return null;
           // return Viewf();
        }
        
        public ActionResult LF()
        {
            
            ViewBag.Archivo = "Hola";
            return View();
        }
        public ActionResult Index()
        {
            return View();
        }

        public ActionResult About()
        {
            ViewBag.Message = "Your application description page.";

            return View();
        }

        public ActionResult Contact()
        {
            ViewBag.Message = "Your contact page.";

            return View();
        }
    }
}