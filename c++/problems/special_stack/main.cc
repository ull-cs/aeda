#include <stdlib.h>
#include <iostream>
#include "special_stack.h"

using namespace std;

const std::string kHelpText = "Este programa toma como parámetro un número y crea una pila especial con dicho número de elementos para luego vaciarla";

void Usage(int argc, char *argv[]) {
  if (argc == 2) {
    std::string parameter{argv[1]};
    if (parameter == "--help") {
      std::cout << kHelpText << std::endl;
      exit(EXIT_FAILURE);
    }
  } else {
    std::cout << "El programa requiere un parámetro." << std::endl;
    std::cout << "Modo de uso:" << std::endl;
    std::cout << argv[0] << " NUMERO" << std::endl;
    std::cout << "Pruebe " << argv[0] << " --help para más información" << std::endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  Usage(argc, argv);
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  SpecialStack stack;
  for (int i = 0; i < kElements; i++) {
    const int randomNumber = rand() % 10 + 1;
    stack.push(randomNumber);
    cout << randomNumber << " has been pushed" << endl;
    stack.print();
  }
  cout << "Elements present in stack: ";
  while (!stack.isEmpty()) {
    int topElement = stack.pop();
    cout << topElement << " (min=" << stack.getMin() << ") ";
  }
  cout << endl;
  return 0;
}
