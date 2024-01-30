/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 *
 * @author Christopher Expósito-Izquierdo
 * @date 3 March 2022
 * @brief Overloading of arithmetic operators. Client code
 */

#include <iostream>

#include "cents.h"

int main() {
  Cents cents1{6};
  Cents cents2{8};
  Cents total{cents1 + cents2};  // without the prototype in cents.h, this would fail to compile
  std::cout << "I have " << total.cents() << " cents." << std::endl;
  return 0;
}
