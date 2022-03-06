#include <iostream>

#include "deque.h"

using namespace std;

const std::string kHelpText = "Este programa toma como parámetro un número y crea una deque con dicho número de elementos para luego vaciarla";

void Usage(int argc, char* argv[]) {
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

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const int kElements = stoi(argv[1]);
  srand(time(NULL));
  Deque deque(kElements);
  for (int i = 0; i < kElements; i++) {
    const int randomNumber = rand() % 10 + 1;
    if ((rand() % 2) == 0) {
      deque.insertFront(randomNumber);
      cout << randomNumber << " has been inserted from front" << endl;
    } else {
      deque.insertRear(randomNumber);
      cout << randomNumber << " has been inserted from rear" << endl;
    }
  }
  while (!deque.isEmpty()) {
    if ((rand() % 2) == 0) {
      cout << "Front element: " << deque.getFront() << endl;
      deque.deleteFront();
    } else {
      cout << "Rear element: " << deque.getRear() << endl;
      deque.deleteRear();
    }
  }
  return 0;
}
