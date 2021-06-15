/** @file Usuario.cc
    @brief Implementación de la clase Usuario
*/
#include "Usuario.hh"

Usuario::Usuario() {
  curso = envios = intentados = 0;
}

void Usuario::inscribir_curso(const int& c) {
  if (enviables.empty()) curso = 0;
  else curso = c;
}

int Usuario::id_curso() const {
  return curso;
}

bool Usuario::problema_resuelto(const string& p) {
  map<string, int>::const_iterator it = resueltos.find(p); // log(n)
  if (it == resueltos.end()) {
    enviables.insert(make_pair(p, 0)); // log(n)
    return false;
  }
  return true;
}

void Usuario::envio_problema(const string& p, const int& r) {
  map<string, int>::iterator it = enviables.find(p); // log(n)
  if (it->second == 0) ++intentados;
  ++it->second, ++envios;
  if (r == 1) {
    resueltos.insert(*it); // log(n)
    enviables.erase(it); // constant
    if (enviables.empty()) curso = 0;
  }
}

void Usuario::escribir_usuario() const {
  cout << '(' << envios << ',' << resueltos.size() << ',' << intentados << ',' << curso << ')' << endl;
}

void Usuario::escribir_resueltos() const {
  for (map<string, int>::const_iterator it = resueltos.begin(); it != resueltos.end(); ++it)
    cout << it->first << '(' << it->second << ')' << endl;
}

void Usuario::escribir_enviables() const {
  for (map<string, int>::const_iterator it = enviables.begin(); it != enviables.end(); ++it)
    cout << it->first << '(' << it->second << ')' << endl;
}