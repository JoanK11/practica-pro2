/** @file Cjt_usuarios.hh
    @brief Especificación de la clase Cjt_usuarios
*/
#ifndef CJT_USUARIOS_HH
#define CJT_USUARIOS_HH
#include "Cjt_cursos.hh"

/** @class Cjt_usuarios
    @brief Representa un conjunto de usuarios
*/
class Cjt_usuarios {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un conjunto de usuarios.
    \pre Cierto.
    \post El resultado es un conjunto de usuarios vacío.
    \coste Constante.
  */
  Cjt_usuarios();

  // Modificadoras

  /** @brief Añade el usuario u al conjunto de usuarios.
      \pre Cierto.
      \post Si no existe un usuario con identificador u en el parámetro implícito retorna cierto y añade u al parámetro implícito. En caso contrario retorna falso.
      \coste Logarítmico en el nombre de usuarios.
  */
  bool anadir_usuario(const string& u);

  /** @brief Borra el usuario u del conjunto de usuarios.
      \pre Cierto.
      \post Si existe un usuario con identificador u en el parámetro implícito retorna cierto, borra u del parámetro implícito y también lo elimina del curso donde estaba inscrito. En caso contrario retorna falso.
      \coste Logarítmico en el nombre de usuarios.
  */
  bool borrar_usuario(const string& u, Cjt_cursos& Cursos);

  /** @brief Inscribe el usuario al que apunta el iterador de usuarios al curso con identificador c.
    \pre El iterador de usuarios apunta a un usuario válido del parámetro implícito. Existe un curso con identificador c en el conjunto de cursos.
    \post Si el usuario al que apunta el iterador no está inscrito en ningún curso lo inscribe al curso c (si no ha resuelto ya todos sus problemas) y también actualiza las estadísticas de c y los problemas enviables del usuario. En caso contrario retorna falso.
  */
  bool inscribir_curso(const int& c, Cjt_sesiones& Sesiones, Cjt_cursos& Cursos);

  /** @brief El usuario u realiza un envío al problema p con resultado r.
    \pre Existe un usuario con identificador u en el parámetro implícito y p pertenece al conjunto de problemas enviables del usuario. Si el envío es exitoso r == 1, en caso contrario r == 0.
    \post Se actualizan las estadísticas del curso y los problemas enviables del usuario.
  */
  void realizar_envio(const string& u, const string& p, const int& r, Cjt_cursos& Cursos, Cjt_sesiones& Sesiones);

  // Consultoras

  /** @brief Consultora del número de usuarios.
    \pre Cierto.
    \post Retorna el número de usuarios del parámetro implícito.
    \coste Constante.
  */
  int tamano() const;

  /** @brief Consulta si existe el usuario u en el conjunto de usuarios.
    \pre Cierto.
    \post Si existe un usuario con identificador u en el parámetro implícito retorna cierto y el iterador de usuarios pasa a apuntar al usuario buscado. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de usuarios.
  */
  bool existe_usuario(const string& u);

  /** @brief Consulta el curso del usuario u.
    \pre Cierto.
    \post Si existe un usuario con identificador u en el parámetro implícito retorna cierto y escribe el identificador del curso en el que está inscrito (0 si no está inscrito en ninguno). En caso contrario retorna falso.
    \coste Logarítmico en el nombre de usuarios.
  */
  bool consultar_curso(const string& u) const;

  // Lectura y escritura

  /** @brief Inicializa el conjunto de usuarios.
    \pre El parámetro implícito	está vacío.
    \post El parámetro implícito contiene los usuarios que se han leído.
  */
  void inicializar();

  /** @brief Escribe el contenido del usuario u.
    \pre Cierto.
    \post Si existe un usuario con identificador u en el parámetro implícito, retorna cierto y escribe el identificador y su contenido. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de usuarios.
  */
  bool escribir_usuario(const string& u) const;

  /** @brief Escribe los problemas resueltos del usuario u.
    \pre Cierto.
    \post Si existe un usuario con identificador u en el parámetro implícito, retorna cierto y escribe sus problemas resueltos. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de usuarios. Si el usuario u existe también se le añade el coste lineal en su nombre de problemas resueltos.
  */
  bool escribir_resueltos(const string& u) const;

  /** @brief Escribe los problemas enviables del usuario al que apunta el iterador de usuarios.
    \pre El iterador de usuarios apunta a un usuario válido del parámetro implícito.
    \post Si el usuario al que apunta el iterador está inscrito en algún curso, retorna cierto y escribe sus problemas enviables. En caso contrario retorna falso.
    \coste Constante si el usuario no estaba inscrito en ningún curso. En caso contrario lineal en su nombre de problemas enviables.
  */
  bool escribir_enviables() const;

  /** @brief Escribe el contenido de cada usuario.
    \pre Cierto.
    \post Lista los usuarios del parámetro implícito y escribe el identificador y su contenido para cada uno de ellos.
    \coste Lineal en el nombre de usuarios.
  */
  void escribir_cjt() const;

private:
  /** @brief Repositorio de usuarios de la plataforma. */
  map<string, Usuario> cjt;
  
  /** @brief Iterador para recorrer el repositorio de usuarios. */
  map<string, Usuario>::iterator cjt_it;
};
#endif