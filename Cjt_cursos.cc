/** @file Cjt_cursos.cc
    @brief Implementación de la clase Cjt_cursos
*/
#include "Cjt_cursos.hh"

Cjt_cursos::Cjt_cursos() {}

void Cjt_cursos::inscribir_usuario(const int& c, Usuario& u, Cjt_sesiones& Sesiones) {
  int n = cjt[c - 1].num_sesiones();
  for (int i = 0; i < n; ++i) {
    string s = cjt[c - 1].sesion_id(i);
    Sesiones[s].encontrar_enviables(u); // log(n) para Sesiones[s]
  }
  cjt[c - 1].nuevo_usuario();
}

void Cjt_cursos::nuevo_completado(const int& c) {
  cjt[c - 1].nuevo_completado();
}

void Cjt_cursos::baja_usuario(const int& c) {
  cjt[c - 1].baja_usuario();
}

bool Cjt_cursos::existe_interseccion(Curso& c, Cjt_sesiones& Sesiones) {
  int n = c.num_sesiones();
  for (int i = 0; i < n; ++i) {
    string s = c.sesion_id(i);
    if (not Sesiones[s].interseccion_vacia(c, s)) return true;
  }
  cjt.push_back(c);
  return false;
}

void Cjt_cursos::realizar_envio(Usuario& u, const string& p, const int& r, Cjt_sesiones& Sesiones) {
  Sesiones.realizar_envio(u, p, r, cjt[u.id_curso() - 1]);
}

int Cjt_cursos::tamano() const {
  return cjt.size();
}

bool Cjt_cursos::existe_curso(const int& c) const {
  return (c <= cjt.size() and c > 0);
}

bool Cjt_cursos::pertenece_problema(const int& c, const string& p) const {
  return cjt[c - 1].pertenece_problema(p); // log(n), n = Nombre de problemas del curso
}

void Cjt_cursos::inicializar(Cjt_sesiones& Sesiones) {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    Curso c;
    c.leer();
    int n = c.num_sesiones();
    for (int i = 0; i < n; ++i) {
      string s = c.sesion_id(i);
      Sesiones[s].anadir_problemas(c, s);
    }
    cjt.push_back(c);
  }
}

bool Cjt_cursos::escribir_curso(const int& c) const {
  if (c > cjt.size() or c < 1) return false;
  cout << c << ' ';
  cjt[c - 1].escribir_curso(); // Lineal en el nombre de sesiones del curso
  return true;
}

void Cjt_cursos::escribir_cjt() const {
  int n = cjt.size();
  for (int i = 0; i < n; ++i) {
    cout << i + 1 << ' ';
    cjt[i].escribir_curso(); // Lineal en el nombre de sesiones del curso
  }
}