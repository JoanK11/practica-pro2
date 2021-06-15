/** @file Problema.cc
    @brief Implementación de la clase Problema
*/
#include "Problema.hh"

Problema::Problema() {
  enviados = resueltos = 0;
}

void Problema::nuevo_envio(const int& r) {
  ++enviados;
  if (r == 1) ++resueltos;
}

double Problema::ratio() const {
  return double(enviados + 1)/(resueltos + 1);
}

void Problema::escribir_problema() const {
  cout << '(' << enviados << ',' << resueltos << ',' << ratio() << ')' << endl;
}