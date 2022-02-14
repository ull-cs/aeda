/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 *
 * @author Christopher Expósito Izquierdo
 * @date 14 February 2022
 * @brief assert macro example
 * assert macro allows testing of boolean condition at run time
 * Typically used to test sanity of code (e.g., test preconditions, postconditions, or other invariants) or test validity of assumptions made by code
 * Defined in header file cassert
 * Macro takes single argument: boolean expression
 * If assertion fails, program is terminated by calling std::abort
 * If NDEBUG preprocessor symbol is defined at time cassert header file included, all assertions are disabled (i.e., not checked)
 *
 * @see https://en.cppreference.com/w/cpp/error/assert
 */

#include <iostream>
// uncomment next line to disable assert()
//#define NDEBUG // it must be above #include <assert.h>

#include <assert.h>
 
// Use (void) to silent unused warnings.
#define assertm(exp, msg) assert(((void)msg, exp))
 
int main() {
  assert(2 + 2 == 4);
  std::cout << "Execution continues past the first assert" << std::endl;
  assertm(2 + 2 == 5, "There are five lights");
  std::cout << "Execution continues past the second assert" << std::endl;
  assert((2 * 2 == 5) && "Yet another way to add assert message");
  return 0;
}
