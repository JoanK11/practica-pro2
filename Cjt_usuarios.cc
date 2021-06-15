/** @file Cjt_usuarios.cc
    @brief Implementación de la clase Cjt_usuarios
*/
#include "Cjt_usuarios.hh"

Cjt_usuarios::Cjt_usuarios() {}

bool Cjt_usuarios::anadir_usuario(const string& u) {
  map<string, Usuario>::const_iterator it = cjt.find(u); // log(n)
  if (it != cjt.end()) return false;
  Usuario us;
  cjt.insert(it, make_pair(u, us)); // constant
  return true;
}

bool Cjt_usuarios::borrar_usuario(const string& u, Cjt_cursos& Cursos) {
  map<string, Usuario>::const_iterator it = cjt.find(u); // log(n)
  if (it == cjt.end()) return false;
  int c = it->second.id_curso();
  if (c != 0) Cursos.baja_usuario(c); // constant
  cjt.erase(it); // constant
  return true;
}

bool Cjt_usuarios::inscribir_curso(const int& c, Cjt_sesiones& Sesiones, Cjt_cursos& Cursos) {
  if (cjt_it->second.id_curso() != 0) return false;
  Cursos.inscribir_usuario(c, cjt_it->second, Sesiones);
  cjt_it->second.inscribir_curso(c); // constant
  if (cjt_it->second.id_curso() == 0) Cursos.nuevo_completado(c); // constant
  return true;
}

void Cjt_usuarios::realizar_envio(const string& u, const string& p, const int& r, Cjt_cursos& Cursos, Cjt_sesiones& Sesiones) {
  Cursos.realizar_envio(cjt.find(u)->second, p, r, Sesiones);
}

int Cjt_usuarios::tamano() const {
  return cjt.size();
}

bool Cjt_usuarios::existe_usuario(const string& u) {
  cjt_it = cjt.find(u); // log(n)
  return (cjt_it != cjt.end());
}

bool Cjt_usuarios::consultar_curso(const string& u) const {
  map<string, Usuario>::const_iterator it = cjt.find(u); // log(n)
  if (it == cjt.end()) return false;
  cout << it->second.id_curso() << endl; // constant
  return true;
}

void Cjt_usuarios::inicializar() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) { // n
    string u;
    cin >> u;
    Usuario us;
    cjt.insert(make_pair(u, us)); // log(n)
  }
}

bool Cjt_usuarios::escribir_usuario(const string& u) const {
  map<string, Usuario>::const_iterator it = cjt.find(u); // log(n)
  if (it == cjt.end()) return false;
  cout << u;
  it->second.escribir_usuario(); // constant
  return true;
}

bool Cjt_usuarios::escribir_resueltos(const string& u) const {
  map<string, Usuario>::const_iterator it = cjt.find(u); // log(N)
  if (it == cjt.end()) return false;
  it->second.escribir_resueltos(); // Lineal en el nombre de problemas resueltos del usuario
  return true;
}

bool Cjt_usuarios::escribir_enviables() const {
  if (cjt_it->second.id_curso() == 0) return false;
  cjt_it->second.escribir_enviables(); // Lineal en el nombre de problemas enviables del usuario
  return true;
}

void Cjt_usuarios::escribir_cjt() const {
  map<string, Usuario>::const_iterator it = cjt.begin(); // log(n)
  while (it != cjt.end()) {
    cout << it->first;
    it->second.escribir_usuario(); // constant
    ++it;
  }
}