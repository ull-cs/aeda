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
 * The assert macro checks for the validity of the assertions or assumptions. 
 * If the assertion results to be FALSE then the macro writes information about the call that 
 * failed on stderr and then calls abort(). 
 * abort() raises the SIGABRT signal and this results in an abnormal termination of the process.
 *
 * @see https://en.cppreference.com/w/cpp/error/assert
 */

#include <iostream>

// uncomment next line to disable assert()
//#define NDEBUG // it must be above #include <assert.h>

#include <assert.h>

double MySqrt(double x) {
  assert(x >= 0);
  std::cout << "Execution in Mysqrt function" << std::endl;
  return x;
}

int main() {
  double param = -1.0;
  const double result{MySqrt(param)};
  std::cout << "param: " << param << " result: " << result << std::endl;
  return 0;
}
