/** @file Cjt_sesiones.cc
    @brief Implementación de la clase Cjt_sesiones
*/
#include "Cjt_sesiones.hh"

Cjt_sesiones::Cjt_sesiones() {}

bool Cjt_sesiones::anadir_sesion(const string& s, const Sesion& ses) {
  map<string, Sesion>::const_iterator it = cjt.find(s); // log(n)
  if (it != cjt.end()) return false;
  cjt.insert(it, make_pair(s, ses)); // constant
  return true;
}

void Cjt_sesiones::realizar_envio(Usuario& u, const string& p, const int& r, Curso& c) {
  if (r == 0) u.envio_problema(p, 0); // constant
  else {
    string s = c.sesion_problema(p); // Logarítmico en el nombre de problemas del curso
    cjt.find(s)->second.nuevo_envio(p, u);
    u.envio_problema(p, 1); // constant
    if (u.id_curso() == 0) c.nuevo_completado();
  }
}

Sesion Cjt_sesiones::operator[](const string& s) {
  return cjt.find(s)->second; // log(n)
}

int Cjt_sesiones::tamano() const {
  return cjt.size();
}

void Cjt_sesiones::inicializar() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    Sesion ses;
    ses.leer();
    cjt.insert(make_pair(s, ses)); // log(n)
  }
}

bool Cjt_sesiones::escribir_sesion(const string& s) const {
  map<string, Sesion>::const_iterator it = cjt.find(s); // log(n)
  if (it == cjt.end()) return false;
  cout << s << ' ';
  it->second.escribir_sesion(); // Lineal en el nombre de problemas de la sesión
  return true;
}

void Cjt_sesiones::escribir_cjt() const {
  map<string, Sesion>::const_iterator it = cjt.begin(); // log(n)
  while (it != cjt.end()) {
    cout << it->first << ' ';
    it->second.escribir_sesion(); // Lineal en el nombre de problemas de la sesión
    ++it;
  }
}