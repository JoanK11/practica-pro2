/**
 * @mainpage EVALUATOR: Plataforma de gestión de problemas y cursos de programación. Documentación.
 
 El programa principal se encuentra en el módulo program.cc. En referencia a los tipos de datos, para cada módulo tendremos un conjunto de módulos asociado. Estos son los siguientes: a Usuario se le asocia Cjt_usuarios, a Problema se le asocia Cjt_problemas, a Sesion se le asocia Cjt_sesiones y a Curso se le asocia Cjt_cursos.
 En Usuario y Cjt_usuarios se guarda la información relacionada sobre los usuarios registrados en la Plataforma, en Problema y Cjt_problemas se guarda la información sobre cada problema, en Sesion y Cjt_sesiones se guarda la información de cada sesión, y en Curso y Cjt_cursos se guarda la información de cada curso.
*/
#include "Cjt_usuarios.hh"
#include "Cjt_problemas.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

int main() {
  Cjt_problemas Problemas;
  Cjt_sesiones Sesiones;
  Cjt_cursos Cursos;
  Cjt_usuarios Usuarios;

  Problemas.inicializar();
  Sesiones.inicializar();
  Cursos.inicializar(Sesiones);
  Usuarios.inicializar();

  string op;
  cin >> op;
  while (op != "fin") {

    if (op == "nuevo_problema" or op == "np") {
      string p;
      cin >> p;
      cout << '#' << op << ' ' << p << endl;

      if (Problemas.anadir_problema(p)) cout << Problemas.tamano() << endl;
      else cout << "error: el problema ya existe" << endl;
    }

    else if (op == "nueva_sesion" or op == "ns") {
      string s;
      Sesion ses;
      cin >> s;
      ses.leer();
      cout << '#' << op << ' ' << s << endl;

      if (Sesiones.anadir_sesion(s, ses)) cout << Sesiones.tamano() << endl;
      else cout << "error: la sesion ya existe" << endl;
    }

    else if (op == "nuevo_curso" or op == "nc") {
      Curso c;
      c.leer();
      cout << '#' << op << endl;

      if (not Cursos.existe_interseccion(c, Sesiones)) cout << Cursos.tamano() << endl;
      else cout << "error: curso mal formado" << endl;
    }

    else if (op == "alta_usuario" or op == "a") {
      string u;
      cin >> u;
      cout << '#' << op << ' ' << u << endl;

      if (Usuarios.anadir_usuario(u)) cout << Usuarios.tamano() << endl;
      else cout << "error: el usuario ya existe" << endl;
    }

    else if (op == "baja_usuario" or op == "b") {
      string u;
      cin >> u;
      cout << '#' << op << ' ' << u << endl;

      if (Usuarios.borrar_usuario(u, Cursos)) cout << Usuarios.tamano() << endl;
      else cout << "error: el usuario no existe" << endl;
    }

    else if (op == "inscribir_curso" or op == "i") {
      string u;
      int c;
      cin >> u >> c;
      cout << '#' << op << ' ' << u << ' ' << c << endl;

      if (not Usuarios.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
      else if (not Cursos.existe_curso(c)) cout << "error: el curso no existe" << endl;
      else if (not Usuarios.inscribir_curso(c, Sesiones, Cursos)) cout << "error: usuario inscrito en otro curso" << endl;
    }

    else if (op == "curso_usuario" or op == "cu") {
      string u;
      cin >> u;
      cout << '#' << op << ' ' << u << endl;

      if (not Usuarios.consultar_curso(u)) cout << "error: el usuario no existe" << endl;
    }

    else if (op == "sesion_problema" or op == "sp") {
      int c;
      string p;
      cin >> c >> p;
      cout << '#' << op << ' ' << c << ' ' << p << endl;

      if (not Cursos.existe_curso(c)) cout << "error: el curso no existe" << endl;
      else if (not Problemas.existe_problema(p)) cout << "error: el problema no existe" << endl;
      else if (not Cursos.pertenece_problema(c, p)) cout << "error: el problema no pertenece al curso" << endl;
    }

    else if (op == "problemas_resueltos" or op == "pr") {
      string u;
      cin >> u;
      cout << '#' << op << ' ' << u << endl;

      if (not Usuarios.escribir_resueltos(u)) cout << "error: el usuario no existe" << endl;
    }

    else if (op == "problemas_enviables" or op == "pe") {
      string u;
      cin >> u;
      cout << '#' << op << ' ' << u << endl;

      if (not Usuarios.existe_usuario(u)) cout << "error: el usuario no existe" << endl;
      else if (not Usuarios.escribir_enviables()) cout << "error: usuario no inscrito en ningun curso" << endl;
    }

    else if (op == "envio" or op == "e") {
      string u, p;
      int r;
      cin >> u >> p >> r;
      cout << '#' << op << ' ' << u << ' ' << p << ' ' << r << endl;

      Problemas.realizar_envio(p, r);
      Usuarios.realizar_envio(u, p, r, Cursos, Sesiones);
    }

    else if (op == "listar_problemas" or op == "lp") {
      cout << '#' << op << endl;
      Problemas.escribir_cjt();
    }

    else if (op == "escribir_problema" or op == "ep") {
      string p;
      cin >> p;
      cout << '#' << op << ' ' << p << endl;

      if (not Problemas.escribir_problema(p)) cout << "error: el problema no existe" << endl;
    }

    else if (op == "listar_sesiones" or op == "ls") {
      cout << '#' << op << endl;
      Sesiones.escribir_cjt();
    }

    else if (op == "escribir_sesion" or op == "es") {
      string s;
      cin >> s;
      cout << '#' << op << ' ' << s << endl;

      if (not Sesiones.escribir_sesion(s)) cout << "error: la sesion no existe" << endl;
    }

    else if (op == "listar_cursos" or op == "lc") {
      cout << '#' << op << endl;
      Cursos.escribir_cjt();
    }

    else if (op == "escribir_curso" or op == "ec") {
      int c;
      cin >> c;
      cout << '#' << op << ' ' << c << endl;

      if (not Cursos.escribir_curso(c)) cout << "error: el curso no existe" << endl;
    }

    else if (op == "listar_usuarios" or op == "lu") {
      cout << '#' << op << endl;
      Usuarios.escribir_cjt();
    }

    else if (op == "escribir_usuario" or op == "eu") {
      string u;
      cin >> u;
      cout << '#' << op << ' ' << u << endl;

      if (not Usuarios.escribir_usuario(u)) cout << "error: el usuario no existe" << endl;
    }
    cin >> op;
  }
}