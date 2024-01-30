/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Algoritmos y Estructuras de Datos Avanzadas
 *
 * @author Christopher Expósito Izquierdo
 * @date 01 March 2022
 * @brief Custom operators
 *        Operators are functions with a signature:
 *          <RETURN_TYPE> operator<NAME>(<PARAMS>)
 *        <NAME> represents the target operation, e.g. >, <, =, ==, << etc.
 *        Have all attributes of functions
 *        Always contain word operator in name
 *
 * @see https://en.cppreference.com/w/cpp/language/operators
 */

#include <algorithm>
#include <iostream>
#include <vector>

class Human {
 public:
  Human(int kindness) : kindness_{kindness} {}
  bool operator<(const Human& other) const {
    return kindness_ < other.kindness_;
  }

 private:
  int kindness_ = 100;
};

int main() {
  std::vector<Human> humans = {Human{0}, Human{10}};
  std::sort(humans.begin(), humans.end());
  return 0;
}
