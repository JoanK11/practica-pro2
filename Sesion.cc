/** @file Sesion.cc
    @brief Implementación de la clase Sesion
*/
#include "Sesion.hh"

Sesion::Sesion() {
  tam = 0;
}

void Sesion::encontrar_enviables_rec(const BinTree<string>& a, Usuario& u) const {
  if (not a.empty()) {
    if (u.problema_resuelto(a.value())) { // Logarítmico
      encontrar_enviables_rec(a.left(), u);
      encontrar_enviables_rec(a.right(), u);
    }
  }
}

void Sesion::encontrar_enviables(Usuario& u) const {
  encontrar_enviables_rec(a, u);
}

void Sesion::interseccion_vacia_rec(const BinTree<string>& a, Curso& c, const string& id, bool& b) const {
  if (not a.empty() and b) {
    b = c.anadir_problema(a.value(), id); // Logarítmico en el nombre de problemas del curso
    if (b) {
      interseccion_vacia_rec(a.left(), c, id, b);
	    interseccion_vacia_rec(a.right(), c, id, b);
    }
  }
}

bool Sesion::interseccion_vacia(Curso& c, const string& id) const {
  bool b = true;
  interseccion_vacia_rec(a, c, id, b);
  return b;
}

void Sesion::encontrar_problema(const BinTree<string>& a, const string& p, Usuario& u, bool& found) const {
  if (not a.empty() and not found) {
    if (a.value() == p) {
      encontrar_enviables_rec(a.left(), u), encontrar_enviables_rec(a.right(), u);
      found = true;
    }
    else encontrar_problema(a.left(), p, u, found), encontrar_problema(a.right(), p, u, found);
  }
}

void Sesion::nuevo_envio(const string& p, Usuario& u) const {
  bool found = false;
  encontrar_problema(a, p, u, found);
}

void Sesion::anadir_problemas_rec(const BinTree<string>& a, Curso& c, const string& id) const {
  if (not a.empty()) {
    c.anadir_problema(a.value(), id); // Logarítmico en el nombre de problemas
    anadir_problemas_rec(a.left(), c, id);
    anadir_problemas_rec(a.right(), c, id);
  }
}

void Sesion::anadir_problemas(Curso& c, const string& id) const {
  anadir_problemas_rec(a, c, id);
}

void Sesion::leer_rec(BinTree<string>& a) {
  string p;
  cin >> p;

  if (p != "0") {
    BinTree<string> i, d;
    leer_rec(i), leer_rec(d);
    a = BinTree<string>(p, i, d);
    ++tam;
  }
}

void Sesion::leer() {
  leer_rec(a); // n
}

void Sesion::escribir_sesion_rec(const BinTree<string>& a) const {
  if (not a.empty()) {
    cout << '(';
    escribir_sesion_rec(a.left()), escribir_sesion_rec(a.right());
    cout << a.value() << ')';
  }
}

void Sesion::escribir_sesion() const {
  cout << tam << ' ';
  escribir_sesion_rec(a); // n
  cout << endl;
}