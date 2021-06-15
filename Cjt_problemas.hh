/** @file Cjt_problemas.hh
    @brief Especificación de la clase Cjt_problemas
*/
#ifndef CJT_PROBLEMAS_HH
#define CJT_PROBLEMAS_HH
#include "Problema.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <set>
#endif

/** @class Cjt_problemas
    @brief Representa un conjunto de problemas
*/
class Cjt_problemas {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un conjunto de problemas.
    \pre Cierto.
    \post El resultado es un conjunto de problemas vacío.
    \coste Constante.
  */
  Cjt_problemas();

  // Modificadoras

  /** @brief Añade el problema p al conjunto de problemas.
      \pre Cierto.
      \post Si no existe un problema con identificador p en el parámetro implícito retorna cierto y añade p al parámetro implícito. En caso contrario retorna falso.
      \coste Logarítmico en el nombre de problemas.
  */
  bool anadir_problema(const string& p);

  /** @brief Se realiza un envío al problema p con resultado r.
    \pre Existe un problema con identificador p en el parámetro implícito. Si el envío es exitoso r == 1, en otro caso r == 0.
    \post Se actualizan las estadísticas del problema p del parámetro implícito según el valor de r.
    \coste Logarítmico en el nombre de problemas.
  */
  void realizar_envio(const string& p, const int& r);

  // Consultoras

  /** @brief Consultora del número de problemas.
    \pre Cierto.
    \post Retorna el número de problemas del parámetro implícito.
    \coste Constante.
  */
  int tamano() const;

  /** @brief Consulta si existe el problema p en el conjunto de problemas.
    \pre Cierto.
    \post Retorna cierto si existe un problema con identificador p en el parámetro implícito. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de problemas.
  */
  bool existe_problema(const string& p) const;

  // Lectura y escritura

  /** @brief Inicializa el conjunto de problemas.
    \pre El parámetro implícito	está vacío.
    \post El parámetro implícito contiene los problemas que se han leído.
  */
  void inicializar();

  /** @brief Escribe el contenido del problema p.
    \pre Cierto.
    \post Si existe un problema con identificador p en el parámetro implícito retorna cierto y escribe el identificador y su contenido. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de problemas.
  */
  bool escribir_problema(const string& p) const;

  /** @brief Escribe el contenido de cada problema del conjunto.
    \pre Cierto.
    \post Lista los problemas del parámetro implícito ordenados crecientemente por ratio y para cada uno escribe el identificador y su contenido.
  */
  void escribir_cjt() const;

private:
  /** @brief Repositorio de problemas de la plataforma. */
  map<string, Problema> cjt;
  
  /** @brief Función para la ordenación de problemas en escribir_cjt(). */
  static bool comp(const pair<const string&, const Problema&>& p1, const pair<const string&, const Problema>& p2);
};
#endif