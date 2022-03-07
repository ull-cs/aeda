/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 *
 * @author Christopher Expósito-Izquierdo
 * @date 3 March 2022
 * @brief Overloading of arithmetic operators.
 * @see https://www.learncpp.com/cpp-tutorial/9-2a-overloading-operators-using-normal-functions/
 */

#include "cents.h"

// note: this function is not a member function nor a friend function!
Cents operator+(const Cents& c1, const Cents& c2) {
  // we don't need direct access to private members here
  return Cents{c1.cents() + c2.cents()};
}
