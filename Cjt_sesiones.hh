/** @file Cjt_sesiones.hh
    @brief Especificación de la clase Cjt_sesiones
*/
#ifndef CJT_SESIONES_HH
#define CJT_SESIONES_HH
#include "Sesion.hh"

/** @class Cjt_sesiones
    @brief Representa un conjunto de sesiones
*/
class Cjt_sesiones {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un conjunto de sesiones.
    \pre Cierto.
    \post El resultado es un conjunto de sesiones vacío.
    \coste Constante.
  */
  Cjt_sesiones();
  
  // Modificadoras

  /** @brief Añade la sesión ses al conjunto de sesiones.
      \pre Cierto.
      \post Si no existe una sesión con identificador s en el parámetro implícito retorna cierto y añade ses al parámetro implícito. En caso contrario retorna falso.
      \coste Logarítmico en el nombre de sesiones.
  */
  bool anadir_sesion(const string& s, const Sesion& ses);

  /**@brief El usuario u realiza un envío al problema p con resultado r.
    \pre El problema p pertenece a una de las sesiones del curso c.
    \post Se actualizan las estadísticas del usuario u y del curso c tras realizar el envío.
  */
  void realizar_envio(Usuario& u, const string& p, const int& r, Curso& c);

  // Consultoras
  
  /** @brief Consultora de la sesión.
    \pre Existe una sesión con identificador s en el parámetro implícito.
    \post Retorna la sesión con identificador s del parámetro implícito.
    \coste Logarítmico en el nombre de sesiones.
  */
  Sesion operator[](const string& s);

  /** @brief Consultora del número de sesiones.
    \pre Cierto.
    \post Retorna el número de sesiones del parámetro implícito.
    \coste Constante.
  */
  int tamano() const;

  // Lectura y escritura

  /** @brief Inicializa el conjunto de sesiones.
    \pre El parámetro implícito	está vacío.
    \post El parámetro implícito tiene su contenido inicial.
  */
  void inicializar();

  /** @brief Escribe el contenido de la sesión s.
    \pre Cierto.
    \post Si existe una sesión con identificador s en el parámetro implícito retorna cierto y escribe su contenido. En caso contrario retorna falso.
    \coste Logarítmico en el nombre de sesiones. Si la sesión s existe también se le añade el coste lineal en el nombre de problemas de la sesión.
  */
  bool escribir_sesion(const string& s) const;

  /** @brief Escribe el contenido de cada sesión.
    \pre Cierto.
    \post Lista las sesiones del parámetro implícito y escribe el identificador y el contenido de cada una, ordenadas crecientemente por identificador.
  */
  void escribir_cjt() const;

private:
  /** @brief Repositorio de sesiones de la plataforma. */
  map<string, Sesion> cjt;
};
#endif