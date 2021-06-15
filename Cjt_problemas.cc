/** @file Cjt_problemas.cc
    @brief Implementación de la clase Cjt_problemas
*/
#include "Cjt_problemas.hh"
#ifndef NO_DIAGRAM
#include <algorithm>
#include <vector>
#endif

Cjt_problemas::Cjt_problemas() {}

bool Cjt_problemas::anadir_problema(const string& p) {
  map<string, Problema>::const_iterator it = cjt.find(p); // log(n)
  if (it != cjt.end()) return false;
  Problema prob;
  cjt.insert(it, make_pair(p, prob)); // constant
  return true;
}

void Cjt_problemas::realizar_envio(const string& p, const int& r) {
  cjt.find(p)->second.nuevo_envio(r); // log(n)
}

int Cjt_problemas::tamano() const {
  return cjt.size();
}

bool Cjt_problemas::existe_problema(const string& p) const {
  return cjt.find(p) != cjt.end(); // log(n)
}

void Cjt_problemas::inicializar() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string p;
    cin >> p;
    Problema prob;
    cjt.insert(make_pair(p, prob)); // log(n)
  }
}

bool Cjt_problemas::escribir_problema(const string& p) const {
  map<string, Problema>::const_iterator it = cjt.find(p); // log(n)
  if (it == cjt.end()) return false;
  cout << p;
  it->second.escribir_problema(); // constant
  return true;
}

void Cjt_problemas::escribir_cjt() const {
  int n = cjt.size(), i = 0;
  vector<pair<string, Problema> > v(n); // Lineal en el nombre de problemas
  for (map<string, Problema>::const_iterator it = cjt.begin(); it != cjt.end(); ++it)
    v[i] = *it, ++i;

  sort(v.begin(), v.end(), comp); // O(Nlog(N)), donde N = Nombre de problemas
  for (i = 0; i < n; ++i) {
    cout << v[i].first;
    v[i].second.escribir_problema(); // constant
  }
}

bool Cjt_problemas::comp(const pair<const string&, const Problema&>& p1, const pair<const string&, const Problema>& p2) {
  double r1 = p1.second.ratio(), r2 = p2.second.ratio();
  if (r1 == r2) return p1.first < p2.first;
  return r1 < r2;
}