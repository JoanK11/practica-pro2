/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef Sesion_hh
#define Sesion_hh
#include "Curso.hh"
#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <set>
#endif

/** @class Sesion
    @brief Representa una sesión
*/
class Sesion {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar una sesión.
    \pre Cierto.
    \post El resultado es una sesión vacía.
    \coste Constante.
  */
  Sesion();

  // Consultoras

  /** @brief Actualiza los problemas enviables del usuario u tras inscribirse a un nuevo curso o realizar un envío exitoso a un problema de la sesión.
    \pre El parámetro implícito pertenece al curso en el cual está inscrito el usuario u.
    \post Se actualizan los problemas enviables del usuario u.
  */
  void encontrar_enviables(Usuario& u) const;

  /** @brief Consulta si hay intersección entre los problemas de la sesión y el curso c.
    \pre El parámetro implícito forma parte de una de las sesiones del curso c.
    \post Si no existe intersección entre el parámetro implícito y los problemas que actualmente forman el curso c, retorna cierto y añade los problemas del parámetro implícito a c. En caso contrario retorna falso.
  */
  bool interseccion_vacia(Curso& c, const string& id) const;

  /** @brief Actualiza los problemas enviables del usuario u después de realizar un envío exitoso al problema p.
    \pre El problema p pertenece al parámetro implícito.
    \post Se añade al conjunto de problemas enviables del usuario u los problemas sucesores a p los cuales ya cumple sus prerrequisitos.
    \coste Lineal en el nombre de problemas.
  */
  void nuevo_envio(const string& p, Usuario& u) const;

  /** @brief Añade los problemas de la sesión al conjunto de problemas del curso c.
    \pre El parámetro implícito forma parte de una de las sesiones del curso c y no existe intersección entre ellos.
    \post Añade los problemas del parámetro implícito al curso c.
    \coste O(Nlog(n)). N = Nombre de problemas de la sesión, n = Nombre de problemas del curso.
  */
  void anadir_problemas(Curso& c, const string& id) const;

  // Lectura y escritura

  /** @brief Lee los problemas de la sesión.
    \pre El parámetro implícito está vacío.
    \post El parámetro implícito contiene los problemas que se han leído, siguiendo un recorrido en preorden. Se actualiza el nombre de problemas de la sesión.
  */
  void leer();

  /** @brief Escribe el contenido de la sesión.
    \pre Cierto.
    \post Escribe el nombre total de problemas y los identificadores de todos los problemas del parámetro implícito, en postorden.
    \coste Lineal en el nombre de problemas.
  */
  void escribir_sesion() const;

private:
  
  /** @brief Repositorio de problemas de la sesión con una estructura de prerrequisitos binario. */
  BinTree<string> a;
  
  /** @brief Contador del número de problemas de la sesión. */
  int tam;

  /** @brief Actualiza los problemas enviables del usuario u.
    \pre Cierto.
    \post El usuario u pasa a tener como enviables los problemas del parámetro implícito a los que ya cumple sus prerrequisitos.
  */
  void encontrar_enviables_rec(const BinTree<string>& a, Usuario& u) const;

  /** @brief Consulta si hay intersección entre los problemas de la sesión y el curso c.
    \pre Cierto.
    \post Añade los problemas del parámetro implícito al curso c. El booleano b es cierto si no existe intersección, falso de lo contrario.
    \coste O(Nlog(n)). N = Nombre de problemas de la sesión, n = Nombre de problemas del curso.
  */
  void interseccion_vacia_rec(const BinTree<string>& a, Curso& c, const string& id, bool& b) const;

  /** @brief Buscadora del subárbol de la sesión con valor de la raíz == p.
    \pre Cierto.
    \post Si el booleano found es cierto raíz == p y se llama a la función encontrar_enviables_rec() con el subárbol actual para actualizar los problemas enviables del usuario u. En caso contrario se sigue buscando el problema p en el parámetro implícito.
    \coste Lineal en el nombre de problemas.
  */
  void encontrar_problema(const BinTree<string>& a, const string& p, Usuario& u, bool& found) const;

  /** @brief Añade los problemas de la sesión al conjunto de problemas del curso c.
    \pre Cierto.
    \post Añade los problemas del parámetro implícito al curso c.
    \coste O(Nlog(n)). N = Nombre de problemas de la sesión, n = Nombre de problemas del curso.
  */
  void anadir_problemas_rec(const BinTree<string>& a, Curso& c, const string& id) const;

  /** @brief Lee los problemas de la sesión.
    \pre Cierto.
    \post El parámetro implícito contiene los problemas que se han leído, siguiendo un recorrido en preorden. Se actualiza el nombre de problemas de la sesión.
  */
  void leer_rec(BinTree<string>& a);

  /** @brief Escribe el contenido de la sesión.
    \pre Cierto.
    \post Escribe los identificadores de todos los problemas del parámetro implícito, siguiendo un recorrido en postorden.
    \coste Lineal en el nombre de problemas.
  */
  void escribir_sesion_rec(const BinTree<string>& a) const;
};
#endif