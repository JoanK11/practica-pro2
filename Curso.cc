/** @file Curso.cc
    @brief Implementación de la clase Curso
*/
#include "Curso.hh"

Curso::Curso() {
  inscritos = completados = 0;
}

bool Curso::anadir_problema(const string& p, const string& s) {
  map<string, string>::const_iterator it = problemas.find(p); // log(n)
  if (it != problemas.end()) return false;
  problemas.insert(it, make_pair(p, s)); // constant
  return true;
}

void Curso::nuevo_usuario() {
  ++inscritos;
  cout << inscritos << endl;
}

void Curso::baja_usuario() {
  --inscritos;
}

void Curso::nuevo_completado() {
  ++completados, --inscritos;
}

bool Curso::pertenece_problema(const string& p) const {
  map<string, string>::const_iterator it = problemas.find(p); // log(n)
  if (it == problemas.end()) return false;
  cout << it->second << endl;
  return true;
}

string Curso::sesion_problema(const string& p) const {
  return problemas.find(p)->second; // log(n)
}

int Curso::num_sesiones() const {
    return v.size();
}

string Curso::sesion_id(const int& i) const {
    return v[i];
}

void Curso::leer() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    v.push_back(s); // constant
  }
}

void Curso::escribir_curso() const {
  int n = v.size();
  cout << completados << ' ' << inscritos << ' ' << n << " (" << v[0];

  for (int i = 1; i < n; ++i) cout << ' ' << v[i];
  cout << ')' << endl;
}