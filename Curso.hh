/** @file Curso.hh
    @brief Especificación de la clase Curso
*/
#ifndef Curso_hh
#define Curso_hh

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#endif
using namespace std;

/** @class Curso
    @brief Representa un curso
*/
class Curso {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un curso.
    \pre Cierto.
    \post El resultado es un curso vacío, sin sesiones.
    \coste Constante.
  */
  Curso();

  // Modificadoras

  /** @brief Añade el problema p de la sesión s al repositorio de problemas del curso.
    \pre Cierto.
    \post Si no existe un problema con identificador p en el repositorio de problemas del parámetro implícito, retorna cierto y añade p al repositorio de problemas. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de problemas.
  */
  bool anadir_problema(const string& p, const string& s);

  /** @brief Un usuario nuevo se inscribe al curso.
    \pre Cierto.
    \post El parámetro implícito tiene un usuario inscrito más. Se escribe el número de usuarios inscritos actualmente al parámetro implícito.
    \coste Constante.
  */
  void nuevo_usuario();

  /** @brief Se da de baja un usuario del curso.
    \pre En el parámetro implícito almenos existe un usuario inscrito en él.
    \post El parámetro implícito tiene un usuario inscrito menos.
    \coste Constante.
  */
  void baja_usuario();

  /** @brief Un usuario completa el curso.
    \pre En el parámetro implícito almenos existe un usuario inscrito en él.
    \post Se incrementa por una unidad el número de usuarios que han completado el parámetro implícito y se decrementa por una unidad su número de usuarios inscritos.
    \coste Constante.
  */
  void nuevo_completado();

  // Consultoras

  /** @brief Consulta si el problema p pertenece al curso.
    \pre Cierto.
    \post Si existe un problema con identificador p en el parámetro implícito retorna cierto y escribe el identificador de la sesión a la que pertenece. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de problemas.
  */
  bool pertenece_problema(const string& p) const;

  /** @brief Consulta a qué sesión pertenece el problema p.
    \pre Existe un problema con identificador p en el parámetro implícito.
    \post Retorna el identificador de la sesión a la que pertenece el problema con identificador p.
    \coste Logarítmico en el nombre de problemas.
  */
  string sesion_problema(const string& p) const;
  
  /** @brief Consultora del nombre de sesiones del curso.
    \pre Cierto.
    \post Retorna el nombre de sesiones que tiene el parámetro implícito.
    \coste Constante.
  */
  int num_sesiones() const;
  
  /** @brief Consultora del identificador de la sesión i-ésima.
    \pre Existe una sesión i-ésima en el parámetro implícito.
    \post Retorna el identificador de la sesión i-ésima del parámetro implícito.
    \coste Constante.
  */
  string sesion_id(const int& i) const;

  // Lectura y escritura

  /** @brief Lee los identificadores de las sesiones que pertenecerán al curso.
    \pre El parámetro implícito está vacío.
    \post El parámetro implícito ahora contiene las sesiones que se han leído.
  */
  void leer();

  /** @brief Escribe el contenido del curso.
    \pre El parámetro implícito está inicializado.
    \post Escribe el número de usuarios inscritos y completados y los identificadores de todas las sesiones del parámetro implícito en el mismo orden de lectura.
    \coste Lineal en el nombre de sesiones.
  */
  void escribir_curso() const;

private:
  /** @brief Contador del número de usuarios actualmente inscritos al curso. */
  int inscritos;
  
  /** @brief Contador del número de usuarios que han completado todos los problemas del curso. */
  int completados;
  
  /** @brief Repositorio de sesiones del curso. */
  vector<string> v;
  
  /** @brief Repositorio de problemas del curso. La clave es el identificador del problema y su contenido el identificador de la sesión a la que pertenece. */
  map<string, string> problemas;
};
#endif