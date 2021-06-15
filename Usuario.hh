/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/
#ifndef Usuario_hh
#define Usuario_hh

#ifndef NO_DIAGRAM
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Usuario
    @brief Representa un usuario registrado en la plataforma
*/
class Usuario {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un usuario.
    \pre Cierto.
    \post El resultado es un usuario vacío: no inscrito en ningún curso y sin ningún envío.
    \coste Constante.
  */
  Usuario();

  // Modificadoras

  /** @brief Inscribe el usuario al curso c.
    \pre El parámetro implícito no está inscrito en ningún curso.
    \post El parámetro implícito está inscrito al curso con identificador c si no ha resuelto ya todos sus problemas.
    \coste Constante.
  */
  void inscribir_curso(const int& c);

  // Consultoras

  /** @brief Consultora del curso.
    \pre Cierto.
    \post El resultado es el identificador del curso en el que está inscrito el parámetro implícito, si no está inscrito en ninguno retorna 0.
    \coste Constante.
  */
  int id_curso() const;

  /** @brief Consulta si el usuario ha resuelto el problema p.
    \pre El parámetro implícito está inscrito en un curso en el que existe un problema con identificador p en él.
    \post Si el parámetro implícito ha resuelto el problema con identificador p retorna cierto. En caso contrario retorna falso y añade p al conjunto de problemas enviables del parámetro implícito.
    \coste Logarítmico en el nombre de problemas resueltos.
    */
  bool problema_resuelto(const string& p);

  /** @brief Actualiza las estadísticas del usuario después de realizar un envío al problema p con resultado r.
    \pre El problema p pertenece al conjunto de problemas enviables del parámetro implícito. Si el envío es exitoso r == 1, en caso contrario r == 0.
    \post Si el parámetro implícito hace el envío a un problema nuevo incrementa por una unidad su número de problemas intentados. Si el envío era correcto elimina p del conjunto de problemas enviables y lo añade al conjunto de problemas resueltos. Por último, si después del envío resulta que el parámetro implícito ha completado todos los problemas del curso, el parámetro implícito deja de estar inscrito a ese curso y pone su curso actual a 0.
    \coste Logarítmico en el nombre de problemas enviables. Si el envío era correcto también se le añade el coste logarítmico en el nombre de problemas resueltos.
  */
  void envio_problema(const string& p, const int& r);

  // Escritura

  /** @brief Escribe el contenido del usuario.
    \pre Cierto.
    \post Escribe el número de envíos totales, resueltos e intentados del parámetro implícito y el identificador del curso en el que está inscrito (0 si no está inscrito en ninguno).
    \coste Constante.
  */
  void escribir_usuario() const;

  /** @brief Escribe todos los problemas resueltos del usuario.
    \pre Cierto.
    \post Escribe el identificador y el número de envíos realizados de todos los problemas que el parámetro implícito ha resuelto, ordenados crecientemente por identificador.
    \coste Lineal en el nombre de problemas resueltos.
  */
  void escribir_resueltos() const;

  /** @brief Escribe todos los problemas enviables del usuario.
    \pre Cierto.
    \post Escribe el identificador y el número de envíos realizados de todos los problemas que el parámetro implícito aún no ha resuelto pero que ya puede realizar un envío, ordenados crecientemente por identificador.
    \coste Lineal en el nombre de problemas enviables.
  */
  void escribir_enviables() const;

private:
  
  /** @brief Identificador del curso en el que está inscrito el usuario. Si no está inscrito en ninguno su valor es 0. */
  int curso;
  
  /** @brief Contador del número de envíos totales del usuario. */
  int envios;
  
  /** @brief Contador del número de problemas intentados del usuario. */
  int intentados;
  
  /** @brief Repositorio de problemas resueltos del usuario. La clave es el identificador del problema y su contenido el número de envíos. */
  map<string, int> resueltos;
  
  /** @brief Repositorio de problemas enviables del usuario. La clave es el identificador del problema y su contenido el número de envíos. */
  map<string, int> enviables;
};
#endif