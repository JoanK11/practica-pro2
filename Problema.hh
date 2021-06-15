/** @file Problema.hh
    @brief Especificación de la clase Problema
*/
#ifndef Problema_hh
#define Problema_hh

#ifndef NO_DIAGRAM
#include <iostream>
#endif
using namespace std;

/** @class Problema
    @brief Representa un problema
*/
class Problema {
public:

  // Constructora

  /** @brief Creadora por defecto.

  Se ejecuta automáticamente al declarar un problema.
    \pre Cierto.
    \post El resultado es un problema sin envíos.
    \coste Constante.
  */
  Problema();

  // Modificadoras

  /** @brief Se realiza un envío con resultado r al problema.
    \pre Si el envío es exitoso r == 1, en otro caso r == 0.
    \post Se incrementa el número de envíos al parámetro implícito. Si el envío es exitoso también se incrementa el número de usuarios que lo han resuelto.
    \coste Constante.
  */
  void nuevo_envio(const int& r);

  // Consultoras

  /** @brief Consultora del ratio.
    \pre Cierto.
    \post El resultado es el ratio del parámetro implícito.
    \coste Constante.
  */
  double ratio() const;

  // Escritura

  /** @brief Escribe el contenido del problema.
    \pre Cierto.
    \post Escribe el número de envíos totales, envíos resueltos y el ratio del parámetro implícito.
    \coste Constante.
  */
  void escribir_problema() const;

private:
  /** @brief Contador del número de envíos totales al problema. */
  int enviados;
  
  /** @brief Contador del número de envíos exitosos al problema. */
  int resueltos;
};
#endif