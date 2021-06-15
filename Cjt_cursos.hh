/** @file Cjt_cursos.hh
    @brief Especificación de la clase Cjt_cursos
*/
#ifndef CJT_CURSOS_HH
#define CJT_CURSOS_HH

#include "Cjt_sesiones.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif

/** @class Cjt_cursos
    @brief Representa un conjunto de cursos
*/
class Cjt_cursos {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un conjunto de cursos.
    \pre Cierto.
    \post El resultado es un conjunto de cursos vacío.
    \coste Constante.
  */
  Cjt_cursos();

  // Modificadoras
  
  /** @brief Actualiza las estadísticas del curso c y del usuario u tras inscribirse a c. 
    \pre Existe un curso con identificador c en el parámetro implícito.
    \post El usuario u pasa a tener como enviables los problemas del curso c a los cuales ya ha completado sus prerrequisitos pero aún no ha resuelto. También se actualiza el nombre de usuarios inscritos al curso c del parámetro implícito.
  */
  void inscribir_usuario(const int& c, Usuario& u, Cjt_sesiones& Sesiones);
  
  /** @brief Un usuario completa el curso c.
    \pre Existe un curso con identificador c en el parámetro implícito.
    \post Se incrementa por una unidad el número de usuarios que han completado el curso c y se decrementa por una unidad su número de usuarios inscritos.
    \coste Constante.
  */
  void nuevo_completado(const int& c);
  
  /** @brief Se da de baja un usuario del curso c.
    \pre Existe un curso con identificador c en el parámetro implícito.
    \post El curso c del parámetro implícito tiene un usuario inscrito menos.
    \coste Constante.
  */
  void baja_usuario(const int& c);

  /** @brief Consultora de intersección entre los problemas del curso c. Si no hay intersección añade c al conjunto de cursos.
    \pre El curso c está inicializado.
    \post Si no hay intersección entre los problemas del curso c retorna cierto y añade c al parámetro implícito. En caso contrario retorna falso.
  */
  bool existe_interseccion(Curso& c, Cjt_sesiones& Sesiones);

  /** @brief Actualiza las estadísticas del usuario u y de su curso tras realizar un envío al problema p con resultado r.
    \pre El usuario u está inscrito en uno de los cursos del parámetro implícito.
    \post Se actualizan las estadísticas del usuario u y del curso en el que está inscrito tras realizar el envío.
  */
  void realizar_envio(Usuario& u, const string& p, const int& r, Cjt_sesiones& Sesiones);

  // Consultoras

  /** @brief Consultora del número de cursos.
    \pre Cierto.
    \post Retorna el número de cursos del parámetro implícito.
    \coste Constante.
  */
  int tamano() const;

  /** @brief Consulta si existe el curso c en el conjunto de cursos.
    \pre Cierto.
    \post Retorna cierto si existe un curso con identificador c en el parámetro implícito. En caso contrario retorna falso.
    \coste Constante.
  */
  bool existe_curso(const int& c) const;

  /** @brief Consulta si el problema p pertenece al curso c.
    \pre Existe un curso con identificador c en el parámetro implícito.
    \post Si existe un problema con identificador p en el curso c retorna cierto y escribe el identificador de la sesión a la que pertenece p. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de problemas de c.
  */
  bool pertenece_problema(const int& c, const string& p) const;

  // Lectura y escritura

  /** @brief Inicializa el conjunto de cursos.
    \pre El parámetro implícito	está vacío.
    \post El parámetro implícito tiene su contenido inicial.
  */
  void inicializar(Cjt_sesiones& Sesiones);

  /** @brief Escribe el contenido del curso c.
    \pre Cierto.
    \post Si existe un curso con identificador c en el parámetro implícito retorna cierto y escribe el identificador y su contenido. En caso contrario retorna falso.
    \coste Constante si el curso no existe. En caso contrario lineal en el nombre de sesiones del curso.
  */
  bool escribir_curso(const int& c) const;

  /** @brief Escribe el contenido de cada curso.
    \pre Cierto.
    \post Lista los cursos del parámetro implícito y escribe para cada uno el identificador y su contenido, en el mismo orden de lectura.
  */
  void escribir_cjt() const;

private:
  /** @brief Repositorio de cursos de la plataforma. */
  vector<Curso> cjt;
};
#endif